#ifndef _LIB_H_
#define _LIB_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace doys
{
	class DayOfYearSet
	{
	public:

		/* DayOfYear class */
		class DayOfYear
		{
			public:
				DayOfYear(); /* set the time to january 1 */
				DayOfYear(int day, int month);
				DayOfYear(const DayOfYear& object); /* copy constructor */
				DayOfYear(initializer_list<int>);
				~DayOfYear();

				/* getters and setters */
				inline int	getDay() const {return (day);};
				inline int	getMonth() const {return (month);};
				void	setDay(int);
				void	setMonth(int);

				void	checkValidity();

				/* operator overloading functions */
				friend bool	operator==(const DayOfYear&, const DayOfYear&);
				friend bool	operator!=(const DayOfYear&, const DayOfYear&);
				DayOfYear&	operator=(const DayOfYear&);
				friend ostream&	operator<<(ostream& output, const DayOfYear&);

				/* static functions to keep the number of DayOfYear objects */
				inline static int	getTotalDayOfYearObjects() {return (totalObjects);};
				static void	setTotalObjects(int change);
			private:
				int	day;
				int	month;
				static int	totalObjects;
		};
		/* DayOfYear class is end*/

		DayOfYearSet(DayOfYear *doyArr, int);
		DayOfYearSet(vector<DayOfYear> doyVector);
		DayOfYearSet(initializer_list<DayOfYear> initList);
		DayOfYearSet();
		~DayOfYearSet();
		DayOfYearSet(const DayOfYearSet& object); /* to copy */
		bool	add(const DayOfYear& dayOfYear);
		bool	remove(const DayOfYear& dayOfYear);
		int	getSize() const;
		DayOfYear*	getArray() const;
		void	setSize(int size);
		void	clear();


		/* const is necessary. Because operator mustn't change the second object's parameters */
		DayOfYearSet&	operator=(const DayOfYearSet&);
		friend ostream&	operator<<(ostream& output, const DayOfYearSet&);
		friend bool	operator==(const DayOfYearSet&, const DayOfYearSet&);
		friend bool	operator!=(const DayOfYearSet&, const DayOfYearSet&);
		friend const DayOfYearSet	operator+(const DayOfYearSet&, const DayOfYearSet&);
		DayOfYearSet&	operator+(const DayOfYear&);
		friend const DayOfYearSet	operator-(const DayOfYearSet&, const DayOfYearSet&);
		DayOfYearSet&	operator-(const DayOfYear&);
		friend const DayOfYearSet	operator^(const DayOfYearSet&, const DayOfYearSet&);
		friend const DayOfYearSet	operator!(const DayOfYearSet&);
		DayOfYear	operator[](int);
		
		static void	saveFile(fstream& file, DayOfYearSet&);

	private:
		DayOfYear	*doyArr;
		int size;
	};
}

#endif /* _LIB_H_ */
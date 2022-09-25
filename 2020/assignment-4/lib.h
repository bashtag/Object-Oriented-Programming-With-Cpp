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
				DayOfYear(); /* empty, this constructor won't initialize variables */
				DayOfYear(int day, int month);
				DayOfYear(const DayOfYear& object); /* copy constructor */

				/* getters and setters */
				inline int	getDay() const {return (day);};
				inline int	getMonth() const {return (month);};
				inline int	getNumOfDay() const {return (numOfDay);};
				void	setDay(int);
				void	setMonth(int);
				void	setNumOfDay();

				/* operator overloading functions */
				bool	operator==(const DayOfYear&);
				bool	operator!=(const DayOfYear&);
				DayOfYear&	operator=(const DayOfYear&);
				friend ostream&	operator<<(ostream& output, const DayOfYear&);

			private:
				int	numOfDay;
				int	day;
				int	month;
		};
		/* DayOfYear class is end*/

		
		DayOfYearSet(DayOfYear *doyArr);
		DayOfYearSet(vector <DayOfYear> doyVector);
		DayOfYearSet();
		~DayOfYearSet();
		DayOfYearSet(const DayOfYearSet& object); /* to copy */
		bool	add(DayOfYear& dayOfYear);
		bool	remove(DayOfYear& dayOfYear);
		int	getSize() const;
		DayOfYear*	getArray() const;
		void	setSize(int change);


		/* const is necessary. Because operator mustn't change the second object's parameters */
		friend	ostream&	operator<<(ostream& output, const DayOfYearSet&);
		friend	bool	operator==(const DayOfYearSet&, const DayOfYearSet&);
		friend	bool	operator!=(const DayOfYearSet&, const DayOfYearSet&);
		friend const DayOfYearSet	operator+(const DayOfYearSet&, const DayOfYearSet&);
		friend const DayOfYearSet	operator-(const DayOfYearSet&, const DayOfYearSet&);
		friend const DayOfYearSet	operator^(const DayOfYearSet&, const DayOfYearSet&);
		friend const DayOfYearSet	operator!(const DayOfYearSet&);
		DayOfYear	operator[](int);

		/* static functions to keep the number of DayOfYear objects */
		inline static int	getTotalDayOfYearObjects() {return (totalObjects);};
		static void	setTotalObjects(int change);
		
		static void	saveFile(fstream& file, DayOfYearSet&);

	private:
		DayOfYear	*doyArr;
		int size;
		static int	totalObjects;
	};
}

#endif /* _LIB_H_ */
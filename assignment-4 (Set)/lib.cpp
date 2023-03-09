#include "lib.h"

using namespace std;

namespace doys
{
	/*----------------------- DayOfYear class implementations -----------------------*/

	/* set the day January 1 */
	DayOfYearSet::DayOfYear::DayOfYear()
	{
		this->day = 1;
		this->month = 1;
		this->checkValidity();
		this->setTotalObjects(1);
	}
	DayOfYearSet::DayOfYear::DayOfYear(int _day, int _month) : day(_day), month(_month)
	{
		this->checkValidity();
		this->setTotalObjects(1);
	}
	DayOfYearSet::DayOfYear::DayOfYear(const DayOfYear& obj)
	{
		*this = obj;
		this->setTotalObjects(1);
	}
	DayOfYearSet::DayOfYear::DayOfYear(initializer_list<int> initList)
	{
		if (initList.size() != 2)
			throw	invalid_argument("Size of DayOfYear object's initializer list must be 2");
		this->day = *(initList.begin());
		this->month = *(initList.begin() + 1);
		this->checkValidity();
		this->setTotalObjects(1);
	}
	DayOfYearSet::DayOfYear::~DayOfYear()
	{
		this->setTotalObjects(-1);
	}

	void	DayOfYearSet::DayOfYear::setDay(int day)
	{
		this->day = day;
	}
	void	DayOfYearSet::DayOfYear::setMonth(int month)
	{
		this->month = month;
	}

	/**
	 * @brief checking function to check if the day is valid or not
	 * 
	 */
	void	DayOfYearSet::DayOfYear::checkValidity()
	{
		if (this->day < 1 || this->day > 31 || (this->month == 2 && this->day > 28) ||
			(this->month < 8 && this->month % 2 == 0 && this->day > 30) ||
			(this->month >= 8 && this->month % 2 == 1 && this->day > 30))
			throw	invalid_argument("Invalid Day or Month");

	}

	bool	operator==(const DayOfYearSet::DayOfYear& obj1, const DayOfYearSet::DayOfYear& obj2)
	{
		if (obj1.getDay() == obj2.getDay() && obj1.getMonth() == obj2.getMonth())
			return (true);
		else
			return (false);
	}

	bool	operator!=(const DayOfYearSet::DayOfYear& obj1, const DayOfYearSet::DayOfYear& obj2)
	{
		if (obj1 == obj2)
			return (false);
		else
			return (true);
	}

	DayOfYearSet::DayOfYear&	DayOfYearSet::DayOfYear::operator=(const DayOfYear& obj)
	{
		this->setDay(obj.getDay());
		this->setMonth(obj.getMonth());

		return (*this);
	}

	ostream&	operator<<(ostream& output, const DayOfYearSet::DayOfYear& obj)
	{
		output << "(Day: " << obj.getDay() << " Month: "
			<< obj.getMonth() << ")" << endl;

		return (output);
	}

	void	DayOfYearSet::DayOfYear::setTotalObjects(int change)
	{	
		DayOfYearSet::DayOfYear::totalObjects+=change;
	}
	/*----------------------- DayOfYearSet class implementations -----------------------*/

	DayOfYearSet::DayOfYearSet(DayOfYear *doyArr, int size)
	{
		this->size = size;
		this->doyArr = nullptr;
		this->doyArr = new DayOfYear[this->size];

		for (int i = 0; i < this->size; i++)
			this->doyArr[i] = doyArr[i];

	}
	DayOfYearSet::DayOfYearSet(vector <DayOfYear> doyVector)
	{
		this->size = doyVector.size();
		this->doyArr = nullptr;
		this->doyArr = new DayOfYear[this->size];

		for(int i = 0; i < this->size; i++)
			this->doyArr[i] = doyVector[i];

	}
	DayOfYearSet::DayOfYearSet(initializer_list<DayOfYear> initList)
	{
		this->size = initList.size();
		this->doyArr = nullptr;
		this->doyArr = new DayOfYear[this->size];

		for (int i = 0; i < this->size; ++i)
			this->doyArr[i] = *(initList.begin() + i);
	}
	DayOfYearSet::DayOfYearSet()
	{
		this->size = 0;
		this->doyArr = nullptr;
	}
	DayOfYearSet::~DayOfYearSet()
	{
		delete[] this->doyArr;
		this->doyArr = nullptr;
	}
	DayOfYearSet::DayOfYearSet(const DayOfYearSet& object)
	{
		this->doyArr = new DayOfYear[object.getSize()];

		for (int i = 0; i < object.getSize(); i++)
			this->doyArr[i] = object.getArray()[i];

		this->setSize(object.getSize());
	}

	/**
	 * @brief to add a day of year object in the set.
	 * I have used a reallocation algorithm.
	 * 
	 * @param dayOfYear 
	 * @return true 
	 * @return false 
	 */
	bool	DayOfYearSet::add(const DayOfYear& dayOfYear)
	{
		DayOfYear	*temp = NULL;
		bool	isThere = false;
		int	i;

		for (i = 0; i < this->getSize(); i++)
			if (dayOfYear == this->getArray()[i])
				isThere = true;

		if (!isThere)
			temp = new DayOfYear[this->size + 1];

		if (temp)
		{
			for (i = 0; i < this->size; i++)
				temp[i] = this->doyArr[i];
			
			temp[this->size] = dayOfYear;

			delete[] this->doyArr;
			this->doyArr = temp;
			this->setSize(this->size + 1);

			DayOfYearSet::DayOfYear::setTotalObjects(1);

			return (true);
		}
		

		return (false);
	}

	/**
	 * @brief to remove a day of year object from the set.
	 * My algorithm is finding element and sliding all remaining elements left.
	 * 
	 * @param dayOfYear 
	 * @return true 
	 * @return false 
	 */
	bool	DayOfYearSet::remove(const DayOfYear& dayOfYear)
	{
		bool	isThere = false;
		int	i;

		for (i = 0; !isThere && i < this->getSize(); i++)
			if (this->getArray()[i] == dayOfYear)
				isThere = true;

		i--;

		if (isThere)
		{
			for (; i + 1 < this->getSize(); i++)
				this->doyArr[i] = this->doyArr[i + 1];
			DayOfYearSet::DayOfYear::setTotalObjects(-1);
			this->setSize(this->size - 1);
		}


		return (isThere);
	}

	int	DayOfYearSet::getSize() const
	{
		return (this->size);
	}

	DayOfYearSet::DayOfYear*	DayOfYearSet::getArray() const
	{
		return (this->doyArr);
	}

	void	DayOfYearSet::setSize(int size)
	{
		this->size = size;
	}

	void	DayOfYearSet::clear()
	{
		this->~DayOfYearSet();
	}


	/* Operator overloading part */

	/**
	 * @brief I used this basic assign method. Memory location didn't changed.
	 * 
	 * @param dayOfYearSet 
	 * @return DayOfYearSet& 
	 */
	DayOfYearSet&	DayOfYearSet::operator=(const DayOfYearSet& dayOfYearSet)
	{
		if (this->doyArr != dayOfYearSet.doyArr)
		{
			delete[] this->doyArr;
			this->doyArr = nullptr;
			this->doyArr = new DayOfYear[dayOfYearSet.size];
			if (this->doyArr != nullptr)
			{
				for (int i = 0; i < dayOfYearSet.size; ++i)
					this->doyArr[i] = dayOfYearSet.doyArr[i];
				this->size = dayOfYearSet.size;
			}
			else
				throw	bad_alloc();
		}
		return (*this);
	}

	ostream&	operator<<(ostream& output, const DayOfYearSet& dayOfYearSet)
	{
		output << "There are " << dayOfYearSet.getSize() << " days." << endl;

		for (int i = 0; i < dayOfYearSet.getSize(); i++)
		{
			output << i + 1 <<  ". element of array:\n\tDay-> " << dayOfYearSet.getArray()[i].getDay() << "\tMonth-> " << dayOfYearSet.getArray()[i].getMonth() << '\n' << endl;
		}

		return (output);
	}

	bool	operator==(const DayOfYearSet& dayOfYearSet, const DayOfYearSet& compDayOfYearSet)
	{
		bool	isEqual = true;

		if (dayOfYearSet.getSize() != compDayOfYearSet.getSize())
			isEqual = false;

		for (int i  = 0; isEqual && i < dayOfYearSet.getSize(); i++)
			if (dayOfYearSet.getArray()[i].getDay() != compDayOfYearSet.getArray()[i].getDay() ||
			dayOfYearSet.getArray()[i].getMonth() != compDayOfYearSet.getArray()[i].getMonth())
				isEqual = false;

		return (isEqual);
	}

	bool	operator!=(const DayOfYearSet& dayOfYearSet, const DayOfYearSet& compDayOfYearSet)
	{
		return (!(dayOfYearSet == compDayOfYearSet));
	}

	/**
	 * @brief I used a constructor which has a vector parameter in this operator overload function.
	 * I used basic intersection method.
	 * @param firstDayOfYearSet 
	 * @param secondDayOfYearSet 
	 * @return const DayOfYearSet 
	 */
	const DayOfYearSet	operator+(const DayOfYearSet& firstDayOfYearSet, const DayOfYearSet& secondDayOfYearSet)
	{
		vector<DayOfYearSet::DayOfYear>	vecArr;
		int	j, i;
		bool	isThere = false;

		for (i = 0; i < firstDayOfYearSet.getSize(); i++)
			vecArr.push_back(firstDayOfYearSet.getArray()[i]);

		for (i = 0; i < secondDayOfYearSet.getSize(); i++)
		{
			isThere = false;
			for (j = 0; !isThere && j < firstDayOfYearSet.getSize(); j++)
			{
				if (secondDayOfYearSet.getArray()[i] == firstDayOfYearSet.getArray()[j])
					isThere = true;
			}

			if (!isThere)
				vecArr.push_back(secondDayOfYearSet.getArray()[i]);
		}
		
		return (DayOfYearSet(vecArr));
	}

	const DayOfYearSet	operator-(const DayOfYearSet& firstDayOfYearSet, const DayOfYearSet& secondDayOfYearSet)
	{
		vector<DayOfYearSet::DayOfYear>	vecArr;
		int	j;
		bool	isThere = false;

		for (int i = 0; i < firstDayOfYearSet.getSize(); i++)
		{
			isThere = false;
			for (j = 0; !isThere && j < secondDayOfYearSet.getSize(); j++)
			{
				if (firstDayOfYearSet.getArray()[i] == secondDayOfYearSet.getArray()[j])
					isThere = true;
			}

			if (!isThere)
				vecArr.push_back(firstDayOfYearSet.getArray()[i]);
		}

		return (DayOfYearSet(vecArr));	
	}

	/**
	 * @brief intersection of two sets
	 * 
	 * @param firstDayOfYearSet 
	 * @param secondDayOfYearSet 
	 * @return const DayOfYearSet 
	 */
	const DayOfYearSet	operator^(const DayOfYearSet& firstDayOfYearSet, const DayOfYearSet& secondDayOfYearSet)
	{
		vector<DayOfYearSet::DayOfYear>	vecArr;
		int	j;

		for (int i = 0; i < firstDayOfYearSet.getSize(); i++)
		{
			for (j = 0; j < secondDayOfYearSet.getSize(); j++)
			{
				if (firstDayOfYearSet.getArray()[i] == secondDayOfYearSet.getArray()[j])
					vecArr.push_back(firstDayOfYearSet.getArray()[i]);
			}
		}

		return (DayOfYearSet(vecArr));
	}

	/**
	 * @brief complement calculation
	 * 
	 * @param dayOfYearSet 
	 * @return const DayOfYearSet 
	 */
	const DayOfYearSet	operator!(const DayOfYearSet& dayOfYearSet)
	{
		vector<DayOfYearSet::DayOfYear>	vecArr;
		DayOfYearSet::DayOfYear	dayOfYear;
		int	day, month, i;
		bool	isThere = false;

		for (month = 1, day = 1; month <= 12;)
		{
			isThere = false;
			dayOfYear.setDay(day);
			dayOfYear.setMonth(month);

			for (i = 0; i < dayOfYearSet.getSize(); i++)
			{
				if (dayOfYear == dayOfYearSet.getArray()[i])
					isThere = true;
			}

			if (!isThere)
				vecArr.push_back(dayOfYear);

			if ((month == 2 && day == 28) ||
				(month < 8 && month % 2 == 0 && day == 30) ||
				(month >= 8 && month % 2 == 1 && day == 30) ||
				day == 31)
			{
				month++;
				day = 0;
			}
			day++;
		}

		return (DayOfYearSet(vecArr));
	}

	DayOfYearSet::DayOfYear	DayOfYearSet::operator[](int index)
	{
		return (this->getArray()[index]);
	}

	DayOfYearSet&	DayOfYearSet::operator+(const DayOfYear& dayOfYear)
	{
		this->add(dayOfYear);

		return (*this);
	}

	DayOfYearSet&	DayOfYearSet::operator-(const DayOfYear& dayOfYear)
	{
		this->remove(dayOfYear);

		return (*this);
	}

	/**
	 * @brief save file function
	 * 
	 * @param file 
	 * @param dayOfYearSet 
	 */
	void	DayOfYearSet::saveFile(fstream &file, DayOfYearSet& dayOfYearSet)
	{
		for (int i = 0; i < dayOfYearSet.getSize(); i++)
			file << "index: " << i << " (Day: " << dayOfYearSet[i].getDay() << " Month: " << dayOfYearSet[i].getMonth() << ")" << endl;
		
		file << '\n' << endl;
	}
}
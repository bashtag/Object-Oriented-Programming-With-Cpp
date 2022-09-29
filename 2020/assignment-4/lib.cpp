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
		this->setNumOfDay();
		this->setTotalObjects(1);
	}
	DayOfYearSet::DayOfYear::DayOfYear(int _day, int _month) : day(_day), month(_month)
	{
		this->setNumOfDay();
		this->setTotalObjects(1);
	}
	DayOfYearSet::DayOfYear::DayOfYear(const DayOfYear& obj)
	{
		*this = obj;
		this->setNumOfDay();
		this->setTotalObjects(1);
	}
	DayOfYearSet::DayOfYear::~DayOfYear()
	{
		delete this;
		this->setTotalObjects(-1);
	}

	void	DayOfYearSet::DayOfYear::setDay(int day)
	{
		if (day < 1 || day > 31 || (this->month == 2 && day > 28) ||
			(this->month < 8 && this->month % 2 == 0 && day > 30) ||
			(this->month >= 8 && this->month % 2 == 1 && day > 30))
			throw	invalid_argument("Invalid Day");
		this->day = day;
	}
	void	DayOfYearSet::DayOfYear::setMonth(int month)
	{
		if (month > 12 || month < 1 ||
			(this->day > 28 && month == 2) ||
			(this->day > 30 && ((month < 8 || month % 2 == 0) || (month >= 8 || month % 2 == 1))))
			throw	invalid_argument("Invalid Month");
		this->month = month;
	}
	void	DayOfYearSet::DayOfYear::setNumOfDay()
	{
		this->numOfDay = month*30;

		if (month < 8)
		{	
			this->numOfDay += (month + 1) / 2;
			if (month > 1)
				this->numOfDay -= 2;
		}
		else
		{
			this->numOfDay += (month + 2) / 2;
			this->numOfDay -= 2;
		}
	}

	bool	DayOfYearSet::DayOfYear::operator==(const DayOfYear& obj)
	{
		if (this->getDay() == obj.getDay() && this->getMonth() == obj.getMonth() && this->getNumOfDay() == obj.getNumOfDay())
			return (true);
		else
			return (false);
	}

	bool	DayOfYearSet::DayOfYear::operator!=(const DayOfYear& obj)
	{
		if (*this == obj)
			return (false);
		else
			return (true);
	}

	DayOfYearSet::DayOfYear&	DayOfYearSet::DayOfYear::operator=(const DayOfYear& obj)
	{
		this->setDay(obj.getDay());
		this->setMonth(obj.getMonth());
		this->setNumOfDay();

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
		DayOfYearSet::DayOfYear::totalObjects += change;
	}
	/*----------------------- DayOfYearSet class implementations -----------------------*/

	DayOfYearSet::DayOfYearSet(DayOfYear *doyArr, int size)
	{
		this->size = size;
		this->doyArr = new DayOfYear[this->size];

		for (int i = 0; i < this->size; i++)
			this->doyArr[i] = doyArr[i];

	}
	DayOfYearSet::DayOfYearSet(vector <DayOfYear> doyVector)
	{
		this->size = doyVector.size();
		this->doyArr = new DayOfYear[this->size];

		for(int i = 0; i < this->size; i++)
			this->doyArr[i] = doyVector[i];

	}
	DayOfYearSet::DayOfYearSet()
	{
		this->size = 0;
		this->doyArr = new DayOfYear[this->size];

	}
	DayOfYearSet::~DayOfYearSet()
	{
		delete[] this->doyArr;
	}
	DayOfYearSet::DayOfYearSet(const DayOfYearSet& object)
	{
		*this = object;
	}

	bool	DayOfYearSet::add(DayOfYear& dayOfYear)
	{
		DayOfYear	*temp;
		bool	isThere = false;

		for (int i = 0; i < this->getSize(); i++)
			if (dayOfYear == this->getArray()[i])
				isThere = true;

		if (!isThere)
			temp = new DayOfYear[this->size + 1];

		if (temp)
		{
			for (int i = 0; i < this->size; i++)
				temp[i] = this->doyArr[i];
			
			temp[this->size] = dayOfYear;

			this->doyArr = temp;
			this->setSize(1);

			delete[] temp;

			return (true);
		}
		return (false);
	}

	bool	DayOfYearSet::remove(DayOfYear& dayOfYear)
	{
		this->size--;

		return (true);
	}

	int	DayOfYearSet::getSize() const
	{
		return (this->size);
	}

	DayOfYearSet::DayOfYear*	DayOfYearSet::getArray() const
	{
		return (this->doyArr);
	}

	void	DayOfYearSet::setSize(int change)
	{
		this->size += change;
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
		*this = dayOfYearSet;

		return (*this);
	}

	ostream&	operator<<(ostream& output, const DayOfYearSet& dayOfYearSet)
	{
		output << "There are " << dayOfYearSet.getSize() << " days." << endl;

		for (int i = 0; i < dayOfYearSet.getSize(); i++)
		{
			output << dayOfYearSet.getSize() <<  ". element of array:\n\tDay-> " << dayOfYearSet.getArray()[i].getDay() << "\tMonth-> " << dayOfYearSet.getArray()[i].getMonth() << '\n' << endl;
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
			dayOfYear.setDay(day);
			dayOfYear.setMonth(month);

			for (i = 0; i < dayOfYearSet.getSize(); i++)
			{
				if (dayOfYear == dayOfYearSet.getArray()[i])
					isThere = true;
			}

			if (!isThere)
				vecArr.push_back(dayOfYear);
		}

		return (vecArr);
	}

	DayOfYearSet::DayOfYear	DayOfYearSet::operator[](int index)
	{
		return (this->getArray()[index]);
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
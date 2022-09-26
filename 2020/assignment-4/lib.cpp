#include "lib.h"

using namespace std;

namespace doys
{
	/* DayOfYear class implementations*/

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
		this->day = day;
	}
	void	DayOfYearSet::DayOfYear::setMonth(int month)
	{
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
		totalObjects += change;
	}
	/* DayOfYearSet class implementations*/

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

	}


	bool	DayOfYearSet::add(DayOfYear& dayOfYear)
	{

	}

	bool	DayOfYearSet::remove(DayOfYear& dayOfYear)
	{

	}

	int	DayOfYearSet::getSize() const
	{

	}

	DayOfYearSet::DayOfYear*	DayOfYearSet::getArray() const
	{

	}

	void	DayOfYearSet::setSize(int change)
	{

	}

}
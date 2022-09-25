#include "lib.h"

using namespace std;

namespace doys
{
	/* DayOfYear class implementations*/
	DayOfYearSet::DayOfYear::DayOfYear()
	{}
	DayOfYearSet::DayOfYear::DayOfYear(int _day, int _month) : day(_day), month(_month)
	{
		setNumOfDay();
	}
	DayOfYearSet::DayOfYear::DayOfYear(const DayOfYear& obj)
	{
		*this = obj;
		setNumOfDay();
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


	/* DayOfYearSet class implementations*/






}
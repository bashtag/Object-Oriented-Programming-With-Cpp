#include <iostream>
#include <fstream>
#include "lib.h"

using namespace std;
using namespace doys;

int	DayOfYearSet::DayOfYear::totalObjects = 0;

int	main(void)
{
	DayOfYearSet	*firstDayOfYearSet, *secondDayOfYearSet;
	vector<DayOfYearSet::DayOfYear>	firstDoyVec, secondDoyVec;
	fstream	file;
	int	i;

	firstDoyVec.push_back(DayOfYearSet::DayOfYear(28, 2));
	firstDoyVec.push_back(DayOfYearSet::DayOfYear(31, 3));
	firstDoyVec.push_back(DayOfYearSet::DayOfYear(12, 1));
	firstDoyVec.push_back(DayOfYearSet::DayOfYear(30, 6));
	firstDoyVec.push_back(DayOfYearSet::DayOfYear(31, 8));
	firstDoyVec.push_back(DayOfYearSet::DayOfYear(23, 12));
	firstDoyVec.push_back(DayOfYearSet::DayOfYear(3, 4));
	firstDoyVec.push_back(DayOfYearSet::DayOfYear(9, 11));
	firstDoyVec.push_back(DayOfYearSet::DayOfYear(21, 10));
	firstDoyVec.push_back(DayOfYearSet::DayOfYear(5, 10));

	secondDoyVec.push_back(DayOfYearSet::DayOfYear(1, 1));
	secondDoyVec.push_back(DayOfYearSet::DayOfYear(28, 2));
	secondDoyVec.push_back(DayOfYearSet::DayOfYear(31, 5));
	secondDoyVec.push_back(DayOfYearSet::DayOfYear(2, 6));
	secondDoyVec.push_back(DayOfYearSet::DayOfYear(5, 10));
	secondDoyVec.push_back(DayOfYearSet::DayOfYear(7, 7));
	secondDoyVec.push_back(DayOfYearSet::DayOfYear(8, 9));
	secondDoyVec.push_back(DayOfYearSet::DayOfYear(12, 1));
	secondDoyVec.push_back(DayOfYearSet::DayOfYear(1, 2));
	secondDoyVec.push_back(DayOfYearSet::DayOfYear(23, 12));
	secondDoyVec.push_back(DayOfYearSet::DayOfYear(20, 5));
	secondDoyVec.push_back(DayOfYearSet::DayOfYear(29, 3));
	secondDoyVec.push_back(DayOfYearSet::DayOfYear(31, 12));

	firstDayOfYearSet = new DayOfYearSet(firstDoyVec);
	secondDayOfYearSet = new DayOfYearSet(secondDoyVec);

	/* getters and setters of inline DayOfYear Class*/
	cout << "--------------- First Day Of Year Vector ---------------------" << endl;
	for (DayOfYearSet::DayOfYear dayOfYear : firstDoyVec)
		cout << "Day: " << dayOfYear.getDay() << ", Month: "
			<< dayOfYear.getMonth() << ", Num of day: " << dayOfYear.getNumOfDay()
			<< ", total objects: " << dayOfYear.getTotalDayOfYearObjects() << endl;
	cout << "--------------------------------------------------------------\n" << endl;
	cout << "--------------- Second Day Of Year Set Object ----------------" << endl;
	for (i = 0; i < secondDayOfYearSet->getSize(); i++)
		cout << "Day: " << (*secondDayOfYearSet)[i].getDay() << ", Month: "
			<< (*secondDayOfYearSet)[i].getMonth() << ", Num of day: " << (*secondDayOfYearSet)[i].getNumOfDay()
			<< ", total objects: " << (*secondDayOfYearSet)[i].getTotalDayOfYearObjects() << endl;
	cout << "--------------------------------------------------------------\n" << endl;
	(*firstDayOfYearSet)[2].setDay(31);
	(*firstDayOfYearSet)[2].setMonth(10);


	cout << "Stream overloading function: \n" << endl;
	cout << "\tFirst Day Of Year Set Object\n\n" << *firstDayOfYearSet << endl;


	return (0);
}
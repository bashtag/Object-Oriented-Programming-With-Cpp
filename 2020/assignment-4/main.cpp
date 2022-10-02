#include <iostream>
#include <fstream>
#include "lib.h"

using namespace std;
using namespace doys;

int	DayOfYearSet::DayOfYear::totalObjects = 0;

int	main(void)
{
	DayOfYearSet	*firstDayOfYearSet, *secondDayOfYearSet, *copyingDayOfYearSet;
	vector<DayOfYearSet::DayOfYear>	firstDoyVec, secondDoyVec;
	fstream	file;
	int	i;

	firstDoyVec = {DayOfYearSet::DayOfYear(28, 2),
		DayOfYearSet::DayOfYear(31, 3),
		DayOfYearSet::DayOfYear(12, 1),
		DayOfYearSet::DayOfYear(20, 5),
		DayOfYearSet::DayOfYear(30, 6),
		DayOfYearSet::DayOfYear(31, 8),
		DayOfYearSet::DayOfYear(23, 12),
		DayOfYearSet::DayOfYear(3, 4),
		DayOfYearSet::DayOfYear(9, 11),
		DayOfYearSet::DayOfYear(21, 10),
		DayOfYearSet::DayOfYear(5, 10)};

	/* I have experienced contructor stuffs while I was making debugging.
	The Vector class uses the copying constructor for realloc operation.
	Also destructor is used.
	I have realized that while I was checking static variables.
	*/

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
		cout << "Day: " << secondDayOfYearSet->getArray()[i].getDay() << ", Month: "
			<< secondDayOfYearSet->getArray()[i].getMonth() << ", Num of day: " << secondDayOfYearSet->getArray()[i].getNumOfDay()
			<< ", total objects: " << secondDayOfYearSet->getArray()[i].getTotalDayOfYearObjects() << endl;
	cout << "--------------------------------------------------------------\n" << endl;
	firstDayOfYearSet->getArray()[2].setDay(31);
	firstDayOfYearSet->getArray()[2].setMonth(10);


	cout << "Stream overloading function: \n" << endl;
	cout << "\tFirst Day Of Year Set Object\n\n" << *firstDayOfYearSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "\nInner class stream and comparison overloading functions: \n" << endl;

	if (firstDayOfYearSet->getArray()[5] == secondDayOfYearSet->getArray()[9])
		cout << "two objects are equal: \n" << firstDayOfYearSet->getArray()[5] << '\n'
			<< secondDayOfYearSet->getArray()[9] << endl;

	if (firstDayOfYearSet->getArray()[8] != secondDayOfYearSet->getArray()[8])
		cout << "two objects are not equal: \n" << firstDayOfYearSet->getArray()[8] << '\n'
			<< secondDayOfYearSet->getArray()[8] << endl;

	/* to free vector */
	firstDoyVec.clear();
	secondDoyVec.clear();
	cout << "There are " << DayOfYearSet::DayOfYear::getTotalDayOfYearObjects() << " objects now.\n" << endl;

	cout << "--------------------------------------------------------------\n" 
		<< "\nDayOfYearSet class functions\n" << endl;

	cout << "Copying Constructor:\n" << endl;

	copyingDayOfYearSet = new DayOfYearSet(*firstDayOfYearSet);

	cout << *firstDayOfYearSet << '\n' << *copyingDayOfYearSet << endl;

	if (*firstDayOfYearSet == *copyingDayOfYearSet)
		cout << "Copying constructor is working right\n" << endl;
	cout << "--------------------------------------------------------------\n"
		<< "Remove function:\n" << endl;

	DayOfYearSet::DayOfYear	firstDoy(20, 5), secondDoy(1, 12);

	cout << *secondDayOfYearSet << endl;
	secondDayOfYearSet->remove(firstDoy);
	cout << *secondDayOfYearSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "Add function:\n" << endl;

	cout << *firstDayOfYearSet << endl;
	firstDayOfYearSet->add(secondDoy);
	cout << *firstDayOfYearSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "Addition (union set) operator overloading:\n" << endl;

	DayOfYearSet	additionSet = *firstDayOfYearSet + *secondDayOfYearSet;

	cout << additionSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "Extraction (difference set) operator overloading:\n" << endl;

	DayOfYearSet	differenceSet = *firstDayOfYearSet - *secondDayOfYearSet;

	cout << differenceSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "Intersection of two sets:\n" << endl;

	DayOfYearSet	intersectSet = *firstDayOfYearSet ^ *secondDayOfYearSet;

	cout << intersectSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "Complemention of two sets:\n" << endl;

	DayOfYearSet	complementSet = !additionSet;

	// cout << complementSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "DeMorgan Rule:\n" << endl;

	if (complementSet == (!(*firstDayOfYearSet) ^ !(*secondDayOfYearSet)))
		cout << "DeMorgan said right." << endl;


	return (0);
}
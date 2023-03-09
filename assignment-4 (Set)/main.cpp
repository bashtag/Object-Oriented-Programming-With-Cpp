#include <iostream>
#include "lib.h"

using namespace std;
using namespace doys;

int	DayOfYearSet::DayOfYear::totalObjects = 0;

int	main(void)
{
	DayOfYearSet	firstDayOfYearSet, secondDayOfYearSet, copyingDayOfYearSet;
	vector<DayOfYearSet::DayOfYear>	firstDoyVec, secondDoyVec;
	fstream	file;
	int	i;

	firstDoyVec = {{28, 2},
		{31, 3},
		{12, 1},
		{20, 5},
		{30, 6},
		{31, 8},
		{23, 12},
		{3, 4},
		{9, 11},
		{21, 10},
		{5, 10}};

	/* I have experienced contructor stuffs while I was making debugging.
	The Vector class uses the copying constructor for realloc operation.
	Also destructor is used.
	I have realized that while I was checking static variables.
	*/

	secondDoyVec.push_back({1, 1});
	secondDoyVec.push_back({28, 2});
	secondDoyVec.push_back({31, 5});
	secondDoyVec.push_back({2, 6});
	secondDoyVec.push_back({5, 10});
	secondDoyVec.push_back({7, 7});
	secondDoyVec.push_back({8, 9});
	secondDoyVec.push_back({12, 1});
	secondDoyVec.push_back({1, 2});
	secondDoyVec.push_back({23, 12});
	secondDoyVec.push_back({20, 5});
	secondDoyVec.push_back({29, 3});
	secondDoyVec.push_back({31, 12});

	vector<DayOfYearSet::DayOfYear>&	refFirstDoyVec = firstDoyVec;
	firstDayOfYearSet = DayOfYearSet(refFirstDoyVec);
	secondDayOfYearSet = DayOfYearSet(secondDoyVec);

	/* getters and setters of inline DayOfYear Class*/
	cout << "--------------- First Day Of Year Vector ---------------------" << endl;
	for (DayOfYearSet::DayOfYear dayOfYear : firstDoyVec)
		cout << "Day: " << dayOfYear.getDay() << ", Month: "
			<< dayOfYear.getMonth()
			<< ", total objects: " << dayOfYear.getTotalDayOfYearObjects() << endl;
	cout << "--------------------------------------------------------------\n" << endl;
	cout << "--------------- Second Day Of Year Set Object ----------------" << endl;
	for (i = 0; i < secondDayOfYearSet.getSize(); i++)
		cout << "Day: " << secondDayOfYearSet.getArray()[i].getDay() << ", Month: "
			<< secondDayOfYearSet.getArray()[i].getMonth()
			<< ", total objects: " << secondDayOfYearSet.getArray()[i].getTotalDayOfYearObjects() << endl;
	cout << "--------------------------------------------------------------\n" << endl;
	firstDayOfYearSet.getArray()[2].setDay(31);
	firstDayOfYearSet.getArray()[2].setMonth(10);


	cout << "Stream overloading function: \n" << endl;
	cout << "\tFirst Day Of Year Set Object\n\n" << firstDayOfYearSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "\nInner class stream and comparison overloading functions: \n" << endl;

	if (firstDayOfYearSet.getArray()[5] == secondDayOfYearSet.getArray()[9])
		cout << "two objects are equal: \n" << firstDayOfYearSet.getArray()[5] << '\n'
			<< secondDayOfYearSet.getArray()[9] << endl;

	if (firstDayOfYearSet.getArray()[8] != secondDayOfYearSet.getArray()[8])
		cout << "two objects are not equal: \n" << firstDayOfYearSet.getArray()[8] << '\n'
			<< secondDayOfYearSet.getArray()[8] << endl;

	/* to free vector */
	firstDoyVec.clear();
	secondDoyVec.clear();
	cout << "There are " << DayOfYearSet::DayOfYear::getTotalDayOfYearObjects() << " objects now.\n" << endl;

	cout << "--------------------------------------------------------------\n" 
		<< "\nDayOfYearSet class functions\n" << endl;

	cout << "Copying Constructor:\n" << endl;

	copyingDayOfYearSet = DayOfYearSet(firstDayOfYearSet);

	cout << firstDayOfYearSet << '\n' << copyingDayOfYearSet << endl;

	if (firstDayOfYearSet == copyingDayOfYearSet)
		cout << "Copying constructor is working right\n" << endl;
	cout << "--------------------------------------------------------------\n"
		<< "Remove function:\n" << endl;

	DayOfYearSet::DayOfYear	firstDoy(20, 5), secondDoy(1, 12);

	cout << secondDayOfYearSet << endl;
	secondDayOfYearSet  - firstDoy;
	cout << secondDayOfYearSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "Add function:\n" << endl;

	cout << firstDayOfYearSet << endl;
	firstDayOfYearSet + secondDoy;
	cout << firstDayOfYearSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "Addition (union set) operator overloading:\n" << endl;

	DayOfYearSet	additionSet = firstDayOfYearSet + secondDayOfYearSet;

	cout << additionSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "Extraction (difference set) operator overloading:\n" << endl;

	DayOfYearSet	differenceSet = firstDayOfYearSet - secondDayOfYearSet;

	cout << differenceSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "Intersection of two sets:\n" << endl;

	DayOfYearSet	intersectSet = firstDayOfYearSet ^ secondDayOfYearSet;

	cout << intersectSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "Complemention of two sets:\n" << endl;

	DayOfYearSet	complementSet;
	complementSet = !additionSet;

	// cout << complementSet << endl;

	cout << "--------------------------------------------------------------\n"
		<< "DeMorgan Rule:\n" << endl;

	if (complementSet == (!(firstDayOfYearSet) ^ !(secondDayOfYearSet)))
		cout << "DeMorgan said right." << endl;
	else
		cout << "Code is wrong!" << endl;

	file.open("firstDayOfYearSet.txt", ios::out);
	DayOfYearSet::saveFile(file, firstDayOfYearSet);
	file.close();

	file.open("secondDayOfYearSet.txt", ios::out);
	DayOfYearSet::saveFile(file, secondDayOfYearSet);
	file.close();

	file.open("complementSet.txt", ios::out);
	DayOfYearSet::saveFile(file, complementSet);
	file.close();

	return (0);
}
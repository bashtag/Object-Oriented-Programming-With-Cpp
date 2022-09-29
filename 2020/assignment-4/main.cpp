#include <iostream>
#include <fstream>
#include "lib.h"

using namespace std;
using namespace doys;

int	main(void)
{
	DayOfYearSet	firstDayOfYearSet, secondDayOfYearSet;
	vector<DayOfYearSet::DayOfYear>	firstDoyVec, secondDoyVec;
	fstream	file;

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



	return (0);
}
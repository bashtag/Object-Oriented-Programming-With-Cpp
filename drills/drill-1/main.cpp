#include <iostream>
#include <vector>
#include "MyVector.hpp"

using namespace std;

int	main(void)
{
	vector<int>	vect = {1, 4, 5, 67, 34, 66};
	MyVector v1, v2(vect); /* can hold at most 100 integers */

	v1.pushBack(23);
	cout << v1.size() << v1[0];

	/**
	 * @brief to print whole the vector
	 * 
	 */
	cout << v2;

	cout << v2++;
	cout << ++v2;
	return (0);
}
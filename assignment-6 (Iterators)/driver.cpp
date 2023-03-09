#include	"Iterator_.hpp"
#include	"PFArray.hpp"
#include	<algorithm>
#include	<iostream>

using namespace	std;
using namespace	it_arr;

template	<class T>
void	printVecInfos(const PFArray<T>& vec, string vecName = "vec")
{
	cout << "----------------\n" << vecName << ": " << endl;
	cout << "size: " << vec.size() << endl;
	cout << "capacity: " << vec.capacity() << endl;
	cout << "bufferSize: " << vec.bufSize() << endl;
	cout << "empty: " << vec.empty() << endl;
	if (!vec.empty())
	{
		cout << "front: " << vec.front() << endl;
		cout << "back: " << vec.back() << endl;
		for (auto it = vec.begin(); it != vec.end(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	cout << "----------------\n" << endl;
}

/**
 * @brief Main function
 * 
 * @return int 
 */
int	main(void)
{
	int	*arr = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	PFArray<int>	vec;
	PFArray<int>	vec_copy;
	PFArray<char>	vec_char = {'a', 'b', 'c', 'd', 'e', 'f'};
	PFArray<int>	vec_size(10);
	PFArray<int>	vec_size_buff(10, 5);
	PFArray<int>	vec_size_buff_arr(arr, 10, 5);

	printVecInfos(vec, "vec");
	printVecInfos(vec_char, "vec_char");
	printVecInfos(vec_size, "vec_size");
	printVecInfos(vec_size_buff, "vec_size_buff");
	printVecInfos(vec_size_buff_arr, "vec_size_buff_arr");

	vec.push_back(28);
	vec.push_back(79);
	vec.push_back(312);
	vec.push_back(43);
	vec.push_back(52);
	vec.push_back(13);
	vec.push_back(6532);
	vec.push_back(35);
	vec.push_back(65);

	vec_copy = vec;
	printVecInfos(vec_copy, "vec_copy");

	/**
	 * @brief cbegin - cend
	 * 
	 */

	cout << "cbegin -> " << *vec.cbegin() <<
		"\nIs cend value equal to end -> " << (vec.end() == vec.cend()) << endl;

	printVecInfos(vec);

	cout << "pop_back" << endl;
	vec.pop_back();
	printVecInfos(vec);

	cout << "insert(begin + 2, 100)" << endl;
	vec.insert(vec.begin() + 2, 100);
	printVecInfos(vec);

	cout << "erase(begin + 2)" << endl;
	vec.erase(vec.begin() + 2);
	printVecInfos(vec);

	cout << "clear" << endl;
	vec.clear();
	printVecInfos(vec);

	cout << "resize(10)" << endl;
	vec.resize(10);
	printVecInfos(vec);

	vec.clear();

	cout << "resize(10, 5)" << endl;
	vec.resize(10, 5);
	printVecInfos(vec);

	cout << "erase(begin, end)" << endl;
	vec.erase(vec.begin(), vec.end());
	printVecInfos(vec);

	cout << "assign(vec, vec_copy) (move semantics)" << endl;
	vec = PFArray<int>(vec_copy);
	printVecInfos(vec);

	cout << "at(4) -> " << vec.at(4) << endl;
	cout << "at(3) = 209" << endl;
	vec.at(3) = 209;
	printVecInfos(vec);

	cout << "vec[5] -> " << vec[5] << endl;
	cout << "vec[5] = 27" << endl;
	vec[5] = 27;
	printVecInfos(vec);

	cout << "reserve(60)" << endl;
	vec.reserve(60);
	printVecInfos(vec);

	cout << "shrink_to_fit" << endl;
	vec.shrink_to_fit();
	printVecInfos(vec);

	cout << "operator==" << endl;
	cout << "(vec == vec_copy) = " << (vec == vec_copy) << endl;

	cout << "----------------\n" << endl;

	cout << "operator!=" << endl;
	cout << "(vec != vec_copy) = " << (vec != vec_copy) << endl;
	
	cout << "----------------\n" << endl;

	printVecInfos(vec);

	cout << "find(209) -> " << *find(vec.cbegin(), vec.cend(), 209) << endl;
	cout << "find(209) -> (bool) " << (find(vec.cbegin(), vec.cend(), 209) == vec.cend()) << endl;
	cout << "find(51) -> (bool) " << (find(vec.cbegin(), vec.cend(), 51) == vec.cend()) << endl;

	cout << "\n----------------\n" << endl;

	cout << "for_each" << endl;
	for_each(vec.begin(), vec.end(), [](int &n) { n *= 2; });
	printVecInfos(vec);

	cout << "sort" << endl;
	sort(vec.begin(), vec.end());
	printVecInfos(vec);

	delete[] arr;
	return (0);
}
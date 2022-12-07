#ifndef MYVECTOR_HPP
# define MYVECTOR_HPP

# include <vector>
# include <iostream>

using namespace std;

class MyVector
{
	public:
		MyVector();
		MyVector(const vector<int>&);

		void	pushBack(int);
		inline int	size() {return (this->dataSize);};

		/* operator overloading part */
		friend ostream&	operator<<(ostream&, const MyVector&);		
		int	operator[](int);
		// const int &operator[]();
		// int &operator[]();
		MyVector&	operator++();
		MyVector	operator++(int);
	private:
		int	data[100];
		int	dataSize;
};

#endif
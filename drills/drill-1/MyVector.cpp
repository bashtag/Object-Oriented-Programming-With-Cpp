#include "MyVector.hpp"

MyVector::MyVector()
{
	this->dataSize = 0;
}

MyVector::MyVector(const vector<int>& vect)
{
	this->dataSize = 0;
	for (auto myInt : vect)
		this->pushBack(myInt);
}

void	MyVector::pushBack(int value)
{
	this->data[this->dataSize] = value;
	++(this->dataSize);
}

ostream&	operator<<(ostream& output, const MyVector& myVector)
{
	output << '[';
	for (int i = 0; i < myVector.dataSize; i++)
	{
		output << myVector.data[i];
		if (i + 1 != myVector.dataSize)
			output << ", ";
	}
	output << ']' << endl;

	return (output);
}

int	MyVector::operator[](int index)
{
	return (data[index]);
}

MyVector&	MyVector::operator++()
{
	for (int i = 0; i < this->dataSize; i++)
		++this->data[i];

	return (*this);
}

MyVector	MyVector::operator++(int)
{
	MyVector	copy;
	copy = *this;

	for (int i = 0; i < copy.dataSize; i++)
		copy.data[i] = this->data[i]++;

	return (copy);
}

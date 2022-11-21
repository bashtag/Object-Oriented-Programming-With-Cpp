#include "GTUVector.hpp"

namespace GTU
{
	template	<class T>
	GTUVector<T>::GTUVector()
	{
		this->arr = NULL;
		this->arrSize = 0;
	}

	template	<class T>
	GTUVector<T>::GTUVector(const GTUVector& vector)
	{
		int	vecSize = vector.arrSize;
		GTUIterator<T>	it;		

		this->arr = NULL;
		this->arr = shared_ptr<T>(new T[vecSize]);
		
		if (this->arr == NULL)
			throw	bad_alloc();
		
		this->arrSize = vecSize;
		it = GTUIterator<T>(this->arr.get());
		for (int i = 0; i < vecSize; ++i)
			it[i] = vector.arr[i];
	}

	template	<class T>
	GTUVector<T>::GTUVector(const GTUVector&& vector)
	{
		int	vecSize = vector.arrSize;
		GTUIterator<T>	it;

		this->arr = NULL;
		this->arr = shared_ptr<T>(new T[vecSize]);
		
		if (this->arr == NULL)
			throw	bad_alloc();
		
		this->arrSize = vecSize;
		it = GTUIterator<T>(this->arrçget());
		for (int i = 0; i < vecSize; ++i)
			it[i] = vector.arr[i];
	}

	template	<class T>
	GTUVector<T>::GTUVector(T *arr, const size_t& arrSize)
	{
		GTUIterator<T>	it;
		this->arr = NULL;
		this->arr = shared_ptr<T>(new T[arrSize]);

		if (this->arr == NULL)
			throw	bad_alloc();
		
		this->arrSize = arrSize;
		it = GTUIterator<T>(this->arr.get());
		for (int i = 0; i < arrSize; ++i)
			it[i] = arr[i];
	}

	template	<class T>
	GTUVector<T>::~GTUVector()
	{}

	template	<class T>
	bool	GTUVector<T>::empty() const
	{
		if (this->arr.get() == NULL)
			return (true);
		return (false);
	}

	template	<class T>
	size_t	GTUVector<T>::size() const
	{
		return (this->arrSize);
	}

	template	<class T>
	GTUIterator<T>	GTUVector<T>::erase(GTUIterator<T> iterator)
	{
		bool	isFind = false;
		GTUIterator<T>	returnIt;
		
		for (GTUIterator<T>	it = begin(); it + 1 != end(); ++it)
		{
			if (it == iterator)
			{
				returnIt = it + 1;
				*(it) = *(it + 1);
				isFind = true;
			}
			if (isFind)
				*(it) = *(it + 1);
		}

		return (returnIt);
	}


}
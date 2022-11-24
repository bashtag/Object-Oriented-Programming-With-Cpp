#include "GTUVector.hpp"

namespace GTU
{
	template	<class T>
	GTUVector<T>::GTUVector()
	{
		this->arr = NULL;
		this->arrSize = 0;
		this->capacity = 0;
		this->bufferSize = 1;
	}

	template	<class T>
	GTUVector<T>::GTUVector(const GTUVector& vector)
	{
		int	vecSize = vector.arrSize;
		GTUIterator<T>	it;		

		// this->arr = NULL;
		// this->arr = shared_ptr<T>(new T[vecSize]);
		
		// if (this->arr == NULL)
		// 	throw	bad_alloc();
		this->reserve(vecSize);

		this->arrSize = vecSize;
		it = GTUIterator<T>(this->arr.get());
		for (int i = 0; i < vecSize; ++i)
			it[i] = vector.arr[i];
		this->bufferSize = 1;
	}

	template	<class T>
	GTUVector<T>::GTUVector(const GTUVector&& vector)
	{
		int	vecSize = vector.arrSize;
		GTUIterator<T>	it;

		// this->arr = NULL;
		// this->arr = shared_ptr<T>(new T[vecSize]);
		
		// if (this->arr == NULL)
		// 	throw	bad_alloc();
		this->reserve(vecSize);
		
		this->arrSize = vecSize;
		it = GTUIterator<T>(this->arrçget());
		for (int i = 0; i < vecSize; ++i)
			it[i] = vector.arr[i];
		this->bufferSize = 1;
	}

	template	<class T>
	GTUVector<T>::GTUVector(T *arr, const size_t& arrSize)
	{
		GTUIterator<T>	it;
		// this->arr = NULL;
		// this->arr = shared_ptr<T>(new T[arrSize]);

		// if (this->arr == NULL)
		// 	throw	bad_alloc();
		this->reserve(arrSize);
		
		this->arrSize = arrSize;
		it = GTUIterator<T>(this->arr.get());
		for (int i = 0; i < arrSize; ++i)
			it[i] = arr[i];
		this->bufferSize = 1;
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
	GTUIterator<T>	GTUVector<T>::erase(const GTUIterator<T> &iterator)
	{
		bool	isFind = false;
		GTUIterator<T>	returnIt;
		
		for (GTUIterator<T>	it = begin(); it + 1 != end(); ++it)
		{
			if (!isFind && it == iterator)
			{
				returnIt = it + 1;
				*(it) = *(it + 1);
				isFind = true;
			}
			if (isFind)
				*(it) = *(it + 1);
		}
		--(this->arrSize);

		return (returnIt);
	}

	template	<class T>
	GTUIterator<T>	GTUVector<T>::erase(const GTUIterator<T> &iterator1, const GTUIterator<T> &iterator2)
	{
		if (iterator1 < this->begin() || iterator1 > this->end() ||
			iterator2 < this->begin() || iterator2 > this->end() ||
			iterator1 < iterator2)
			throw out_of_range();

		bool	isFind = false;
		GTUIterator<T>	returnIt;
		size_t	diff = iterator1.getPtr() - iterator2.getPtr();
		
		if (diff != 0)
			for (GTUIterator<T>	it = begin(); it + diff != end(); ++it)
			{
				if (!isFind && it == iterator1)
				{
					returnIt = it + diff;
					*(it) = *(it + diff);
					isFind = true;
				}
				else if (isFind)
					*(it) = *(it + diff);
			}
		(this->arrSize) -= diff;

		return (returnIt);
	}

	template	<class T>
	GTUIterator<T>	GTUVector<T>::insert(const GTUIterator<T>& iterator, const T& element)
	{
		if (iterator < begin() || iterator > end())
			throw out_of_range();

		T	temp, temp2;
		bool	isFind = false;

		this->resize(this->arrSize + 1);
		for (GTUIterator<T> it = begin(); it + 1 != end(); ++it)
		{
			if (!isFind && it == iterator)
			{
				temp = *(it);
				*(it) = element;
				isFind = true;
			}
			else if (isFind)
			{
				temp2 = *(it);
				*(it) = temp;
				temp = *(it + 1);
				*(it + 1) = temp2;
			}
		}
		return (iterator);
	}

	template	<class T>
	GTUIterator<T>	GTUVector<T>::insert(const GTUIterator<T>& iterator, T&& element)
	{
		if (iterator < begin() || iterator > end())
			throw out_of_range();

		T	temp, temp2;
		bool	isFind = false;

		this->resize(this->arrSize + 1);
		for (GTUIterator<T> it = begin(); it + 1 != end(); ++it)
		{
			if (!isFind && it == iterator)
			{
				temp = *(it);
				*(it) = element;
				isFind = true;
			}
			else if (isFind)
			{
				temp2 = *(it);
				*(it) = temp;
				temp = *(it + 1);
				*(it + 1) = temp2;
			}
		}
		return (iterator);
	}

	GTUIterator<T>	GTUVector<T>::insert(const GTUIterator<T>& iterator, size_t count, T&& value)
	{
		if (iterator < begin() || iterator > end())
			throw out_of_range();

		bool	isFind = false;

		
		this->resize(this->arrSize + count);
		/**
		 * @brief 
		 * 
		 */
	}
}
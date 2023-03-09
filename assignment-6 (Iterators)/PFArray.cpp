#ifdef	PFARRAY_HPP

namespace	it_arr
{
	template	<class T>
	PFArray<T>::PFArray()
	{
		this->arr = NULL;
		this->arrSize = 0;
		this->arrCapacity = 0;
		this->bufferSize = 1;
	}

	template	<class T>
	PFArray<T>::PFArray(const PFArray& other)
	{
		Iterator_<T>	it = other.begin();

		/**
		 * @brief 1) Creates a new array with the same size as the other array.
		 * 
		 */
		this->arr = shared_ptr<T>(new T[other.arrCapacity]);
		for (Iterator_<T> it2 = Iterator_<T>(this->arr); it != other.end(); ++it, ++it2)
			*(it2) = *(it);
		this->arrSize = other.arrSize;
		this->arrCapacity = other.arrCapacity;
		this->bufferSize = other.bufferSize;
	}

	template	<class T>
	PFArray<T>::PFArray(const PFArray&& other)
	{
		Iterator_<T>	it = other.begin();

		this->arr = shared_ptr<T>(new T[other.arrCapacity]);
		for (Iterator_<T> it2 = Iterator_<T>(this->arr); it != other.end(); ++it, ++it2)
			*(it2) = *(it);
		this->arrSize = other.arrSize;
		this->arrCapacity = other.arrCapacity;
		this->bufferSize = other.bufferSize;
	}

	template	<class T>
	PFArray<T>::PFArray(const size_t& size)
	{
		this->arr = shared_ptr<T>(new T[size]);
		this->arrSize = 0;
		this->arrCapacity = size;
		this->bufferSize = 1;
	}

	template	<class T>
	PFArray<T>::PFArray(const size_t& size, const size_t& bufferSize)
	{
		this->arr = shared_ptr<T>(new T[size]);
		this->arrSize = 0;
		this->arrCapacity = size;
		this->bufferSize = bufferSize;
	}

	template	<class T>
	PFArray<T>::PFArray(initializer_list<T> list)
	{
		Iterator_<T>	it;

		this->arr = shared_ptr<T>(new T[list.size()]);
		it = Iterator_<T>(this->arr);
		for (size_t i = 0; i < list.size(); i++)
			it[i] = *(list.begin() + i);
		this->arrSize = list.size();
		this->arrCapacity = list.size();
		this->bufferSize = 1;
	}

	template	<class T>
	PFArray<T>::PFArray(T *arr, const size_t& size)
	{
		Iterator_<T>	it;

		this->arr = shared_ptr<T>(new T[size]);
		it = Iterator_<T>(this->arr);
		for (size_t i = 0; i < size; i++)
			it[i] = arr[i];
		this->arrSize = size;
		this->arrCapacity = size;
		this->bufferSize = 1;
	}

	template	<class T>
	PFArray<T>::PFArray(T *arr, const size_t& size, const size_t& bufferSize)
	{
		Iterator_<T>	it;

		this->arr = shared_ptr<T>(new T[size]);
		it = Iterator_<T>(this->arr);
		for (size_t i = 0; i < size; i++)
			it[i] = arr[i];
		this->arrSize = size;
		this->arrCapacity = size;
		this->bufferSize = bufferSize;
	}

	template	<class T>
	PFArray<T>::~PFArray()
	{
		this->clear();
	}

	template	<class T>
	Iterator_<T>	PFArray<T>::begin() const
	{
		return (Iterator_<T>(this->arr));
	}

	template	<class T>
	Iterator_<T>	PFArray<T>::end() const
	{
		return (Iterator_<T>(this->arr) + this->arrSize);
	}

	template	<class T>
	const Iterator_<T>	PFArray<T>::cbegin() const
	{
		return (Iterator_<T>(this->arr));
	}

	template	<class T>
	const Iterator_<T>	PFArray<T>::cend() const
	{
		return (Iterator_<T>(this->arr) + this->arrSize);
	}

	template	<class T>
	bool	PFArray<T>::empty() const
	{
		return (this->arrSize == 0);
	}

	template	<class T>
	T&	PFArray<T>::at(size_t index)
	{
		if (index < 0 || index >= this->arrSize)
			throw	out_of_range("Index out of range");
		return (*(this->begin() + index));
	}

	template	<class T>
	const T	PFArray<T>::at(size_t index) const
	{
		if (index < 0 || index >= this->arrSize)
			throw	out_of_range("Index out of range");
		return (*(this->begin() + index));
	}

	template	<class T>
	T&	PFArray<T>::operator[](size_t index)
	{
		return (*(this->begin() + index));
	}

	template	<class T>
	const T	PFArray<T>::operator[](size_t index) const
	{
		return (*(this->begin() + index));
	}

	template	<class T>
	T&	PFArray<T>::front()
	{
		return (*this->begin());
	}

	template	<class T>
	const T	PFArray<T>::front() const
	{
		return (*this->begin());
	}

	template	<class T>
	T&	PFArray<T>::back()
	{
		return (*(this->end() - 1));
	}

	template	<class T>
	const T	PFArray<T>::back() const
	{
		return (*(this->end() - 1));
	}

	template	<class T>
	void	PFArray<T>::resize(const size_t& newSize)
	{
		if (newSize > this->arrCapacity)
			this->reserve(newSize);
		this->arrSize = newSize;
	}

	template	<class T>
	void	PFArray<T>::resize(const size_t& newSize, const T& value)
	{
		Iterator_<T>	it;

		if (newSize > this->arrCapacity)
			this->reserve(newSize);

		it = Iterator_<T>(this->arr);
		for (size_t i = this->arrSize; i < newSize; ++i)
			it[i] = value;
		this->arrSize = newSize;
	}

	template	<class T>
	void	PFArray<T>::reserve(size_t newCapacity)
	{
		shared_ptr<T>	newArr(new T[newCapacity]);
		Iterator_<T>	it;
		Iterator_<T>	it2;
		size_t		i;

		/**
		 * @brief Don't do anything if the new capacity is smaller than the current one
		 * 
		 */
		if (newCapacity <= this->arrCapacity)
			return ;
		it = Iterator_<T>(newArr);
		it2 = Iterator_<T>(this->arr);
		for (i = 0; i < this->arrSize; ++i)
			it[i] = it2[i];
		this->arr = newArr;
		this->arrCapacity = newCapacity;
	}

	template	<class T>
	size_t	PFArray<T>::capacity() const
	{
		return (this->arrCapacity);
	}

	template	<class T>
	size_t	PFArray<T>::bufSize() const
	{
		return (this->bufferSize);
	}

	template	<class T>
	void	PFArray<T>::push_back(const T& value)
	{
		if (this->arrSize == this->arrCapacity)
		{
			this->reserve(this->arrCapacity + this->bufferSize);
			/**
			 * @brief Double the buffer size
			 * 
			 */
			this->bufferSize *= 2;
		}
		*(this->end()) = value;
		++this->arrSize;
	}

	template	<class T>
	const T	PFArray<T>::pop_back()
	{
		if (this->arrSize == 0)
			throw	out_of_range("Array is empty");
		--this->arrSize;
		return (*(this->begin() + this->arrSize));
	}

	template	<class T>
	void	PFArray<T>::clear()
	{
		this->arr.reset();
		this->arrCapacity = 0;
		this->arrSize = 0;
		this->bufferSize = 1;
	}

	template	<class T>
	Iterator_<T>	PFArray<T>::insert(const Iterator_<T>& pos, const T& value)
	{
		Iterator_<T>	it;
		size_t		index;

		index = pos - this->begin();
		if (this->arrSize == this->arrCapacity)
		{
			this->reserve(this->arrCapacity + this->bufferSize);
			this->bufferSize *= 2;
		}
		/**
		 * @brief Shift all the elements to the right
		 * 
		 */
		it = this->end();
		while (it != pos)
		{
			*it = *(it - 1);
			--it;
		}
		*pos = value;
		++this->arrSize;
		return (this->begin() + index);
	}

	template	<class T>
	Iterator_<T>	PFArray<T>::insert(const Iterator_<T>& pos, T&& value)
	{
		Iterator_<T>	it;
		size_t		index;

		index = pos - this->begin();
		if (this->arrSize == this->arrCapacity)
		{
			this->reserve(this->arrCapacity + this->bufferSize);
			this->bufferSize *= 2;
		}
		/**
		 * @brief Shift all the elements to the right
		 * 
		 */
		it = this->end();
		while (it != pos)
		{
			*it = *(it - 1);
			--it;
		}
		*pos = value;
		++this->arrSize;
		return (this->begin() + index);
	}

	template	<class T>
	Iterator_<T>	PFArray<T>::erase(const Iterator_<T>& pos)
	{
		Iterator_<T>	it;
		size_t		index;

		if (pos >= this->end() || pos < this->begin())
			throw	out_of_range("Iterator out of range");

		/**
		 * @brief Shift all the elements to the left
		 * 
		 */
		index = pos - this->begin();
		it = pos;
		while (it != this->end())
		{
			*it = *(it + 1);
			++it;
		}
		--this->arrSize;
		return (this->begin() + index);
	}

	template	<class T>
	Iterator_<T>	PFArray<T>::erase(const Iterator_<T>& first, const Iterator_<T>& last)
	{
		Iterator_<T>	it;
		Iterator_<T>	it2;
		size_t		index;

		if ((first >= this->end() || first < this->begin()) &&
			(last >= this->end() || last < this->begin()) &&
			(first > last))
			throw	out_of_range("Iterator out of range");

		/**
		 * @brief Shift all the elements to the left
		 * 
		 */
		index = first - this->begin();
		it = first;
		it2 = last;
		while (it2 != this->end())
		{
			*it = *it2;
			++it;
			++it2;
		}
		this->arrSize -= (last - first);
		return (this->begin() + index);
	}

	template	<class T>
	void	PFArray<T>::shrink_to_fit()
	{
		shared_ptr<T>	newArr(new T[this->arrSize]);
		Iterator_<T>	it;
		Iterator_<T>	it2;
		size_t		i;

		it = Iterator_<T>(newArr);
		it2 = Iterator_<T>(this->arr);
		for (i = 0; i < this->arrSize; ++i)
			it[i] = it2[i];
		this->arr = newArr;
		this->arrCapacity = this->arrSize;
	}

	template	<class T>
	size_t	PFArray<T>::size() const
	{
		return (this->arrSize);
	}

	template	<class T>
	bool	PFArray<T>::operator==(const PFArray<T>& rhs) const
	{
		Iterator_<T>	it;
		Iterator_<T>	it2;
		size_t		i;

		if (this->arrSize != rhs.arrSize)
			return (false);
		it = Iterator_<T>(this->arr);
		it2 = Iterator_<T>(rhs.arr);
		for (i = 0; i < this->arrSize; ++i)
		{
			if (it[i] != it2[i])
				return (false);
		}
		return (true);
	}

	template	<class T>
	bool	PFArray<T>::operator!=(const PFArray<T>& rhs) const
	{
		return (!(*this == rhs));
	}

	template	<class T>
	PFArray<T>&	PFArray<T>::operator=(const PFArray<T>& rhs)
	{
		Iterator_<T>	it;
		Iterator_<T>	it2;

		if (this == &rhs)
			return (*this);
		this->arrSize = rhs.arrSize;
		this->arrCapacity = rhs.arrCapacity;
		this->bufferSize = rhs.bufferSize;
		this->arr.reset(new T[this->arrCapacity]);
		/**
		 * @brief Copy the elements
		 * 
		 */
		it = Iterator_<T>(this->arr);
		it2 = Iterator_<T>(rhs.arr);
		for (size_t i = 0; i < this->arrSize; ++i)
			it[i] = it2[i];
		return (*this);
	}

	template	<class T>
	PFArray<T>&	PFArray<T>::operator=(PFArray<T>&& rhs)
	{
		/**
		 * @brief Move assignment operator
		 * 
		 */
		if (this == &rhs)
			return (*this);
		this->arrSize = rhs.arrSize;
		this->arrCapacity = rhs.arrCapacity;
		this->bufferSize = rhs.bufferSize;
		this->arr = rhs.arr;
		/**
		 * @brief Reset rhs, so it doesn't delete the array
		 * 
		 */
		rhs.arr = nullptr;
		return (*this);
	}
}

#endif
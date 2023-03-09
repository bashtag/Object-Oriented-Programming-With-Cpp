#ifdef	ITERATOR_HPP

namespace it_arr
{
	template <class T>
	Iterator_<T>::Iterator_() : ptr(nullptr)
	{}

	template <class T>
	Iterator_<T>::Iterator_(T* ptr) : ptr(ptr)
	{}

	template <class T>
	Iterator_<T>::Iterator_(const Iterator_<T>& iterator) : ptr(iterator.ptr)
	{}

	template <class T>
	Iterator_<T>::Iterator_(const Iterator_<T>&& iterator) : ptr(iterator.ptr)
	{}

	template <class T>
	Iterator_<T>::Iterator_(shared_ptr<T> ptr) : ptr(ptr.get())
	{}

	template <class T>
	bool	Iterator_<T>::isEmpty() const
	{
		if (this->ptr == nullptr)
			return (true);
		return (false);
	}

	template <class T>
	T&	Iterator_<T>::operator*() const
	{
		return (*(this->ptr));
	}

	template <class T>
	T*	Iterator_<T>::operator->() const
	{
		return (this->ptr);
	}

	template <class T>
	Iterator_<T>	Iterator_<T>::operator+(ptrdiff_t n)
	{
		return (Iterator_<T>(this->ptr + n));
	}

	template <class T>
	Iterator_<T>	Iterator_<T>::operator-(ptrdiff_t n)
	{
		return (Iterator_<T>(this->ptr - n));
	}

	template <class U>
	ptrdiff_t	operator-(const Iterator_<U>& lhs, const Iterator_<U>& rhs)
	{
		return (lhs.ptr - rhs.ptr);
	}

	template <class U>
	Iterator_<U>	operator+(ptrdiff_t n, const Iterator_<U>& rhs)
	{
		Iterator_<U>	copy = rhs;
		copy.ptr += n;
		return (copy);
	}

	template <class T>
	Iterator_<T>&	Iterator_<T>::operator++()
	{
		++(this->ptr);
		return (*this);
	}

	template <class T>
	Iterator_<T>	Iterator_<T>::operator++(int)
	{
		Iterator_<T>	copy = (*this);
		++(this->ptr);
		return (copy);
	}

	template <class T>
	Iterator_<T>&	Iterator_<T>::operator--()
	{
		--(this->ptr);
		return (*this);
	}

	template <class T>
	Iterator_<T>	Iterator_<T>::operator--(int)
	{
		Iterator_<T>	copy = (*this);
		--(this->ptr);
		return (copy);
	}

	template <class T>
	T&	Iterator_<T>::operator[](ptrdiff_t n)
	{
		return (*(this->ptr + n));
	}
	
	template <class T>
	const T	Iterator_<T>::operator[](ptrdiff_t n) const
	{
		return (*(this->ptr + n));
	}

	template <class T>
	Iterator_<T>&	Iterator_<T>::operator=(const Iterator_<T>& iterator)
	{
		this->ptr = iterator.ptr;
		return (*this);
	}

	template <class T>
	Iterator_<T>&	Iterator_<T>::operator=(const Iterator_<T>&& iterator)
	{
		this->ptr = iterator.ptr;
		return (*this);
	}

	template <class T>
	Iterator_<T>&	Iterator_<T>::operator+=(ptrdiff_t n)
	{
		this->ptr += n;
		return (*this);
	}

	template <class T>
	Iterator_<T>&	Iterator_<T>::operator-=(ptrdiff_t n)
	{
		this->ptr -= n;
		return (*this);
	}

	template <class T>
	bool	Iterator_<T>::operator==(const Iterator_<T>& iterator) const
	{
		if (this->ptr == iterator.ptr)
			return (true);
		return (false);
	}

	template <class T>
	bool	Iterator_<T>::operator!=(const Iterator_<T>& iterator) const
	{
		return (!(*this == iterator));
	}

	template <class T>
	bool	Iterator_<T>::operator<(const Iterator_<T>& iterator) const
	{
		if (this->ptr < iterator.ptr)
			return (true);
		return (false);
	}

	template <class T>
	bool	Iterator_<T>::operator>(const Iterator_<T>& iterator) const
	{
		if (this->ptr > iterator.ptr)
			return (true);
		return (false);
	}

	template <class T>
	bool	Iterator_<T>::operator<=(const Iterator_<T>& iterator) const
	{
		return (!(*this > iterator));
	}

	template <class T>
	bool	Iterator_<T>::operator>=(const Iterator_<T>& iterator) const
	{
		return (!(*this < iterator));
	}
}

#endif
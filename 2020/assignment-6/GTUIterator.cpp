#include "GTUIterator.hpp"

using namespace std;

namespace gtu
{
	template <class T>
	GTUIterator<T>::GTUIterator() : ptr(nullptr)
	{}

	template <class T>
	GTUIterator<T>::GTUIterator(const GTUIterator<T>& iterator) : ptr(iterator.ptr)
	{}

	template <class T>
	GTUIterator<T>::GTUIterator(const GTUIterator<T>&& iterator) : ptr(iterator.ptr)
	{}

	template <class T>
	GTUIterator<T>::GTUIterator(shared_ptr<T> ptr) : ptr(ptr.get())
	{}

	template <class T>
	GTUIterator<T>::~GTUIterator()
	{}

	template <class T>
	bool	GTUIterator<T>::isEmpty() const
	{
		if (this->ptr == nullptr)
			return (true);
		return (false);
	}

	template <class T>
	T&	GTUIterator<T>::operator*()
	{
		return (*(this->ptr));
	}

	template <class T>
	T&	GTUIterator<T>::operator->()
	{
		return (*(this->ptr));
	}

	template <class T>
	GTUIterator<T>&	GTUIterator<T>::operator++()
	{
		++(this->ptr);
		return (*this);
	}

	template <class T>
	GTUIterator<T>&	GTUIterator<T>::operator++(int)
	{
		GTUIterator<T>	copy = (*this);
		++(this->ptr);
		return (copy);
	}

	template <class T>
	GTUIterator<T>&	GTUIterator<T>::operator--()
	{
		--(this->ptr);
		return (*this);
	}

	template <class T>
	GTUIterator<T>&	GTUIterator<T>::operator--(int)
	{
		GTUIterator<T>	copy = (*this);
		--(this->ptr);
		return (copy);
	}

	template <class T>
	GTUIterator<T>&	GTUIterator<T>::operator=(const GTUIterator<T>& iterator)
	{
		this->ptr = iterator.ptr;
		return (*this)
	}

	template <class T>
	GTUIterator<T>&	GTUIterator<T>::operator=(const GTUIterator<T>&& iterator)
	{
		this->ptr = iterator.ptr;
		return (*this)
	}

	template <class T>
	bool	GTUIterator<T>::operator==(const GTUIterator<T>& iterator)
	{
		if (this->ptr == iterator.ptr)
			return (true);
		return (false);
	}

	template <class T>
	bool	GTUIterator<T>::operator!=(const GTUIterator<T>& iterator)
	{
		return (!(*this == iterator));
	}
}
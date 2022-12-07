#include "GTUIteratorConst.hpp"

using namespace std;

namespace GTU
{
	template <class T>
	GTUIteratorConst<T>::GTUIteratorConst() : ptr(nullptr)
	{}

	template <class T>
	GTUIteratorConst<T>::GTUIteratorConst(const GTUIteratorConst<T>& iterator) : ptr(iterator.ptr)
	{}

	template <class T>
	GTUIteratorConst<T>::GTUIteratorConst(const GTUIteratorConst<T>&& iterator) : ptr(iterator.ptr)
	{}

	template <class T>
	GTUIteratorConst<T>::GTUIteratorConst(shared_ptr<T> ptr)
	{
		this->ptr = ptr.get();
	}

	template <class T>
	bool	GTUIteratorConst<T>::isEmpty() const
	{
		if (this->ptr == nullptr)
			return (true);
		return (false);
	}

	template <class T>
	T&	GTUIteratorConst<T>::operator*() const
	{
		return (*(this->ptr));
	}

	template <class T>
	T&	GTUIteratorConst<T>::operator->() const
	{
		return (*(this->ptr));
	}

	template <class T>
	GTUIteratorConst<T>&	GTUIteratorConst<T>::operator=(const GTUIteratorConst<T>& iterator)
	{
		this->ptr = iterator.ptr;
		return (*this);
	}

	template <class T>
	GTUIteratorConst<T>&	GTUIteratorConst<T>::operator=(const GTUIteratorConst<T>&& iterator)
	{
		this->ptr = iterator.ptr;
		return (*this);
	}

	template <class T>
	bool	GTUIteratorConst<T>::operator==(const GTUIteratorConst<T>& iterator) const
	{
		if (this->ptr == iterator.ptr)
			return (true);
		return (false);
	}

	template <class T>
	bool	GTUIteratorConst<T>::operator!=(const GTUIteratorConst<T>& iterator) const
	{
		return (!((*this)==iterator));
	}
}
#ifndef _ITERABLE_HPP_
#define _ITERABLE_HPP_

#include <iterator>
#include "GTUIterator.hpp"
#include "GTUIteratorConst.hpp"

namespace	GTU
{
	template <typename T>
	class	Iterable
	{
		public:
			virtual bool	empty() const = 0;
			virtual int		size() const = 0;
			virtual	GTUIterator<T>	erase(GTUIterator<T>) = 0;
			virtual	GTUIterator<T>	erase(const GTUIterator<T>) = 0;
			virtual	GTUIterator<T>	erase(GTUIterator<T>, GTUIterator<T>) = 0;
			virtual	GTUIterator<T>	erase(const GTUIterator<T>, const GTUIterator<T>) = 0;
			virtual	GTUIterator<T>	insert(const GTUIterator<T>, const T&) = 0; /* iterator, value*/
			virtual	GTUIterator<T>	insert(const GTUIterator<T>, T&&) = 0; /* iterator, value*/
			virtual	GTUIterator<T>	insert(const GTUIterator<T>, size_t, T&&) = 0; /* iterator, count, value*/
			virtual	GTUIterator<T>	insert(const GTUIterator<T>, const GTUIterator<T>&, const GTUIterator<T>&) = 0; /* iterator, input iterator(begin), input iterator(end) */
			virtual	void	clear() = 0;
			virtual void	shrink_to_fit() = 0;
			virtual	GTUIterator<T>	begin() const = 0;
			virtual	GTUIterator<T>	end() const = 0;
			virtual GTUIteratorConst<T>	cbegin() const = 0;
			virtual GTUIteratorConst<T>	cend() const = 0;

		private:

	};
}

#endif
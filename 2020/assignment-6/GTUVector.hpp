#include "iterable.h"

namespace	GTU
{
	template <class T>
	class GTUVector : public Iterable<T>
	{
		public:
			GTUVector();
			GTUVector(const GTUVector&);
			GTUVector(const GTUVector&&);
			GTUVector(T	*arr, const size_t& arrSize);
			~GTUVector();

			virtual bool	empty() const = 0;
			virtual size_t		size() const = 0;
			/**
			 * @brief 1) Removes the element at pos.
			 * 2) Removes the elements in the range [first, last).
			 * 
			 * @return GTUIterator<T> 
			 */
			virtual	GTUIterator<T>	erase(const GTUIterator<T>&) = 0;
			virtual	GTUIterator<T>	erase(const GTUIterator<T>&, const GTUIterator<T>&) = 0; /* range */
			virtual	GTUIterator<T>	insert(const GTUIterator<T>&, const T&) = 0;
			virtual	GTUIterator<T>	insert(const GTUIterator<T>&, T&&) = 0;
			virtual	GTUIterator<T>	insert(const GTUIterator<T>&, size_t, T&&) = 0;
			virtual	GTUIterator<T>	insert(const GTUIterator<T>&, const GTUIterator<T>&, const GTUIterator<T>&) = 0;
			virtual	void	clear() = 0;
			virtual void	shrink_to_fit() = 0;
			virtual	GTUIterator<T>	begin() const = 0;
			virtual	GTUIterator<T>	end() const = 0;
			virtual GTUIteratorConst<T>	cbegin() const = 0;
			virtual GTUIteratorConst<T>	cend() const = 0;

			T&	at(size_t);
			const T&	at(size_t);
			T&	operator[](int);
			const T&	operator[](int);
			T&	front();
			const T&	front();
			void	resize(const size_t&);
			void	push_back(const T&); /* lvalue */
			void	push_back(T&&); /* rvalue */
			size_t	capacity();
			void	reserve(size_t);

			bool	operator==(const GTUVector<T>&) const;
			bool	operator==(const GTUVector<T>&&) const;
			bool	operator!=(const GTUVector<T>&) const;
			bool	operator!=(const GTUVector<T>&&) const;
			GTUVector<T>&	operator=(const GTUVector<T>&);
			const GTUVector<T>&	operator=(const GTUVector<T>&);

		private:
			shared_ptr<T>	arr;
			size_t	arrSize, capacity, bufferSize;
	}
}

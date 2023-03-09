#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <memory>
# include <iostream>

using namespace std;

namespace it_arr
{
	template<class T>
	class Iterator_
	{
		public:
			Iterator_();
			Iterator_(T*);
			Iterator_(const Iterator_<T>&);
			Iterator_(const Iterator_<T>&&);
			Iterator_(shared_ptr<T>);

			inline T*	getPtr() const {return (this->ptr);};
			bool	isEmpty() const;

			T&	operator*() const;
			T*	operator->() const;

			Iterator_<T>	operator+(ptrdiff_t);
			Iterator_<T>	operator-(ptrdiff_t);
			template <class U> friend ptrdiff_t	operator-(const Iterator_<U>&, const Iterator_<U>&);
			template <class U> friend Iterator_<U>	operator+(ptrdiff_t, const Iterator_<U>&);
			
			Iterator_<T>&	operator++();
			Iterator_<T>	operator++(int);
			
			Iterator_<T>&	operator--();
			Iterator_<T>	operator--(int);
			
			T&	operator[](ptrdiff_t);
			const T	operator[](ptrdiff_t) const;
			
			Iterator_<T>&	operator=(const Iterator_<T>&); /* lvalue */
			Iterator_<T>&	operator=(const Iterator_<T>&&); /* rvalue */
			Iterator_<T>&	operator+=(ptrdiff_t);
			Iterator_<T>&	operator-=(ptrdiff_t);
			bool	operator==(const Iterator_<T>&) const; /* both lvalue and rvlue */
			bool	operator!=(const Iterator_<T>&) const;
			bool	operator<(const Iterator_<T>&) const;
			bool	operator>(const Iterator_<T>&) const;
			bool	operator<=(const Iterator_<T>&) const;
			bool	operator>=(const Iterator_<T>&) const;

			using	value_type = T;
			using	pointer = T*;
			using	reference = T&;
			using	difference_type = ptrdiff_t;
			using	iterator_category = random_access_iterator_tag;

		private:
			T	*ptr;
	};
}

# include "Iterator_.cpp"

#endif
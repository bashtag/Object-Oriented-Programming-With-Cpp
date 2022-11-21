#ifndef GTUITERATOR_HPP
# define GTUITERATOR_HPP
# include <memory>

using namespace std;

namespace gtu
{
	template<class T>
	class GTUIterator
	{
		public:
			GTUIterator();
			GTUIterator(const GTUIterator<T>&);
			GTUIterator(const GTUIterator<T>&&);
			GTUIterator(shared_ptr<T>);
			~GTUIterator();

			inline T*	getPtr() const {return (this->ptr);};
			bool	isEmpty() const;

			T&	operator*();
			T&	operator->();
			
			GTUIterator<T>&	operator++();
			GTUIterator<T>&	operator++(int);
			
			GTUIterator<T>&	operator--();
			GTUIterator<T>&	operator--(int);
			
			GTUIterator<T>&	operator=(const GTUIterator<T>&); /* lvalue */
			GTUIterator<T>&	operator=(const GTUIterator<T>&&); /* rvalue */
			bool	operator==(const GTUIterator<T>&); /* both lvalue and rvlue */
			bool	operator!=(const GTUIterator<T>&);

		private:
			T	*ptr;
	};
}

# endif
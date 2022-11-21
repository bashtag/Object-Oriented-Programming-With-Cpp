#ifndef GTUITERATORCONST_HPP
# define GTUITERATORCONST_HPP

# include <memory>

using namespace std;

namespace GTU
{
	template <class T>
	class GTUIteratorConst
	{
		public:
			GTUIteratorConst();
			GTUIteratorConst(const GTUIteratorConst<T>&);
			GTUIteratorConst(const GTUIteratorConst<T>&&);
			GTUIteratorConst(shared_ptr<T>);
			~GTUIteratorConst();

			inline const T*	getPtr() const {return (this->ptr);};
			bool	isEmpty() const;

			T&	operator*() const; /* try to use const */
			T&	operator->() const;

			GTUIteratorConst<T>&	operator=(const GTUIteratorConst<T>&);
			GTUIteratorConst<T>&	operator=(const GTUIteratorConst<T>&&);

			bool	operator==(const GTUIteratorConst<T>&) const;
			bool	operator!=(const GTUIteratorConst<T>&) const;

		private:
			const T*	ptr;
	};
}
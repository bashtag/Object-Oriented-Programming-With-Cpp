#ifndef	PFARRAY_HPP
# define	PFARRAY_HPP

# include	"Iterator_.hpp"

namespace	it_arr
{
	/**
	 * @brief PFArray is a class that represents a dynamic array.
	 * 
	 * @tparam T 
	 */
	template < class T >
	class	PFArray
	{
		public:
			/**
			 * @brief Construct a new PFArray object
			 * 
			 */
			PFArray();
			PFArray(const PFArray&);
			PFArray(const PFArray&&);
			PFArray(const size_t&);
			PFArray(const size_t&, const size_t&);
			/**
			 * @brief Initialize a new PFArray object with an initializer list.
			 * 
			 */
			PFArray(initializer_list<T>);
			/**
			 * @brief Construct a new PFArray object with an array.
			 * 
			 */
			PFArray(T *arr, const size_t& arrSize);
			PFArray(T *arr, const size_t& arrSize, const size_t& bufferSize);
			~PFArray();

			/**
			 * @brief Returns the number of elements in the container.
			 * 
			 * @return true 
			 * @return false 
			 */
			bool	empty() const;
			/**
			 * @brief 1) Removes the element at pos.
			 * 2) Removes the elements in the range [first, last).
			 * 
			 * @return Iterator_<T> 
			 */
			Iterator_<T>	erase(const Iterator_<T>&);
			Iterator_<T>	erase(const Iterator_<T>&, const Iterator_<T>&); /* range */
			/**
			 * @brief Inserts value before pos.
			 * 
			 * @return Iterator_<T> 
			 */
			Iterator_<T>	insert(const Iterator_<T>&, const T&);
			Iterator_<T>	insert(const Iterator_<T>&, T&&);
			/**
			 * @brief Removes all elements from the container (which are destroyed), leaving the container with a size of 0.
			 * 
			 */
			void	clear();
			/**
			 * @brief Requests that the vector capacity be at least enough to contain n elements.
			 * 
			 */
			void	shrink_to_fit();
			
			/**
			 * @brief Returns an iterator to the first element of the container.
			 * 
			 * @return Iterator_<T> 
			 */
			Iterator_<T>	begin() const;
			/**
			 * @brief Returns an iterator to the element following the last element of the container.
			 * 
			 * @return Iterator_<T> 
			 */
			Iterator_<T>	end() const;
			/**
			 * @brief Returns a const iterator to the first element of the container.
			 * 
			 * @return const Iterator_<T> 
			 */
			const Iterator_<T>	cbegin() const;
			/**
			 * @brief Returns a const iterator to the element following the last element of the container.
			 * 
			 * @return const Iterator_<T> 
			 */
			const Iterator_<T>	cend() const;

			/**
			 * @brief Returns a reference to the element at position n in the vector container.
			 * There is bounds checking.
			 * 
			 * @return T& 
			 */
			T&	at(size_t);
			const T	at(size_t) const;

			/**
			 * @brief Returns a reference to the element at position n in the vector container.
			 * There is no bounds checking.
			 * 
			 * @return T& 
			 */
			T&	operator[](size_t);
			const T	operator[](size_t) const;

			/**
			 * @brief Returns a reference to the first element in the container.
			 * 
			 * There is no bounds checking.
			 * 
			 * @return T& 
			 */
			T&	front();
			/**
			 * @brief Returns a const value to the first element in the container.
			 * 
			 * @return const T 
			 */
			const T	front() const;
			/**
			 * @brief Returns a reference to the last element in the container.
			 * 
			 * @return T& 
			 */
			T&	back();
			/**
			 * @brief Returns a const value to the last element in the container.
			 * 
			 * @return const T 
			 */
			const T	back() const;

			/**
			 * @brief 1) Resizes the container so that it contains n elements.
			 * 2) Resizes the container so that it contains n elements. And fills the new elements with copies of val.
			 * 
			 */
			void	resize(const size_t&);
			void	resize(const size_t&, const T&);

			/**
			 * @brief Requests that the vector capacity be at least enough to contain n elements.
			 * 
			 */
			void	reserve(size_t);

			/**
			 * @brief Adds a new element at the end of the vector, after its current last element.
			 * The content of val is copied (or moved) to the new element.
			 * 
			 */
			void	push_back(const T&);

			/**
			 * @brief Removes the last element in the vector, effectively reducing the container size by one.
			 * Returns a value to the element that was removed.
			 * 
			 * @return T 
			 */
			const T	pop_back();

			/**
			 * @brief Returns the number of elements that the container has currently allocated space for.
			 * 
			 * @return size_t 
			 */
			size_t	capacity() const;

			/**
			 * @brief Returns the number of elements in the container.
			 * 
			 * @return size_t 
			 */
			size_t	size() const;

			/**
			 * @brief Returns the size of the buffer.
			 * 
			 * @return size_t 
			 */
			size_t	bufSize() const;

			/**
			 * @brief Returns true if the container is empty, and false otherwise.
			 * 
			 * @return true 
			 * @return false 
			 */
			bool	operator==(const PFArray<T>&) const;

			/**
			 * @brief Returns true if the container is not empty, and false otherwise.
			 * 
			 * @return true 
			 * @return false 
			 */
			bool	operator!=(const PFArray<T>&) const;

			/**
			 * @brief Assignment operator.
			 * 
			 * @return PFArray<T>& 
			 */
			PFArray<T>&	operator=(const PFArray<T>&);

			/**
			 * @brief Assignment with move semantics.
			 * 
			 * @return PFArray<T>& 
			 */
			PFArray<T>&	operator=(PFArray<T>&&);
			
		private:
			/**
			 * @brief The array of elements.
			 * 
			 */
			shared_ptr<T>	arr;
			/**
			 * @brief 1) The number of elements in the container.
			 * 2) The size of the storage space currently allocated for the array, expressed in terms of elements.
			 * 3) The size of the buffer.
			 * 
			 */
			size_t	arrSize, arrCapacity, bufferSize;
	};
}

# include	"PFArray.cpp"

#endif
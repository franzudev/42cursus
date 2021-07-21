#pragma once

#include <memory>
#include <algorithm>
#include "iterator.hpp"

namespace ft {
	template <class T>
	class VectorIterator : public iterator<bidirectional_iterator_tag, T, ptrdiff_t, T*, T&> {
	private:
		T*	p;
	public:
		VectorIterator() {
			p = nullptr;
		}
		~VectorIterator() {};
		VectorIterator(VectorIterator const& it){
			p = it.p;
		}
		VectorIterator(T * it){
			p = it;
		}
		VectorIterator&	operator=(VectorIterator& it) {
			if (p != it.p)
				p = it.p;
			return *this;
		}
		VectorIterator&	operator=(T* it) {
			if (p != it)
				p = it;
			return *this;
		}
		VectorIterator&	operator++() {
			p++;
			return *this;
		}
		VectorIterator&	operator++(int) {
			VectorIterator<T> temp(*this);
			++*this;
			return temp;
		}
		VectorIterator&	operator--() {
			p--;
			return *this;
		}
		VectorIterator&	operator--(int) {
			VectorIterator<T> temp(*this);
			--*this;
			return temp;
		}
		VectorIterator operator-(T val) {
			VectorIterator<T> nV;
			p -= val;
			return *this;
		}
		VectorIterator&	operator+=(int n){
			p += n;
			return *this;
		}
//		friend bool operator==(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs);
	};

//	template <class T>
//	bool operator==(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs) {
//		return lhs.p == rhs.p;
//	}

	template <class T, class Allocator = std::allocator<T> >
	class vector {
	protected:
		size_t	_size;		// Elements
		size_t	_capacity;	// Allocated Space
		bool	_empty;
		T*		_vec;

	public:
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef VectorIterator<T>							iterator;
		typedef const iterator_traits<T*>					const_iterator;

		// --- Constructors && Destructors
		vector() {
			_vec = new T();
			_size = 0;
			_capacity = 1;
			_empty = true;
		}
		~vector() {
			delete[] _vec;
		}
		vector(vector<T> const &vec) {
			*this = vec;
		}

		// --- Operator Overloads
		vector<T> &operator=(vector<T> const &vec) {
			if (_capacity)
				delete[] _vec;
			_vec = new T[vec._capacity];
			for (iterator start = vec.begin(), end = vec.end(), copy = this->begin; start != end; ++start, ++copy) {
				*copy = *start;
			}
			_size = vec._size;
			_capacity = vec._capacity;
			_empty = vec._empty;
			return *this;
		}

		// --- Iterators
		iterator	begin(void) {
			if (_size)
				return iterator(&_vec[0]);
			return iterator();
		}
		iterator	end(void) {
			if (_size)
				return iterator(&_vec[_size]);
			return iterator();
		}

		// --- Getters
		size_t	size(void)		const {return _size;}
		size_t	max_size(void)	const {return std::allocator<T>::max_size();}
		size_t	capacity(void)	const {return _capacity;}
		bool	empty(void)		const {return _empty;}

		// --- Member Functions
		void 	resize(size_t n) {
			(void) n;
			// ---
		}
		void	reserve(size_t n) {
			if (n <= _capacity)
				return;
			// ---
		}
		void 	push_back(T i){
			if (_size + 1 < capacity()){
				_vec[_size++] = i;
			}
		}
	};
}

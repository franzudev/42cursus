#pragma once

#include "enable_if.hpp"
#include "lexicographical_compare.hpp"
#include "rb_tree.hpp"
#include "pair.hpp"

namespace ft {

	template <class Pair>
	struct keyLess {
		bool operator ()(const Pair& p1, const Pair& p2) const {
			return p1.first < p2.first;
		}
	};

	template<class Pointer, class Value>
	struct map_iterator {
		typedef Pointer                                                     iterator_type;
		typedef Value														value;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type			value_type;
		typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer			pointer;
		typedef typename iterator_traits<iterator_type>::reference         	reference;

		explicit map_iterator(): m_ptr(nullptr){};

		explicit map_iterator(iterator_type ptr): m_ptr(ptr) {}

		template<class Iter>
		map_iterator(map_iterator<Iter, Value> const & other) {
			*this = other;
		}

		value operator*() const { return m_ptr->key; }

		value *operator->() const { return &m_ptr->key; }

		// Prefix increment
		map_iterator &operator++() {
			if (m_ptr->right)
				m_ptr = m_ptr->right;
			else if (m_ptr->isLeft()) {
				m_ptr = m_ptr->parent;
			} else {
				while (m_ptr->parent && !m_ptr->isLeft())
					m_ptr = m_ptr->parent;
				m_ptr = m_ptr->parent;
			}
			return *this;
		}

		// Postfix increment
		map_iterator operator++(int) { map_iterator tmp = *this; ++*this; return tmp; }

		// Prefix decrement
		map_iterator &operator--() {
			if (m_ptr->left)
				m_ptr = m_ptr->left;
			else if (m_ptr->isRight()) {
				m_ptr = m_ptr->parent;
			} else {
				while (m_ptr->parent && !m_ptr->isRight())
					m_ptr = m_ptr->parent;
				m_ptr = m_ptr->parent;
			}
			return *this;
		}

		// Postfix decrement
		map_iterator operator--(int) { map_iterator tmp = *this; --*this; return tmp; }

		iterator_type	base() const {
			return m_ptr;
		}

		template <class Iter>
		map_iterator&	operator=(map_iterator<Iter, Value> const & other) {
			std::cout << "called" << std::endl;
			m_ptr = other.base();
			return *this;
		}
	private:
		iterator_type m_ptr;
	};

	template < class Key, class T, class Compare = keyLess<ft::pair<const Key,T> >, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map {
	public:
		// --- Definitions
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef Compare												key_compare;
		typedef Alloc												allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::value_type					value_type;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef typename allocator_type::size_type					size_type;
		typedef typename allocator_type::difference_type			difference_type;
		typedef rb_tree<value_type>									tree;
		typedef Node<value_type>*									node_ptr;

		typedef ft::map_iterator<node_ptr, value_type>				iterator;
		typedef ft::map_iterator<const node_ptr, const value_type>	const_iterator;
		typedef std::reverse_iterator<iterator>						reverse_iterator;
		typedef std::reverse_iterator<const_iterator>				const_reverse_iterator;
		// definitions

//		class value_compare: public binary_function<value_type, value_type, bool>
//		{
//			friend class map;
//		protected:
//			key_compare comp;
//
//			value_compare(key_compare c);
//		public:
//			bool operator()(const value_type& x, const value_type& y) const;
//		};

		// --- constructors
		map() {};
		explicit map( const Compare& comp, const Alloc& alloc = Alloc()) {}
		template< class InputIt > map( InputIt first, InputIt last, const Compare& comp = Compare(), const Alloc& alloc = Alloc()) {}
		map( const map& other ){}
		~map() {};
		// constructors

		// ---operators overload
		map& operator=( const map& other ) {}
		// operators overload

		// ---getters
		allocator_type get_allocator() const {}
		// getters

		// --- element access
		mapped_type& operator[](const key_type& k) {}

		mapped_type& at(const key_type& k) {}
		const mapped_type& at(const key_type& k) const {}
		// element access

		// --- iterators
		iterator begin() {}
		const_iterator begin() const {}
		iterator end() {}
		const_iterator end() const {}

		reverse_iterator rbegin() {}
		const_reverse_iterator rbegin() const {}
		reverse_iterator rend() {}
		const_reverse_iterator rend()   const {}
		// iterators

		// --- Capacity
		bool empty() const {}
		size_type size() const {}
		size_type max_size() const {}
		// capacity

		// --- modifiers
		void clear() {}
		ft::pair<iterator, bool> insert( const value_type& value ) {
			ft::pair<node_ptr, bool> inserted = _tree.insert(value);
			return ft::make_pair(iterator(inserted.first), inserted.second);
		}
		iterator insert( iterator hint, const value_type& value ) {
			ft::pair<node_ptr, bool> inserted = _tree.insert(hint, value);
			return ft::make_pair(iterator(inserted.first), inserted.second);
		}
		template< class InputIt >
		void insert( InputIt first, InputIt last ) {
			for (InputIt begin = first; begin != last; ++begin)
				insert(begin);
		}
		void erase( iterator pos ) {}
		void erase( iterator first, iterator last ) {}
		size_type erase( const key_type& key ) {}
		void swap( map& other ) {}
		//

		// --- Lookup
		size_type count( const Key& key ) const {}
		iterator find( const Key& key ) {}
		const_iterator find( const Key& key ) const {}
		std::pair<iterator,iterator> equal_range( const Key& key ) {}
		std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {}
		iterator lower_bound( const Key& key ) {}
		const_iterator lower_bound( const Key& key ) const {}
		iterator upper_bound( const Key& key ) {}
		const_iterator upper_bound( const Key& key ) const {}
		//

		// --- Observers
		key_compare key_comp() const {}
//		map::value_compare value_comp() const {}

	private:
		tree	_tree;
	};
}

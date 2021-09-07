/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:24:09 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/07 17:57:20 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>

# include "iterator/RandomAccessIterator.hpp"
# include "iterator/InputIterator.hpp"

# include "tool/EnableIf.hpp"
# include "tool/IsIntegral.hpp"

namespace ft
{

template < class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef T 					value_type;
		typedef Allocator			allocator_type;
		typedef value_type&			reference;
		typedef const value_type&	const_reference;
		typedef value_type*			pointer;
		typedef const value_type*	const_pointer;
		typedef std::ptrdiff_t		difference_type;
		typedef std::size_t			size_type;

		typedef RandomAccessIterator<value_type>		iterator;
		typedef const RandomAccessIterator<value_type>	const_iterator;
		//typedef reverse_iterator<iterator>			reverse_iterator;
		//typedef reverse_iterator<const_iterator>	const_reverse_operator;

	protected:
		pointer			_c;
		size_type		_size;
		size_type		_capacity;

	public:
		allocator_type	_alloc;
		// Constructors and destructor
		explicit	vector(const allocator_type& alloc = allocator_type());
		explicit	vector(size_type n, const_reference val = value_type(), \
							const allocator_type& alloc = allocator_type());
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, \
				const allocator_type& alloc = allocator_type());
		vector(const vector<T, Allocator>& x);
		virtual ~vector();

		// Iterators
		iterator		begin();
		const_iterator	begin() const;
		iterator		end();
		const_iterator	end() const;

		// Capacity
		size_type	size() const;
		size_type	capacity() const;
		size_type	max_size() const;
		void		resize(size_type n, value_type val = value_type());
		bool		empty() const;
		void		reserve(size_type n);

		// Element access
		reference		operator[](size_type n);
		const_reference	operator[](size_type n) const;
		reference		at(size_type n);
		const_reference	at(size_type n) const;
		reference		front();
		const_reference	front() const;
		reference		back();
		const_reference	back() const;

		// Modifiers
		void	push_back(const_reference val);
		void	pop_back();
		void	clear();
		
		//Allocator
		allocator_type	get_allocator() const;

	private:
		void	_reallocate(difference_type n = 1);
};



// Constructors and destructor
template < class T, class Allocator >
vector<T, Allocator>::vector(const allocator_type& alloc) : _size(0), _capacity(0), _alloc(alloc)
{
	_c = _alloc.allocate(_capacity);
}

template < class T, class Allocator >
vector<T, Allocator>::vector(size_type n, const_reference val, const allocator_type& alloc) \
: _size(n), _capacity(n), _alloc(alloc)
{
	_c = _alloc.allocate(_capacity);
	for (size_type i = 0; i < _size; ++i)
		_alloc.construct(&_c[i], val);
}

template< class T, class Allocator >
template< class InputIterator >
vector<T, Allocator>::vector(InputIterator first, InputIterator last, const allocator_type& alloc) \
: _size(0), _capacity(0), _alloc(alloc)
{
	InputIterator count = first;

	for (; count != last; count++)
		_size++;

	_capacity = _size;
	_c = _alloc.allocate(_capacity);
	for (size_type i = 0; i < _size; ++i)
	{
		_alloc.construct(&_c[i], *first);
		++first;
	}
}

template < class T, class Allocator >
vector<T, Allocator>::vector(const vector<T, Allocator>& x) \
: _size(x._size), _capacity(x._size), _alloc(x._alloc)
{
	_c = _alloc.allocate(_capacity);
	for (size_type i = 0; i < _size; ++i)
		_alloc.construct(&_c[i], x[i]);
}

template < class T, class Allocator >
vector<T, Allocator>::~vector()
{
	for (size_type i = 0; i < _size; ++i)
		_alloc.destroy(&_c[i]);
	_alloc.deallocate(_c, _capacity);
}



// Iterators
template < class T, class Allocator >
typename vector<T, Allocator>::iterator	vector<T, Allocator>::begin()
{
	return iterator(_c);
}

template < class T, class Allocator >
typename vector<T, Allocator>::const_iterator	vector<T, Allocator>::begin() const
{
	return iterator(_c);
}

template < class T, class Allocator >
typename vector<T, Allocator>::iterator	vector<T, Allocator>::end()
{
	return iterator(_c + _size);
}

template < class T, class Allocator >
typename vector<T, Allocator>::const_iterator	vector<T, Allocator>::end() const
{
	return iterator(_c + _size);
}



// Capacity
template < class T, class Allocator >
typename vector<T, Allocator>::size_type	vector<T, Allocator>::size() const
{
	return (_size);
}

template < class T, class Allocator >
typename vector<T, Allocator>::size_type	vector<T, Allocator>::max_size() const
{
	return (_alloc.max_size());
}

template < class T, class Allocator>
void	vector<T, Allocator>::resize(size_type n, value_type val)
{
	if (n < _size)
		for (size_type i = n; i < _size; ++i)
			_alloc.destroy(&_c[i]);
	else if (n > _size)
	{
		if (n + _size > _capacity)
			_reallocate(n - _size);
		for (size_type i = _size; i < n; ++i)
			_alloc.construct(&_c[i], val);
	}
	_size = n;
}

template < class T, class Allocator >
typename vector<T, Allocator>::size_type	vector<T, Allocator>::capacity() const
{
	return (_capacity);
}

template < class T, class Allocator>
bool	vector<T, Allocator>::empty() const
{
	return (_size == 0);
}

template < class T, class Allocator >
void	vector<T, Allocator>::reserve(size_type n)
{
	if (n > _capacity)
		_reallocate(n);
}



// Element access
template < class T, class Allocator >
typename vector<T, Allocator>::reference	vector<T, Allocator>::operator[](size_type n)
{
	return (_c[n]);
}

template < class T, class Allocator >
typename vector<T, Allocator>::const_reference	vector<T, Allocator>::operator[](size_type n) const
{
	return (_c[n]);
}

template < class T, class Allocator >
typename vector<T, Allocator>::reference	vector<T, Allocator>::at(size_type n)
{
	if (n < 0 || n >= _size)
		throw std::out_of_range("Index is out of range");
	else
		return (_c[n]);
}

template < class T, class Allocator >
typename vector<T, Allocator>::const_reference	vector<T, Allocator>::at(size_type n) const
{
	if (n < 0 || n >= _size)
		throw std::out_of_range("Index is out of range");
	else
		return (_c[n]);
}

template < class T, class Allocator >
typename vector<T, Allocator>::reference	vector<T, Allocator>::front()
{
	return (*_c);
}

template < class T, class Allocator >
typename vector<T, Allocator>::const_reference	vector<T, Allocator>::front() const
{
	return (*_c);
}

template < class T, class Allocator >
typename vector<T, Allocator>::reference	vector<T, Allocator>::back()
{
	return (*(_c + _size - 1));
}

template < class T, class Allocator >
typename vector<T, Allocator>::const_reference	vector<T, Allocator>::back() const
{
	return (*(_c + _size - 1));
}



// Modifiers
template < class T, class Allocator>
void	vector<T, Allocator>::push_back(const_reference val)
{
	if (_size == _capacity)
		_reallocate();
	_alloc.construct(&_c[_size], val);
	++_size;
}

template < class T, class Allocator>
void	vector<T, Allocator>::pop_back()
{
	_alloc.destroy(&_c[_size - 1]);
	--_size;
}

template < class T, class Allocator>
void	vector<T, Allocator>::clear()
{
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(&_c[i]);
	_size = 0;
}



// Allocator
template <class T, class Allocator>
typename vector<T, Allocator>::allocator_type	vector<T, Allocator>::get_allocator() const
{
	return (_alloc);
}

// Private functions
template <class T, class Allocator>
void	vector<T, Allocator>::_reallocate(difference_type n)
{
	pointer	realloc;
	difference_type	doublingCounter = 1;
	size_type	newCapacity = 1;

	if (_capacity != 0)
	{
		while (_size + n > _capacity * 2 * doublingCounter)
			doublingCounter++;
		newCapacity =  _capacity * 2 * doublingCounter;
	}
	realloc = _alloc.allocate(newCapacity);

	for (size_type i = 0; i < _size; ++i)
	{
		_alloc.construct(&realloc[i], _c[i]);
		_alloc.destroy(&_c[i]);
	}
	_alloc.deallocate(_c, _capacity);
	
	_c = realloc;
	_capacity = newCapacity;
}


}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:24:09 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/05 16:36:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>

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

		//typedef 					iterator;
		//typedef 					const_iterator;
		//typedef reverse_iterator<iterator>			reverse_iterator;
		//typedef reverse_iterator<const_iterator>	const_reverse_operator;

	protected:
		pointer			_c;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_alloc;

	public:
		// Constructors and destructor
		explicit	vector(const allocator_type& alloc = allocator_type());
		explicit	vector(size_type n, const_reference val = value_type(), \
							const allocator_type& alloc = allocator_type());
		virtual ~vector();

		// Capacity
		size_type	size() const;
		size_type	capacity() const;
		size_type	max_size() const;
		bool		empty() const;

		// Overloads
		reference		operator[](size_type n);
		const_reference	operator[](size_type n) const;
};

// Constructors
template < class T, class Allocator >
vector<T, Allocator>::vector(const allocator_type& alloc) : _size(0), _capacity(0), _alloc(alloc)
{
	_c = _alloc.allocate(0);
}

template < class T, class Allocator >
vector<T, Allocator>::vector(size_type n, const_reference val, const allocator_type& alloc) \
: _size(n), _capacity(n), _alloc(alloc)
{
	_c = _alloc.allocate(_size);
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(&_c[i], val);
}


// Destructor
template < class T, class Allocator >
vector<T, Allocator>::~vector()
{
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(&_c[i]);
	_alloc.deallocate(_c, _capacity);
}


// Capacity
template < class T, class Allocator >
typename vector<T, Allocator>::size_type	vector<T, Allocator>::size() const
{
	return (_size);
}

template < class T, class Allocator >
typename vector<T, Allocator>::size_type	vector<T, Allocator>::capacity() const
{
	return (_capacity);
}

template < class T, class Allocator >
typename vector<T, Allocator>::size_type	vector<T, Allocator>::max_size() const
{
	return (_alloc.max_size());
}

template < class T, class Allocator>
bool	vector<T, Allocator>::empty() const
{
	return (_size == 0);
}


// Element access
template < class T, class Allocator >
typename vector<T, Allocator>::reference	vector<T, Allocator>::operator[](size_type n)
{
	if (n < 0 || n >= _size)
		throw std::out_of_range("Index is out of range");
	else
		return (_c[n]);
}

template < class T, class Allocator >
typename vector<T, Allocator>::const_reference	vector<T, Allocator>::operator[](size_type n) const
{
	if (n < 0 || n >= _size)
		throw std::out_of_range("Index is out of range");
	else
		return (_c[n]);
}

}

#endif

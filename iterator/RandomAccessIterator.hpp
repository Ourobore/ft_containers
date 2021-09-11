/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:43:35 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/11 13:49:27 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

# include <iostream>

//# include "utils/IsConst.hpp"
//# include "utils/IteratorType.hpp"

namespace ft
{

template < class Container >
class RandomAccessIterator
{
	public:
		typedef typename Container::value_type		value_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;
		typedef typename Container::pointer			pointer;
		typedef typename Container::difference_type	difference_type;
		typedef std::random_access_iterator_tag		iterator_category;

	protected:
		pointer	_it;

	public:
		// Constructors, assignation and destructor
		RandomAccessIterator();
		RandomAccessIterator(pointer p);
		RandomAccessIterator(const RandomAccessIterator& rhs);
		RandomAccessIterator&	operator=(const RandomAccessIterator& rhs);
		virtual ~RandomAccessIterator();

		// Implicit conversion form iterator to const_iterator
		operator RandomAccessIterator<const Container>();

		// Equivalence
		bool	operator==(const RandomAccessIterator& rhs) const;
		bool	operator!=(const RandomAccessIterator& rhs) const;

		// Dereference
		reference	operator*();
		pointer		operator->();
		reference	operator[](difference_type n);

		// Increment and Decrement
		RandomAccessIterator&	operator++();
		RandomAccessIterator	operator++(int);
		RandomAccessIterator&	operator--();
		RandomAccessIterator	operator--(int);

		// Arithmetic
		RandomAccessIterator	operator+(difference_type n) const;
		RandomAccessIterator	operator-(difference_type n) const;
		difference_type	operator-(const RandomAccessIterator& rhs) const;

		// Relational
		bool	operator<(const RandomAccessIterator& rhs) const;
		bool	operator>(const RandomAccessIterator& rhs) const;
		bool	operator<=(const RandomAccessIterator& rhs) const;
		bool	operator>=(const RandomAccessIterator& rhs) const;

		// Assignment arithmetic
		RandomAccessIterator&	operator+=(difference_type n);
		RandomAccessIterator&	operator-=(difference_type n);
};


// Constructors and destructor
template < class Container >
RandomAccessIterator<Container>::RandomAccessIterator() : _it(NULL)
{
}

template < class Container >
RandomAccessIterator<Container>::RandomAccessIterator(pointer p) : _it(p)
{
}

template < class Container >
RandomAccessIterator<Container>::RandomAccessIterator(const RandomAccessIterator& rhs) : _it(rhs._it)
{
}

template < class Container >
RandomAccessIterator<Container>&	RandomAccessIterator<Container>::operator=(const RandomAccessIterator& rhs)
{
	if (this != &rhs)
		_it = rhs._it;
	return (*this);
}

template < class Container >
RandomAccessIterator<Container>::~RandomAccessIterator()
{
	_it = NULL;
}



// Implicit conversion form iterator to const_iterator
template < class Container >
RandomAccessIterator<Container>::operator RandomAccessIterator<const Container>()
{
	return RandomAccessIterator<const Container>(_it);
}



// Equivalence
template < class Container >
bool	RandomAccessIterator<Container>::operator==(const RandomAccessIterator<Container>& rhs) const
{
	return (_it == rhs._it);
}

template < class Container >
bool	RandomAccessIterator<Container>::operator!=(const RandomAccessIterator<Container>& rhs) const
{
	return !(*this == rhs);
}



// Dereference
template < class Container >
typename RandomAccessIterator<Container>::reference	RandomAccessIterator<Container>::operator*()
{
	return (*_it);
}

template < class Container >
typename RandomAccessIterator<Container>::pointer	RandomAccessIterator<Container>::operator->()
{
	return (_it);
}

template < class Container >
typename RandomAccessIterator<Container>::reference	RandomAccessIterator<Container>::operator[](difference_type n)
{
	return (_it[n]);
}



// Increment and Decrement
template < class Container >
RandomAccessIterator<Container>&	RandomAccessIterator<Container>::operator++()
{
	++_it;
	return (*this);
}

template < class Container >
RandomAccessIterator<Container>	RandomAccessIterator<Container>::operator++(int)
{
	RandomAccessIterator<Container>	tmp(*this);
	++_it;
	return (tmp);
}

template < class Container >
RandomAccessIterator<Container>&	RandomAccessIterator<Container>::operator--()
{
	--_it;
	return (*this);
}

template < class Container >
RandomAccessIterator<Container>	RandomAccessIterator<Container>::operator--(int)
{
	RandomAccessIterator<Container>	tmp(*this);
	--_it;
	return (tmp);
}



// Arithmetic
template < class Container >
RandomAccessIterator<Container>	RandomAccessIterator<Container>::operator+(difference_type n) const
{
	RandomAccessIterator<Container> sum(*this);
	sum._it += n;
	return (sum);
}

template < class Container >
RandomAccessIterator<Container>	RandomAccessIterator<Container>::operator-(difference_type n) const
{
	RandomAccessIterator<Container> diff(*this);
	diff._it -= n;
	return (diff);
}

template < class Container >
typename RandomAccessIterator<Container>::difference_type	RandomAccessIterator<Container>::operator-(const RandomAccessIterator<Container>& rhs) const
{
	return (_it - rhs._it);
}



// Relational
template < class Container >
bool	RandomAccessIterator<Container>::operator<(const RandomAccessIterator<Container>& rhs) const
{
	return (_it < rhs._it);
}

template < class Container >
bool	RandomAccessIterator<Container>::operator>(const RandomAccessIterator<Container>& rhs) const
{
	return (!(*this < rhs) && *this != rhs);
}

template < class Container >
bool	RandomAccessIterator<Container>::operator<=(const RandomAccessIterator<Container>& rhs) const
{
	return (*this < rhs || *this == rhs);
}

template < class Container >
bool	RandomAccessIterator<Container>::operator>=(const RandomAccessIterator<Container>& rhs) const
{
	return (*this > rhs || *this == rhs);
}



// Assignment arithmetics
template < class Container >
RandomAccessIterator<Container>&	RandomAccessIterator<Container>::operator+=(difference_type n)
{
	_it += n;
	return (*this);
}

template < class Container >
RandomAccessIterator<Container>&	RandomAccessIterator<Container>::operator-=(difference_type n)
{
	_it -= n;
	return (*this);
}


// Non member function overloads
template < class Container >
RandomAccessIterator<Container>	operator+(typename RandomAccessIterator<Container>::difference_type n, const RandomAccessIterator<Container>& rev_it)
{
	return RandomAccessIterator<Container>(rev_it + n);
}

template < class Container >
RandomAccessIterator<Container>		operator-(typename RandomAccessIterator<Container>::difference_type n, const RandomAccessIterator<Container>& rev_it)
{
	return RandomAccessIterator<Container>(rev_it - n);
}

}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:43:35 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/11 12:09:31 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

# include <iostream>

//# include "utils/IsConst.hpp"
//# include "utils/IteratorType.hpp"

namespace ft
{

template <typename Container, typename T>
class RandomAccessIterator
{
	public:
		typedef T					value_type;
		typedef value_type&			reference;
		typedef const value_type&	const_reference;
		typedef value_type*			pointer;
		typedef std::ptrdiff_t		difference_type;
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
		operator RandomAccessIterator<const Container, T>();

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
template <typename Container, typename T>
RandomAccessIterator<Container, T>::RandomAccessIterator() : _it(NULL)
{
}

template <typename Container, typename T>
RandomAccessIterator<Container, T>::RandomAccessIterator(pointer p) : _it(p)
{
}

template <typename Container, typename T>
RandomAccessIterator<Container, T>::RandomAccessIterator(const RandomAccessIterator& rhs) : _it(rhs._it)
{
}

template <typename Container, typename T>
RandomAccessIterator<Container, T>&	RandomAccessIterator<Container, T>::operator=(const RandomAccessIterator& rhs)
{
	if (this != &rhs)
		_it = rhs._it;
	return (*this);
}

template <typename Container, typename T>
RandomAccessIterator<Container, T>::~RandomAccessIterator()
{
	_it = NULL;
}



// Implicit conversion form iterator to const_iterator
template <typename Container, typename T>
RandomAccessIterator<Container, T>::operator RandomAccessIterator<const Container, T>()
{
	return RandomAccessIterator<const Container, T>(_it);
}


// Equivalence
template <typename Container, typename T>
bool	RandomAccessIterator<Container, T>::operator==(const RandomAccessIterator<Container, T>& rhs) const
{
	return (_it == rhs._it);
}

template <typename Container, typename T>
bool	RandomAccessIterator<Container, T>::operator!=(const RandomAccessIterator<Container, T>& rhs) const
{
	return !(*this == rhs);
}



// Dereference
template <typename Container, typename T>
typename RandomAccessIterator<Container, T>::reference	RandomAccessIterator<Container, T>::operator*()
{
	return (*_it);
}

template <typename Container, typename T>
typename RandomAccessIterator<Container, T>::pointer	RandomAccessIterator<Container, T>::operator->()
{
	return (_it);
}

template <typename Container, typename T>
typename RandomAccessIterator<Container, T>::reference	RandomAccessIterator<Container, T>::operator[](difference_type n)
{
	return (_it[n]);
}



// Increment and Decrement
template <typename Container, typename T>
RandomAccessIterator<Container, T>&	RandomAccessIterator<Container, T>::operator++()
{
	++_it;
	return (*this);
}

template <typename Container, typename T>
RandomAccessIterator<Container, T>	RandomAccessIterator<Container, T>::operator++(int)
{
	RandomAccessIterator<Container, T>	tmp(*this);
	++_it;
	return (tmp);
}

template <typename Container, typename T>
RandomAccessIterator<Container, T>&	RandomAccessIterator<Container, T>::operator--()
{
	--_it;
	return (*this);
}

template <typename Container, typename T>
RandomAccessIterator<Container, T>	RandomAccessIterator<Container, T>::operator--(int)
{
	RandomAccessIterator<Container, T>	tmp(*this);
	--_it;
	return (tmp);
}



// Arithmetic
template <typename Container, typename T>
RandomAccessIterator<Container, T>	RandomAccessIterator<Container, T>::operator+(difference_type n) const
{
	RandomAccessIterator<Container, T> sum(*this);
	sum._it += n;
	return (sum);
}

template <typename Container, typename T>
RandomAccessIterator<Container, T>	RandomAccessIterator<Container, T>::operator-(difference_type n) const
{
	RandomAccessIterator<Container, T> diff(*this);
	diff._it -= n;
	return (diff);
}

template <typename Container, typename T>
typename RandomAccessIterator<Container, T>::difference_type	RandomAccessIterator<Container, T>::operator-(const RandomAccessIterator<Container, T>& rhs) const
{
	return (_it - rhs._it);
}



// Relational
template <typename Container, typename T>
bool	RandomAccessIterator<Container, T>::operator<(const RandomAccessIterator<Container, T>& rhs) const
{
	return (_it < rhs._it);
}

template <typename Container, typename T>
bool	RandomAccessIterator<Container, T>::operator>(const RandomAccessIterator<Container, T>& rhs) const
{
	return (!(*this < rhs) && *this != rhs);
}

template <typename Container, typename T>
bool	RandomAccessIterator<Container, T>::operator<=(const RandomAccessIterator<Container, T>& rhs) const
{
	return (*this < rhs || *this == rhs);
}

template <typename Container, typename T>
bool	RandomAccessIterator<Container, T>::operator>=(const RandomAccessIterator<Container, T>& rhs) const
{
	return (*this > rhs || *this == rhs);
}



// Assignment arithmetics
template <typename Container, typename T>
RandomAccessIterator<Container, T>&	RandomAccessIterator<Container, T>::operator+=(difference_type n)
{
	_it += n;
	return (*this);
}

template <typename Container, typename T>
RandomAccessIterator<Container, T>&	RandomAccessIterator<Container, T>::operator-=(difference_type n)
{
	_it -= n;
	return (*this);
}


// Non member function overloads
template <typename Container, typename T>
RandomAccessIterator<Container, T>	operator+(typename RandomAccessIterator<Container, T>::difference_type n, const RandomAccessIterator<Container, T>& rev_it)
{
	return RandomAccessIterator<Container, T>(rev_it + n);
}

template <typename Container, typename T>
RandomAccessIterator<Container, T>		operator-(typename RandomAccessIterator<Container, T>::difference_type n, const RandomAccessIterator<Container, T>& rev_it)
{
	return RandomAccessIterator<Container, T>(rev_it - n);
}

}

#endif
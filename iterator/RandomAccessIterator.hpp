/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:43:35 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/07 16:19:08 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

# include <iostream>

namespace ft
{

template <typename T>
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
		RandomAccessIterator	operator-(const RandomAccessIterator& rhs) const;

		// Relational
		bool	operator<(const RandomAccessIterator& rhs) const;
		bool	operator>(const RandomAccessIterator& rhs) const;
		bool	operator<=(const RandomAccessIterator& rhs) const;
		bool	operator>=(const RandomAccessIterator& rhs) const;

		// Assignment arithmetics
		RandomAccessIterator&	operator+=(difference_type n);
		RandomAccessIterator&	operator-=(difference_type n);
};


// Constructors and destructor
template <typename T>
RandomAccessIterator<T>::RandomAccessIterator() : _it(NULL)
{
}

template <typename T>
RandomAccessIterator<T>::RandomAccessIterator(pointer p) : _it(p)
{
}

template <typename T>
RandomAccessIterator<T>::RandomAccessIterator(const RandomAccessIterator& rhs) : _it(rhs._it)
{
}

template <typename T>
RandomAccessIterator<T>&	RandomAccessIterator<T>::operator=(const RandomAccessIterator& rhs)
{
	if (this != &rhs)
		_it = rhs._it;
	return (*this);
}

template <typename T>
RandomAccessIterator<T>::~RandomAccessIterator()
{
	_it = NULL;
}



// Equivalence
template <typename T>
bool	RandomAccessIterator<T>::operator==(const RandomAccessIterator<T>& rhs) const
{
	return (_it == rhs._it);
}

template <typename T>
bool	RandomAccessIterator<T>::operator!=(const RandomAccessIterator<T>& rhs) const
{
	return !(*this == rhs);
}



// Dereference
template <typename T>
typename RandomAccessIterator<T>::reference	RandomAccessIterator<T>::operator*()
{
	return (*_it);
}

template <typename T>
typename RandomAccessIterator<T>::pointer	RandomAccessIterator<T>::operator->()
{
	return (_it);
}

template <typename T>
typename RandomAccessIterator<T>::reference	RandomAccessIterator<T>::operator[](difference_type n)
{
	return (_it[n]);
}



// Increment and Decrement
template <typename T>
RandomAccessIterator<T>&	RandomAccessIterator<T>::operator++()
{
	++_it;
	return (*this);
}

template <typename T>
RandomAccessIterator<T>	RandomAccessIterator<T>::operator++(int)
{
	RandomAccessIterator<T>	tmp(*this);
	++_it;
	return (tmp);
}

template <typename T>
RandomAccessIterator<T>&	RandomAccessIterator<T>::operator--()
{
	--_it;
	return (*this);
}

template <typename T>
RandomAccessIterator<T>	RandomAccessIterator<T>::operator--(int)
{
	RandomAccessIterator<T>	tmp(*this);
	--_it;
	return (tmp);
}



// Arithmetic
template <typename T>
RandomAccessIterator<T>	RandomAccessIterator<T>::operator+(difference_type n) const
{
	RandomAccessIterator<T> sum(*this);
	sum._it += n;
	return (sum);
}

template <typename T>
RandomAccessIterator<T>	RandomAccessIterator<T>::operator-(difference_type n) const
{
	RandomAccessIterator<T> diff(*this);
	diff._it -= n;
	return (diff);
}

template <typename T>
RandomAccessIterator<T>	RandomAccessIterator<T>::operator-(const RandomAccessIterator<T>& rhs) const
{
	RandomAccessIterator<T> diff;
	diff._it = _it - rhs._it;
	return (diff);
}



// Relational
template <typename T>
bool	RandomAccessIterator<T>::operator<(const RandomAccessIterator<T>& rhs) const
{
	return (_it < rhs._it);
}

template <typename T>
bool	RandomAccessIterator<T>::operator>(const RandomAccessIterator<T>& rhs) const
{
	return (!(*this < rhs) && *this != rhs);
}

template <typename T>
bool	RandomAccessIterator<T>::operator<=(const RandomAccessIterator<T>& rhs) const
{
	return (*this < rhs || *this == rhs);
}

template <typename T>
bool	RandomAccessIterator<T>::operator>=(const RandomAccessIterator<T>& rhs) const
{
	return (*this > rhs || *this == rhs);
}



// Assignment arithmetics
template <typename T>
RandomAccessIterator<T>&	RandomAccessIterator<T>::operator+=(difference_type n)
{
	_it += n;
	return (*this);
}

template <typename T>
RandomAccessIterator<T>&	RandomAccessIterator<T>::operator-=(difference_type n)
{
	_it -= n;
	return (*this);
}

}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:43:35 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/05 16:59:10 by user42           ###   ########.fr       */
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
		RandomAccessIterator(const RandomAccessIterator& rhs);
		RandomAccessIterator&	operator=(const RandomAccessIterator& rhs);
		virtual ~RandomAccessIterator();

		// Overloads
		bool	operator==(const RandomAccessIterator& rhs) const;
		bool	operator!=(const RandomAccessIterator& rhs) const;
		reference	operator*();
		pointer		operator->();
		RandomAccessIterator&	operator++();
		RandomAccessIterator	operator++(int);
		RandomAccessIterator&	operator--();
		RandomAccessIterator	operator--(int);
		RandomAccessIterator	operator+(difference_type n);
		RandomAccessIterator	operator+(value_type);
		RandomAccessIterator	operator-(difference_type n);
		RandomAccessIterator	operator-(value_type);
		bool	operator<(const RandomAccessIterator& rhs);
		bool	operator>(const RandomAccessIterator& rhs);
		bool	operator<=(const RandomAccessIterator& rhs);
		bool	operator>=(const RandomAccessIterator& rhs);
		RandomAccessIterator&	operator+=(difference_type n);
		RandomAccessIterator&	operator-=(difference_type n);
		reference	operator[](difference_type n);
};

// Constructors and destructor
template <typename T>
RandomAccessIterator<T>::RandomAccessIterator() : _it(NULL)
{
}

template <typename T>
RandomAccessIterator<T>::RandomAccessIterator(const RandomAccessIterator& rhs) : _it(rhs._ptr)
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



// Overloads
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
RandomAccessIterator<T>&	RandomAccessIterator<T>::operator++()
{
	return (++_it);
}

template <typename T>
RandomAccessIterator<T>	RandomAccessIterator<T>::operator++(int)
{
	RandomAccessIterator<T>	tmp(*this);
	++_it;
	return (tmp);
}

template <typename T>
RandomAccessIterator<T>	RandomAccessIterator<T>::operator+(difference_type n)
{
	
}

}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:20:33 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/13 16:16:01 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

namespace ft
{

template < class Iterator >
class ReverseIterator
{
	public:
		typedef Iterator								iterator_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::iterator_category	iterator_category;

	protected:
		Iterator	_base;

	public:
		// Constructors
		ReverseIterator();
		explicit ReverseIterator(iterator_type it);
		ReverseIterator(ReverseIterator<iterator_type>& rev_it);
		template < class is_const >
		ReverseIterator(const ReverseIterator<is_const>& rev_it);

		// Access element
		Iterator	base() const;

		// Dereference
		reference	operator*() const;
		pointer		operator->() const;
		reference	operator[](difference_type n) const;

		// Increment and Decrement
		ReverseIterator&	operator++();
		ReverseIterator		operator++(int);
		ReverseIterator&	operator--();
		ReverseIterator		operator--(int);

		// Arithmetic
		ReverseIterator		operator+(difference_type n) const;
		ReverseIterator		operator-(difference_type n) const;

		// Assignment arithmetic
		ReverseIterator&	operator+=(difference_type n);
		ReverseIterator&	operator-=(difference_type n);
};



// Constructors
template < class Iterator >
ReverseIterator<Iterator>::ReverseIterator() : _base(NULL)
{
}

template < class Iterator >
ReverseIterator<Iterator>::ReverseIterator(iterator_type it) : _base(it)
{
}

template < class Iterator >
ReverseIterator<Iterator>::ReverseIterator(ReverseIterator<Iterator>& rev_it) : _base(rev_it.base())
{
}

template < class Iterator >
template < class is_const >
ReverseIterator<Iterator>::ReverseIterator(const ReverseIterator<is_const>& rev_it) : _base(rev_it.base())
{
}



// Access element
template < class Iterator >
Iterator	ReverseIterator<Iterator>::base() const
{
	return Iterator(_base);
}



// Dereference
template < class Iterator >
typename ReverseIterator<Iterator>::reference	ReverseIterator<Iterator>::operator*() const
{
	return (*(_base - 1));
}

template < class Iterator >
typename ReverseIterator<Iterator>::pointer	ReverseIterator<Iterator>::operator->() const
{
	return &(operator*());
}

template < class Iterator >
typename ReverseIterator<Iterator>::reference	ReverseIterator<Iterator>::operator[](difference_type n) const
{
	return (_base[-n - 1]);
}



// Increment and Decrement
template < class Iterator >
ReverseIterator<Iterator>&		ReverseIterator<Iterator>::operator++()
{
	return (--_base);
}

template < class Iterator >
ReverseIterator<Iterator>		ReverseIterator<Iterator>::operator++(int)
{
	ReverseIterator	tmp(*this);
	--(*this);
	return (tmp);
}

template < class Iterator >
ReverseIterator<Iterator>&		ReverseIterator<Iterator>::operator--()
{
	return (++_base);
}

template < class Iterator >
ReverseIterator<Iterator>		ReverseIterator<Iterator>::operator--(int)
{
	ReverseIterator	tmp(*this);
	--(*this);
	return (tmp);
}



// Arithmetic
template < class Iterator >
ReverseIterator<Iterator>	ReverseIterator<Iterator>::operator+(difference_type n) const
{
	return ReverseIterator(_base - n);
}

template < class Iterator >
ReverseIterator<Iterator>	ReverseIterator<Iterator>::operator-(difference_type n) const
{
	return ReverseIterator(_base + n);
}



// Assignment arithmetic
template < class Iterator >
ReverseIterator<Iterator>&	ReverseIterator<Iterator>::operator+=(difference_type n)
{
	_base -= n;
	return (*this);
}

template < class Iterator >
ReverseIterator<Iterator>&	ReverseIterator<Iterator>::operator-=(difference_type n)
{
	_base += n;
	return (*this);
}



// Non member functions
template < class Iterator >
bool	operator==(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
{
	if (lhs.base() == rhs.base())
		return (true);
	else
		return (false);
}

template < class Iterator >
bool	operator!=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
{
	if (!(lhs == rhs))
		return (true);
	else
		return (false);
}

template < class Iterator >
bool	operator<(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
{
	if (lhs.base() > rhs.base())
		return (true);
	else
		return (false);
}

template < class Iterator >
bool	operator<=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return (true);
	else
		return (false);
}

template < class Iterator >
bool	operator>(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
{
	if (!(rhs < lhs) && lhs != rhs)
		return (true);
	else
		return (false);
}

template < class Iterator >
bool	operator>=(const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
{
	if (lhs > rhs || lhs == rhs)
		return (true);
	else
		return (false);
}

template < class Iterator >
ReverseIterator<Iterator>	operator+(typename ReverseIterator<Iterator>::difference_type n, const ReverseIterator<Iterator>& rev_it)
{
	return ReverseIterator<Iterator>(rev_it - n);
}

template < class Iterator >
ReverseIterator<Iterator>	operator-(typename ReverseIterator<Iterator>::difference_type n, const ReverseIterator<Iterator>& rev_it)
{
	return ReverseIterator<Iterator>(rev_it + n);
}

}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:20:33 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/10 16:25:27 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

namespace ft
{

template < class Iterator >
class reverse_iterator
{
	public:
		typedef Iterator								iterator_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::iterator_category	iterator_category;

	protected:
		Iterator	_it;

	public:
		// Constructors
		reverse_iterator();
		explicit reverse_iterator(iterator_type it);
		reverse_iterator(const reverse_iterator<Iterator>& rev_it);
		Iterator	base() const;

		// Dereference
		reference	operator*() const;
		pointer		operator->() const;
		reference	operator[](difference_type n) const;

		// Increment and Decrement
		reverse_iterator&	operator++();
		reverse_iterator	operator++(int);
		reverse_iterator&	operator--();
		reverse_iterator	operator--(int);

		// Arithmetic
		reverse_iterator	operator+(difference_type n) const;
		reverse_iterator	operator-(difference_type n) const;

		// Assignment arithmetic
		reverse_iterator&	operator+=(difference_type n);
		reverse_iterator&	operator-=(difference_type n);
};



// Constructors
template < class Iterator >
reverse_iterator<Iterator>::reverse_iterator() : _it(NULL)
{
}

template < class Iterator >
reverse_iterator<Iterator>::reverse_iterator(iterator_type it) : _it(it)
{
}

template < class Iterator >
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iterator>& rev_it) : _it(rev_it._it)
{
}

template < class Iterator >
Iterator	reverse_iterator<Iterator>::base() const
{
	return Iterator(_it);
}



// Dereference
template < class Iterator >
typename reverse_iterator<Iterator>::reference	reverse_iterator<Iterator>::operator*() const
{
	return (*(_it - 1));
}

template < class Iterator >
typename reverse_iterator<Iterator>::pointer	reverse_iterator<Iterator>::operator->() const
{
	return (_it - 1);
}

template < class Iterator >
typename reverse_iterator<Iterator>::reference	reverse_iterator<Iterator>::operator[](difference_type n) const
{
	return (_it[n - 1]);
}



// Increment and Decrement
template < class Iterator >
reverse_iterator<Iterator>&		reverse_iterator<Iterator>::operator++()
{
	return (--_it);
}

template < class Iterator >
reverse_iterator<Iterator>		reverse_iterator<Iterator>::operator++(int)
{
	reverse_iterator	tmp(*this);
	--(*this);
	return (tmp);
}

template < class Iterator >
reverse_iterator<Iterator>&		reverse_iterator<Iterator>::operator--()
{
	return (++_it);
}

template < class Iterator >
reverse_iterator<Iterator>		reverse_iterator<Iterator>::operator--(int)
{
	reverse_iterator	tmp(*this);
	--(*this);
	return (tmp);
}



// Arithmetic
template < class Iterator >
reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator+(difference_type n) const
{
	return reverse_iterator(_it - n);
}

template < class Iterator >
reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator-(difference_type n) const
{
	return reverse_iterator(_it + n);
}



// Assignment arithmetic
template < class Iterator >
reverse_iterator<Iterator>&	reverse_iterator<Iterator>::operator+=(difference_type n)
{
	_it - n;
	return (*this);
}

template < class Iterator >
reverse_iterator<Iterator>&	reverse_iterator<Iterator>::operator-=(difference_type n)
{
	_it + n;
	return (*this);
}



// Non member functions
template < class Iterator >
bool	operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	if (lhs.base() == rhs.base())
		return (true);
	else
		return (false);
}

template < class Iterator >
bool	operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	if (!(lhs == rhs))
		return (true);
	else
		return (false);
}

template < class Iterator >
bool	operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	if (lhs.base() > rhs.base() && lhs != rhs)
		return (true);
	else
		return (false);
}

template < class Iterator >
bool	operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return (true);
	else
		return (false);
}

template < class Iterator >
bool	operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	if (!(rhs < lhs))
		return (true);
	else
		return (false);
}

template < class Iterator >
bool	operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	if (lhs > rhs || lhs == rhs)
		return (true);
	else
		return (false);
}

template < class Iterator >
reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
{
	return reverse_iterator<Iterator>(rev_it - n);
}

template < class Iterator >
reverse_iterator<Iterator>	operator-(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
{
	return reverse_iterator<Iterator>(rev_it + n);
}
}

#endif
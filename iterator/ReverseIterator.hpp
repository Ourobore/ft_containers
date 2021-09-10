/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:20:33 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/10 12:46:51 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

template < class Iterator >
class reverse_iterator
{
	public:
		typedef Iterator					iterator_type;
		typedef Iterator::value_type		value_type;
		typedef Iterator::reference			reference;
		typedef Iterator::pointer			pointer;
		typedef Iterator::difference_type	difference_type;
		typedef Iterator::iterator_category	iterator_category;

	protected:
		Iterator	_it;

	public:
		// Constructors
		reverse_iterator();
		explicit reverse_iterator(iterator_type it);
		template < class Iterator >
		reverse_iterator(const reverse_iterator<Iterator>& rev_it);

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

#endif
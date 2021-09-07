/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BidirectionalIterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:29:30 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/07 10:36:10 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP

template <typename T>
class BidirectionalIterator : class InputIterator
{
	public:
		typedef T					value_type;
		typedef value_type&			reference;
		typedef const value_type&	const_reference;
		typedef value_type*			pointer;
		typedef std::ptrdiff_t		difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;

		// Constructors, assignation and destructor
		BidirectionalIterator();
};

#endif
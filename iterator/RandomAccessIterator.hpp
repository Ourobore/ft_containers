/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:43:35 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/03 15:04:15 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

template <typename T>
class RandomAccessIterator
{
	public:
		typedef T				value_type;
		typedef value_type&		reference;
		typedef value_type*		pointer;
		typedef std::ptrdiff	difference_type;
		typedef std::random_access_iterator_tag	iterator_category;

	protected:
		pointer	_it;

	public:
		
};

#endif
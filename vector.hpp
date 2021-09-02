/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:24:09 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/02 17:23:54 by lchapren         ###   ########.fr       */
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
			typedef std::ptrdiff_t			difference_type;
			typedef std::size_t				size_type;

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
			explicit	vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc)
			{
				_c = _alloc.allocate(0);
			}
			explicit	vector(size_type n, const_reference val = value_type(),
								const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc)
			{
				_c = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(&_c[i], val);
					std::cout << _c[i] << std::endl;
				}			
			}
	};
}

#endif

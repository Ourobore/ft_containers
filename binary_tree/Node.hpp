/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:20:55 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/12 14:36:45 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template < class T, class Allocator = std::allocator<T> >
class Node
{
  public:
    typedef T         value_type;
    typedef Allocator allocator_type;

    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;

    typedef std::size_t size_type;

  private:
    value_type     _data;
    pointer        _left;
    pointer        _right;
    allocator_type _alloc;

  public:
    // Constructors and Destructor
    Node(const allocator_type& allocator = allocator_type());
    ~Node();

    // Element access
    reference data();
    pointer   left();
    pointer   right();

    // Allocator
    allocator_type get_allocator() const;
    size_type      max_size() const;
};
// Constructors and Destructor
template <class T, class Allocator>
Node<T, Allocator>::Node(const allocator_type& allocator)
    : _data(NULL), _left(NULL), _right(NULL), _alloc(allocator)
{
}

template <class T, class Allocator>
Node<T, Allocator>::~Node()
{
}

// Element access
template <class T, class Allocator>
typename Node<T, Allocator>::reference Node<T, Allocator>::data()
{
    return (_data);
}

template <class T, class Allocator>
typename Node<T, Allocator>::pointer Node<T, Allocator>::left()
{
    return (_left);
}

template <class T, class Allocator>
typename Node<T, Allocator>::pointer Node<T, Allocator>::right()
{
    return (_right);
}

// Allocator
template <class T, class Allocator>
typename Node<T, Allocator>::allocator_type Node<T, Allocator>::get_allocator() const
{
    return (_alloc);
}

template <class T, class Allocator>
typename Node<T, Allocator>::size_type Node<T, Allocator>::max_size() const
{
    return (_alloc.max_size());
}

#endif
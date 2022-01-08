/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lena <lena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:20:55 by lchapren          #+#    #+#             */
/*   Updated: 2022/01/08 09:37:03 by lena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

#include "BaseNode.hpp"

namespace ft
{

template < class T >
class Node : public BaseNode< Node<T>, T >
{
  public:
    typedef T                 value_type;
    typedef value_type&       reference;
    typedef const value_type& const_reference;
    typedef value_type*       pointer;
    typedef const value_type* const_pointer;

    typedef std::size_t size_type;

  protected:
    value_type _data;

  public:
    // Constructors and Destructor
    Node();
    Node(const_reference value);
    template < class N >
    Node(Node< N >* rhs);
    template < class N >
    Node(const Node< N >& rhs);
    Node& operator=(const Node& rhs);
    ~Node();

    // Element access
    reference data();

    // Modifiers
    void set_data(const_reference value);
};

// Constructors and Destructor
template < class T >
Node< T >::Node()
    : BaseNode<Node, T>(), _data(value_type())
{
}

template < class T >
Node< T >::Node(const_reference value)
    : BaseNode<Node, T>(), _data(value)
{
}

template < class T >
template < class N >
Node< T >::Node(Node< N >* rhs)
    : BaseNode<Node, T>(rhs), _data(rhs->data())
{
}

template < class T >
template < class N >
Node< T >::Node(const Node< N >& rhs)
    : BaseNode<Node, T>(rhs), _data(rhs.data())
{
}

template < class T >
Node< T >& Node< T >::operator=(const Node< T >& rhs)
{
    if (this != &rhs)
    {
        _data = rhs.data();
        this->parent() = rhs.parent();
        this->parent() = rhs.left();
        this->parent() = rhs.right();
    }
    return (*this);
}

template < class T >
Node< T >::~Node()
{
    // _data = value_type();
}

// Element access
template < class T >
typename Node< T >::reference Node< T >::data()
{
    return (_data);
}

// Modifiers
template < class T >
void Node< T >::set_data(const_reference value)
{
    _data = value;
}

} // namespace ft

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:20:55 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/12 17:39:01 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

namespace ft
{

template < class T >
class Node
{
  public:
    typedef T value_type;

    typedef T&       reference;
    typedef const T& const_reference;
    typedef T*       pointer;
    typedef const T* const_pointer;

    typedef std::size_t size_type;

  private:
    value_type _data;
    Node*      _left;
    Node*      _right;

  public:
    // Constructors and Destructor
    Node();
    Node(const_reference value);
    ~Node();

    // Element access
    reference data();
    Node*     left();
    Node*     right();

    // Modifiers
    void set_data(const_reference value);
    void set_left(Node* left);
    void set_right(Node* right);
};

// Constructors and Destructor
template <class T>
Node<T>::Node()
    : _data(value_type()), _left(NULL), _right(NULL)
{
}

template <class T>
Node<T>::Node(const_reference value)
    : _data(value), _left(NULL), _right(NULL)
{
}

template <class T>
Node<T>::~Node()
{
}

// Element access
template <class T>
typename Node<T>::reference Node<T>::data()
{
    return (_data);
}

template <class T>
Node<T>* Node<T>::left()
{
    return (_left);
}

template <class T>
Node<T>* Node<T>::right()
{
    return (_right);
}

// Modifiers
template <class T>
void Node<T>::set_data(const_reference value)
{
    _data = value;
}

template <class T>
void Node<T>::set_left(Node* left)
{
    _left = left;
}

template <class T>
void Node<T>::set_right(Node* right)
{
    _right = right;
}

} // namespace ft

#endif
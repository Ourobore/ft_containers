/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:39:06 by lena              #+#    #+#             */
/*   Updated: 2022/01/11 16:27:43 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
#define RBNODE_HPP

#include "BaseNode.hpp"

namespace ft
{

template < class T >
class RBNode : public BaseNode< RBNode<T>, T >
{
  public:
    typedef T                 value_type;
    typedef value_type&       reference;
    typedef const value_type& const_reference;
    typedef value_type*       pointer;
    typedef const value_type* const_pointer;

    typedef std::size_t size_type;

  protected:
    enum RBColor
    {
        red,
        black
    };

    value_type _data;
    RBColor    _color;

  public:
    // Constructors and Destructor
    RBNode();
    RBNode(const_reference value, RBColor color = red);
    template < class N >
    RBNode(RBNode< N >* rhs);
    template < class N >
    RBNode(const RBNode< N >& rhs);
    RBNode& operator=(const RBNode& rhs);
    ~RBNode();

    // Element access
    reference data();
    RBColor   color() const;

    // Modifiers
    void set_data(const_reference value);
    void set_color(RBColor color);

    // Utility
    RBNode<T> auntie() const;
    RBNode<T> grandparent() const;
    size_type black_height() const;
};

// Constructors and Destructor
template < class T >
RBNode< T >::RBNode()
    : BaseNode<RBNode, T>(), _data(value_type()), _color(red)
{
}

template < class T >
RBNode< T >::RBNode(const_reference value, RBColor color)
    : BaseNode<RBNode, T>(), _data(value), _color(color)
{
}

template < class T >
template < class N >
RBNode< T >::RBNode(RBNode< N >* rhs)
    : BaseNode<RBNode, T>(rhs), _data(rhs->data())
{
}

template < class T >
template < class N >
RBNode< T >::RBNode(const RBNode< N >& rhs)
    : BaseNode<RBNode, T>(rhs), _data(rhs.data())
{
}

template < class T >
RBNode< T >& RBNode< T >::operator=(const RBNode< T >& rhs)
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
RBNode< T >::~RBNode()
{
    // _data = value_type();
}

// Element access
template < class T >
typename RBNode< T >::reference RBNode< T >::data()
{
    return (_data);
}

template < class T >
typename RBNode<T>::RBColor RBNode<T>::color() const
{
    return (_color);
}

// Modifiers
template < class T >
void RBNode< T >::set_data(const_reference value)
{
    _data = value;
}

template < class T >
void RBNode< T >::set_color(RBColor color)
{
    _color = color;
}

// Utility
template < class T >
RBNode< T > RBNode< T >::auntie() const
{
    RBNode* parent = NULL;
    RBNode* grandparent = NULL;
    RBNode* auntie = NULL;

    if (this->parent())
        parent = this->parent();

    if (parent && parent->parent())
        grandparent = parent->parent();

    if (grandparent)
    {
        if (grandparent->left() && grandparent->left() == parent)
            auntie = grandparent->right();
        else
            auntie = grandparent->left();
    }

    return (auntie);
}

template < class T >
RBNode< T > RBNode< T >::grandparent() const
{
    RBNode* parent = NULL;
    RBNode* grandparent = NULL;

    if (this->parent())
        parent = this->parent();
    if (parent && parent->parent())
        grandparent = parent->parent();

    return (grandparent);
}

template < class T >
typename RBNode< T >::size_type RBNode< T >::black_height() const
{
    RBNode* node_pointer = this;
    if (!node_pointer || !node_pointer->left() || !node_pointer->right())
        return (0);

    size_type black_height = 0;
    node_pointer = node_pointer->left();
    while (node_pointer)
    {
        if (node_pointer->color() == black)
            ++black_height;
        node_pointer = node_pointer->left();
    }
    ++black_height; // NIL node is counted

    return (black_height);
}

} // namespace ft

#endif
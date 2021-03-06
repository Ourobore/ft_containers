/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:39:06 by lena              #+#    #+#             */
/*   Updated: 2022/01/31 15:16:45 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
#define RBNODE_HPP

#include "BaseNode.hpp"

namespace ft
{

template < class T, class Compare = std::less<T> >
class RBNode : public BaseNode< RBNode<T, Compare>, T >
{
  public:
    typedef T                 value_type;
    typedef value_type&       reference;
    typedef const value_type& const_reference;
    typedef value_type*       pointer;
    typedef const value_type* const_pointer;

    typedef std::size_t size_type;

    enum RBColor
    {
        red = false,
        black = true
    };

  protected:
    value_type _data;
    Compare    _comp;
    RBColor    _color;

  public:
    // Constructors and Destructor
    RBNode(const Compare& comp = Compare());
    RBNode(const_reference value, const Compare& comp = Compare(), RBColor color = red);
    template < class N >
    RBNode(RBNode< N, Compare >* rhs);
    template < class N >
    RBNode(const RBNode< N, Compare >& rhs);
    RBNode& operator=(const RBNode& rhs);
    ~RBNode();

    // Relational
    bool operator==(const RBNode<T, Compare>& rhs) const;
    bool operator!=(const RBNode<T, Compare>& rhs) const;
    bool operator<(const RBNode<T, Compare>& rhs) const;
    bool operator>(const RBNode<T, Compare>& rhs) const;
    bool operator<=(const RBNode<T, Compare>& rhs) const;
    bool operator>=(const RBNode<T, Compare>& rhs) const;

    // Element access
    reference data();
    Compare&  compare();
    RBColor   color() const;

    // Modifiers
    void set_data(const_reference value);
    void set_color(RBColor color);

    // Utility
    size_type black_height() const;
};

// Constructors and Destructor
template < class T, class Compare >
RBNode< T, Compare >::RBNode(const Compare& comp)
    : BaseNode<RBNode, T>(), _data(value_type()), _comp(comp), _color(red)
{
}

template < class T, class Compare >
RBNode< T, Compare >::RBNode(const_reference value, const Compare& comp, RBColor color)
    : BaseNode<RBNode, T>(), _data(value), _comp(comp), _color(color)
{
}

template < class T, class Compare >
template < class N>
RBNode< T, Compare >::RBNode(RBNode< N, Compare >* rhs)
    : BaseNode<RBNode, T>(rhs), _data(rhs->data()), _comp(rhs->compare()), _color(rhs->color())
{
}

template < class T, class Compare >
template < class N >
RBNode< T, Compare >::RBNode(const RBNode< N, Compare >& rhs)
    : BaseNode<RBNode, T>(rhs), _data(rhs.data()), _comp(rhs.compare()), _color(rhs.color())
{
}

template < class T, class Compare >
RBNode< T, Compare >& RBNode< T, Compare >::operator=(const RBNode& rhs)
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

template < class T, class Compare >
RBNode< T, Compare >::~RBNode()
{
    // _data = value_type();
}

// Element access
template < class T, class Compare >
typename RBNode< T, Compare >::reference RBNode< T, Compare >::data()
{
    return (_data);
}

template < class T, class Compare >
Compare& RBNode< T, Compare >::compare()
{
    return (_comp);
}

template < class T, class Compare >
typename RBNode< T, Compare >::RBColor RBNode<T, Compare>::color() const
{
    return (_color);
}

// Modifiers
template < class T, class Compare >
void RBNode< T, Compare >::set_data(const_reference value)
{
    _data = value;
}

template < class T, class Compare >
void RBNode< T, Compare >::set_color(RBColor color)
{
    _color = color;
}

// Utility
template < class T, class Compare >
typename RBNode< T, Compare >::size_type RBNode< T, Compare >::black_height() const
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

// Relational
template < class T, class Compare >
bool RBNode< T, Compare >::operator==(const RBNode<T, Compare>& rhs) const
{
    return (!_comp(_data, rhs._data) && !_comp(rhs._data, _data));
}

template < class T, class Compare >
bool RBNode< T, Compare >::operator!=(const RBNode<T, Compare>& rhs) const
{
    return !(*this == rhs);
}

template < class T, class Compare >
bool RBNode< T, Compare >::operator<(const RBNode<T, Compare>& rhs) const
{
    return (_comp(this->_data, rhs._data));
}

template < class T, class Compare >
bool RBNode< T, Compare >::operator>(const RBNode<T, Compare>& rhs) const
{
    return (!(*this < rhs) && *this != rhs);
}

template < class T, class Compare >
bool RBNode< T, Compare >::operator<=(const RBNode<T, Compare>& rhs) const
{
    return (*this < rhs || *this == rhs);
}

template < class T, class Compare >
bool RBNode< T, Compare >::operator>=(const RBNode<T, Compare>& rhs) const
{
    return (!(*this < rhs));
}

} // namespace ft

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNodePair.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:03:37 by lchapren          #+#    #+#             */
/*   Updated: 2022/01/31 11:06:43 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODEPAIR_HPP
#define RBNODEPAIR_HPP

#include "BaseNode.hpp"

namespace ft
{

template < class T, class Compare = std::less<T> >
class RBNodePair : public BaseNode< RBNodePair<T, Compare>, T >
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
    RBNodePair(const Compare& comp = Compare());
    RBNodePair(const_reference value, const Compare& comp = Compare(), RBColor color = red);
    template < class N >
    RBNodePair(RBNodePair< N, Compare >* rhs);
    template < class N >
    RBNodePair(const RBNodePair< N, Compare >& rhs);
    RBNodePair& operator=(const RBNodePair& rhs);
    ~RBNodePair();

    // Relational
    bool operator==(const RBNodePair<T, Compare>& rhs) const;
    bool operator!=(const RBNodePair<T, Compare>& rhs) const;
    bool operator<(const RBNodePair<T, Compare>& rhs) const;
    bool operator>(const RBNodePair<T, Compare>& rhs) const;
    bool operator<=(const RBNodePair<T, Compare>& rhs) const;
    bool operator>=(const RBNodePair<T, Compare>& rhs) const;

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
RBNodePair< T, Compare >::RBNodePair(const Compare& comp)
    : BaseNode<RBNodePair, T>(), _data(value_type()), _comp(comp), _color(red)
{
}

template < class T, class Compare >
RBNodePair< T, Compare >::RBNodePair(const_reference value, const Compare& comp, RBColor color)
    : BaseNode<RBNodePair, T>(), _data(value), _comp(comp), _color(color)
{
}

template < class T, class Compare >
template < class N>
RBNodePair< T, Compare >::RBNodePair(RBNodePair< N, Compare >* rhs)
    : BaseNode<RBNodePair, T>(rhs), _data(rhs->data()), _comp(rhs->compare()), _color(rhs->color())
{
}

template < class T, class Compare >
template < class N >
RBNodePair< T, Compare >::RBNodePair(const RBNodePair< N, Compare >& rhs)
    : BaseNode<RBNodePair, T>(rhs), _data(rhs.data()), _comp(rhs.compare()), _color(rhs.color())
{
}

template < class T, class Compare >
RBNodePair< T, Compare >& RBNodePair< T, Compare >::operator=(const RBNodePair& rhs)
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
RBNodePair< T, Compare >::~RBNodePair()
{
    // _data = value_type();
}

// Element access
template < class T, class Compare >
typename RBNodePair< T, Compare >::reference RBNodePair< T, Compare >::data()
{
    return (_data);
}

template < class T, class Compare >
Compare& RBNodePair< T, Compare >::compare()
{
    return (_comp);
}

template < class T, class Compare >
typename RBNodePair< T, Compare >::RBColor RBNodePair<T, Compare>::color() const
{
    return (_color);
}

// Modifiers
template < class T, class Compare >
void RBNodePair< T, Compare >::set_data(const_reference value)
{
    _data = value;
}

template < class T, class Compare >
void RBNodePair< T, Compare >::set_color(RBColor color)
{
    _color = color;
}

// Utility
template < class T, class Compare >
typename RBNodePair< T, Compare >::size_type RBNodePair< T, Compare >::black_height() const
{
    RBNodePair* node_pointer = this;
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
bool RBNodePair< T, Compare >::operator==(const RBNodePair<T, Compare>& rhs) const
{
    return (!_comp(_data.first, rhs._data.first) && !_comp(rhs._data.first, _data.first));
}

template < class T, class Compare >
bool RBNodePair< T, Compare >::operator!=(const RBNodePair<T, Compare>& rhs) const
{
    return !(*this == rhs);
}

template < class T, class Compare >
bool RBNodePair< T, Compare >::operator<(const RBNodePair<T, Compare>& rhs) const
{
    return (_comp(this->_data.first, rhs._data.first));
}

template < class T, class Compare >
bool RBNodePair< T, Compare >::operator>(const RBNodePair<T, Compare>& rhs) const
{
    return (!(*this < rhs) && *this != rhs);
}

template < class T, class Compare >
bool RBNodePair< T, Compare >::operator<=(const RBNodePair<T, Compare>& rhs) const
{
    return (*this < rhs || *this == rhs);
}

template < class T, class Compare >
bool RBNodePair< T, Compare >::operator>=(const RBNodePair<T, Compare>& rhs) const
{
    return (!(*this < rhs));
}

} // namespace ft

#endif
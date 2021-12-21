/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BidirectionalIterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:29:30 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/21 17:43:38 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
#define BIDIRECTIONALITERATOR_HPP

#include <iostream>

#include "utils/EnableIf.hpp"
#include "utils/IteratorType.hpp"

namespace ft
{

template <typename T, bool IsConst>
class BidirectionalIterator
{
  public:
    typedef typename iterator_type<IsConst, T, const T>::type value_type;
    typedef value_type&                                       reference;
    typedef const value_type&                                 const_reference;
    typedef value_type*                                       pointer;
    typedef std::ptrdiff_t                                    difference_type;
    typedef std::bidirectional_iterator_tag                   iterator_category;

  protected:
    pointer _it;

  public:
    // Constructors, assignation and destructor
    BidirectionalIterator();
    BidirectionalIterator(pointer p);
    template <bool is_const>
    BidirectionalIterator(const BidirectionalIterator<T, is_const>& rhs, typename enable_if<!is_const, T>::type* = 0);
    BidirectionalIterator& operator=(const BidirectionalIterator& rhs);
    virtual ~BidirectionalIterator();

    // Equivalence
    bool operator==(const BidirectionalIterator& rhs) const;
    bool operator!=(const BidirectionalIterator& rhs) const;

    // Dereference
    reference operator*();
    pointer   operator->();

    // Increment and Decrement
    BidirectionalIterator& operator++();
    BidirectionalIterator  operator++(int);
    BidirectionalIterator& operator--();
    BidirectionalIterator  operator--(int);

    pointer getPointer() const;
};

// Constructors and destructor
template <typename T, bool IsConst>
BidirectionalIterator<T, IsConst>::BidirectionalIterator()
    : _it(NULL)
{
}

template <typename T, bool IsConst>
BidirectionalIterator<T, IsConst>::BidirectionalIterator(pointer p)
    : _it(p)
{
}

template <typename T, bool IsConst>
template <bool is_const>
BidirectionalIterator<T, IsConst>::BidirectionalIterator(const BidirectionalIterator<T, is_const>& rhs, typename enable_if<!is_const, T>::type*)
    : _it(rhs.getPointer())
{
}

template <typename T, bool IsConst>
BidirectionalIterator<T, IsConst>& BidirectionalIterator<T, IsConst>::operator=(const BidirectionalIterator& rhs)
{
    if (this != &rhs)
        _it = rhs._it;
    return (*this);
}

template <typename T, bool IsConst>
BidirectionalIterator<T, IsConst>::~BidirectionalIterator()
{
    _it = NULL;
}

// Equivalence
template <typename T, bool IsConst>
bool BidirectionalIterator<T, IsConst>::operator==(const BidirectionalIterator<T, IsConst>& rhs) const
{
    return (_it == rhs._it);
}

template <typename T, bool IsConst>
bool BidirectionalIterator<T, IsConst>::operator!=(const BidirectionalIterator<T, IsConst>& rhs) const
{
    return !(*this == rhs);
}

// Dereference
template <typename T, bool IsConst>
typename BidirectionalIterator<T, IsConst>::reference BidirectionalIterator<T, IsConst>::operator*()
{
    return (*_it);
}

template <typename T, bool IsConst>
typename BidirectionalIterator<T, IsConst>::pointer BidirectionalIterator<T, IsConst>::operator->()
{
    return (_it);
}

// Increment and Decrement
template <typename T, bool IsConst>
BidirectionalIterator<T, IsConst>& BidirectionalIterator<T, IsConst>::operator++()
{
    _it += 1;
    return (*this);
}

template <typename T, bool IsConst>
BidirectionalIterator<T, IsConst> BidirectionalIterator<T, IsConst>::operator++(int)
{
    BidirectionalIterator<T, IsConst> tmp(*this);
    ++_it;
    return (tmp);
}

template <typename T, bool IsConst>
BidirectionalIterator<T, IsConst>& BidirectionalIterator<T, IsConst>::operator--()
{
    _it -= 1;
    return (*this);
}

template <typename T, bool IsConst>
BidirectionalIterator<T, IsConst> BidirectionalIterator<T, IsConst>::operator--(int)
{
    BidirectionalIterator<T, IsConst> tmp(*this);
    --_it;
    return (tmp);
}

// Access
template < class T, bool IsConst >
typename BidirectionalIterator<T, IsConst>::pointer BidirectionalIterator<T, IsConst>::getPointer() const
{
    return (_it);
}

} // namespace ft

#endif

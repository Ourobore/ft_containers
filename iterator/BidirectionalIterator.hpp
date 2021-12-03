/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BidirectionalIterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:29:30 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/03 13:35:33 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
#define BIDIRECTIONALITERATOR_HPP

#include <iostream>

namespace ft
{

template <typename T>
class BidirectionalIterator
{
  public:
    typedef T                               value_type;
    typedef value_type&                     reference;
    typedef const value_type&               const_reference;
    typedef value_type*                     pointer;
    typedef std::ptrdiff_t                  difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

  protected:
    pointer _it;

  public:
    // Constructors, assignation and destructor
    BidirectionalIterator();
    BidirectionalIterator(pointer p);
    BidirectionalIterator(const BidirectionalIterator& rhs);
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
};

// Constructors and destructor
template <typename T>
BidirectionalIterator<T>::BidirectionalIterator()
    : _it(NULL)
{
}

template <typename T>
BidirectionalIterator<T>::BidirectionalIterator(pointer p)
    : _it(p)
{
}

template <typename T>
BidirectionalIterator<T>::BidirectionalIterator(const BidirectionalIterator& rhs)
    : _it(rhs._it)
{
}

template <typename T>
BidirectionalIterator<T>& BidirectionalIterator<T>::operator=(const BidirectionalIterator& rhs)
{
    if (this != &rhs)
        _it = rhs._it;
    return (*this);
}

template <typename T>
BidirectionalIterator<T>::~BidirectionalIterator()
{
    _it = NULL;
}

// Equivalence
template <typename T>
bool BidirectionalIterator<T>::operator==(const BidirectionalIterator<T>& rhs) const
{
    return (_it == rhs._it);
}

template <typename T>
bool BidirectionalIterator<T>::operator!=(const BidirectionalIterator<T>& rhs) const
{
    return !(*this == rhs);
}

// Dereference
template <typename T>
typename BidirectionalIterator<T>::reference BidirectionalIterator<T>::operator*()
{
    return (*_it);
}

template <typename T>
typename BidirectionalIterator<T>::pointer BidirectionalIterator<T>::operator->()
{
    return (_it);
}

// Increment and Decrement
template <typename T>
BidirectionalIterator<T>& BidirectionalIterator<T>::operator++()
{
    _it += 1;
    return (*this);
}

template <typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator++(int)
{
    BidirectionalIterator<T> tmp(*this);
    ++_it;
    return (tmp);
}

template <typename T>
BidirectionalIterator<T>& BidirectionalIterator<T>::operator--()
{
    _it -= 1;
    return (*this);
}

template <typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator--(int)
{
    BidirectionalIterator<T> tmp(*this);
    --_it;
    return (tmp);
}

} // namespace ft

#endif
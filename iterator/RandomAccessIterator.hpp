/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:43:35 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/03 14:05:42 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include <iostream>

//# include "../utils/IsConst.hpp"
#include "../utils/EnableIf.hpp"
#include "../utils/IteratorType.hpp"

namespace ft
{

template < class T, bool IsConst >
class RandomAccessIterator
{
  public:
    typedef typename iterator_type<IsConst, const T, T>::type value_type;
    typedef value_type&                                       reference;
    typedef const value_type&                                 const_reference;
    typedef value_type*                                       pointer;
    typedef std::ptrdiff_t                                    difference_type;
    typedef std::random_access_iterator_tag                   iterator_category;

  protected:
    pointer _it;

  public:
    // Constructors, assignation and destructor
    RandomAccessIterator();
    RandomAccessIterator(pointer p);
    template <bool is_const>
    RandomAccessIterator(const RandomAccessIterator<T, is_const>& rhs, typename enable_if<!is_const, T>::type* = 0)
    {
        _it = rhs.getPointer();
    }
    // RandomAccessIterator(const RandomAccessIterator& rhs);
    RandomAccessIterator& operator=(const RandomAccessIterator& rhs);
    virtual ~RandomAccessIterator();

    // Access
    pointer getPointer() const;

    // Equivalence
    template < bool is_const >
    bool operator==(const RandomAccessIterator<T, is_const>& rhs) const;
    template < bool is_const >
    bool operator!=(const RandomAccessIterator<T, is_const>& rhs) const;

    // Dereference
    reference operator*();
    pointer   operator->();
    reference operator[](difference_type n);

    // Increment and Decrement
    RandomAccessIterator& operator++();
    RandomAccessIterator  operator++(int);
    RandomAccessIterator& operator--();
    RandomAccessIterator  operator--(int);

    // Arithmetic
    RandomAccessIterator operator+(difference_type n) const;
    RandomAccessIterator operator-(difference_type n) const;
    template < bool is_const >
    difference_type operator-(const RandomAccessIterator<T, is_const>& rhs) const;

    // Relational
    template < bool is_const >
    bool operator<(const RandomAccessIterator<T, is_const>& rhs) const;
    template < bool is_const >
    bool operator>(const RandomAccessIterator<T, is_const>& rhs) const;
    template < bool is_const >
    bool operator<=(const RandomAccessIterator<T, is_const>& rhs) const;
    template < bool is_const >
    bool operator>=(const RandomAccessIterator<T, is_const>& rhs) const;

    // Assignment arithmetic
    RandomAccessIterator& operator+=(difference_type n);
    RandomAccessIterator& operator-=(difference_type n);
};

// Constructors and destructor
template < class T, bool IsConst >
RandomAccessIterator<T, IsConst>::RandomAccessIterator()
    : _it(NULL)
{
}

template < class T, bool IsConst >
RandomAccessIterator<T, IsConst>::RandomAccessIterator(pointer p)
    : _it(p)
{
}

/*
template < class T, bool IsConst >
RandomAccessIterator<T, IsConst>::RandomAccessIterator(const RandomAccessIterator& rhs) : _it(rhs._it)
{
}
*/

template < class T, bool IsConst >
RandomAccessIterator<T, IsConst>& RandomAccessIterator<T, IsConst>::operator=(const RandomAccessIterator& rhs)
{
    if (this != &rhs)
        _it = rhs._it;
    return (*this);
}

template < class T, bool IsConst >
RandomAccessIterator<T, IsConst>::~RandomAccessIterator()
{
    _it = NULL;
}

// Access
template < class T, bool IsConst >
typename RandomAccessIterator<T, IsConst>::pointer RandomAccessIterator<T, IsConst>::getPointer() const
{
    return (_it);
}

// Equivalence
template < class T, bool IsConst >
template < bool is_const >
bool RandomAccessIterator<T, IsConst>::operator==(const RandomAccessIterator<T, is_const>& rhs) const
{
    return (_it == rhs.getPointer());
}

template < class T, bool IsConst >
template < bool is_const >
bool RandomAccessIterator<T, IsConst>::operator!=(const RandomAccessIterator<T, is_const>& rhs) const
{
    return !(*this == rhs);
}

// Dereference
template < class T, bool IsConst >
typename RandomAccessIterator<T, IsConst>::reference RandomAccessIterator<T, IsConst>::operator*()
{
    return (*_it);
}

template < class T, bool IsConst >
typename RandomAccessIterator<T, IsConst>::pointer RandomAccessIterator<T, IsConst>::operator->()
{
    return (_it);
}

template < class T, bool IsConst >
typename RandomAccessIterator<T, IsConst>::reference RandomAccessIterator<T, IsConst>::operator[](difference_type n)
{
    return (_it[n]);
}

// Increment and Decrement
template < class T, bool IsConst >
RandomAccessIterator<T, IsConst>& RandomAccessIterator<T, IsConst>::operator++()
{
    ++_it;
    return (*this);
}

template < class T, bool IsConst >
RandomAccessIterator<T, IsConst> RandomAccessIterator<T, IsConst>::operator++(int)
{
    RandomAccessIterator<T, IsConst> tmp(*this);
    ++_it;
    return (tmp);
}

template < class T, bool IsConst >
RandomAccessIterator<T, IsConst>& RandomAccessIterator<T, IsConst>::operator--()
{
    --_it;
    return (*this);
}

template < class T, bool IsConst >
RandomAccessIterator<T, IsConst> RandomAccessIterator<T, IsConst>::operator--(int)
{
    RandomAccessIterator<T, IsConst> tmp(*this);
    --_it;
    return (tmp);
}

// Arithmetic
template < class T, bool IsConst >
RandomAccessIterator<T, IsConst> RandomAccessIterator<T, IsConst>::operator+(difference_type n) const
{
    RandomAccessIterator<T, IsConst> sum(*this);
    sum._it += n;
    return (sum);
}

template < class T, bool IsConst >
RandomAccessIterator<T, IsConst> RandomAccessIterator<T, IsConst>::operator-(difference_type n) const
{
    RandomAccessIterator<T, IsConst> diff(*this);
    diff._it -= n;
    return (diff);
}

template < class T, bool IsConst >
template < bool is_const >
typename RandomAccessIterator<T, IsConst>::difference_type RandomAccessIterator<T, IsConst>::operator-(const RandomAccessIterator<T, is_const>& rhs) const
{
    return (getPointer() - rhs.getPointer());
}

// Relational
template < class T, bool IsConst >
template < bool is_const >
bool RandomAccessIterator<T, IsConst>::operator<(const RandomAccessIterator<T, is_const>& rhs) const
{
    return (_it < rhs.getPointer());
}

template < class T, bool IsConst >
template < bool is_const >
bool RandomAccessIterator<T, IsConst>::operator>(const RandomAccessIterator<T, is_const>& rhs) const
{
    return (!(*this < rhs) && *this != rhs);
}

template < class T, bool IsConst >
template < bool is_const >
bool RandomAccessIterator<T, IsConst>::operator<=(const RandomAccessIterator<T, is_const>& rhs) const
{
    return (*this < rhs || *this == rhs);
}

template < class T, bool IsConst >
template < bool is_const >
bool RandomAccessIterator<T, IsConst>::operator>=(const RandomAccessIterator<T, is_const>& rhs) const
{
    return (*this > rhs || *this == rhs);
}

// Assignment arithmetics
template < class T, bool IsConst >
RandomAccessIterator<T, IsConst>& RandomAccessIterator<T, IsConst>::operator+=(difference_type n)
{
    _it += n;
    return (*this);
}

template < class T, bool IsConst >
RandomAccessIterator<T, IsConst>& RandomAccessIterator<T, IsConst>::operator-=(difference_type n)
{
    _it -= n;
    return (*this);
}

// Non member function overloads
template < class T, bool IsConst >
RandomAccessIterator<T, IsConst> operator+(typename RandomAccessIterator<T, IsConst>::difference_type n, const RandomAccessIterator<T, IsConst>& rev_it)
{
    return RandomAccessIterator<T, IsConst>(rev_it + n);
}

template < class T, bool IsConst>
RandomAccessIterator<T, IsConst> operator-(typename RandomAccessIterator<T, IsConst>::difference_type n, const RandomAccessIterator<T, IsConst>& rev_it)
{
    return RandomAccessIterator<T, IsConst>(-n - rev_it);
}

} // namespace ft

#endif
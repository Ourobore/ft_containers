/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:24:09 by lchapren          #+#    #+#             */
/*   Updated: 2022/01/20 11:55:19 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

#include "iterator/IteratorTraits.hpp"
#include "iterator/RandomAccessIterator.hpp"
#include "iterator/ReverseIterator.hpp"

#include "utils/EnableIf.hpp"
#include "utils/IsIntegral.hpp"
#include "utils/LexicographicalCompare.hpp"

#include "Cavalry/srcs/utils/print_container.hpp"

namespace ft
{

template < class T, class Allocator = std::allocator<T> >
class vector
{
  public:
    typedef T         value_type;
    typedef Allocator allocator_type;

    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;

    typedef RandomAccessIterator< value_type, false > iterator;
    typedef RandomAccessIterator< value_type, true >  const_iterator;
    typedef ReverseIterator< iterator >               reverse_iterator;
    typedef ReverseIterator< const_iterator >         const_reverse_iterator;

    typedef typename iterator_traits<iterator>::difference_type difference_type;
    typedef std::size_t                                         size_type;

  protected:
    pointer        _c;
    size_type      _size;
    size_type      _capacity;
    allocator_type _alloc;

  public:
    // Constructors and destructor
    explicit vector(const allocator_type& alloc = allocator_type());
    explicit vector(size_type n, const_reference val = value_type(), const allocator_type& alloc = allocator_type());
    template < class InputIterator >
    vector(typename enable_if< !is_integral< InputIterator >::value, InputIterator >::type first, InputIterator last, const allocator_type& alloc = allocator_type());
    vector(const vector< T, Allocator >& x);
    vector& operator=(const vector< T, Allocator >& x);
    virtual ~vector();

    // Iterators
    iterator               begin();
    const_iterator         begin() const;
    iterator               end();
    const_iterator         end() const;
    reverse_iterator       rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator       rend();
    const_reverse_iterator rend() const;

    // Capacity
    size_type size() const;
    size_type max_size() const;
    void      resize(size_type n, value_type val = value_type());
    size_type capacity() const;
    bool      empty() const;
    void      reserve(size_type n);

    // Element access
    reference       operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference       at(size_type n);
    const_reference at(size_type n) const;
    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    // Modifiers
    template < class InputIterator >
    void     assign(typename enable_if< !is_integral< InputIterator >::value, InputIterator >::type first, InputIterator last);
    void     assign(size_type n, const_reference val);
    void     push_back(const_reference val);
    void     pop_back();
    iterator insert(iterator position, const_reference val);
    void     insert(iterator position, size_type n, const_reference val);
    template < class InputIterator >
    void     insert(iterator position, typename enable_if< !is_integral< InputIterator >::value, InputIterator >::type first, InputIterator last);
    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);
    void     swap(vector< value_type >& x);
    void     clear();

    // Allocator
    allocator_type get_allocator() const;
};

// Constructors and destructor
template < class T, class Allocator >
vector< T, Allocator >::vector(const allocator_type& alloc)
    : _size(0), _capacity(0), _alloc(alloc)
{
    _c = _alloc.allocate(_capacity);
}

template < class T, class Allocator >
vector< T, Allocator >::vector(size_type n, const_reference val, const allocator_type& alloc)
    : _size(n), _capacity(n), _alloc(alloc)
{
    _c = _alloc.allocate(_capacity);
    for (size_type i = 0; i < _size; ++i)
        _alloc.construct(&_c[i], val);
}

template < class T, class Allocator >
template < class InputIterator >
vector< T, Allocator >::vector(typename enable_if< !is_integral< InputIterator >::value, InputIterator >::type first, InputIterator last, const allocator_type& alloc)
    : _size(0), _capacity(0), _alloc(alloc)
{
    InputIterator count = first;

    for (; count != last; count++)
        ++_size;

    _capacity = _size;
    _c = _alloc.allocate(_capacity);
    for (size_type i = 0; i < _size; ++i, ++first)
        _alloc.construct(&_c[i], *first);
}

template < class T, class Allocator >
vector< T, Allocator >::vector(const vector< T, Allocator >& x)
    : _size(x._size), _capacity(x._size), _alloc(x._alloc)
{
    _c = _alloc.allocate(_capacity);
    for (size_type i = 0; i < _size; ++i)
        _alloc.construct(&_c[i], x[i]);
}

template < class T, class Allocator >
vector< T, Allocator >& vector< T, Allocator >::operator=(const vector< T, Allocator >& x)
{
    if (this != &x)
    {
        this->clear();
        this->reserve(x.size());

        for (size_type i = 0; i < x.size(); ++i, ++_size)
            _alloc.construct(&_c[i], x[i]);
    }
    return (*this);
}

template < class T, class Allocator >
vector< T, Allocator >::~vector()
{
    this->clear();
    _alloc.deallocate(_c, _capacity);
}

// Iterators
template < class T, class Allocator >
typename vector< T, Allocator >::iterator vector< T, Allocator >::begin()
{
    return iterator(_c);
}

template < class T, class Allocator >
typename vector< T, Allocator >::const_iterator vector< T, Allocator >::begin() const
{
    return const_iterator(_c);
}

template < class T, class Allocator >
typename vector< T, Allocator >::iterator vector< T, Allocator >::end()
{
    return iterator(_c + _size);
}

template < class T, class Allocator >
typename vector< T, Allocator >::const_iterator vector< T, Allocator >::end() const
{
    return const_iterator(_c + _size);
}

template < class T, class Allocator >
typename vector< T, Allocator >::reverse_iterator vector< T, Allocator >::rbegin()
{
    return reverse_iterator(end());
}

template < class T, class Allocator >
typename vector< T, Allocator >::const_reverse_iterator vector< T, Allocator >::rbegin() const
{
    return const_reverse_iterator(end());
}

template < class T, class Allocator >
typename vector< T, Allocator >::reverse_iterator vector< T, Allocator >::rend()
{
    return reverse_iterator(begin());
}

template < class T, class Allocator >
typename vector< T, Allocator >::const_reverse_iterator vector< T, Allocator >::rend() const
{
    return const_reverse_iterator(begin());
}

// Capacity
template < class T, class Allocator >
typename vector< T, Allocator >::size_type vector< T, Allocator >::size() const
{
    return (_size);
}

template < class T, class Allocator >
typename vector< T, Allocator >::size_type vector< T, Allocator >::max_size() const
{
    return (_alloc.max_size());
}

template < class T, class Allocator >
void vector< T, Allocator >::resize(size_type n, value_type val)
{
    if (n < _size)
    {
        for (size_type i = n; i < _size; ++i)
            _alloc.destroy(&_c[i]);
    }
    else if (n > _size)
    {
        if (n > _capacity)
        {
            if (_capacity * 2 < n)
                reserve(n);
            else
                reserve(_capacity * 2);
        }
        for (size_type i = _size; i < n; ++i)
            _alloc.construct(&_c[i], val);
    }
    _size = n;
}

template < class T, class Allocator >
typename vector< T, Allocator >::size_type vector< T, Allocator >::capacity() const
{
    return (_capacity);
}

template < class T, class Allocator >
bool vector< T, Allocator >::empty() const
{
    return (_size == 0);
}

template < class T, class Allocator >
void vector< T, Allocator >::reserve(size_type n)
{
    if (n > max_size())
        throw std::length_error("vector::reserve"); // "vector::reserve() : n is greater than vector::max_size()"
    else if (n > _capacity)
    {
        pointer realloc;

        realloc = _alloc.allocate(n);
        for (size_type i = 0; i < _size; ++i)
        {
            _alloc.construct(&realloc[i], _c[i]);
            _alloc.destroy(&_c[i]);
        }
        _alloc.deallocate(_c, _capacity);

        _c = realloc;
        _capacity = n;
    }
}

// Element access
template < class T, class Allocator >
typename vector< T, Allocator >::reference vector< T, Allocator >::operator[](size_type n)
{
    return (_c[n]);
}

template < class T, class Allocator >
typename vector< T, Allocator >::const_reference vector< T, Allocator >::operator[](size_type n) const
{
    return (_c[n]);
}

template < class T, class Allocator >
typename vector< T, Allocator >::reference vector< T, Allocator >::at(size_type n)
{
    if (n < 0 || n >= _size)
        throw std::out_of_range("Index is out of range");
    else
        return (_c[n]);
}

template < class T, class Allocator >
typename vector< T, Allocator >::const_reference vector< T, Allocator >::at(size_type n) const
{
    if (n < 0 || n >= _size)
        throw std::out_of_range("Index is out of range");
    else
        return (_c[n]);
}

template < class T, class Allocator >
typename vector< T, Allocator >::reference vector< T, Allocator >::front()
{
    return (*_c);
}

template < class T, class Allocator >
typename vector< T, Allocator >::const_reference vector< T, Allocator >::front() const
{
    return (*_c);
}

template < class T, class Allocator >
typename vector< T, Allocator >::reference vector< T, Allocator >::back()
{
    return (*(_c + _size - 1));
}

template < class T, class Allocator >
typename vector< T, Allocator >::const_reference vector< T, Allocator >::back() const
{
    return (*(_c + _size - 1));
}

// Modifiers
template < class T, class Allocator >
template < class InputIterator >
void vector< T, Allocator >::assign(typename enable_if< !is_integral< InputIterator >::value, InputIterator >::type first, InputIterator last)
{
    this->clear();
    size_type newSize = 0;

    InputIterator count = first;
    for (; count != last; ++count)
        ++newSize;

    if (newSize > _capacity)
        reserve(newSize);

    for (size_type i = 0; i < newSize; ++i, ++first)
        _alloc.construct(&_c[i], *first);
    _size = newSize;
}

template < class T, class Allocator >
void vector< T, Allocator >::assign(size_type n, const_reference val)
{
    this->clear();

    if (n > _capacity)
        reserve(n);

    for (size_type i = 0; i < n; ++i, ++_size)
        _alloc.construct(&_c[i], val);
}

template < class T, class Allocator >
void vector< T, Allocator >::push_back(const_reference val)
{
    if (_size == _capacity)
        reserve(_capacity == 0 ? 1 : _capacity * 2);
    _alloc.construct(&_c[_size], val);
    ++_size;
}

template < class T, class Allocator >
void vector< T, Allocator >::pop_back()
{
    _alloc.destroy(&_c[_size - 1]);
    --_size;
}

template < class T, class Allocator >
typename vector< T, Allocator >::iterator vector< T, Allocator >::insert(iterator position, const_reference val)
{
    size_type pos = static_cast< size_type >(position - this->begin());
    if (_size == _capacity)
        reserve(_capacity == 0 ? 1 : _capacity * 2);

    ++_size;
    for (size_type i = _size - 1; i != pos; --i)
    {
        _alloc.construct(&_c[i], _c[i - 1]);
        _alloc.destroy(&_c[i - 1]);
    }
    _alloc.construct(&_c[pos], val);
    return iterator(&_c[pos]);
}

template < class T, class Allocator >
void vector< T, Allocator >::insert(iterator position, size_type n, const_reference val)
{
    size_type pos = static_cast< size_type >(position - this->begin());
    if (_size + n > _capacity)
    {
        if (_capacity * 2 < _size + n)
            reserve(_size + n);
        else
            reserve(_size * 2);
    }

    _size += n;
    for (size_type i = _size - 1; i != pos + n - 1; --i)
    {
        _alloc.construct(&_c[i], _c[i - n]);
        _alloc.destroy(&_c[i - n]);
    }
    for (size_type i = pos; i != pos + n; ++i)
        _alloc.construct(&_c[i], val);
}

template < class T, class Allocator >
template < class InputIterator >
void vector< T, Allocator >::insert(iterator position, typename enable_if< !is_integral< InputIterator >::value, InputIterator >::type first, InputIterator last)
{
    size_type pos = static_cast< size_type >(position - this->begin());
    size_type old_capacity = _capacity;
    vector    tmp(first, last);
    size_type n = tmp.size();

    if (_size + n > _capacity)
    {
        if (_capacity * 2 < _size + n)
            reserve(_size + n);
        else
            reserve(_size * 2);
    }

    _size += n;
    for (size_type i = _size - 1; i != pos + n - 1; --i)
    {
        _alloc.construct(&_c[i], _c[i - n]);
        _alloc.destroy(&_c[i - n]);
    }

    if (old_capacity == _capacity)
        for (size_type i = pos; i != pos + n; ++i, ++first)
            _alloc.construct(&_c[i], *first);
    else
    {
        vector::iterator it = tmp.begin();
        for (size_type i = pos; i != pos + n; ++i, ++it)
            _alloc.construct(&_c[i], *it);
    }
}

template < class T, class Allocator >
typename vector< T, Allocator >::iterator vector< T, Allocator >::erase(iterator position)
{
    size_type pos = static_cast< size_type >(position - begin());

    for (size_type i = pos; i != _size; ++i)
    {
        _alloc.destroy(&_c[i]);
        if (i + 1 != _size)
            _alloc.construct(&_c[i], _c[i + 1]);
    }
    --_size;
    return iterator(position);
}

template < class T, class Allocator >
typename vector< T, Allocator >::iterator vector< T, Allocator >::erase(iterator first, iterator last)
{
    size_type posFirst = static_cast< size_type >(first - begin());
    size_type posLast = static_cast< size_type >(last - begin());
    size_type n = posLast - posFirst;

    for (size_type i = posFirst; i < posLast; ++i)
        _alloc.destroy(&_c[i]);
    for (size_type i = posLast; i < _size; ++i)
    {
        _alloc.construct(&_c[i - n], _c[i]);
        _alloc.destroy(&_c[i]);
    }

    _size -= n;
    return iterator(first);
}

template < class T, class Allocator >
void vector< T, Allocator >::swap(vector< value_type >& x)
{
    pointer   tmpContainer = _c;
    size_type tmpSize = _size;
    size_type tmpCapacity = _capacity;

    _c = x._c;
    _size = x._size;
    _capacity = x._capacity;
    x._c = tmpContainer;
    x._size = tmpSize;
    x._capacity = tmpCapacity;
}

template < class T, class Allocator >
void vector< T, Allocator >::clear()
{
    for (size_type i = 0; i < _size; i++)
        _alloc.destroy(&_c[i]);
    _size = 0;
}

// Allocator
template < class T, class Allocator >
typename vector< T, Allocator >::allocator_type vector< T, Allocator >::get_allocator() const
{
    return (_alloc);
}

// Non member function overloads
template < class T, class Allocator >
bool operator==(const vector< T, Allocator >& lhs, const vector< T, Allocator >& rhs)
{
    if (lhs.size() != rhs.size())
        return (false);
    if (!(lhs < rhs) && !(rhs < lhs))
        return (true);
    else
        return (false);
}

template < class T, class Allocator >
bool operator!=(const vector< T, Allocator >& lhs, const vector< T, Allocator >& rhs)
{
    return (!(lhs == rhs));
}

template < class T, class Allocator >
bool operator<(const vector< T, Allocator >& lhs, const vector< T, Allocator >& rhs)
{
    if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
        return (true);
    else
        return (false);
}

template < class T, class Allocator >
bool operator<=(const vector< T, Allocator >& lhs, const vector< T, Allocator >& rhs)
{
    return (!(rhs < lhs));
}

template < class T, class Allocator >
bool operator>(const vector< T, Allocator >& lhs, const vector< T, Allocator >& rhs)
{
    return (rhs < lhs);
}

template < class T, class Allocator >
bool operator>=(const vector< T, Allocator >& lhs, const vector< T, Allocator >& rhs)
{
    return (!(lhs < rhs));
}

template < class T, class Allocator >
void swap(vector< T, Allocator >& x, vector< T, Allocator >& y)
{
    x.swap(y);
}

} // namespace ft

#endif

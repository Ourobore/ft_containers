/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:11:05 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/21 17:43:42 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTITERATOR_HPP
#define INPUTITERATOR_HPP

#include <iostream>

namespace ft
{

template <typename T>
class InputIterator
{
  public:
    typedef T                       value_type;
    typedef value_type&             reference;
    typedef const value_type&       const_reference;
    typedef value_type*             pointer;
    typedef std::ptrdiff_t          difference_type;
    typedef std::input_iterator_tag iterator_category;

  protected:
    pointer _it;

  public:
    // Constructors, assignation and destructor
    InputIterator(pointer p);
    InputIterator(const InputIterator& rhs);
    InputIterator& operator=(const InputIterator& rhs);
    virtual ~InputIterator();

    // Equivalence
    bool operator==(const InputIterator& rhs) const;
    bool operator!=(const InputIterator& rhs) const;

    // Dereference
    reference operator*();
    pointer   operator->();

    // Increment
    InputIterator& operator++();
    InputIterator  operator++(int);
};

// Constructors and destructor
template <typename T>
InputIterator<T>::InputIterator(pointer p)
    : _it(p)
{
}

template <typename T>
InputIterator<T>::InputIterator(const InputIterator& rhs)
    : _it(rhs._it)
{
}

template <typename T>
InputIterator<T>& InputIterator<T>::operator=(const InputIterator& rhs)
{
    if (this != &rhs)
        _it = rhs._it;
    return (*this);
}

template <typename T>
InputIterator<T>::~InputIterator()
{
    _it = NULL;
}

// Equivalence
template <typename T>
bool InputIterator<T>::operator==(const InputIterator<T>& rhs) const
{
    return (_it == rhs._it);
}

template <typename T>
bool InputIterator<T>::operator!=(const InputIterator<T>& rhs) const
{
    return !(*this == rhs);
}

// Dereference
template <typename T>
typename InputIterator<T>::reference InputIterator<T>::operator*()
{
    return (*_it);
}

template <typename T>
typename InputIterator<T>::pointer InputIterator<T>::operator->()
{
    return (_it);
}

// Increment and Decrement
template <typename T>
InputIterator<T>& InputIterator<T>::operator++()
{
    _it += 1;
    return (*this);
}

template <typename T>
InputIterator<T> InputIterator<T>::operator++(int)
{
    InputIterator<T> tmp(*this);
    ++_it;
    return (tmp);
}

} // namespace ft

#endif

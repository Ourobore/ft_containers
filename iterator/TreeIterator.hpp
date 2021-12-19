/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:52:58 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/19 17:21:50 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP

#include "BidirectionalIterator.hpp"
#include "binary_tree/Node.hpp"
//#include "binary_tree/BinarySearchTree.hpp"

namespace ft
{

template <class T>
class TreeIterator : public BidirectionalIterator<T>
{
  public:
    typedef Node<typename BidirectionalIterator<T>::value_type> value_type;

  protected:
    value_type* _it;

  public:
    // Constructors
    TreeIterator();
    TreeIterator(value_type* p);

    // Dereference
    T& operator*();
    T* operator->();

    // Increment and Decrement
    TreeIterator& operator++();
    TreeIterator  operator++(int);
    TreeIterator& operator--();
    TreeIterator  operator--(int);
};

// Constructor
template <typename T>
TreeIterator<T>::TreeIterator()
{
}

template <typename T>
TreeIterator<T>::TreeIterator(value_type* p)
    : BidirectionalIterator<T>(), _it(p)
{
}

// Dereference
template <typename T>
T& TreeIterator<T>::operator*()
{
    return (_it->data());
}

template <typename T>
T* TreeIterator<T>::operator->()
{
    return (&(_it->data()));
}

// Increment and Decrement
template <typename T>
TreeIterator<T>& TreeIterator<T>::operator++()
{
    _it = _it->inorder_successor();
    return (*this);
}

template <typename T>
TreeIterator<T> TreeIterator<T>::operator++(int)
{
    TreeIterator<T> tmp(*this);
    _it = _it->inorder_successor();
    return (tmp);
}

template <typename T>
TreeIterator<T>& TreeIterator<T>::operator--()
{
    _it = _it->inorder_predecessor();
    return (*this);
}

template <typename T>
TreeIterator<T> TreeIterator<T>::operator--(int)
{
    TreeIterator<T> tmp(*this);
    _it = _it->inorder_predecessor();
    return (tmp);
}

} // namespace ft

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:52:58 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/17 15:15:28 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP

#include "BidirectionalIterator.hpp"
//#include "binary_tree/BinarySearchTree.hpp"

namespace ft
{

template <class T>
class TreeIterator : public BidirectionalIterator<T>
{
  public:
    // Constructors
    TreeIterator();
    TreeIterator(typename BidirectionalIterator<T>::pointer p);

    // Dereference
    typename BidirectionalIterator<T>::reference operator*();
    typename BidirectionalIterator<T>::pointer   operator->();

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
TreeIterator<T>::TreeIterator(typename BidirectionalIterator<T>::pointer p)
    : BidirectionalIterator<T>(p)
{
}

// Dereference
template <typename T>
typename BidirectionalIterator<T>::reference TreeIterator<T>::operator*()
{
    return (BidirectionalIterator<T>::_it->data());
}

template <typename T>
typename BidirectionalIterator<T>::pointer TreeIterator<T>::operator->()
{
    typename BidirectionalIterator<T>::pointer it = BidirectionalIterator<T>::_it->data();
    return (&it);
}

// Increment and Decrement
template <typename T>
TreeIterator<T>& TreeIterator<T>::operator++()
{
    BidirectionalIterator<T>::_it = BidirectionalIterator<T>::_it.inorder_successor();
    return (*this);
}

template <typename T>
TreeIterator<T> TreeIterator<T>::operator++(int)
{
    TreeIterator<T> tmp(*this);
    BidirectionalIterator<T>::_it = BidirectionalIterator<T>::_it.inorder_successor();
    return (tmp);
}

template <typename T>
TreeIterator<T>& TreeIterator<T>::operator--()
{
    BidirectionalIterator<T>::_it = BidirectionalIterator<T>::_it.inorder_predecessor();
    return (*this);
}

template <typename T>
TreeIterator<T> TreeIterator<T>::operator--(int)
{
    TreeIterator<T> tmp(*this);
    BidirectionalIterator<T>::_it = BidirectionalIterator<T>::_it.inorder_predecessor();
    return (tmp);
}

} // namespace ft

#endif
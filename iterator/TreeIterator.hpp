/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:52:58 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/20 15:11:42 by lchapren         ###   ########.fr       */
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

  private:
    value_type* _back;

    void update_back();

  public:
    // Constructors
    TreeIterator();
    TreeIterator(value_type* p, value_type* back);

    // Equivalence
    bool operator==(const TreeIterator<T>& rhs) const;
    bool operator!=(const TreeIterator<T>& rhs) const;

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
TreeIterator<T>::TreeIterator(value_type* p, value_type* back)
    : BidirectionalIterator<T>(), _it(p), _back(back)
{
}

// Equivalence
template <typename T>
bool TreeIterator<T>::operator==(const TreeIterator<T>& rhs) const
{
    return (_it == rhs._it);
}

template <typename T>
bool TreeIterator<T>::operator!=(const TreeIterator<T>& rhs) const
{
    return !(*this == rhs);
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
    update_back();
    if (_it)
        _it = _it->inorder_successor();
    else
        _it = _back;
    return (*this);
}

template <typename T>
TreeIterator<T> TreeIterator<T>::operator++(int)
{
    TreeIterator<T> tmp(*this);

    update_back();
    if (_it)
        _it = _it->inorder_successor();
    else
        _it = _back;
    return (tmp);
}

template <typename T>
TreeIterator<T>& TreeIterator<T>::operator--()
{
    update_back();
    if (_it)
        _it = _it->inorder_predecessor();
    else
        _it = _back;
    return (*this);
}

template <typename T>
TreeIterator<T> TreeIterator<T>::operator--(int)
{
    TreeIterator<T> tmp(*this);

    update_back();
    if (_it)
        _it = _it->inorder_predecessor();
    else
        _it = _back;
    return (tmp);
}

template <typename T>
void TreeIterator<T>::update_back()
{
    value_type* node_pointer = _back;
    while (node_pointer && node_pointer->parent())
        node_pointer = node_pointer->parent();

    _back = value_type::max_child(node_pointer);
}

} // namespace ft

#endif
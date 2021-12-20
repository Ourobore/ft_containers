/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:52:58 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/20 17:08:30 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP

#include "BidirectionalIterator.hpp"
#include "binary_tree/Node.hpp"
//#include "binary_tree/BinarySearchTree.hpp"

namespace ft
{

template <class T, bool IsConst>
class TreeIterator : public BidirectionalIterator<T, IsConst>
{
  public:
    typedef Node<typename BidirectionalIterator<T, IsConst>::value_type> value_type;

  protected:
    value_type* _it;

  private:
    value_type* _back;
    void        update_back();

  public:
    // Constructors
    TreeIterator();
    TreeIterator(value_type* p, value_type* back);

    // Equivalence
    template < bool is_const >
    bool operator==(const TreeIterator<T, is_const>& rhs) const;
    template < bool is_const >
    bool operator!=(const TreeIterator<T, is_const>& rhs) const;

    // Dereference
    T& operator*();
    T* operator->();

    // Increment and Decrement
    TreeIterator& operator++();
    TreeIterator  operator++(int);
    TreeIterator& operator--();
    TreeIterator  operator--(int);

    value_type* getPointer() const;
};

// Constructor
template <typename T, bool IsConst>
TreeIterator<T, IsConst>::TreeIterator()
{
}

template <typename T, bool IsConst>
TreeIterator<T, IsConst>::TreeIterator(value_type* p, value_type* back)
    : BidirectionalIterator<T, IsConst>(), _it(p), _back(back)
{
}

// Equivalence
template <typename T, bool IsConst>
template < bool is_const >
bool TreeIterator<T, IsConst>::operator==(const TreeIterator<T, is_const>& rhs) const
{
    return (_it == rhs._it);
}

template <typename T, bool IsConst>
template < bool is_const >
bool TreeIterator<T, IsConst>::operator!=(const TreeIterator<T, is_const>& rhs) const
{
    return !(*this == rhs);
}

// Dereference
template <typename T, bool IsConst>
T& TreeIterator<T, IsConst>::operator*()
{
    return (_it->data());
}

template <typename T, bool IsConst>
T* TreeIterator<T, IsConst>::operator->()
{
    return (&(_it->data()));
}

// Increment and Decrement
template <typename T, bool IsConst>
TreeIterator<T, IsConst>& TreeIterator<T, IsConst>::operator++()
{
    update_back();
    if (_it)
        _it = _it->inorder_successor();
    else
        _it = _back;
    return (*this);
}

template <typename T, bool IsConst>
TreeIterator<T, IsConst> TreeIterator<T, IsConst>::operator++(int)
{
    TreeIterator<T, IsConst> tmp(*this);

    update_back();
    if (_it)
        _it = _it->inorder_successor();
    else
        _it = _back;
    return (tmp);
}

template <typename T, bool IsConst>
TreeIterator<T, IsConst>& TreeIterator<T, IsConst>::operator--()
{
    update_back();
    if (_it)
        _it = _it->inorder_predecessor();
    else
        _it = _back;
    return (*this);
}

template <typename T, bool IsConst>
TreeIterator<T, IsConst> TreeIterator<T, IsConst>::operator--(int)
{
    TreeIterator<T, IsConst> tmp(*this);

    update_back();
    if (_it)
        _it = _it->inorder_predecessor();
    else
        _it = _back;
    return (tmp);
}

template <typename T, bool IsConst>
void TreeIterator<T, IsConst>::update_back()
{
    value_type* node_pointer = _back;
    while (node_pointer && node_pointer->parent())
        node_pointer = node_pointer->parent();

    _back = value_type::max_child(node_pointer);
}

// Access
template < class T, bool IsConst >
typename TreeIterator<T, IsConst>::value_type* TreeIterator<T, IsConst>::getPointer() const
{
    return (_it);
}

} // namespace ft

#endif
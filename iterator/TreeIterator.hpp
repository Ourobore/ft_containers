/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:52:58 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/21 11:15:28 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP

#include "binary_tree/Node.hpp"
#include "utils/EnableIf.hpp"
#include "utils/IteratorType.hpp"

namespace ft
{

template <class T, bool IsConst>
class TreeIterator
{
  public:
    typedef typename iterator_type<IsConst, T, const T >::type value_type;
    typedef value_type&                                        reference;
    typedef const value_type&                                  const_reference;
    typedef value_type*                                        pointer;
    typedef std::ptrdiff_t                                     difference_type;
    typedef std::bidirectional_iterator_tag                    iterator_category;

  protected:
    Node<value_type>* _it;
    Node<value_type>* _back;

    void update_back();

  public:
    // Constructors
    TreeIterator();
    TreeIterator(Node<value_type>* p, Node<value_type>* back);
    template <bool is_const>
    TreeIterator(const TreeIterator<T, is_const>& rhs, typename enable_if<!is_const, T>::type* = 0);
    TreeIterator& operator=(const TreeIterator& rhs);
    virtual ~TreeIterator();

    // Equivalence
    template < bool is_const >
    bool operator==(const TreeIterator<T, is_const>& rhs) const;
    template < bool is_const >
    bool operator!=(const TreeIterator<T, is_const>& rhs) const;

    // Dereference
    reference operator*();
    pointer   operator->();

    // Increment and Decrement
    TreeIterator& operator++();
    TreeIterator  operator++(int);
    TreeIterator& operator--();
    TreeIterator  operator--(int);

    pointer getPointer() const;
    pointer getBack() const;
};

// Constructor
template <typename T, bool IsConst>
TreeIterator<T, IsConst>::TreeIterator()
{
}

template <typename T, bool IsConst>
TreeIterator<T, IsConst>::TreeIterator(Node<value_type>* p, Node<value_type>* back)
    : _it(p), _back(back)
{
}

template < class T, bool IsConst >
template <bool is_const>
TreeIterator<T, IsConst>::TreeIterator(const TreeIterator<T, is_const>& rhs, typename enable_if<!is_const, T>::type*)
    : _it(rhs.getPointer()), _back(rhs.getBack())
{
}

template < class T, bool IsConst >
TreeIterator<T, IsConst>& TreeIterator<T, IsConst>::operator=(const TreeIterator& rhs)
{
    if (this != &rhs)
    {
        _it = rhs._it;
        _back = rhs._back;
    }
    return (*this);
}

template < class T, bool IsConst >
TreeIterator<T, IsConst>::~TreeIterator()
{
    _it = NULL;
    _back = NULL;
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
typename TreeIterator<T, IsConst>::reference TreeIterator<T, IsConst>::operator*()
{
    return (_it->data());
}

template <typename T, bool IsConst>
typename TreeIterator<T, IsConst>::pointer TreeIterator<T, IsConst>::operator->()
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
    Node<value_type>* node_pointer = _back;
    while (node_pointer && node_pointer->parent())
        node_pointer = node_pointer->parent();

    _back = Node<value_type>::max_child(node_pointer);
}

// Access
template < class T, bool IsConst >
typename TreeIterator<T, IsConst>::value_type* TreeIterator<T, IsConst>::getPointer() const
{
    return (_it);
}

template < class T, bool IsConst >
typename TreeIterator<T, IsConst>::value_type* TreeIterator<T, IsConst>::getBack() const
{
    return (_back);
}

} // namespace ft

#endif
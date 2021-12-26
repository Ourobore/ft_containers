/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:52:58 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/26 13:39:12 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP

#include "binary_tree/Node.hpp"
#include "utils/EnableIf.hpp"
#include "utils/IteratorType.hpp"
#include "utils/Remove_const.hpp"

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
    typedef Node<typename remove_const<value_type>::type > node_type;

    node_type* _it;
    node_type* _back;

    void update_back();

  public:
    // Constructors
    TreeIterator();
    TreeIterator(node_type* p, node_type* back);
    template <bool is_const>
    TreeIterator(const TreeIterator<T, is_const>& rhs);
    template <bool is_const>
    TreeIterator& operator=(const TreeIterator<T, is_const>& rhs);
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

    Node<value_type>* getPointer() const;
    Node<value_type>* getBack() const;
};

// Constructor
template <typename T, bool IsConst>
TreeIterator<T, IsConst>::TreeIterator()
{
}

template <typename T, bool IsConst>
TreeIterator<T, IsConst>::TreeIterator(node_type* p, node_type* back)
    : _it(p), _back(back)
{
}

template < class T, bool IsConst >
template <bool is_const>
TreeIterator<T, IsConst>::TreeIterator(const TreeIterator<T, is_const>& rhs)
    : _it(rhs.getPointer()), _back(rhs.getBack())
{
}

template < class T, bool IsConst >
template <bool is_const>
TreeIterator<T, IsConst>& TreeIterator<T, IsConst>::operator=(const TreeIterator<T, is_const>& rhs)
{
    // if (this != &rhs)
    // {
    _it = rhs.getPointer();
    _back = rhs.getBack();
    // }
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
    node_type* node_pointer = _back;
    while (node_pointer && node_pointer->parent())
        node_pointer = node_pointer->parent();

    _back = node_type::max_child(node_pointer);
}

// Access
template < class T, bool IsConst >
Node<typename TreeIterator<T, IsConst>::value_type>* TreeIterator<T, IsConst>::getPointer() const
{
    return (_it);
}

template < class T, bool IsConst >
Node<typename TreeIterator<T, IsConst>::value_type>* TreeIterator<T, IsConst>::getBack() const
{
    return (_back);
}

} // namespace ft

#endif

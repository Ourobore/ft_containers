/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:20:55 by lchapren          #+#    #+#             */
/*   Updated: 2022/01/02 11:22:55 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

namespace ft
{

template < class T >
class Node
{
  public:
    typedef T                 value_type;
    typedef value_type&       reference;
    typedef const value_type& const_reference;
    typedef value_type*       pointer;
    typedef const value_type* const_pointer;

    typedef std::size_t size_type;

  protected:
    value_type _data;
    Node*      _parent;
    Node*      _left;
    Node*      _right;

  public:
    // Constructors and Destructor
    Node();
    Node(const_reference value);
    template < class N >
    Node(const Node< N >* rhs);
    template < class N >
    Node(const Node< N >& rhs);
    Node< T >& operator=(const Node< T >& rhs);
    ~Node();

    // Element access
    reference data();
    Node*&    parent();
    Node*&    left();
    Node*&    right();

    reference operator*();

    // Algorithms
    static Node< T >* min_child(Node< T >* subtree_root);
    static Node< T >* max_child(Node< T >* subtree_root);
    Node< T >*        inorder_successor();
    Node< T >*        preorder_successor();
    Node< T >*        postorder_successor();
    Node< T >*        inorder_predecessor();
    Node< T >*        preorder_predecessor();
    Node< T >*        postorder_predecessor();

    // Modifiers
    void set_data(const_reference value);
    void set_parent(Node* parent);
    void set_left(Node* left);
    void set_right(Node* right);
};

// Constructors and Destructor
template < class T >
Node< T >::Node()
    : _data(value_type()), _parent(NULL), _left(NULL), _right(NULL)
{
}

template < class T >
Node< T >::Node(const_reference value)
    : _data(value), _parent(NULL), _left(NULL), _right(NULL)
{
}

template < class T >
template < class N >
Node< T >::Node(const Node< N >* rhs)
    : _data(rhs->data()), _parent(rhs->parent()), _left(rhs->left()), _right(rhs->right())
{
}

template < class T >
template < class N >
Node< T >::Node(const Node< N >& rhs)
    : _data(rhs.data()), _parent(rhs.parent()), _left(rhs.left()), _right(rhs.right())
{
}

template < class T >
Node< T >& Node< T >::operator=(const Node< T >& rhs)
{
    if (this != &rhs)
    {
        _data = rhs.data();
        _parent = rhs.parent();
        _left = rhs.left();
        _right = rhs.right();
    }
    return (*this);
}

template < class T >
Node< T >::~Node()
{
    //_data = value_type();
}

// Element access
template < class T >
typename Node< T >::reference Node< T >::data()
{
    return (_data);
}

template < class T >
Node< T >*& Node< T >::parent()
{
    return (_parent);
}

template < class T >
Node< T >*& Node< T >::left()
{
    return (_left);
}

template < class T >
Node< T >*& Node< T >::right()
{
    return (_right);
}

template < class T >
typename Node< T >::reference Node< T >::operator*()
{
    return (*this);
}

// Algorithms
template < class T >
Node< T >* Node< T >::min_child(Node< T >* subtree_root)
{
    if (!subtree_root)
        return (NULL);

    Node< T >* node_pointer = subtree_root;
    while (node_pointer->left())
        node_pointer = node_pointer->left();

    return (node_pointer);
}

template < class T >
Node< T >* Node< T >::max_child(Node< T >* subtree_root)
{
    if (!subtree_root)
        return (NULL);

    Node< T >* node_pointer = subtree_root;
    while (node_pointer->right())
        node_pointer = node_pointer->right();

    return (node_pointer);
}

template < class T >
Node< T >* Node< T >::inorder_successor()
{
    if (_right)
        return (min_child(_right));
    else
    {
        Node< T >* ancestor = _parent;
        Node< T >* node_pointer = this;
        while (ancestor && ancestor->right() == node_pointer)
        {
            ancestor = ancestor->parent();
            node_pointer = node_pointer->parent();
        }
        if (ancestor)
            return (ancestor);
        else
            return (NULL);
    }
}

template < class T >
Node< T >* Node< T >::preorder_successor()
{
    if (_left)
        return (_left);
    else if (_right)
        return (_right);
    else
    {
        Node< T >* ancestor = _parent;
        while (ancestor)
        {
            if (this->data() < ancestor->data() && ancestor->right())
                break;
            ancestor = ancestor->parent();
        }
        if (ancestor)
            return (ancestor->right());
        else
            return (NULL);
    }
}

template < class T >
Node< T >* Node< T >::postorder_successor()
{
    if (!_parent)
        return (NULL);
    if (this == _parent->right())
        return (_parent);
    if (!_parent->right())
        return (_parent);
    else
    {
        Node< T >* node_pointer = _parent->right();
        while (node_pointer && node_pointer->left())
            node_pointer = node_pointer->left();
        return (node_pointer);
    }
    // if (!_parent)
    //     return (NULL);
    // else if (!_parent->right() || _parent->right() == this)
    //     return (_parent);
    // else
    //     return (Node<T>::min_child(_parent->right()));
}

template < class T >
Node< T >* Node< T >::inorder_predecessor()
{
    if (_left)
        return (max_child(_left));
    else
    {
        Node< T >* ancestor = _parent;
        Node< T >* node_pointer = this;
        while (ancestor && ancestor->left() == node_pointer)
        {
            ancestor = ancestor->parent();
            node_pointer = node_pointer->parent();
        }
        if (ancestor && _data > ancestor->data())
            return (ancestor);
        else
            return (NULL);
    }
}

template < class T >
Node< T >* Node< T >::preorder_predecessor()
{
    if (!_parent)
        return (NULL);
    else if (!_parent->left() || _parent->left() == this)
        return (_parent);
    else
    {
        Node< T >* node_pointer = _parent->left();
        while (node_pointer)
        {
            if (node_pointer->right())
                return (Node< T >::max_child(node_pointer->right()));
            else if (node_pointer->left())
                node_pointer = node_pointer->left();
            else
                return (node_pointer);
        }
        return (NULL);
    }
}

template < class T >
Node< T >* Node< T >::postorder_predecessor()
{
    if (_right)
        return (_right);
    else
    {
        Node< T >* ancestor = _parent;
        while (ancestor && !ancestor->left())
            ancestor = ancestor->_parent;
        if (ancestor && _data > ancestor->data())
            return (ancestor->left());
        else
            return (NULL);
    }
}

// Modifiers
template < class T >
void Node< T >::set_data(const_reference value)
{
    _data = value;
}

template < class T >
void Node< T >::set_parent(Node* parent)
{
    _parent = parent;
}

template < class T >
void Node< T >::set_left(Node* left)
{
    _left = left;
    _left->set_parent(this);
}

template < class T >
void Node< T >::set_right(Node* right)
{
    _right = right;
    _right->set_parent(this);
}

} // namespace ft

#endif

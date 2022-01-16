/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseNode.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:50:56 by lena              #+#    #+#             */
/*   Updated: 2022/01/16 14:33:52 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASENODE_HPP
#define BASENODE_HPP

#include <iostream>

namespace ft
{

template < typename Node, typename T >
struct BaseNode
{
    typedef BaseNode&       reference;
    typedef const BaseNode& const_reference;
    typedef BaseNode*       pointer;
    typedef const BaseNode* const_pointer;

    Node* _parent;
    Node* _left;
    Node* _right;

    // Constructor and Destructor
    BaseNode();
    BaseNode(BaseNode* rhs);
    BaseNode(const BaseNode* rhs);
    BaseNode(BaseNode& rhs);
    BaseNode(const BaseNode& rhs);
    virtual ~BaseNode();

    // Accessors
    // Node* parent();
    Node* parent() const;
    // Node* left();
    Node* left() const;
    // Node* right();
    Node* right() const;

    Node* sister() const;
    Node* auntie() const;
    Node* grandparent() const;

    // Modifiers
    void set_parent(Node* parent);
    void set_left(Node* left);
    void set_right(Node* right);

    // Algorithms
    Node* min_child();
    Node* max_child();
    Node* inorder_successor();
    Node* inorder_predecessor();
    Node* preorder_successor();
    Node* preorder_predecessor();
    // BaseNode* postorder_successor();
    // BaseNode* postorder_predecessor();

    virtual T& data() = 0; // Could probably remove if fix for data() in inorder_predecessor(). But with it we get an abstract class
};

// Constructors and Destructor
template < typename Node, typename T >
BaseNode<Node, T>::BaseNode()
    : _parent(NULL), _left(NULL), _right(NULL)
{
}

template < typename Node, typename T >
BaseNode<Node, T>::BaseNode(BaseNode* rhs)
    : _parent(rhs->parent()), _left(rhs->left()), _right(rhs->right())
{
}

template < typename Node, typename T >
BaseNode<Node, T>::BaseNode(const BaseNode* rhs)
    : _parent(rhs->parent()), _left(rhs->left()), _right(rhs->right())
{
}

template < typename Node, typename T >
BaseNode<Node, T>::BaseNode(BaseNode& rhs)
    : _parent(rhs.parent()), _left(rhs.left()), _right(rhs.right())
{
}

template < typename Node, typename T >
BaseNode<Node, T>::BaseNode(const BaseNode& rhs)
    : _parent(rhs.parent()), _left(rhs.left()), _right(rhs.right())
{
}

template < typename Node, typename T >
BaseNode<Node, T>::~BaseNode()
{
    _parent = NULL;
    _left = NULL;
    _right = NULL;
}

// Accesssors
template < typename Node, typename T >
Node* BaseNode<Node, T>::parent() const
{
    return (_parent);
}

template < typename Node, typename T >
Node* BaseNode<Node, T>::left() const
{
    return (_left);
}

template < typename Node, typename T >
Node* BaseNode<Node, T>::right() const
{
    return (_right);
}

template < typename Node, typename T >
Node* BaseNode<Node, T>::sister() const
{
    Node* sister = NULL;

    if (this->parent())
    {
        Node* parent = this->parent();
        if (parent->left() == this)
            sister = parent->right();
        else
            sister = parent->left();
    }

    return (sister);
}

template < typename Node, typename T >
Node* BaseNode<Node, T>::auntie() const
{
    Node* parent = NULL;
    Node* grandparent = NULL;
    Node* auntie = NULL;

    if (this->parent())
        parent = this->parent();

    if (parent && parent->parent())
        grandparent = parent->parent();

    if (grandparent)
    {
        if (grandparent->left() && grandparent->left() == parent)
            auntie = grandparent->right();
        else
            auntie = grandparent->left();
    }

    return (auntie);
}

template < typename Node, typename T >
Node* BaseNode<Node, T>::grandparent() const
{
    Node* parent = NULL;
    Node* grandparent = NULL;

    if (this->parent())
        parent = this->parent();
    if (parent && parent->parent())
        grandparent = parent->parent();

    return (grandparent);
}

// Modifiers
template < typename Node, typename T >
void BaseNode<Node, T>::set_parent(Node* parent)
{
    _parent = parent;
}

template < typename Node, typename T >
void BaseNode<Node, T>::set_left(Node* left)
{
    _left = left;
    if (_left)
        _left->set_parent(static_cast<Node*>(this));
}

template < typename Node, typename T >
void BaseNode<Node, T>::set_right(Node* right)
{
    _right = right;
    if (_right)
        _right->set_parent(static_cast<Node*>(this));
}

// Algorithms
template < typename Node, typename T >
Node* BaseNode<Node, T>::min_child()
{
    BaseNode* node_pointer = this;
    while (node_pointer->left())
        node_pointer = node_pointer->left();

    return (static_cast<Node*>(node_pointer));
}

template < typename Node, typename T >
Node* BaseNode<Node, T>::max_child()
{
    BaseNode* node_pointer = this;
    while (node_pointer->right())
        node_pointer = node_pointer->right();

    return (static_cast<Node*>(node_pointer));
}

template < typename Node, typename T >
Node* BaseNode<Node, T>::inorder_successor()
{
    if (this->right())
        return (this->right()->min_child());
    else
    {
        BaseNode* ancestor = this->parent();
        BaseNode* node_pointer = this;
        while (ancestor && ancestor->right() == node_pointer)
        {
            ancestor = ancestor->parent();
            node_pointer = node_pointer->parent();
        }
        if (ancestor)
            return (static_cast<Node*>(ancestor));
        else
            return (NULL);
    }
}

template < typename Node, typename T >
Node* BaseNode<Node, T>::inorder_predecessor()
{
    if (this->left())
        return (this->left()->max_child());
    else
    {
        BaseNode* ancestor = this->parent();
        BaseNode* node_pointer = this;
        while (ancestor && ancestor->left() == node_pointer)
        {
            ancestor = ancestor->parent();
            node_pointer = node_pointer->parent();
        }
        if (ancestor && data() > ancestor->data())
            return (static_cast<Node*>(ancestor));
        else
            return (NULL);
    }
}

template < typename Node, typename T >
Node* BaseNode<Node, T>::preorder_successor()
{
    if (this->left())
        return (this->left());
    else if (this->right())
        return (this->right());
    else
    {
        BaseNode* ancestor = this->parent();
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

template < typename Node, typename T >
Node* BaseNode<Node, T>::preorder_predecessor()
{
    if (!this->parent())
        return (NULL);
    else if (!this->parent()->left() || this->parent()->left() == this)
        return (this->parent());
    else
    {
        BaseNode* node_pointer = this->parent()->left();
        while (node_pointer)
        {
            if (node_pointer->right())
                return (node_pointer->right()->max_child());
            else if (node_pointer->left())
                node_pointer = node_pointer->left();
            else
                return (static_cast<Node*>(node_pointer));
        }
        return (NULL);
    }
}

} // namespace ft

#endif

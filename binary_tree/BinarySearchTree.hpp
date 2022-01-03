/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:16:56 by lchapren          #+#    #+#             */
/*   Updated: 2022/01/03 12:27:27 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "Node.hpp"

#include <iostream>

namespace ft
{

template < class T, class Allocator = std::allocator< T > >
class BinarySearchTree
{
  public:
    typedef T                  value_type;
    typedef Allocator          allocator_type;
    typedef Node< value_type > node_type;
    typedef node_type*         node_pointer;

    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;

    typedef typename allocator_type::template rebind< node_type >::other node_allocator;

    typedef std::size_t size_type;

  protected:
    node_type*     _root;
    allocator_type _alloc;

    // Recursive implementations
    static void recursive_destroy(node_type* node);

  public:
    // Constructor
    BinarySearchTree(const allocator_type& allocator = allocator_type());
    BinarySearchTree(const BinarySearchTree& rhs);
    ~BinarySearchTree();

    // Search
    node_type* search(const value_type& value);

    // Insert
    node_type* insert(const value_type& value);
    node_type* insert(node_type* hint, const value_type& value);

    // Erase
    bool erase(const value_type& value);

    // Algorithm
    static node_type* min_elem(node_type* tree_root);
    static node_type* max_elem(node_type* tree_root);
    node_type*        inorder_successor(node_type* node);   // Left -> Root  -> Right
    node_type*        preorder_successor(node_type* node);  // Root -> Left  -> Right
    node_type*        postorder_successor(node_type* node); // Left -> Right -> Root
    node_type*        inorder_predecessor(node_type* node);
    node_type*        preorder_predecessor(node_type* node);
    node_type*        postorder_predecessor(node_type* node);

    // Accessors
    node_type*     root() const;
    void           set_root(node_type* root);
    allocator_type get_allocator() const;

    void print_inorder();
};

// Constructor and Destructor
template < class T, class Allocator >
BinarySearchTree< T, Allocator >::BinarySearchTree(const allocator_type& allocator)
    : _root(NULL), _alloc(allocator)
{
}

template < class T, class Allocator >
BinarySearchTree< T, Allocator >::BinarySearchTree(const BinarySearchTree& rhs)
    : _root(NULL), _alloc(rhs.get_allocator())
{
    node_type* node_pointer = rhs.root();
    while (node_pointer)
    {
        insert(node_pointer->data());
        node_pointer = BinarySearchTree::preorder_successor(node_pointer);
    }
}

template < class T, class Allocator >
void BinarySearchTree< T, Allocator >::recursive_destroy(node_type* node)
{
    if (!node)
        return;

    BinarySearchTree::recursive_destroy(node->left());
    BinarySearchTree::recursive_destroy(node->right());

    node_allocator allocator;
    allocator.destroy(node);
    allocator.deallocate(node, 1);
    node = NULL;
}

template < class T, class Allocator >
BinarySearchTree< T, Allocator >::~BinarySearchTree()
{
    BinarySearchTree::recursive_destroy(_root);
    _root = NULL;
}

// Search
template < class T, class Allocator >
typename BinarySearchTree< T, Allocator >::node_type* BinarySearchTree< T, Allocator >::search(const value_type& value)
{
    node_type* search = _root;

    while (search)
    {
        if (search->data() == value)
            return (search);

        if (value < search->data())
            search = search->left();
        else
            search = search->right();
    }
    return (NULL);
}

// Insert
template < class T, class Allocator >
typename BinarySearchTree< T, Allocator >::node_type* BinarySearchTree< T, Allocator >::insert(const value_type& value)
{
    node_allocator allocator;

    node_type* new_node = allocator.allocate(1);
    allocator.construct(new_node, value);
    if (!_root)
    {
        _root = new_node;
        return _root;
    }

    node_type* node_pointer = _root;
    bool       inserted = false;

    while (!inserted)
    {
        if (!node_pointer)
        {
            node_pointer = new_node;
            inserted = true;
        }
        else
        {
            if (new_node->data() < node_pointer->data())
            {
                if (!node_pointer->left())
                {
                    node_pointer->set_left(new_node);
                    inserted = true;
                }
                else
                    node_pointer = node_pointer->left();
            }
            else if (new_node->data() > node_pointer->data())
            {
                if (!node_pointer->right())
                {
                    node_pointer->set_right(new_node);
                    inserted = true;
                }
                else
                    node_pointer = node_pointer->right();
            }
        }
    }
    return (new_node);
}

template < class T, class Allocator >
typename BinarySearchTree< T, Allocator >::node_type* BinarySearchTree< T, Allocator >::insert(node_type* hint, const value_type& value)
{
    if (!hint)
        return (insert(value));

    node_type* successor = hint->inorder_successor();
    if (!(hint->data() < value && (!successor || successor->data() > value)))
        return (insert(value));
    else
    {
        node_allocator allocator;

        node_type* new_node = allocator.allocate(1);
        allocator.construct(new_node, value);

        hint->set_right(new_node);
        new_node->parent() = hint;

        return (new_node);
    }
}
// Erase
template < class T, class Allocator >
bool BinarySearchTree< T, Allocator >::erase(const value_type& value)
{
    node_type* node = search(value);
    if (!node)
        return (false);

    // If Node has no child
    else if (!node->left() && !node->right())
    {
        if (node->parent())
        {
            if (node->parent()->left() == node)
                node->parent()->left() = NULL;
            else
                node->parent()->right() = NULL;
        }
        else
            _root = NULL;
    }

    // If Node has only one child
    else if ((!node->left() && node->right()) || (node->left() && !node->right()))
    {
        node_type* child = node->left() ? node->left() : node->right();
        if (!node->parent())
        {
            child->parent() = NULL;
            _root = child;
        }
        else
        {
            if (node->parent()->left() == node)
                node->parent()->left() = child;
            else
                node->parent()->right() = child;
            child->parent() = node->parent();
        }
    }

    // If Node has 2 childs
    else
    {
        node_type* successor = BinarySearchTree< T >::inorder_successor(node);
        node_type  moved_successor(*successor);
        erase(successor->data());

        moved_successor.left() = node->left();
        moved_successor.right() = node->right();

        if (node->left())
            node->left()->parent() = &moved_successor;
        if (node->right())
            node->right()->parent() = &moved_successor;

        if (!node->parent())
            _root = &moved_successor;
        else
            moved_successor.parent() = node->parent();
    }

    node_allocator allocator;
    allocator.destroy(node);
    allocator.deallocate(node, 1);
    node = NULL;

    return (true);
}

// Algorithm
template < class T, class Allocator >
typename BinarySearchTree< T, Allocator >::node_type* BinarySearchTree< T, Allocator >::min_elem(node_type* tree_root)
{
    return (node_type::min_child(tree_root));
}

template < class T, class Allocator >
typename BinarySearchTree< T, Allocator >::node_type* BinarySearchTree< T, Allocator >::max_elem(node_type* tree_root)
{
    return (node_type::max_child(tree_root));
}

template < class T, class Allocator >
typename BinarySearchTree< T, Allocator >::node_type* BinarySearchTree< T, Allocator >::inorder_successor(node_type* node)
{
    return (node->inorder_successor());
}

template < class T, class Allocator >
typename BinarySearchTree< T, Allocator >::node_type* BinarySearchTree< T, Allocator >::preorder_successor(node_type* node)
{
    return (node->preorder_successor());
}

template < class T, class Allocator >
typename BinarySearchTree< T, Allocator >::node_type* BinarySearchTree< T, Allocator >::inorder_predecessor(node_type* node)
{
    return (node->inorder_predecessor());
}

template < class T, class Allocator >
typename BinarySearchTree< T, Allocator >::node_type* BinarySearchTree< T, Allocator >::preorder_predecessor(node_type* node)
{
    return (node->preorder_predecessor());
}

// Accessors
template < class T, class Allocator >
typename BinarySearchTree< T, Allocator >::node_type* BinarySearchTree< T, Allocator >::root() const
{
    return (_root);
}

template < class T, class Allocator >
void BinarySearchTree< T, Allocator >::set_root(node_type* root)
{
    _root = root;
}

template < class T, class Allocator >
typename BinarySearchTree< T, Allocator >::allocator_type BinarySearchTree< T, Allocator >::get_allocator() const
{
    return (_alloc);
}

// Print BinarySearchTree
template < class T, class Allocator >
void BinarySearchTree< T, Allocator >::print_inorder()
{
    node_type* node = BinarySearchTree::min_elem(_root);

    while (node)
    {
        std::cout << "[" << node->data() << "] ";
        node = inorder_successor(node);
    }
    std::cout << std::endl;
}

} // namespace ft

#endif

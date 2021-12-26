/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:16:56 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/26 15:42:14 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "Node.hpp"

#include <iostream>

namespace ft
{

template < class T, class Allocator = std::allocator<T> >
class BinarySearchTree
{
  public:
    typedef T         value_type;
    typedef Allocator allocator_type;

    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef Node<value_type>                         node_type;

    typedef std::size_t size_type;

  private:
    node_type*     _root;
    allocator_type _alloc;

    typedef typename allocator_type::template rebind< node_type >::other node_allocator;

    // Recursive implementations
    static void        recursive_destroy(node_type* node);
    static node_type*& recursive_search(const value_type& value, node_type* node);
    static node_type*  recursive_erase(const value_type& value, node_type* node);

  public:
    // Constructor
    BinarySearchTree(const allocator_type& allocator = allocator_type());
    BinarySearchTree(const BinarySearchTree& rhs);
    ~BinarySearchTree();

    // Search
    node_type* search(const value_type& value);

    // Insert
    void insert(const value_type& value);

    // Erase
    node_type* erase(const value_type& value);

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
    allocator_type get_allocator() const;

    void print_inorder();
};

// Constructor and Destructor
template <class T, class Allocator>
BinarySearchTree<T, Allocator>::BinarySearchTree(const allocator_type& allocator)
    : _root(NULL), _alloc(allocator)
{
}

template <class T, class Allocator>
BinarySearchTree<T, Allocator>::BinarySearchTree(const BinarySearchTree& rhs)
    : _root(NULL), _alloc(rhs.get_allocator())
{
    node_type* node_pointer = rhs.root();
    while (node_pointer)
    {
        insert(node_pointer->data());
        node_pointer = BinarySearchTree::preorder_successor(node_pointer);
    }
}

template <class T, class Allocator>
void BinarySearchTree<T, Allocator>::recursive_destroy(node_type* node)
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

template <class T, class Allocator>
BinarySearchTree<T, Allocator>::~BinarySearchTree()
{
    BinarySearchTree::recursive_destroy(_root);
    _root = NULL;
    // Implement not recursive destroy?
}

// Search
template <class T, class Allocator>
typename BinarySearchTree<T, Allocator>::node_type*& BinarySearchTree<T, Allocator>::recursive_search(const value_type& value, node_type* node)
{
    if (!node || node->data() == value)
        return (node);

    if (value > node->data())
        return (BinarySearchTree::recursive_search(value, node->right()));
    else
        return (BinarySearchTree::recursive_search(value, node->left()));
}

template <class T, class Allocator>
typename BinarySearchTree<T, Allocator>::node_type* BinarySearchTree<T, Allocator>::search(const value_type& value)
{
    return (BinarySearchTree::recursive_search(value, _root));
}

// Insert
template <class T, class Allocator>
void BinarySearchTree<T, Allocator>::insert(const value_type& value)
{
    node_allocator allocator;

    node_type* new_node = allocator.allocate(1);
    allocator.construct(new_node, value);
    if (!_root)
    {
        _root = new_node;
        return;
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
}

// Erase
template <class T, class Allocator>
typename BinarySearchTree<T, Allocator>::node_type* BinarySearchTree<T, Allocator>::recursive_erase(const value_type& value, node_type* node)
{
    if (node == NULL)
        return (node);

    // Searching recursively in which subtree is the erased node
    if (value < node->data())
        node->left() = BinarySearchTree::recursive_erase(value, node->left());
    else if (value > node->data())
        node->right() = BinarySearchTree::recursive_erase(value, node->right());

    // If this is the right node
    else
    {
        node_allocator allocator;

        // Node has no child
        if (!node->left() && !node->right())
        {
            allocator.destroy(node);
            allocator.deallocate(node, 1);
            node = NULL;
            return (node);
        }

        // Node with only one child or no child:
        // Set child as new subtree root
        else if (!node->left())
        {
            node_type*& new_sub_root = node->right();
            allocator.destroy(node);
            allocator.deallocate(node, 1);
            node = NULL;
            return new_sub_root;
        }
        else if (!node->right())
        {
            node_type*& new_sub_root = node->left();
            allocator.destroy(node);
            allocator.deallocate(node, 1);
            node = NULL;
            return new_sub_root;
        }

        // Node with two children: Get the inorder successor(smallest in right subtree)
        node_type* old_min = BinarySearchTree::min_elem(node->right());

        // Copy the inorder successor's content to this node
        node->data() = old_min->data();

        // Erase the inorder successor
        node->right() = BinarySearchTree::recursive_erase(old_min->data(), node->right());
    }
    return (node);
}

template <class T, class Allocator>
typename BinarySearchTree<T, Allocator>::node_type* BinarySearchTree<T, Allocator>::erase(const value_type& value)
{
    return (BinarySearchTree::recursive_erase(value, _root));
}

// Algorithm
template <class T, class Allocator>
typename BinarySearchTree<T, Allocator>::node_type* BinarySearchTree<T, Allocator>::min_elem(node_type* tree_root)
{
    return (node_type::min_child(tree_root));
}

template <class T, class Allocator>
typename BinarySearchTree<T, Allocator>::node_type* BinarySearchTree<T, Allocator>::max_elem(node_type* tree_root)
{
    return (node_type::max_child(tree_root));
}

template <class T, class Allocator>
typename BinarySearchTree<T, Allocator>::node_type* BinarySearchTree<T, Allocator>::inorder_successor(node_type* node)
{
    return (node->inorder_successor());
}

template <class T, class Allocator>
typename BinarySearchTree<T, Allocator>::node_type* BinarySearchTree<T, Allocator>::preorder_successor(node_type* node)
{
    return (node->preorder_successor());
}

template <class T, class Allocator>
typename BinarySearchTree<T, Allocator>::node_type* BinarySearchTree<T, Allocator>::inorder_predecessor(node_type* node)
{
    return (node->inorder_predecessor());
}

template <class T, class Allocator>
typename BinarySearchTree<T, Allocator>::node_type* BinarySearchTree<T, Allocator>::preorder_predecessor(node_type* node)
{
    return (node->preorder_predecessor());
}

// Accessors
template <class T, class Allocator>
typename BinarySearchTree<T, Allocator>::node_type* BinarySearchTree<T, Allocator>::root() const
{
    return (_root);
}

template <class T, class Allocator>
typename BinarySearchTree<T, Allocator>::allocator_type BinarySearchTree<T, Allocator>::get_allocator() const
{
    return (_alloc);
}

// Print BinarySearchTree
template <class T, class Allocator>
void BinarySearchTree<T, Allocator>::print_inorder()
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

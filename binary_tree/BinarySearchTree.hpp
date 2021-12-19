/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:16:56 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/19 13:08:34 by lchapren         ###   ########.fr       */
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

    typedef std::size_t size_type;

  private:
    Node<T>*       _root;
    allocator_type _alloc;

    typedef typename allocator_type::template rebind< Node<T> >::other node_allocator;

    // Recursive implementations
    static void      recursive_destroy(Node<T>*& node);
    static Node<T>*& recursive_search(value_type value, Node<T>*& node);
    static Node<T>*  recursive_erase(value_type value, Node<T>*& node);

  public:
    // Constructor
    BinarySearchTree(const allocator_type& allocator = allocator_type());
    BinarySearchTree(const BinarySearchTree& rhs);
    ~BinarySearchTree();

    // Search
    Node<T>* search(value_type value);

    // Insert
    void insert(value_type value);

    // Erase
    Node<T>* erase(value_type value);

    // Algorithm
    static Node<T>* min_elem(Node<T>* tree_root);
    static Node<T>* max_elem(Node<T>* tree_root);
    Node<T>*        inorder_successor(Node<T>*& node);   // Left -> Root  -> Right
    Node<T>*        preorder_successor(Node<T>*& node);  // Root -> Left  -> Right
    Node<T>*        postorder_successor(Node<T>*& node); // Left -> Right -> Root
    Node<T>*        inorder_predecessor(Node<T>*& node);
    Node<T>*        preorder_predecessor(Node<T>*& node);
    Node<T>*        postorder_predecessor(Node<T>*& node);

    // Accessors
    Node<T>*       root();
    allocator_type get_allocator() const;

    // Print BinarySearchTree
    void print_inorder();
    void print_postorder();
    void print_preorder();
};

// Constructor and Destructor
template <class T, class Allocator>
BinarySearchTree<T, Allocator>::BinarySearchTree(const allocator_type& allocator)
    : _root(NULL), _alloc(allocator)
{
}

template <class T, class Allocator>
BinarySearchTree<T, Allocator>::BinarySearchTree(const BinarySearchTree& rhs)
    : _alloc(rhs.get_allocator())
{
}

template <class T, class Allocator>
void BinarySearchTree<T, Allocator>::recursive_destroy(Node<T>*& node)
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
}

// Search
template <class T, class Allocator>
Node<T>*& BinarySearchTree<T, Allocator>::recursive_search(value_type value, Node<T>*& node)
{
    if (!node || node->data() == value)
        return (node);

    if (value > node->data())
        return (BinarySearchTree::recursive_search(value, node->right()));
    else
        return (BinarySearchTree::recursive_search(value, node->left()));
}

template <class T, class Allocator>
Node<T>* BinarySearchTree<T, Allocator>::search(value_type value)
{
    return (BinarySearchTree::recursive_search(value, _root));
}

// Insert
template <class T, class Allocator>
void BinarySearchTree<T, Allocator>::insert(value_type value)
{
    node_allocator allocator;

    Node<T>* new_node = allocator.allocate(1);
    allocator.construct(new_node, value);

    Node<T>*& node_pointer = _root;
    Node<T>*  parent = NULL;
    bool      inserted = false;

    while (!inserted)
    {
        if (!node_pointer)
        {
            node_pointer = new_node;
            inserted = true;
        }
        else
        {
            parent = node_pointer;
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
Node<T>* BinarySearchTree<T, Allocator>::recursive_erase(value_type value, Node<T>*& node)
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
            Node<T>*& new_sub_root = node->right();
            allocator.destroy(node);
            allocator.deallocate(node, 1);
            node = NULL;
            return new_sub_root;
        }
        else if (!node->right())
        {
            Node<T>*& new_sub_root = node->left();
            allocator.destroy(node);
            allocator.deallocate(node, 1);
            node = NULL;
            return new_sub_root;
        }

        // Node with two children: Get the inorder successor(smallest in right subtree)
        Node<T>* old_min = BinarySearchTree::min_elem(node->right());

        // Copy the inorder successor's content to this node
        node->data() = old_min->data();

        // Erase the inorder successor
        node->right() = BinarySearchTree::recursive_erase(old_min->data(), node->right());
    }
    return (node);
}

template <class T, class Allocator>
Node<T>* BinarySearchTree<T, Allocator>::erase(value_type value)
{
    return (BinarySearchTree::recursive_erase(value, _root));
}

// Algorithm
template <class T, class Allocator>
Node<T>* BinarySearchTree<T, Allocator>::min_elem(Node<T>* tree_root)
{
    if (!tree_root)
        return (tree_root);

    Node<T>* node_pointer = tree_root;
    while (node_pointer->left())
        node_pointer = node_pointer->left();

    return (node_pointer);
}

template <class T, class Allocator>
Node<T>* BinarySearchTree<T, Allocator>::max_elem(Node<T>* tree_root)
{
    if (!tree_root)
        return (tree_root);

    Node<T>* node_pointer = tree_root;
    while (node_pointer->right())
        node_pointer = node_pointer->right();

    return (node_pointer);
}

template <class T, class Allocator>
Node<T>* BinarySearchTree<T, Allocator>::inorder_successor(Node<T>*& node)
{
    Node<T>* successor = NULL;

    Node<T>* node_pointer = _root;
    while (node_pointer)
    {
        if (node->data() < node_pointer->data())
        {
            successor = node_pointer;
            node_pointer = node_pointer->left();
        }
        else
            node_pointer = node_pointer->right();
    }
    return (successor);
}

template <class T, class Allocator>
Node<T>* BinarySearchTree<T, Allocator>::preorder_successor(Node<T>*& node)
{
    if (node->left())
        return (node->left());

    if (node->right())
        return (node->right());

    Node<T>* node_pointer = node;
    Node<T>* ancestor = parent(node_pointer);
    while (ancestor && ancestor->right() == node_pointer)
    {
        node_pointer = parent(node_pointer);
        ancestor = parent(ancestor);
    }

    if (!ancestor)
        return (ancestor);

    return ancestor->right();
}

template <class T, class Allocator>
Node<T>* BinarySearchTree<T, Allocator>::postorder_successor(Node<T>*& node)
{
    if (node == _root)
        return NULL;

    Node<T>* ancestor = parent(node);
    if (!ancestor->right() || ancestor->right() == node)
        return (ancestor);

    return BinarySearchTree::min_elem(ancestor->right());
}

template <class T, class Allocator>
Node<T>* BinarySearchTree<T, Allocator>::inorder_predecessor(Node<T>*& node)
{
    Node<T>* predecessor = NULL;
    Node<T>* node_pointer = _root;

    if (!_root)
        return (NULL);

    while (node_pointer && node_pointer != node)
    {
        if (node->data() < node_pointer->data())
            node_pointer = node_pointer->left();
        else
        {
            predecessor = node_pointer;
            node_pointer = node_pointer->right();
        }
    }
    if (node->data() == node_pointer->data() && node->left())
        predecessor = BinarySearchTree::max_elem(node_pointer->left());
    return (predecessor);
}

template <class T, class Allocator>
Node<T>* BinarySearchTree<T, Allocator>::preorder_predecessor(Node<T>*& node)
{
    if (node == _root)
        return NULL;

    Node<T>* ancestor = parent(node);
    if (!ancestor->left() || ancestor->left() == node)
        return (ancestor);

    return BinarySearchTree::max_elem(ancestor->left());
}

template <class T, class Allocator>
Node<T>* BinarySearchTree<T, Allocator>::postorder_predecessor(Node<T>*& node)
{
    if (node->right())
        return (node->right());

    Node<T>* node_pointer = node;
    Node<T>* ancestor = parent(node_pointer);

    while (ancestor && ancestor->left() == node_pointer)
    {
        node_pointer = parent(node_pointer);
        ancestor = parent(ancestor);
    }

    if (!ancestor)
        return ancestor;

    return ancestor->left();
}

// Accessors
template <class T, class Allocator>
Node<T>* BinarySearchTree<T, Allocator>::root()
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
    Node<T>* node = BinarySearchTree::min_elem(_root);

    while (node)
    {
        std::cout << "[" << node->data() << "] ";
        node = inorder_successor(node);
    }
    std::cout << std::endl;
}

template <class T, class Allocator>
void BinarySearchTree<T, Allocator>::print_preorder()
{
    Node<T>* node = _root;

    while (node)
    {
        std::cout << "[" << node->data() << "] ";
        node = preorder_successor(node);
    }
    std::cout << std::endl;
}

template <class T, class Allocator>
void BinarySearchTree<T, Allocator>::print_postorder()
{
    Node<T>* node = BinarySearchTree::min_elem(_root);

    while (node)
    {
        std::cout << "[" << node->data() << "] ";
        node = postorder_successor(node);
    }
    std::cout << std::endl;
}

} // namespace ft

#endif
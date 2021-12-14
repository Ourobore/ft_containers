/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:16:56 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/14 10:42:37 by lchapren         ###   ########.fr       */
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

    typedef typename allocator_type::template rebind< Node<T> >::other node_allocator;

    typedef std::size_t size_type;

  public:
    Node<T>*       _root;
    allocator_type _alloc;

    static void     recursive_destroy(Node<T>*& node);
    static Node<T>* recursive_search(value_type value, Node<T>*& node);
    static void     recursive_insert(Node<T>*& new_node, Node<T>*& node_root);

  public:
    // Constructor
    BinarySearchTree(const allocator_type& allocator = allocator_type());
    ~BinarySearchTree();

    // Search
    Node<T>* search(value_type value);

    // Insert
    void insert(value_type value);

    // Print BinarySearchTree
    static void print_postorder(Node<T>* node);
    static void print_inorder(Node<T>* node);
    static void print_preorder(Node<T>* node);
};

// Constructor
template <class T, class Allocator>
BinarySearchTree<T, Allocator>::BinarySearchTree(const allocator_type& allocator)
    : _root(NULL), _alloc(allocator)
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
Node<T>* BinarySearchTree<T, Allocator>::recursive_search(value_type value, Node<T>*& node)
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
void BinarySearchTree<T, Allocator>::recursive_insert(Node<T>*& new_node, Node<T>*& node)
{
    if (!node)
        node = new_node;
    else if (new_node->data() < node->data())
    {
        if (!node->left())
            node->set_left(new_node);
        else
            recursive_insert(new_node, node->left());
    }
    else if (new_node->data() > node->data())
    {
        if (!node->right())
            node->set_right(new_node);
        else
            recursive_insert(new_node, node->right());
    }
}

template <class T, class Allocator>
void BinarySearchTree<T, Allocator>::insert(value_type value)
{
    node_allocator allocator;

    Node<T>* new_node = allocator.allocate(1);
    allocator.construct(new_node, value);

    recursive_insert(new_node, _root);
}

// Printing BinarySearchTree
template <class T, class Allocator>
void BinarySearchTree<T, Allocator>::print_postorder(Node<T>* node)
{
    if (node == NULL)
        return;

    print_postorder(node->left());
    print_postorder(node->right());
    std::cout << node->data() << " ";
}

template <class T, class Allocator>
void BinarySearchTree<T, Allocator>::print_inorder(Node<T>* node)
{
    if (node == NULL)
        return;

    print_inorder(node->left());
    std::cout << node->data() << " ";
    print_inorder(node->right());
}

template <class T, class Allocator>
void BinarySearchTree<T, Allocator>::print_preorder(Node<T>* node)
{
    if (node == NULL)
        return;

    std::cout << node->data() << " ";
    print_preorder(node->left());
    print_preorder(node->right());
}

} // namespace ft

#endif
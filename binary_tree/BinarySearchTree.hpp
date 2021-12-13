/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:16:56 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/13 16:58:53 by lchapren         ###   ########.fr       */
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

    void destroy(Node<T>*& node);

  public:
    // Constructor
    BinarySearchTree(const allocator_type& allocator = allocator_type());
    ~BinarySearchTree();

    // Insert
    void insert(value_type value);
    void recursive_insert(Node<T>*& new_node, Node<T>*& node_root);

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
void BinarySearchTree<T, Allocator>::destroy(Node<T>*& node)
{
    if (!node)
        return;

    destroy(node->left());
    destroy(node->right());

    node_allocator allocator;
    allocator.destroy(node);
    allocator.deallocate(node, 1);
    node = NULL;
}

template <class T, class Allocator>
BinarySearchTree<T, Allocator>::~BinarySearchTree()
{
    destroy(_root);
}

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
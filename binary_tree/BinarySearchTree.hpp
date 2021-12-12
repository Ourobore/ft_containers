/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:16:56 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/12 17:41:34 by lchapren         ###   ########.fr       */
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

  public:
    Node<T>*       _root;
    allocator_type _alloc;

  public:
    // Constructor
    BinarySearchTree(const allocator_type& allocator = allocator_type());
    ~BinarySearchTree();

    // Insert
    void insert(value_type value);
    void recursive_insert(Node<T>* new_node, Node<T>* node_root);
};

// Constructor
template <class T, class Allocator>
BinarySearchTree<T, Allocator>::BinarySearchTree(const allocator_type& allocator)
    : _root(NULL), _alloc(allocator)
{
}

template <class T, class Allocator>
BinarySearchTree<T, Allocator>::~BinarySearchTree()
{
}

template <class T, class Allocator>
void BinarySearchTree<T, Allocator>::recursive_insert(Node<T>* new_node, Node<T>* node_root)
{
    if (!node_root)
        node_root = new_node;
    else if (new_node->data() < node_root->data())
    {
        if (!node_root->left())
            node_root->set_left(new_node);
        else
            recursive_insert(new_node, node_root->left());
    }
    else if (new_node->data() > node_root->data())
    {
        if (!node_root->right())
            node_root->set_right(new_node);
        else
            recursive_insert(new_node, node_root->right());
    }
}

template <class T, class Allocator>
void BinarySearchTree<T, Allocator>::insert(value_type value)
{
    Node<T>* new_node;
    new_node = _alloc.allocate(1);
    _root = new_node;
    // recursive_insert(&new_node, this->_root);
}

} // namespace ft

#endif
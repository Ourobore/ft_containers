/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:48:48 by lena              #+#    #+#             */
/*   Updated: 2022/01/13 15:06:14 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>

#include "BinarySearchTree.hpp"
#include "RBNode.hpp"

namespace ft
{

template < class Key, class T, class Compare = std::less< Key >, class Allocator = std::allocator< ft::pair<const Key, T> >, class NodeType = RBNode< typename Allocator::value_type > >
class RBTree : public BinarySearchTree<Key, T, Compare, Allocator, NodeType>
{
  public:
    typedef typename Allocator::value_type value_type;
    typedef RBNode< value_type >           node_type;
    typedef std::size_t                    size_type;

  protected: // Change to protected?
    enum direction
    {
        left,
        right
    };

  private:
    // Insert rebalance cases
    void insert_rebalance_1(node_type* node);
    void insert_rebalance_2(node_type* node);
    void insert_rebalance_3(node_type* node);

  public:
    // Insert
    ft::pair<node_type*, bool> insert(const value_type& value);

    // Rotations
    node_type* rotate_dir(node_type* subtree_root, enum direction direction);
    node_type* rotate_left(node_type* subtree_root);
    node_type* rotate_right(node_type* subtree_root);

    // Utility
    static size_type black_height(node_type* node);
};

// Insert
template < class Key, class T, class Compare, class Allocator, class NodeType >
ft::pair<typename RBTree< Key, T, Compare, Allocator, NodeType >::node_type*, bool> RBTree< Key, T, Compare, Allocator, NodeType >::insert(const value_type& value)
{
    ft::pair<node_type*, bool> node_inserted = BinarySearchTree<Key, T, Compare, Allocator, NodeType >::insert(value);
    node_type*                 node = node_inserted.first;

    // If parent is also red, that is a tree violation that need fixing
    if (node_inserted.second && node->parent() && node->parent()->color() == red)
    {
        node_type* auntie = node->auntie();
        if (auntie && auntie->color() == red)
            insert_rebalance_1(auntie->parent());
        else if (node->parent()->left() == node)
            insert_rebalance_2(node->parent());
        else if (node->parent()->right() == node)
            insert_rebalance_3(node->parent());
    }

    return (node_inserted);
}

// Insert rebalance cases
template < class Key, class T, class Compare, class Allocator, class NodeType >
void RBTree<Key, T, Compare, Allocator, NodeType>::insert_rebalance_1(node_type* node_grandparent)
{
    // If node's auntie is also red, just recolor parent, grandparent and auntie
    node_grandparent->set_color(red);
    node_grandparent->left()->set_color(black);
    node_grandparent->right()->set_color(black);
}

template < class Key, class T, class Compare, class Allocator, class NodeType >
void RBTree<Key, T, Compare, Allocator, NodeType>::insert_rebalance_2(node_type* node_parent)
{
    // If node is left child of parent, do a right rotation on node's parent
    node_type* new_subtree_root = rotate_right(node_parent);
    if (new_subtree_root)
    {
        new_subtree_root->set_color(black);
        if (new_subtree_root->right())
            new_subtree_root->right()->set_color(red);
    }
}

template < class Key, class T, class Compare, class Allocator, class NodeType >
void RBTree<Key, T, Compare, Allocator, NodeType>::insert_rebalance_3(node_type* node_parent)
{
    // If node is right child of parent, do a left rotation on node's parent, then a right rotation on the new parent
    node_type* left_rotation_parent = rotate_left(node_parent);

    if (left_rotation_parent)
    {
        left_rotation_parent->set_color(black);
        if (left_rotation_parent->left())
            left_rotation_parent->left()->set_color(red);

        insert_rebalance_2(left_rotation_parent);
    }
}

// Rotations
template < class Key, class T, class Compare, class Allocator, class NodeType >
typename RBTree<Key, T, Compare, Allocator, NodeType>::node_type* RBTree<Key, T, Compare, Allocator, NodeType>::rotate_dir(node_type* subtree_root, enum direction direction)
{
    node_type* ancestor = subtree_root->parent();
    node_type* opposite_child = (direction == left ? subtree_root->right() : subtree_root->right());

    // This node is the new subtree root
    if (!opposite_child)
        return (NULL);

    // Get child that will change branches, and make it switch branches
    node_type* child_of_child = (direction == left ? opposite_child->left() : opposite_child->right());
    if (direction == left)
        subtree_root->set_right(child_of_child);
    else
        subtree_root->set_left(child_of_child);
    if (child_of_child)
        child_of_child->set_parent(subtree_root); // Delete?

    if (direction == left)
        opposite_child->set_left(subtree_root);
    else
        opposite_child->set_right(subtree_root);
    subtree_root->set_parent(opposite_child); // Delete?

    // Setup opposite child as new subtree root
    opposite_child->set_parent(ancestor);
    if (ancestor)
    {
        if (ancestor->right() && ancestor->right() == subtree_root)
            ancestor->set_right(opposite_child);
        else
            ancestor->set_left(opposite_child);
    }
    else
        this->set_root(opposite_child);

    return (opposite_child);
}

template < class Key, class T, class Compare, class Allocator, class NodeType >
typename RBTree<Key, T, Compare, Allocator, NodeType>::node_type* RBTree<Key, T, Compare, Allocator, NodeType>::rotate_left(node_type* subtree_root)
{
    return (rotate_dir(subtree_root, left));
}

template < class Key, class T, class Compare, class Allocator, class NodeType >
typename RBTree<Key, T, Compare, Allocator, NodeType>::node_type* RBTree<Key, T, Compare, Allocator, NodeType>::rotate_right(node_type* subtree_root)
{
    return (rotate_dir(subtree_root, right));
}

// Utility
template < class Key, class T, class Compare, class Allocator, class NodeType >
typename RBTree<Key, T, Compare, Allocator, NodeType>::size_type RBTree<Key, T, Compare, Allocator, NodeType>::black_height(node_type* node)
{
    return (node->black_height());
}

} // namespace ft

#endif
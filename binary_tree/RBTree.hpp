/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:48:48 by lena              #+#    #+#             */
/*   Updated: 2022/01/14 17:19:28 by lchapren         ###   ########.fr       */
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
    void       insert_rebalance_wrapper(ft::pair<node_type*, bool> node_inserted);
    node_type* insert_rebalance_color(node_type* node);
    node_type* insert_rebalance_left(node_type* node);
    node_type* insert_rebalance_right(node_type* node);

  public:
    // Insert
    ft::pair<node_type*, bool> insert(const value_type& value);
    ft::pair<node_type*, bool> insert(node_type* hint, const value_type& value);

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
    insert_rebalance_wrapper(node_inserted);

    return (node_inserted);
}

template < class Key, class T, class Compare, class Allocator, class NodeType >
ft::pair<typename RBTree< Key, T, Compare, Allocator, NodeType >::node_type*, bool> RBTree< Key, T, Compare, Allocator, NodeType >::insert(node_type* hint, const value_type& value)
{
    ft::pair<node_type*, bool> node_inserted = BinarySearchTree<Key, T, Compare, Allocator, NodeType >::insert(hint, value);
    insert_rebalance_wrapper(node_inserted);

    return (node_inserted);
}

// Insert rebalance cases
template < class Key, class T, class Compare, class Allocator, class NodeType >
void RBTree<Key, T, Compare, Allocator, NodeType>::insert_rebalance_wrapper(ft::pair<node_type*, bool> node_inserted)
{
    // If node was really inserted
    if (node_inserted.second)
    {
        node_type* node = node_inserted.first;

        // Need to check red violation
        while (node->parent() && node->parent()->color() == RBNode< value_type >::red)
        {
            node_type* auntie = node->auntie();
            // If auntie exists and is also red
            if (auntie && auntie->color() == RBNode<value_type>::red)
                node = insert_rebalance_color(auntie->parent());

            // If parent is left child of grandparent
            else if (node->parent() == node->parent()->parent()->left())
                node = insert_rebalance_left(node);

            // If parent is right child of grandparent
            else
                node = insert_rebalance_right(node);
        }
        this->root()->set_color(RBNode<value_type>::black);
    }
}

template < class Key, class T, class Compare, class Allocator, class NodeType >
typename RBTree<Key, T, Compare, Allocator, NodeType>::node_type* RBTree<Key, T, Compare, Allocator, NodeType>::insert_rebalance_color(node_type* node_grandparent)
{
    // If node's auntie is also red, just recolor parent, grandparent and auntie
    node_grandparent->set_color(RBNode<value_type>::red);
    node_grandparent->left()->set_color(RBNode<value_type>::black);
    node_grandparent->right()->set_color(RBNode<value_type>::black);

    // New node to check is now grandparent
    return (node_grandparent);
}

template < class Key, class T, class Compare, class Allocator, class NodeType >
typename RBTree<Key, T, Compare, Allocator, NodeType>::node_type* RBTree<Key, T, Compare, Allocator, NodeType>::insert_rebalance_left(node_type* node)
{
    // If node is right child of parent
    if (node == node->parent()->right())
    {
        // Update node as node's parent, then do a left rotation on node's parent
        node = node->parent();
        rotate_left(node);
    }

    // Recolor and do a right rotation on node's parent
    node->parent()->set_color(RBNode<value_type>::black);
    node->parent()->parent()->set_color(RBNode<value_type>::red);
    rotate_right(node->parent()->parent());

    // New node to check is now node's parent if left-right rotation, or node
    return (node);
}

template < class Key, class T, class Compare, class Allocator, class NodeType >
typename RBTree<Key, T, Compare, Allocator, NodeType>::node_type* RBTree<Key, T, Compare, Allocator, NodeType>::insert_rebalance_right(node_type* node)
{
    // If node is left child of parent
    if (node == node->parent()->left())
    {
        // Update node as node's parent, then do a right rotation on node's parent
        node = node->parent();
        rotate_right(node);
    }

    // Recolor and do a left rotation on node's parent
    node->parent()->set_color(RBNode<value_type>::black);
    node->parent()->parent()->set_color(RBNode<value_type>::red);
    rotate_left(node->parent()->parent());

    // New node to check is now node's parent if right-left rotation, or node
    return (node);
}

// Rotations
template < class Key, class T, class Compare, class Allocator, class NodeType >
typename RBTree<Key, T, Compare, Allocator, NodeType>::node_type* RBTree<Key, T, Compare, Allocator, NodeType>::rotate_dir(node_type* subtree_root, enum direction direction)
{
    node_type* ancestor = subtree_root->parent();
    node_type* opposite_child = (direction == left ? subtree_root->right() : subtree_root->left());

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
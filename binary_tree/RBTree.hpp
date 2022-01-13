/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:48:48 by lena              #+#    #+#             */
/*   Updated: 2022/01/13 12:23:13 by lchapren         ###   ########.fr       */
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

  public: // Change to protected?
    enum direction
    {
        left,
        right
    };

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
    BinarySearchTree<Key, T, Compare, Allocator, NodeType >::insert(value);

    node_type* null = NULL;
    return (ft::make_pair(null, false));
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
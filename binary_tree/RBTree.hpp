/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lena <lena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:48:48 by lena              #+#    #+#             */
/*   Updated: 2022/01/07 10:57:12 by lena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

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

  protected:
  public:
};

} // namespace ft

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:38:10 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/12 14:07:16 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

#include "iterator/BidirectionalIterator.hpp"
#include "iterator/IteratorTraits.hpp"
#include "iterator/ReverseIterator.hpp"

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< std::pair<const Key, T> > >
class map
{
  public:
    typedef Key                                    key_type;
    typedef T                                      mapped_type;
    typedef std::pair<const key_type, mapped_type> value_type;
    typedef Compare                                key_compare;
    // typedef Compare value_compare;

    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;

    typedef BidirectionalIterator<value_type>       iterator;
    typedef BidirectionalIterator<const value_type> const_iterator;
    typedef ReverseIterator<iterator>               reverse_iterator;
    typedef ReverseIterator<const_iterator>         const_reverse_iterator;

    typedef typename iterator_traits<iterator>::difference_type difference_type;
    typedef std::size_t                                         size_type;

  private:
    allocator_type _alloc;

  public:
    // Capacity
    size_type max_size() const;

    // Allocator
    allocator_type get_allocator() const;
};

// Capacity
template < class Key, class T, class Compare, class Allocator >
typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::max_size() const
{
    return (_alloc.max_size());
}

// Allocator
template < class Key, class T, class Compare, class Allocator >
typename map<Key, T, Compare, Allocator>::allocator_type map<Key, T, Compare, Allocator>::get_allocator() const
{
    return (_alloc);
}

} // namespace ft

#endif
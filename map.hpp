/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:38:10 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/19 17:21:07 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

#include "iterator/BidirectionalIterator.hpp"
#include "iterator/IteratorTraits.hpp"
#include "iterator/ReverseIterator.hpp"
#include "iterator/TreeIterator.hpp"

#include "binary_tree/BinarySearchTree.hpp"

#include "utils/Pair.hpp"

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< ft::pair<const Key, T> > >
class map
{
  public:
    typedef Key                            key_type;
    typedef T                              mapped_type;
    typedef typename Allocator::value_type value_type;
    typedef Compare                        key_compare;

    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;

    typedef TreeIterator<value_type>        iterator;
    typedef TreeIterator<const value_type>  const_iterator;
    typedef ReverseIterator<iterator>       reverse_iterator;
    typedef ReverseIterator<const_iterator> const_reverse_iterator;

    typedef typename iterator_traits<iterator>::difference_type difference_type;
    typedef std::size_t                                         size_type;

    class value_compare : std::binary_function<value_type, value_type, bool>
    {
        friend class map;

      protected:
        Compare comp;
        value_compare(Compare c)
            : comp(c)
        {
        }

      public:
        typedef bool       result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;
        bool               operator()(const value_type& x, const value_type& y) const
        {
            return comp(x.first, y.first);
        }
    };

  public:
    typedef BinarySearchTree<value_type>                                 tree_type;
    typedef typename allocator_type::template rebind< tree_type >::other tree_allocator;

    BinarySearchTree<value_type> _tree;
    size_type                    _size;
    key_compare                  _comp;
    allocator_type               _alloc;

  public:
    // Constructor
    explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

    // Iterators
    iterator begin();
    iterator end();

    // Capacity
    bool      empty() const;
    size_type size() const;
    size_type max_size() const;

    // Observers
    key_compare   key_comp() const;
    value_compare value_comp() const;

    // Allocator
    allocator_type       get_allocator() const;
    pair<iterator, bool> insert(const value_type& val);
};

// Constructor
template < class Key, class T, class Compare, class Allocator >
map<Key, T, Compare, Allocator>::map(const key_compare& comp, const allocator_type& alloc)
    : _tree(), _size(0), _comp(comp), _alloc(alloc)
{
}

// Iterators
template < class Key, class T, class Compare, class Allocator >
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::begin()
{
    return (iterator(_tree.min_elem(_tree.root())));
}

// Iterators
template < class Key, class T, class Compare, class Allocator >
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::end()
{
    return (iterator(NULL));
}

// Capacity
template < class Key, class T, class Compare, class Allocator >
bool map<Key, T, Compare, Allocator>::empty() const
{
    return (_size == 0);
}

template < class Key, class T, class Compare, class Allocator >
typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::size() const
{
    return (_size);
}

template < class Key, class T, class Compare, class Allocator >
typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::max_size() const
{
    return (_alloc.max_size());
}

// Observers
template < class Key, class T, class Compare, class Allocator >
typename map<Key, T, Compare, Allocator>::key_compare map<Key, T, Compare, Allocator>::key_comp() const
{
    return (_comp);
}

template < class Key, class T, class Compare, class Allocator >
typename map<Key, T, Compare, Allocator>::value_compare map<Key, T, Compare, Allocator>::value_comp() const
{
    return (value_compare(_comp));
}

// Allocator
template < class Key, class T, class Compare, class Allocator >
typename map<Key, T, Compare, Allocator>::allocator_type map<Key, T, Compare, Allocator>::get_allocator() const
{
    return (_alloc);
}

template < class Key, class T, class Compare, class Allocator >
pair<typename map<Key, T, Compare, Allocator>::iterator, bool> map<Key, T, Compare, Allocator>::insert(const value_type& val)
{
    _tree.insert(val);
    _size++;
    return (make_pair(iterator(), true));
}
} // namespace ft

#endif
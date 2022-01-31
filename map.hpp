/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:38:10 by lchapren          #+#    #+#             */
/*   Updated: 2022/01/31 20:56:57 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

#include "iterator/IteratorTraits.hpp"
#include "iterator/ReverseIterator.hpp"
#include "iterator/TreeIterator.hpp"

#include "binary_tree/BinarySearchTree.hpp"
#include "binary_tree/Node.hpp"
#include "binary_tree/RBNode.hpp"
#include "binary_tree/RBNodePair.hpp"
#include "binary_tree/RBTree.hpp"

#include "utils/LexicographicalCompare.hpp"
#include "utils/Pair.hpp"

namespace ft
{

template < class Key, class T, class Compare = std::less< Key >, class Allocator = std::allocator< ft::pair< const Key, T > > >
class map
{
  public:
    typedef Key                    key_type;
    typedef T                      mapped_type;
    typedef ft::pair<const Key, T> value_type;
    typedef Compare                key_compare;

    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;

    typedef RBNodePair<value_type, key_compare> node_type;
    typedef TreeIterator< node_type, false >    iterator;
    typedef TreeIterator< node_type, true >     const_iterator;
    typedef ReverseIterator< iterator >         reverse_iterator;
    typedef ReverseIterator< const_iterator >   const_reverse_iterator;

    typedef typename iterator_traits< iterator >::difference_type difference_type;
    typedef std::size_t                                           size_type;

    class value_compare : std::binary_function< value_type, value_type, bool >
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

  protected:
    typedef RBTree< key_type, mapped_type, key_compare, allocator_type, node_type > tree_type;
    typedef typename allocator_type::template rebind< tree_type >::other            tree_allocator;

    tree_type      _tree;
    size_type      _size;
    key_compare    _comp;
    allocator_type _alloc;

  public:
    // Constructors and Destructor
    explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
    template < class InputIterator >
    map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
    map(const map& x);
    ~map();
    map& operator=(const map& rhs);

    // Iterators
    iterator               begin();
    const_iterator         begin() const;
    iterator               end();
    const_iterator         end() const;
    reverse_iterator       rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator       rend();
    const_reverse_iterator rend() const;

    // Capacity
    bool      empty() const;
    size_type size() const;
    size_type max_size() const;

    // Element Access
    mapped_type& operator[](const key_type& k);

    // Modifiers
    template <class InputIterator>
    void                       insert(InputIterator first, InputIterator last);
    ft::pair< iterator, bool > insert(const value_type& val);
    iterator                   insert(iterator position, const value_type& val);
    void                       erase(iterator position);
    size_type                  erase(const key_type& k);
    void                       erase(iterator first, iterator last);
    void                       swap(map& x);
    void                       clear();

    // Observers
    key_compare   key_comp() const;
    value_compare value_comp() const;

    // Operations
    iterator                               find(const key_type& k);
    const_iterator                         find(const key_type& k) const;
    size_type                              count(const key_type& k) const;
    iterator                               lower_bound(const key_type& k);
    const_iterator                         lower_bound(const key_type& k) const;
    iterator                               upper_bound(const key_type& k);
    const_iterator                         upper_bound(const key_type& k) const;
    pair< iterator, iterator >             equal_range(const key_type& k);
    pair< const_iterator, const_iterator > equal_range(const key_type& k) const;

    // Allocator
    allocator_type get_allocator() const;
};

// Constructors and Destructor
template < class Key, class T, class Compare, class Allocator >
map< Key, T, Compare, Allocator >::map(const key_compare& comp, const allocator_type& alloc)
    : _tree(), _size(0), _comp(comp), _alloc(alloc)
{
}

template < class Key, class T, class Compare, class Allocator >
template < class InputIterator >
map< Key, T, Compare, Allocator >::map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc)
    : _tree(), _size(0), _comp(comp), _alloc(alloc)
{
    insert(first, last);
}

template < class Key, class T, class Compare, class Allocator >
map< Key, T, Compare, Allocator >::map(const map& x)
    : _tree(x._tree), _size(x._size), _comp(x._comp), _alloc(x._alloc)
{
}

template < class Key, class T, class Compare, class Allocator >
map< Key, T, Compare, Allocator >::~map()
{
    this->clear();
}

template < class Key, class T, class Compare, class Allocator >
map< Key, T, Compare, Allocator >& map< Key, T, Compare, Allocator >::operator=(const map& rhs)
{
    this->clear();

    map::const_iterator cit;
    for (cit = rhs.begin(); cit != rhs.end(); ++cit, ++_size)
        _tree.insert(*cit);

    return (*this);
}

// Iterators
template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::iterator map< Key, T, Compare, Allocator >::begin()
{
    return (iterator(tree_type::far_left(_tree.root())));
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::const_iterator map< Key, T, Compare, Allocator >::begin() const
{
    return (const_iterator(tree_type::far_left(_tree.root())));
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::iterator map< Key, T, Compare, Allocator >::end()
{
    return (++iterator(tree_type::far_right(_tree.root())));
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::const_iterator map< Key, T, Compare, Allocator >::end() const
{
    return (++iterator(tree_type::far_right(_tree.root())));
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::reverse_iterator map< Key, T, Compare, Allocator >::rbegin()
{
    return (reverse_iterator(end()));
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::const_reverse_iterator map< Key, T, Compare, Allocator >::rbegin() const
{
    return (const_reverse_iterator(end()));
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::reverse_iterator map< Key, T, Compare, Allocator >::rend()
{
    return (reverse_iterator(begin()));
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::const_reverse_iterator map< Key, T, Compare, Allocator >::rend() const
{
    return (const_reverse_iterator(begin()));
}

// Capacity
template < class Key, class T, class Compare, class Allocator >
bool map< Key, T, Compare, Allocator >::empty() const
{
    return (_size == 0);
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::size_type map< Key, T, Compare, Allocator >::size() const
{
    return (_size);
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::size_type map< Key, T, Compare, Allocator >::max_size() const
{
    return (_alloc.max_size());
}

// Element Access
template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::mapped_type& map< Key, T, Compare, Allocator >::operator[](const key_type& k)
{
    return ((*((this->insert(ft::make_pair(k, mapped_type()))).first)).second);
}

// Modifiers
template < class Key, class T, class Compare, class Allocator >
ft::pair< typename map< Key, T, Compare, Allocator >::iterator, bool > map< Key, T, Compare, Allocator >::insert(const value_type& val)
{
    map::iterator it;

    // If we get a node back, the node is inserted (or already inserted)
    ft::pair<node_type*, bool> node_inserted = _tree.insert(val);
    if (node_inserted.first)
    {
        // If not already inserted
        if (node_inserted.second)
            _size++;
        it = iterator(node_inserted.first);
    }
    else
        it = end();

    return (ft::make_pair(it, node_inserted.second));
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::iterator map< Key, T, Compare, Allocator >::insert(iterator position, const value_type& val)
{
    map::iterator it;

    // If we get a node back, the node is inserted (or already inserted)
    ft::pair<node_type*, bool> node_inserted = _tree.insert(position.getPointer(), val);
    if (node_inserted.first)
    {
        // If not already inserted
        if (node_inserted.second)
            _size++;
        it = iterator(node_inserted.first);
    }
    else
        it = end();

    return (it);
}

template < class Key, class T, class Compare, class Allocator >
template <class InputIterator>
void map<Key, T, Compare, Allocator>::insert(InputIterator first, InputIterator last)
{
    InputIterator it;
    for (it = first; it != last; ++it)
        insert(*it);
}

template < class Key, class T, class Compare, class Allocator >
void map< Key, T, Compare, Allocator >::erase(iterator position)
{
    _tree.erase(position.getPointer());
    --_size;
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::size_type map< Key, T, Compare, Allocator >::erase(const key_type& k)
{
    map::iterator it = find(k);

    if (it != end())
    {
        _tree.erase(it.getPointer());
        --_size;
        return (size_type(1));
    }
    else
        return (size_type(0));
}

template < class Key, class T, class Compare, class Allocator >
void map< Key, T, Compare, Allocator >::erase(iterator first, iterator last)
{
    map::iterator it;

    while (first != last)
    {
        it = first;
        ++first;
        erase(it);
    }
}

template < class Key, class T, class Compare, class Allocator >
void map< Key, T, Compare, Allocator >::swap(map& x)
{
    typename tree_type::node_type* tmp_tree = _tree.root();
    _tree.set_root(x._tree.root());
    x._tree.set_root(tmp_tree);

    size_type tmp_size = size();
    _size = x.size();
    x._size = tmp_size;
}

template < class Key, class T, class Compare, class Allocator >
void map< Key, T, Compare, Allocator >::clear()
{
    tree_allocator allocator;
    allocator.destroy(&_tree);
    _size = 0;
}

// Observers
template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::key_compare map< Key, T, Compare, Allocator >::key_comp() const
{
    return (_comp);
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::value_compare map< Key, T, Compare, Allocator >::value_comp() const
{
    return (value_compare(_comp));
}

// Operations
template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::iterator map< Key, T, Compare, Allocator >::find(const key_type& k)
{
    return (iterator(_tree.search(k)));
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::const_iterator map< Key, T, Compare, Allocator >::find(const key_type& k) const
{
    return (const_iterator(_tree.search(k)));
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::size_type map< Key, T, Compare, Allocator >::count(const key_type& k) const
{
    if (find(k) == end())
        return (0);
    else
        return (1);
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::iterator map< Key, T, Compare, Allocator >::lower_bound(const key_type& k)
{
    // Could use a node_pointer, but with iterator we already have return value. Let's see computation time
    // typename BinarySearchTree<T>::node_type* node_pointer;

    map::iterator it = begin();

    while (it != end())
    {
        if (!key_comp()(it->first, k))
            break;
        ++it;
    }
    return (it);
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::const_iterator map< Key, T, Compare, Allocator >::lower_bound(const key_type& k) const
{
    map::const_iterator it = begin();

    while (it != end())
    {
        if (!key_comp()(it->first, k))
            break;
        ++it;
    }
    return (it);
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::iterator map< Key, T, Compare, Allocator >::upper_bound(const key_type& k)
{
    map::iterator it = begin();

    while (it != end())
    {
        if (key_comp()(k, it->first))
            break;
        ++it;
    }
    return (it);
}

template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::const_iterator map< Key, T, Compare, Allocator >::upper_bound(const key_type& k) const
{
    map::const_iterator it = begin();

    while (it != end())
    {
        if (key_comp()(k, it->first))
            break;
        ++it;
    }
    return (it);
}

template < class Key, class T, class Compare, class Allocator >
pair< typename map< Key, T, Compare, Allocator >::iterator, typename map< Key, T, Compare, Allocator >::iterator > map< Key, T, Compare, Allocator >::equal_range(const key_type& k)
{
    return (ft::make_pair(lower_bound(k), upper_bound(k)));
}

template < class Key, class T, class Compare, class Allocator >
pair< typename map< Key, T, Compare, Allocator >::const_iterator, typename map< Key, T, Compare, Allocator >::const_iterator > map< Key, T, Compare, Allocator >::equal_range(const key_type& k) const
{
    return (ft::make_pair(lower_bound(k), upper_bound(k)));
}

// Allocator
template < class Key, class T, class Compare, class Allocator >
typename map< Key, T, Compare, Allocator >::allocator_type map< Key, T, Compare, Allocator >::get_allocator() const
{
    return (_alloc);
}

template <class Key, class T, class Compare, class Alloc>
void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y)
{
    x.swap(y);
}

// Relational
template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
{
    if (lhs.size() != rhs.size())
        return (false);
    if (!(lhs < rhs) && !(rhs < lhs))
        return (true);
    else
        return (false);
}

template <class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
{
    return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Allocator>
bool operator<(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
{
    if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
        return (true);
    else
        return (false);
}

template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
{
    return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Allocator>
bool operator>(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
{
    return (rhs < lhs);
}

template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs)
{
    return (!(lhs < rhs));
}

} // namespace ft

#endif

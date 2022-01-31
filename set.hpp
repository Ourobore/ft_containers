/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:19:05 by lchapren          #+#    #+#             */
/*   Updated: 2022/01/31 22:54:53 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "iostream"

#include "map.hpp"

namespace ft
{

template < class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class set
{
  public:
    typedef T       key_type;
    typedef T       value_type;
    typedef Compare key_compare;
    typedef Compare value_compare;

    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;

    typedef RBNode<value_type, Compare>       node_type;
    typedef TreeIterator< node_type, true >   iterator;
    typedef TreeIterator< node_type, true >   const_iterator;
    typedef ReverseIterator< iterator >       reverse_iterator;
    typedef ReverseIterator< const_iterator > const_reverse_iterator;

    typedef typename iterator_traits< iterator >::difference_type difference_type;
    typedef std::size_t                                           size_type;

  protected:
    typedef RBTree< key_type, key_type, key_compare, allocator_type, node_type > tree_type;
    typedef typename allocator_type::template rebind< tree_type >::other         tree_allocator;

    tree_type      _tree;
    size_type      _size;
    key_compare    _comp;
    allocator_type _alloc;

  public:
    // Constructors and Destructor
    explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
    template <class InputIterator>
    set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
    set(const set& x);
    ~set();
    set& operator=(const set& x);

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

    // Modifiers
    template <class InputIterator>
    void                 insert(InputIterator first, InputIterator last);
    pair<iterator, bool> insert(const value_type& val);
    iterator             insert(iterator position, const value_type& val);
    void                 erase(iterator position);
    size_type            erase(const value_type& val);
    void                 erase(iterator first, iterator last);
    void                 swap(set& x);
    void                 clear();

    // Observers
    key_compare   key_comp() const;
    value_compare value_comp() const;

    // Operations
    iterator                             find(const value_type& val) const;
    size_type                            count(const value_type& val) const;
    iterator                             lower_bound(const value_type& val);
    const_iterator                       lower_bound(const value_type& val) const;
    iterator                             upper_bound(const value_type& val);
    const_iterator                       upper_bound(const value_type& val) const;
    pair<iterator, iterator>             equal_range(const value_type& val);
    pair<const_iterator, const_iterator> equal_range(const value_type& val) const;

    // Allocator
    allocator_type get_allocator() const;
};

// Constructors and Destructor
template < class T, class Compare, class Allocator >
set<T, Compare, Allocator>::set(const key_compare& comp, const allocator_type& alloc)
    : _tree(), _size(0), _comp(comp), _alloc(alloc)
{
}

template < class T, class Compare, class Allocator >
template < class InputIterator >
set<T, Compare, Allocator>::set(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc)
    : _tree(), _size(0), _comp(comp), _alloc(alloc)
{
    insert(first, last);
}

template < class T, class Compare, class Allocator >
set<T, Compare, Allocator>::set(const set& x)
    : _tree(x._tree), _size(x._size), _comp(x._comp), _alloc(x._alloc)
{
}

template < class T, class Compare, class Allocator >
set<T, Compare, Allocator>::~set()
{
    this->clear();
}

template < class T, class Compare, class Allocator >
set<T, Compare, Allocator>& set<T, Compare, Allocator>::operator=(const set& x)
{
    this->clear();

    set::const_iterator cit;
    for (cit = x.begin(); cit != x.end(); ++cit, ++_size)
        _tree.insert(*cit);

    return (*this);
}

// Iterators
template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::begin()
{
    return (iterator(tree_type::far_left(_tree.root())));
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::const_iterator set<T, Compare, Allocator>::begin() const
{
    return (const_iterator(tree_type::far_left(_tree.root())));
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::end()
{
    return (++iterator(tree_type::far_right(_tree.root())));
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::const_iterator set<T, Compare, Allocator>::end() const
{
    return (++const_iterator(tree_type::far_right(_tree.root())));
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::reverse_iterator set<T, Compare, Allocator>::rbegin()
{
    return (reverse_iterator(end()));
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::const_reverse_iterator set<T, Compare, Allocator>::rbegin() const
{
    return (const_reverse_iterator(end()));
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::reverse_iterator set<T, Compare, Allocator>::rend()
{
    return (reverse_iterator(begin()));
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::const_reverse_iterator set<T, Compare, Allocator>::rend() const
{
    return (const_reverse_iterator(begin()));
}

// Capacity
template < class T, class Compare, class Allocator >
bool set<T, Compare, Allocator>::empty() const
{
    return (_size == 0);
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::size() const
{
    return (_size);
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::max_size() const
{
    return (_alloc.max_size());
}

// Modifiers
template < class T, class Compare, class Allocator >
ft::pair<typename set<T, Compare, Allocator>::iterator, bool> set<T, Compare, Allocator>::insert(const value_type& val)
{
    set::iterator it;

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

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::insert(iterator position, const value_type& val)
{
    set::iterator it;

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

template < class T, class Compare, class Allocator >
template <class InputIterator>
void set<T, Compare, Allocator>::insert(InputIterator first, InputIterator last)
{
    InputIterator it;
    for (it = first; it != last; ++it)
        insert(*it);
}

template < class T, class Compare, class Allocator >
void set<T, Compare, Allocator>::erase(iterator position)
{
    _tree.erase(position.getPointer());
    --_size;
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::erase(const value_type& val)
{
    set::iterator it = find(val);

    if (it != end())
    {
        _tree.erase(it.getPointer());
        --_size;
        return (size_type(1));
    }
    else
        return (size_type(0));
}

template < class T, class Compare, class Allocator >
void set<T, Compare, Allocator>::erase(iterator first, iterator last)
{
    set::iterator it;

    while (first != last)
    {
        it = first;
        ++first;
        erase(it);
    }
}

template < class T, class Compare, class Allocator >
void set<T, Compare, Allocator>::swap(set& x)
{
    typename tree_type::node_type* tmp_tree = _tree.root();
    _tree.set_root(x._tree.root());
    x._tree.set_root(tmp_tree);

    size_type tmp_size = size();
    _size = x.size();
    x._size = tmp_size;
}

template < class T, class Compare, class Allocator >
void set<T, Compare, Allocator>::clear()
{
    tree_allocator allocator;
    allocator.destroy(&_tree);
    _size = 0;
}

// Observers
template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::key_compare set<T, Compare, Allocator>::key_comp() const
{
    return (_comp);
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::value_compare set<T, Compare, Allocator>::value_comp() const
{
    return (_comp);
}

// Operations
template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::find(const value_type& val) const
{
    return (iterator(_tree.search(val)));
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::count(const value_type& val) const
{
    if (find(val) == end())
        return (0);
    else
        return (1);
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::lower_bound(const value_type& val)
{
    set::iterator it = begin();
    while (it != end())
    {
        if (!key_comp()(*it, val))
            break;
        ++it;
    }
    return (it);
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::const_iterator set<T, Compare, Allocator>::lower_bound(const value_type& val) const
{
    set::const_iterator it = begin();
    while (it != end())
    {
        if (!key_comp()(*it, val))
            break;
        ++it;
    }
    return (it);
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::upper_bound(const value_type& val)
{
    set::iterator it = begin();
    while (it != end())
    {
        if (key_comp()(val, *it))
            break;
        ++it;
    }
    return (it);
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::const_iterator set<T, Compare, Allocator>::upper_bound(const value_type& val) const
{
    set::const_iterator it = begin();
    while (it != end())
    {
        if (key_comp()(val, *it))
            break;
        ++it;
    }
    return (it);
}

template < class T, class Compare, class Allocator >
ft::pair<typename set<T, Compare, Allocator>::iterator, typename set<T, Compare, Allocator>::iterator> set<T, Compare, Allocator>::equal_range(const value_type& val)
{
    return (ft::make_pair(lower_bound(val), upper_bound(val)));
}

template < class T, class Compare, class Allocator >
ft::pair<typename set<T, Compare, Allocator>::const_iterator, typename set<T, Compare, Allocator>::const_iterator> set<T, Compare, Allocator>::equal_range(const value_type& val) const
{
    return (ft::make_pair(lower_bound(val), upper_bound(val)));
}

// Allocator
template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::allocator_type set<T, Compare, Allocator>::get_allocator() const
{
    return (_alloc);
}

template <class T, class Compare, class Alloc>
void swap(set<T, Compare, Alloc>& x, set<T, Compare, Alloc>& y)
{
    x.swap(y);
}

// Relational
template < class T, class Compare, class Allocator >
bool operator==(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs)
{
    if (lhs.size() != rhs.size())
        return (false);
    if (!(lhs < rhs) && !(rhs < lhs))
        return (true);
    else
        return (false);
}

template < class T, class Compare, class Allocator >
bool operator!=(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs)
{
    return (!(lhs == rhs));
}

template < class T, class Compare, class Allocator >
bool operator<(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs)
{
    if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
        return (true);
    else
        return (false);
}

template < class T, class Compare, class Allocator >
bool operator<=(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs)
{
    return (!(rhs < lhs));
}

template < class T, class Compare, class Allocator >
bool operator>(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs)
{
    return (rhs < lhs);
}

template < class T, class Compare, class Allocator >
bool operator>=(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs)
{
    return (!(lhs < rhs));
}

} // namespace ft

#endif

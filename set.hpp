/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:19:05 by lchapren          #+#    #+#             */
/*   Updated: 2022/01/31 10:23:37 by lchapren         ###   ########.fr       */
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
    typedef TreeIterator< node_type, false >  iterator;
    typedef TreeIterator< node_type, true >   const_iterator;
    typedef ReverseIterator< iterator >       reverse_iterator;
    typedef ReverseIterator< const_iterator > const_reverse_iterator;

    typedef typename iterator_traits< iterator >::difference_type difference_type;
    typedef std::size_t                                           size_type;

  protected:
    typedef ft::map<T, T, Compare, Allocator> Container;

    Container _c;
    Container base() const;

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
    iterator                 find(const value_type& val) const;
    size_type                count(const value_type& val) const;
    iterator                 lower_bound(const value_type& val) const;
    iterator                 upper_bound(const value_type& val) const;
    pair<iterator, iterator> equal_range(const value_type& val) const;

    // Allocator
    allocator_type get_allocator() const;
};

// Constructors and Destructor
template < class T, class Compare, class Allocator >
set<T, Compare, Allocator>::set(const key_compare& comp, const allocator_type& alloc)
    : _c(comp, alloc)
{
}

template < class T, class Compare, class Allocator >
template < class InputIterator >
set<T, Compare, Allocator>::set(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc)
    : _c(first, last, comp, alloc)
{
}

template < class T, class Compare, class Allocator >
set<T, Compare, Allocator>::set(const set& x)
    : _c(x.base())
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
    _c = x.base();
}

// Iterators
template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::begin()
{
    return (_c.begin());
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::const_iterator set<T, Compare, Allocator>::begin() const
{
    return (_c.begin());
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::end()
{
    return (_c.end());
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::const_iterator set<T, Compare, Allocator>::end() const
{
    return (_c.end());
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::reverse_iterator set<T, Compare, Allocator>::rbegin()
{
    return (_c.rbegin());
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::const_reverse_iterator set<T, Compare, Allocator>::rbegin() const
{
    return (_c.rbegin());
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::reverse_iterator set<T, Compare, Allocator>::rend()
{
    return (_c.rend());
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::const_reverse_iterator set<T, Compare, Allocator>::rend() const
{
    return (_c.rend());
}

// Capacity
template < class T, class Compare, class Allocator >
bool set<T, Compare, Allocator>::empty() const
{
    return (_c.empty());
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::size() const
{
    return (_c.size());
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::max_size() const
{
    return (_c.max_size());
}

// Modifiers
template < class T, class Compare, class Allocator >
ft::pair<typename set<T, Compare, Allocator>::iterator, bool> set<T, Compare, Allocator>::insert(const value_type& val)
{
    return (_c.insert(val));
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::insert(iterator position, const value_type& val)
{
    return (_c.insert(position, val));
}

template < class T, class Compare, class Allocator >
template <class InputIterator>
void set<T, Compare, Allocator>::insert(InputIterator first, InputIterator last)
{
    _c.insert(first, last);
}

template < class T, class Compare, class Allocator >
void set<T, Compare, Allocator>::erase(iterator position)
{
    _c.erase(position);
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::erase(const value_type& val)
{
    return (_c.erase(val));
}

template < class T, class Compare, class Allocator >
void set<T, Compare, Allocator>::erase(iterator first, iterator last)
{
    return (_c.erase(first, last));
}

template < class T, class Compare, class Allocator >
void set<T, Compare, Allocator>::swap(set& x)
{
    _c.swap(x.base());
}

template < class T, class Compare, class Allocator >
void set<T, Compare, Allocator>::clear()
{
    _c.clear();
}

// Observers
template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::key_compare set<T, Compare, Allocator>::key_comp() const
{
    return (_c.key_comp());
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::value_compare set<T, Compare, Allocator>::value_comp() const
{
    return (_c.key_comp());
}

// Operations
template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::find(const value_type& val) const
{
    return (_c.find(val));
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::count(const value_type& val) const
{
    return (_c.count(val));
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::lower_bound(const value_type& val) const
{
    set::iterator it = begin();

    while (it != end() && key_comp()(val))
        ++it;
    return (it);
}

template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::upper_bound(const value_type& val) const
{
    set::iterator it = begin();

    while (it != end() && key_comp()(val))
        ++it;
    if (it != end() && !(val < it->first))
        ++it;
    return (it);
}

template < class T, class Compare, class Allocator >
ft::pair<typename set<T, Compare, Allocator>::iterator, typename set<T, Compare, Allocator>::iterator> set<T, Compare, Allocator>::equal_range(const value_type& val) const
{
    return (ft::make_pair(lower_bound(val), upper_bound(val)));
}

// Allocator
template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::allocator_type set<T, Compare, Allocator>::get_allocator() const
{
    return (_c.get_allocator());
}

// Base
template < class T, class Compare, class Allocator >
typename set<T, Compare, Allocator>::Container set<T, Compare, Allocator>::base() const
{
    return (_c);
}

} // namespace ft

#endif

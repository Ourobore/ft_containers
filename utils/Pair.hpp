/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:30:52 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/21 17:43:11 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{

template <class T1, class T2>
class pair
{
  public:
    typedef T1 first_type;
    typedef T2 second_type;

    first_type  first;
    second_type second;

    // Constructors
    pair();
    template <class U, class V>
    pair(const pair<U, V>& p);
    pair(const first_type& a, const second_type& b);

    // Assignment
    pair& operator=(const pair& p);

    // Relational
    template <class U, class V>
    friend bool operator==(const pair<U, V>& lhs, const pair<U, V>& rhs);

    template <class U, class V>
    friend bool operator!=(const pair<U, V>& lhs, const pair<U, V>& rhs);

    template <class U, class V>
    friend bool operator<(const pair<U, V>& lhs, const pair<U, V>& rhs);

    template <class U, class V>
    friend bool operator<=(const pair<U, V>& lhs, const pair<U, V>& rhs);

    template <class U, class V>
    friend bool operator>(const pair<U, V>& lhs, const pair<U, V>& rhs);

    template <class U, class V>
    friend bool operator>=(const pair<U, V>& lhs, const pair<U, V>& rhs);
};

// Constructors
template <class T1, class T2>
pair<T1, T2>::pair()
    : first(T1()), second(T2())
{
}

template <class T1, class T2>
template <class U, class V>
pair<T1, T2>::pair(const pair<U, V>& p)
    : first(p.first), second(p.second)
{
}

template <class T1, class T2>
pair<T1, T2>::pair(const first_type& a, const second_type& b)
    : first(a), second(b)
{
}

// Assignment
template <class T1, class T2>
pair<T1, T2>& pair<T1, T2>::operator=(const pair<T1, T2>& p)
{
    first = first_type(p.first);
    second = second_type(p.second);
    return (*this);
}

// Relational
template <class U, class V>
bool operator==(const pair<U, V>& lhs, const pair<U, V>& rhs)
{
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class U, class V>
bool operator!=(const pair<U, V>& lhs, const pair<U, V>& rhs)
{
    return !(lhs == rhs);
}

template <class U, class V>
bool operator<(const pair<U, V>& lhs, const pair<U, V>& rhs)
{
    return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class U, class V>
bool operator<=(const pair<U, V>& lhs, const pair<U, V>& rhs)
{
    return !(rhs < lhs);
}

template <class U, class V>
bool operator>(const pair<U, V>& lhs, const pair<U, V>& rhs)
{
    return (rhs < lhs);
}

template <class U, class V>
bool operator>=(const pair<U, V>& lhs, const pair<U, V>& rhs)
{
    return !(lhs < rhs);
}

// Make_Pair
template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y)
{
    return (pair<T1, T2>(x, y));
}

} // namespace ft

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:33:23 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/07 10:56:52 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "vector.hpp"

namespace ft
{

template < class T, class Container = vector<T> >
class stack
{
  public:
    typedef T           value_type;
    typedef Container   container_type;
    typedef std::size_t size_type;

  protected:
    Container _c;

  public:
    // Constructor
    explicit stack(const container_type& container = container_type());

    // Size
    bool      empty() const;
    size_type size() const;

    // Element access
    value_type&       top();
    const value_type& top() const;

    // Modifiers
    void push(const value_type& val);
    void pop();

    // Relational operators
    template <class R, class Cont>
    friend bool operator==(const stack<R, Cont>& lhs, const stack<R, Cont>& rhs);
    template <class R, class Cont>
    friend bool operator!=(const stack<R, Cont>& lhs, const stack<R, Cont>& rhs);
    template <class R, class Cont>
    friend bool operator<(const stack<R, Cont>& lhs, const stack<R, Cont>& rhs);
    template <class R, class Cont>
    friend bool operator<=(const stack<R, Cont>& lhs, const stack<R, Cont>& rhs);
    template <class R, class Cont>
    friend bool operator>(const stack<R, Cont>& lhs, const stack<R, Cont>& rhs);
    template <class R, class Cont>
    friend bool operator>=(const stack<R, Cont>& lhs, const stack<R, Cont>& rhs);
};

// Constructor
template <class T, class Container>
stack<T, Container>::stack(const container_type& container)
    : _c(container_type(container))
{
}

// Size
template <class T, class Container>
bool stack<T, Container>::empty() const
{
    return (_c.empty());
}

template <class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const
{
    return (_c.size());
}

// Element access
template <class T, class Container>
typename stack<T, Container>::value_type& stack<T, Container>::top()
{
    return (_c.back());
}

template <class T, class Container>
typename stack<T, Container>::value_type const& stack<T, Container>::top() const
{
    return (_c.back());
}

// Modifiers
template <class T, class Container>
void stack<T, Container>::push(const value_type& val)
{
    _c.push_back(val);
}

template <class T, class Container>
void stack<T, Container>::pop()
{
    _c.pop_back();
}

// Relational operators
template <class T, class Container>
bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
    return (lhs._c == rhs._c);
}

template <class T, class Container>
bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
    return (lhs._c != rhs._c);
}

template <class T, class Container>
bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
    return (lhs._c < rhs._c);
}

template <class T, class Container>
bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
    return (lhs._c <= rhs._c);
}

template <class T, class Container>
bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
    return (lhs._c > rhs._c);
}

template <class T, class Container>
bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
    return (lhs._c >= rhs._c);
}

} // namespace ft
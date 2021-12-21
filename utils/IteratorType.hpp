/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorType.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:59:23 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/21 17:43:02 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORTYPE_HPP
#define ITERATORTYPE_HPP

namespace ft
{

/* Templated struct to determinate if the iterator is const or not */
template < bool flag, class NotConst, class IsConst >
struct iterator_type;

template < class IsConst, class NotConst>
struct iterator_type<false, NotConst, IsConst>
{
    typedef NotConst type;
};

template < class IsConst, class NotConst>
struct iterator_type<true, NotConst, IsConst>
{
    typedef IsConst type;
};

} // namespace ft

#endif

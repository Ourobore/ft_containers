/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorType.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:59:23 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/03 15:44:05 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORTYPE_HPP
#define ITERATORTYPE_HPP

template < bool flag, class IsConst, class NotConst >
struct iterator_type;

template < class IsConst, class NotConst>
struct iterator_type<false, IsConst, NotConst>
{
    typedef NotConst type;
};

template < class IsConst, class NotConst>
struct iterator_type<true, IsConst, NotConst>
{
    typedef IsConst type;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorType.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:59:23 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/09 15:04:05 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORTYPE_HPP
# define ITERATORTYPE_HPP

template < bool flag, class NotConst, class IsConst >
struct iterator_type;

template < class NotConst, class IsConst>
struct iterator_type<false, NotConst, IsConst>
{
	typedef NotConst type;
};

template < class NotConst, class IsConst>
struct iterator_type<true, NotConst, IsConst>
{
	typedef IsConst type;
};

#endif
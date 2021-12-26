/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Remove_const.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:12:49 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/26 13:15:16 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE_CONST_HPP
#define REMOVE_CONST_HPP

template <class T>
struct remove_const
{
    typedef T type;
};

template <class T>
struct remove_const<const T>
{
    typedef T type;
};

#endif
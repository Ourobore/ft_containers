/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnableIf.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:53:13 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/03 14:59:23 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLEIF_HPP
#define ENABLEIF_HPP

namespace ft
{

template < bool B, class T = void >
struct enable_if
{
};

template <class T>
struct enable_if<true, T>
{
    typedef T type;
};

} // namespace ft

#endif
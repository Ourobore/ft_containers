/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsIntegral.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:54:02 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/03 14:58:59 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISINTEGRAL_HPP
#define ISINTEGRAL_HPP

template < class T >
struct is_integral
{
    const static bool value = false;
};

template <>
struct is_integral<int>
{
    const static bool value = true;
};

#endif
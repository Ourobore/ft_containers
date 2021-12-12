/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsIntegral.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:54:02 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/12 12:50:46 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISINTEGRAL_HPP
#define ISINTEGRAL_HPP

namespace ft
{

/* Templated struct to determinate if a type is integral or not */
template < class T >
struct is_integral
{
    const static bool value = false;
};

template <>
struct is_integral<bool>
{
    const static bool value = true;
};

template <>
struct is_integral<char>
{
    const static bool value = true;
};

template <>
struct is_integral<short>
{
    const static bool value = true;
};

template <>
struct is_integral<int>
{
    const static bool value = true;
};

template <>
struct is_integral<long>
{
    const static bool value = true;
};

template <>
struct is_integral<long long>
{
    const static bool value = true;
};

template <>
struct is_integral<signed char>
{
    const static bool value = true;
};

template <>
struct is_integral<unsigned char>
{
    const static bool value = true;
};

template <>
struct is_integral<unsigned short>
{
    const static bool value = true;
};

template <>
struct is_integral<unsigned int>
{
    const static bool value = true;
};

template <>
struct is_integral<unsigned long>
{
    const static bool value = true;
};

template <>
struct is_integral<unsigned long long>
{
    const static bool value = true;
};

} // namespace ft

#endif
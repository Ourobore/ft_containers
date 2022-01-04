/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Is_Const.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:29:54 by lchapren          #+#    #+#             */
/*   Updated: 2022/01/04 11:37:34 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_CONST_HPP
#define IS_CONST_HPP

template < class T >
class Is_Const
{
  public:
    bool operator()(T& x)
    {
        return (false);
        (void)x;
    }

    bool operator()(const T& x)
    {
        return (true);
        (void)x;
    }

    bool operator()(T* x)
    {
        return (false);
        (void)x;
    }

    bool operator()(const T* x)
    {
        return (true);
        (void)x;
    }
};

#endif
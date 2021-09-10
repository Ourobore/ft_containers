/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsConst.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:45:39 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/09 15:14:50 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISCONST_HPP
# define ISCONST_HPP

template < class T >
bool	is_const(T& type)
{
	(void)type;
	return (false);
}

template < class T >
bool	is_const(const T& type)
{
	(void)type;
	return (true);
}

#endif
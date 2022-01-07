/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lena <lena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:39:06 by lena              #+#    #+#             */
/*   Updated: 2022/01/07 14:14:03 by lena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
#define RBNODE_HPP

#include "Node.hpp"

namespace ft
{

enum RBColor
{
    red,
    black
};

template < class T >
class RBNode : public Node<T>
{
  protected:
    RBColor _color;

  public:
    RBColor color() const;
};

template < class T >
RBColor RBNode<T>::color() const
{
    return (_color);
}

} // namespace ft

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorTraits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:30:37 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/21 17:43:45 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORTRAITS_HPP
#define ITERATORTRAITS_HPP

namespace ft
{

template <class Iterator>
struct iterator_traits
{
    typedef typename Iterator::difference_type   difference_type;
    typedef typename Iterator::value_type        value_type;
    typedef typename Iterator::pointer           pointer;
    typedef typename Iterator::reference         reference;
    typedef typename Iterator::iterator_category iterator_category;
};

} // namespace ft

#endif

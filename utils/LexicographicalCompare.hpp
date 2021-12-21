/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexicographicalCompare.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:14:19 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/21 17:43:06 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICALCOMPARE_HPP
#define LEXICOGRAPHICALCOMPARE_HPP

namespace ft
{

template < class InputIterator1, class InputIterator2 >
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2)
{
    while (first1 != last1)
    {
        if (first2 == last2 || *first2 < *first1)
            return (false);
        else if (*first1 < *first2)
            return (true);
        ++first1;
        ++first2;
    }
    return (first2 != last2);
}

} // namespace ft

#endif

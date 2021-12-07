/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_container.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:30:59 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/07 15:12:49 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_CONTAINER_HPP
#define PRINT_CONTAINER_HPP

#include <iostream>

#include "print_separator.hpp"

namespace ft
{

template <class Container>
void printContainer(Container c)
{
    std::cout << std::endl;

    ft::printSeparator('=', 1, 45);
    std::cout << "Size: [" << c.size() << "]   Capacity: [" << c.capacity() << "]" << std::endl;

    std::cout << "[ ";
    for (typename Container::size_type i = 0; i < c.size(); ++i)
    {
        std::cout << c[i];
        if (i < c.size() - 1)
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;

    ft::printSeparator('=', 1, 45);

    std::cout << std::endl;
}

} // namespace ft

#endif
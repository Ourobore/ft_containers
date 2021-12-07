/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_container.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:30:59 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/07 10:33:41 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace ft
{

template <class Container>
void printContainer(Container c)
{
    std::cout << "=============================================" << std::endl;
    std::cout << "Size: [" << c.size() << "]   Capacity: [" << c.capacity() << "]" << std::endl;

    std::cout << "[ ";
    for (typename Container::size_type i = 0; i < c.size(); ++i)
    {
        std::cout << c[i];
        if (i < c.size() - 1)
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;

    std::cout << "=============================================" << std::endl;
}

} // namespace ft
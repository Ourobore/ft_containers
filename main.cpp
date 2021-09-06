/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/06 11:44:33 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main()
{
	ft::vector<int> test(3, 4);
	//std::cout << test[0] << std::endl;
	//std::cout << test[1] << std::endl;
	//std::cout << test[2] << std::endl;
	std::cout << test.capacity() << std::endl;
	ft::vector<int>::iterator	it = test.begin();
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;
}

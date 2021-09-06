/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/06 16:20:52 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main()
{
	ft::vector<int> test(3, 4);
	test.push_back(42);
	test.push_back(-21);
	test.push_back(15);
	ft::vector<int>::iterator	it = test.begin();
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;


	std::cout << std::endl;
	test.pop_back();
	for (size_t i = 0; i < test.size(); ++i)
		std::cout << test[i] << std::endl;

	std::cout << std::endl;
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl;
	std::cout << test[test.size()] << std::endl;
	std::cout << *(test.end() + 1) << std::endl;
}

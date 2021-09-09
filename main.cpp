/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/09 15:45:05 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int main()
{
	ft::vector<int> test;
	test.push_back(4);
	test.push_back(5);
	test.push_back(6);
	test.push_back(42);
	test.push_back(-21);
	test.push_back(69);

	std::cout << std::endl;
	std::cout << "test" << std::endl;
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;

	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	std::cout << std::endl;
	std::cout << "test" << std::endl;
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;

}
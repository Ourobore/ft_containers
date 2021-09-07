/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/07 10:03:51 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

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

	std::vector<int>	real(3, 4);
	real.push_back(42);
	real.push_back(-21);
	real.push_back(15);
	real.pop_back();
	std::cout << std::endl;
	std::cout << test[test.size()] << std::endl;
	std::cout << *(test.end()) << std::endl;


	std::cout << std::endl;
	std::cout << real[real.size()] << std::endl;
	std::cout << *(real.end()) << std::endl;

	std::cout << std::endl;
	std::cout << "verif" << std::endl;
	test.clear();
	real.clear();
	std::cout << *(test.begin() + 4) << std::endl;
	std::cout << *(real.begin() + 4) << std::endl;
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	for (std::vector<int>::iterator it = real.begin(); it != real.end(); ++it)
		std::cout << *it << std::endl;

}

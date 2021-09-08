/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/08 16:44:24 by lchapren         ###   ########.fr       */
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
	//test.push_back(15);
	test.push_back(69);

	std::cout << "test" << std::endl;
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl;
	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	ft::vector<int>::iterator it = test.insert(test.begin(), -33);
	test.insert(test.begin(), -46);
	test.insert(test.begin(), -555);
	std::cout << std::endl;
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;
	/*std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	std::cout << *it << std::endl;
	ft::vector<int>::iterator ip = test.insert(test.begin(), -99);
	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	std::cout << *ip << std::endl;
	ft::vector<int>::iterator iq = test.insert(test.begin(), 555);
	std::cout << *iq << std::endl;

	std::cout << std::endl;
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;
*/
}
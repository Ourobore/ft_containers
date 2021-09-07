/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/07 17:49:50 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int main()
{
	ft::vector<std::string> test(3, "4");
	test.push_back("42");
	test.push_back("-21");
	test.push_back("15");
	test.push_back("69");


	ft::vector<std::string> test1;
	test1.push_back("4");
	test1.push_back("4");
	test1.push_back("4");
	test1.push_back("42");
	test1.push_back("-21");
	test1.push_back("15");
	test1.push_back("69");
	
	std::cout << std::endl;
	//std::cout << test.size() << std::endl;
	//std::cout << test.capacity() << std::endl;
	std::cout << test1.size() << std::endl;
	std::cout << test1.capacity() << std::endl;
	std::cout << std::endl;


	//for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
	//	std::cout << *it << std::endl;
	std::cout << std::endl;
	for (ft::vector<std::string>::iterator it = test1.begin(); it != test1.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl;
	//for (size_t i = 0; i < test.size(); i++)
	//	std::cout << test[i] << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < test1.size(); i++)
		std::cout << test1[i] << std::endl;


	std::cout << std::endl;
	ft::vector<std::string> verif(test1.begin() + 1, test1.end() - 1, test1.get_allocator());
	
	for (ft::vector<std::string>::iterator it = verif.begin(); it != verif.end(); ++it)
		std::cout << *it << std::endl;

}
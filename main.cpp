/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/08 12:12:29 by lchapren         ###   ########.fr       */
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
	test.push_back(69);


	ft::vector<int> test1;
	test1.push_back(4);
	test1.push_back(4);
	test1.push_back(4);
	test1.push_back(42);
	test1.push_back(-21);
	test1.push_back(15);
	test1.push_back(69);

	ft::vector<int> prout;
	prout.push_back(21);

	std::cout << std::endl;
	std::cout << "test" << std::endl;
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl;
	std::cout << "test1" << std::endl;
	for (ft::vector<int>::iterator it = test1.begin(); it != test1.end(); ++it)
		std::cout << *it << std::endl;


	std::cout << std::endl;
	std::cout << "real" << std::endl;
	std::vector<int> real;
	real.push_back(4);
	real.push_back(4);
	real.push_back(4);
	real.push_back(42);
	real.push_back(-21);
	real.push_back(15);
	real.push_back(69);
	ft::vector<int> rverif(real.begin() + 1, real.end() - 1, real.get_allocator());



	std::cout << std::endl;
	std::cout << "verif" << std::endl;
	ft::vector<int> verif(test1.begin() + 1, test1.end() - 1, test1.get_allocator());
	
	for (ft::vector<int>::iterator it = verif.begin(); it != verif.end(); ++it)
		std::cout << *it << std::endl;
	
	std::cout << std::endl;
	std::cout << "prout" << std::endl;
	for (ft::vector<int>::iterator it = prout.begin(); it != prout.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	std::cout << "s: " << prout.size() << std::endl;
	std::cout << "c: " <<prout.capacity() << std::endl;
	prout.assign(test.begin(), test.end());
	for (ft::vector<int>::iterator it = prout.begin(); it != prout.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl;
	std::cout << "s: " << prout.size() << std::endl;
	std::cout << "c: " <<prout.capacity() << std::endl;
	prout.assign(15, 10);
	std::cout << "s: " << prout.size() << std::endl;
	std::cout << "c: " << prout.capacity() << std::endl;
	for (ft::vector<int>::iterator it = prout.begin(); it != prout.end(); ++it)
		std::cout << *it << std::endl;

}
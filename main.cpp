/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/06 15:48:55 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main()
{
	ft::vector<int> test(3, 4);
	std::cout << test.capacity() << std::endl;
	ft::vector<int>::iterator	it = test.begin();
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;


	std::cout << std::endl;
	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;

	test.push_back(5);
	std::cout << std::endl;
	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;
	std::cout << test[3] << std::endl;
	//for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
	//	std::cout << *it << std::endl;

	std::cout << std::endl;
	test.push_back(42);
	test.push_back(-21);
	test.push_back(15);
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	std::cout << test.size() << std::endl;
	std::cout << test.capacity() << std::endl;

	std::cout << std::endl;
	ft::vector<int> review(test);
	for (ft::vector<int>::iterator it = review.begin(); it != review.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	std::cout << review.size() << std::endl;
	std::cout << review.capacity() << std::endl;
	review.push_back(15);
	std::cout << review.size() << std::endl;
	std::cout << review.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << "Resize()" << std::endl;
	test.resize(7);
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	for (size_t i = 0; i < test.size(); i++)
			std::cout << test[i] << std::endl;
}

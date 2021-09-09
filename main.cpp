/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/09 17:42:22 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int main()
{
	/*
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
		*/

{
	const int start_size = 7;
	ft::vector<int> vct(start_size, 20);
	ft::vector<int> vct2;
	ft::vector<int>::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	std::cout << vct.capacity() << std::endl;;

	
	std::cout << std::endl << "################################ 14" << std::endl << std::endl;;
	vct.resize(10, 42);
	std::cout << vct.capacity() << std::endl;;

	std::cout << std::endl << "################################ 28" << std::endl << std::endl;;
	vct.resize(18, 43);
	std::cout << vct.capacity() << std::endl;;
	std::cout << std::endl << "################################ 28" << std::endl << std::endl;;
	vct.resize(10);
	std::cout << vct.capacity() << std::endl;;
	std::cout << std::endl << "################################ 28" << std::endl << std::endl;;
	vct.resize(23, 44);
	std::cout << vct.capacity() << std::endl;;
	std::cout << std::endl << "################################ 28" << std::endl << std::endl;;
	vct.resize(5);
	std::cout << vct.capacity() << std::endl;;
	std::cout << std::endl << "################################ 28" << std::endl << std::endl;;
	vct.reserve(5);
	vct.reserve(3);
	std::cout << vct.capacity() << std::endl;;
	std::cout << std::endl << "################################ 87" << std::endl << std::endl;;
	vct.resize(87);
	vct.resize(5);
	std::cout << vct.capacity() << std::endl;;

	//is_empty(vct2);
	vct2 = vct;
	std::cout << vct2.capacity() << std::endl;;
	//is_empty(vct2);
	std::cout << std::endl << "################################" << std::endl << std::endl;;
	vct.reserve(vct.capacity() + 1);
	std::cout << vct.capacity() << std::endl;;
	std::cout << vct2.capacity() << std::endl;;
	std::cout << std::endl << "################################" << std::endl << std::endl;;
	vct2.resize(0);
	//is_empty(vct2);
	std::cout << vct2.capacity() << std::endl;;
}
	
	std::cout << "################################" << std::endl;;
	std::cout << "################################" << std::endl;;
	std::cout << "################################" << std::endl;;
{
	const int start_size = 7;
	std::vector<int> vct(start_size, 20);
	std::vector<int> vct2;
	std::vector<int>::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	std::cout << vct.capacity() << std::endl;;

	
	std::cout << std::endl << "################################ 7" << std::endl << std::endl;;
	vct.resize(10, 42);
	std::cout << vct.capacity() << std::endl;;

	std::cout << std::endl << "################################ 14" << std::endl << std::endl;;
	vct.resize(18, 43);
	std::cout << vct.capacity() << std::endl;;
	std::cout << std::endl << "################################ 28" << std::endl << std::endl;;
	vct.resize(10);
	std::cout << vct.capacity() << std::endl;;
	std::cout << std::endl << "################################ 28" << std::endl << std::endl;;
	vct.resize(23, 44);
	std::cout << vct.capacity() << std::endl;;
	std::cout << std::endl << "################################ 28" << std::endl << std::endl;;
	vct.resize(5);
	std::cout << vct.capacity() << std::endl;;
	std::cout << std::endl << "################################ 28" << std::endl << std::endl;;
	vct.reserve(5);
	vct.reserve(3);
	std::cout << vct.capacity() << std::endl;;
	std::cout << std::endl << "################################ 87" << std::endl << std::endl;;
	vct.resize(87);
	vct.resize(5);
	std::cout << vct.capacity() << std::endl;;

	//is_empty(vct2);
	vct2 = vct;
	std::cout << vct2.capacity() << std::endl;;
	//is_empty(vct2);
	std::cout << std::endl << "################################" << std::endl << std::endl;;
	vct.reserve(vct.capacity() + 1);
	std::cout << vct.capacity() << std::endl;;
	std::cout << vct2.capacity() << std::endl;;
	std::cout << std::endl << "################################" << std::endl << std::endl;;
	vct2.resize(0);
	//is_empty(vct2);
	std::cout << vct2.capacity() << std::endl;;
}
}
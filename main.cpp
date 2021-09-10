/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/10 10:31:48 by lchapren         ###   ########.fr       */
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
	ft::vector<int> vct(10);
	ft::vector<int> vct2;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	std::cout << "=============================== 1" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "===============================" << std::endl;
	//printSize(vct);

	vct2.insert(vct2.end(), 42);
	std::cout << "=============================== 2" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "===============================" << std::endl;
	vct2.insert(vct2.begin(), 2, 21);
	std::cout << "=============================== 3" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "===============================" << std::endl;
	//printSize(vct2);

	vct2.insert(vct2.end() - 2, 42);
	std::cout << "=============================== 4" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "===============================" << std::endl;
	//printSize(vct2);

	vct2.insert(vct2.end(), 2, 84);
	std::cout << "=============================== 5" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "===============================" << std::endl;
	//printSize(vct2);

	vct2.resize(4);
	std::cout << "=============================== 6" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "=============================== " << std::endl;
	//printSize(vct2);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	std::cout << "=============================== 7" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "===============================" << std::endl;
	vct.clear();
	std::cout << "=============================== 8" << std::endl;
	std::cout << "size: " << vct.size() << std::endl;
	std::cout << "capacity: " << vct.capacity() << std::endl;
	for (size_t i = 0; i < vct.size(); ++i)
		std::cout << vct[i] << std::endl;
	std::cout << "===============================" << std::endl;
	//printSize(vct2);

	//printSize(vct);
	//return (0);
}
	
	std::cout << std::endl << "################################" << std::endl;;
	std::cout << "################################" << std::endl;;
	std::cout << "################################" << std::endl << std::endl;;
{
}
	std::vector<int> vct(10);
	std::vector<int> vct2;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	std::cout << "=============================== 1" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "===============================" << std::endl;
	//printSize(vct);

	vct2.insert(vct2.end(), 42);
	std::cout << "=============================== 2" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "===============================" << std::endl;
	vct2.insert(vct2.begin(), 2, 21);
	std::cout << "=============================== 3" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "===============================" << std::endl;
	//printSize(vct2);

	vct2.insert(vct2.end() - 2, 42);
	std::cout << "=============================== 4" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "===============================" << std::endl;
	//printSize(vct2);

	vct2.insert(vct2.end(), 2, 84);
	std::cout << "=============================== 5" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "===============================" << std::endl;
	//printSize(vct2);

	vct2.resize(4);
	std::cout << "=============================== 6" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "===============================" << std::endl;
	//printSize(vct2);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	std::cout << "=============================== 7" << std::endl;
	std::cout << "size: " << vct2.size() << std::endl;
	std::cout << "capacity: " << vct2.capacity() << std::endl;
	for (size_t i = 0; i < vct2.size(); ++i)
		std::cout << vct2[i] << std::endl;
	std::cout << "===============================" << std::endl;
	vct.clear();
	std::cout << "===============================8" << std::endl;
	std::cout << "size: " << vct.size() << std::endl;
	std::cout << "capacity: " << vct.capacity() << std::endl;
	for (size_t i = 0; i < vct.size(); ++i)
		std::cout << vct[i] << std::endl;
	std::cout << "===============================" << std::endl;
	//printSize(vct2);

	//printSize(vct);
	//return (0);
}
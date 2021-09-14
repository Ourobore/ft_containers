/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/14 14:01:07 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

template <class Container>
void	printContainer(Container c)
{
	std::cout << "=============================================" << std::endl;
	std::cout << "Size: [" << c.size() << "]   Capacity: [" << c.capacity() << "]" << std::endl;
	std::cout << "[ ";
	for (typename Container::size_type i = 0; i < c.size(); ++i)
	{
		std::cout << c[i];
		if (i < c.size() - 1)
			std::cout << ", ";
	}
	std::cout << " ]" << std::endl;
	std::cout << "=============================================" << std::endl;
}

int main(int argc, char **argv)
{
(void)argv;
if (argc == 2)
{
	
	const int size = 5;
	ft::vector<int> vct(size);
	ft::vector<int>::reverse_iterator it = vct.rbegin();
	ft::vector<int>::const_reverse_iterator ite = vct.rbegin();
	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;
	printContainer(vct);

	std::cout << "rbegin: " << *it << std::endl;
	it = it + 5;
	//std::cout << *it << std::endl;
	it = 1 + it;
	//std::cout << *it << std::endl;
	it = it - 4;
	//std::cout << *it << std::endl; //15
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	std::cout << *(it -  2) << std::endl;
	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	printContainer(vct);
	//printSize(vct, true);
	return (0);
}
//std::cout << std::endl << std::endl <<std::endl;
else
{
	const int size = 5;
	std::vector<int> vct(size);
	std::vector<int>::reverse_iterator it = vct.rbegin();
	std::vector<int>::const_reverse_iterator ite = vct.rbegin();
	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;
	printContainer(vct);

	std::cout << "rbegin: " << *it << std::endl;
	it = it + 5;
	//std::cout << *it << std::endl;
	//it = 1 + it;
	//std::cout << *it << std::endl;
	it = it - 4;
	//std::cout << *it << std::endl;
	//std::cout << *it << std::endl;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	std::cout << *(it -  2) << std::endl;
	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	printContainer(vct);
	//printSize(vct, true);
	return (0);
}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/11 11:42:31 by lchapren         ###   ########.fr       */
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

int main()
{
{
// Non const iterator with non const vector work
ft::vector<int> v;
ft::vector<int>::iterator it = v.begin();
ft::vector<int>::iterator ite = v.end();
}
{
// Const iterator with const vector work
const ft::vector<int> v;
ft::vector<int>::const_iterator cit = v.begin();
ft::vector<int>::const_iterator cite = v.end();
}
{
// Const iterator with non const vector doesn't work
// Conversion needed?
ft::vector<int> v;
ft::vector<int>::const_iterator cit = v.begin();
ft::vector<int>::const_iterator cite = v.end();
}
{
// Non const iterator with const vector doesn't work
// Conversion needed?
//const ft::vector<int> v;//
//t::vector<int>::iterator it = v.begin();
//ft::vector<int>::iterator ite = v.end();
}
/*
{
	ft::vector<int>	v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);

	ft::vector<int>::iterator it = v.begin();
	ft::vector<int>::iterator ite = v.end();

	//for (; it != ite; ++it)
	//	std::cout << *it << std::endl;

	const ft::vector<int> vv(3, 4);
	ft::vector<int>::iterator cit = vv.begin();
	ft::vector<int>::iterator cite = vv.end();
	
	for (; cit != cite; ++cit)
		std::cout << *cit << std::endl;

	printContainer(v);
}
*/	
	std::cout << std::endl << "################################" << std::endl;;
	std::cout << "################################" << std::endl;;
	std::cout << "################################" << std::endl << std::endl;;
{
}

}
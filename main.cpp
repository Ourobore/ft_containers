/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/11 13:50:15 by lchapren         ###   ########.fr       */
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
	ft::vector<int>	v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);

	ft::vector<int>::iterator it = v.begin();
	ft::vector<int>::const_iterator ite = v.end();
	*(ite) -= 1;
	++it;
	std::cout << *ite << std::endl;
	//for (; it != ite; ++it)
	//	std::cout << *it << std::endl;

	printContainer(v);
}

	std::cout << std::endl << "################################" << std::endl;;
	std::cout << "################################" << std::endl;;
	std::cout << "################################" << std::endl << std::endl;;

{
	std::vector<int>	v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);

	//std::vector<int>::iterator it = v.begin();
	//std::vector<int>::const_iterator ite = v.end();
	//*(ite) -= 1;
	//std::cout << *ite << std::endl;
	//for (; it != ite; ++it)
	//	std::cout << *it << std::endl;

	printContainer(v);
}

}
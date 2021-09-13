/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/09/13 10:53:54 by lchapren         ###   ########.fr       */
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
	const int size = 5;
	ft::vector<int> vct(size);
	ft::vector<int>::iterator it_ = vct.begin();
	ft::vector<int>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;
	printContainer(vct);
	//printSize(vct);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == (it + 3).base()) << std::endl;
	std::cout << std::endl;

	std::cout << *(it.base() + 1) << std::endl;
	std::cout << *(it - 3) << std::endl;
	std::cout << *(it - 3).base() << std::endl;
	std::cout << "before decrement" << std::endl;
	it -= 3;
	std::cout << "after decrement" << std::endl;
	std::cout << *it.base() << std::endl;

	std::cout << "TEST OFFSET" << std::endl;
	std::cout << *(it) << std::endl;
	std::cout << *(it).base() << std::endl;
	std::cout << *(it - 0) << std::endl;
	std::cout << *(it - 0).base() << std::endl;
	std::cout << *(it - 1).base() << std::endl;
}

/*
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
*/
	std::cout << std::endl << "################################" << std::endl;;
	std::cout << "################################" << std::endl;;
	std::cout << "################################" << std::endl << std::endl;;

{
	const int size = 5;
	std::vector<int> vct(size);
	std::vector<int>::iterator it_ = vct.begin();
	std::vector<int>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;
	printContainer(vct);
	//printSize(vct);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == (it + 3).base()) << std::endl;
	std::cout << std::endl;

	std::cout << *(it.base() + 1) << std::endl;
	std::cout << *(it - 3) << std::endl;
	std::cout << *(it - 3).base() << std::endl;
	it -= 3;
	std::cout << *it.base() << std::endl;

	std::cout << "TEST OFFSET" << std::endl;
	std::cout << *(it) << std::endl;
	std::cout << *(it).base() << std::endl;
	std::cout << *(it - 0) << std::endl;
	std::cout << *(it - 0).base() << std::endl;
	std::cout << *(it - 1).base() << std::endl;
}
/*
{
	std::vector<int>	v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);

	//std::vector<int>::iterator it = v.begin();
	//std::vector<int>::const_iterator ite = v.end();
	*(ite) -= 1;
	//std::cout << *ite << std::endl;
	//for (; it != ite; ++it)
	//	std::cout << *it << std::endl;

	printContainer(v);
}
*/
}
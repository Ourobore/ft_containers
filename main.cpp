/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/03 14:33:54 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

template <class Container>
void printContainer(Container c)
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

template < typename container >
void checkErase(container const& vct, typename container::const_iterator const& it)
{
    static int i = 0;
    std::cout << "[" << i++ << "] "
              << "erase: " << it - vct.begin() << std::endl;
    printContainer(vct);
}

int main(void)
{
    {
        std::vector<std::string> v;

        for (char c = 'A'; c != '['; ++c)
            v.push_back(std::string() + c);

        printContainer(v);

        checkErase(v, v.erase(v.begin() + 2));

        checkErase(v, v.erase(v.begin()));
        checkErase(v, v.erase(v.end() - 1));

        checkErase(v, v.erase(v.begin(), v.begin() + 3));
        checkErase(v, v.erase(v.end() - 3, v.end() - 1));

        v.push_back("Hello");
        v.push_back("Hi there");
        printContainer(v);
        checkErase(v, v.erase(v.end() - 3, v.end()));

        v.push_back("ONE");
        v.push_back("TWO");
        v.push_back("THREE");
        v.push_back("FOUR");
        printContainer(v);
        checkErase(v, v.erase(v.begin(), v.end()));
    }

    std::cout << "==================================" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "==================================" << std::endl;

    {
        ft::vector<std::string> v;

        for (char c = 'A'; c != '['; ++c)
            v.push_back(std::string() + c);

        printContainer(v);

        checkErase(v, v.erase(v.begin() + 2));

        checkErase(v, v.erase(v.begin()));
        checkErase(v, v.erase(v.end() - 1));

        checkErase(v, v.erase(v.begin(), v.begin() + 3));
        checkErase(v, v.erase(v.end() - 3, v.end() - 1));

        v.push_back("Hello");
        v.push_back("Hi there");
        printContainer(v);
        checkErase(v, v.erase(v.end() - 3, v.end()));

        v.push_back("ONE");
        v.push_back("TWO");
        v.push_back("THREE");
        v.push_back("FOUR");
        printContainer(v);
        checkErase(v, v.erase(v.begin(), v.end()));
    }
}
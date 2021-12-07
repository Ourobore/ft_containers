/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/07 14:48:57 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

#ifndef NAMESPACE
#define NAMESPACE std
#endif

int main()
{
    std::cout << "=== +1 size (push_back) ===" << std::endl;
    ft::printSeparator();
    std::vector<int> v;
    ft::vector<int>  vv;

    ft::printTraits(v.begin());
    ft::printTraits(vv.begin());
    NAMESPACE::stack<int> s;
    s.push(3);
    std::cout << s.top() << std::endl;
    s.push(5);
    std::cout << s.top() << std::endl;
    s.push(7);
    std::cout << s.top() << std::endl;

    NAMESPACE::stack<int> t;
    t.push(3);
    std::cout << t.top() << std::endl;
    t.push(5);
    std::cout << t.top() << std::endl;
    t.push(7);
    std::cout << t.top() << std::endl;

    if (s == t)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
}
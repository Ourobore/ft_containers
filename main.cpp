#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"

#include <map>
#include <stack>
#include <vector>

#include <iostream>
#include <typeinfo>

#include "binary_tree/BinarySearchTree.hpp"
#include "binary_tree/Node.hpp"
#include "utils/Pair.hpp"

#define NAMESPACE ft

int main()
{

    NAMESPACE::map<int, int> m;

    NAMESPACE::pair<int, int> a = NAMESPACE::make_pair(10, 100);
    m.insert(a);
    m.insert(NAMESPACE::make_pair(5, 50));
    m.insert(NAMESPACE::make_pair(15, 150));
    m.insert(NAMESPACE::make_pair(1, 10));
    m.insert(NAMESPACE::make_pair(8, 80));
    m.insert(NAMESPACE::make_pair(13, 130));
    m.insert(NAMESPACE::make_pair(20, 200));
    m.insert(NAMESPACE::make_pair(3, 30));
    m.insert(NAMESPACE::make_pair(6, 60));
    m.insert(NAMESPACE::make_pair(12, 120));
    m.insert(NAMESPACE::make_pair(18, 180));
    m.insert(NAMESPACE::make_pair(22, 220));
    m.insert(NAMESPACE::make_pair(2, 20));
    m.insert(NAMESPACE::make_pair(4, 40));
    m.insert(NAMESPACE::make_pair(7, 70));
    m.insert(NAMESPACE::make_pair(9, 90));
    m.insert(NAMESPACE::make_pair(16, 160));
    m.insert(NAMESPACE::make_pair(24, 240));
    NAMESPACE::pair<int, int> b = NAMESPACE::make_pair(26, 260);
    m.insert(b);

    NAMESPACE::map<int, int>::iterator       it = m.begin();
    NAMESPACE::map<int, int>::const_iterator cite = m.end();

    for (; it != cite; ++it)
        std::cout << it->first << std::endl;

    std::cout << std::endl;

    it = ++m.end();
    for (; it != cite; --it)
        std::cout << it->first << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    NAMESPACE::map<int, int> n(m);
    std::cout << "lower bound: " << n.lower_bound(24)->second << std::endl;
    std::cout << "upper bound: " << n.upper_bound(24)->second << std::endl;
    NAMESPACE::pair<NAMESPACE::map<int, int>::iterator, NAMESPACE::map<int, int>::iterator> p(m.equal_range(24));
    std::cout << "equal range: " << p.first->first << " " << p.second->first << std::endl;

    return (0);
}

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

#include <list>

#define T1 int
#define T2 std::string
typedef NAMESPACE::pair<const T1, T2> T3;

template <typename T>
std::string printPair(const T& iterator, bool nl = true, std::ostream& o = std::cout)
{
    o << "key: " << iterator->first << " | value: " << iterator->second;
    if (nl)
        o << std::endl;
    return ("");
}

template <typename T_MAP>
void printSize(T_MAP const& mp, bool print_content = 1)
{
    std::cout << "size: " << mp.size() << std::endl;
    std::cout << "max_size: " << mp.max_size() << std::endl;
    if (print_content)
    {
        typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
        std::cout << std::endl
                  << "Content is:" << std::endl;
        for (; it != ite; ++it)
            std::cout << "- " << printPair(it, false) << std::endl;
    }
    std::cout << "###############################################" << std::endl;
}

static int iter = 0;
template <typename MAP, typename U>
void ft_erase(MAP& mp, U param)
{
    std::cout << "\t-- [" << iter++ << "] --" << std::endl;
    mp.erase(param);
    printSize(mp);
}
template <typename MAP, typename U, typename V>
void ft_erase(MAP& mp, U param, V param2)
{
    std::cout << "\t-- [" << iter++ << "] --" << std::endl;
    mp.erase(param, param2);
    printSize(mp);
}

int main()
{
    // NAMESPACE::map<int, int> m;

    // NAMESPACE::pair<int, int> a = NAMESPACE::make_pair(10, 100);
    // m.insert(a);
    // m.insert(NAMESPACE::make_pair(5, 50));
    // m.insert(NAMESPACE::make_pair(15, 150));
    // m.insert(NAMESPACE::make_pair(1, 10));
    // m.insert(NAMESPACE::make_pair(8, 80));
    // m.insert(NAMESPACE::make_pair(13, 130));
    // m.insert(NAMESPACE::make_pair(20, 200));
    // m.insert(NAMESPACE::make_pair(3, 30));
    // m.insert(NAMESPACE::make_pair(6, 60));
    // m.insert(NAMESPACE::make_pair(12, 120));
    // m.insert(NAMESPACE::make_pair(18, 180));
    // m.insert(NAMESPACE::make_pair(22, 220));
    // m.insert(NAMESPACE::make_pair(2, 20));
    // m.insert(NAMESPACE::make_pair(4, 40));
    // m.insert(NAMESPACE::make_pair(7, 70));
    // m.insert(NAMESPACE::make_pair(9, 90));
    // m.insert(NAMESPACE::make_pair(16, 160));
    // m.insert(NAMESPACE::make_pair(24, 240));
    // NAMESPACE::pair<int, int> b = NAMESPACE::make_pair(26, 260);
    // m.insert(b);

    std::list<T3> lst;
    unsigned int  lst_size = 10;
    for (unsigned int i = 0; i < lst_size; ++i)
        lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
    NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
    printSize(mp);
    ft_erase(mp, ++mp.begin());

    ft_erase(mp, mp.begin());
    ft_erase(mp, --mp.end());

    ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
    ft_erase(mp, --(--(--mp.end())), --mp.end());

    mp[10] = "Hello";
    mp[11] = "Hi there";
    printSize(mp);
    ft_erase(mp, --(--(--mp.end())), mp.end());

    mp[12] = "ONE";
    mp[13] = "TWO";
    mp[14] = "THREE";
    mp[15] = "FOUR";
    printSize(mp);
    ft_erase(mp, mp.begin(), mp.end());

    // NAMESPACE::map<int, int>::iterator       it = m.begin();
    // NAMESPACE::map<int, int>::const_iterator cite = m.end();

    // for (; it != cite; ++it)
    //     std::cout << it->first << std::endl;

    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;

    // NAMESPACE::map<int, int> n;
    // n.insert(NAMESPACE::make_pair(55, 550));
    // n.insert(NAMESPACE::make_pair(115, 1150));
    // n.insert(NAMESPACE::make_pair(11, 110));
    // n.insert(NAMESPACE::make_pair(88, 880));
    // n.insert(NAMESPACE::make_pair(113, 1130));
    // n.insert(NAMESPACE::make_pair(220, 2200));
    // n.insert(NAMESPACE::make_pair(33, 330));
    // n.insert(NAMESPACE::make_pair(66, 660));

    // m.insert(n.begin(), n.end());
    // for (it = m.begin(); it != cite; ++it)
    //     std::cout << it->first << std::endl;

    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;

    // m.erase(--m.end());
    // for (it = m.begin(); it != cite; ++it)
    //     std::cout << it->first << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // m.erase(--(--(--m.end())), m.end());
    // for (it = m.begin(); it != cite; ++it)
    //     std::cout << it->first << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << "verif erase: " << m.erase((--m.end())->first) << std::endl;
    // for (it = m.begin(); it != cite; ++it)
    //     std::cout << it->first << std::endl;

    return (0);
}

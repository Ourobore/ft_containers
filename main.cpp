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

#include "binary_tree/Node.hpp"
#include "binary_tree/RBNode.hpp"
#include "binary_tree/RBTree.hpp"
#include <typeinfo>
int main()
{
    ft::BaseNode<int>* b = new ft::Node<int>(3);
    ft::Node<int>      n(2);

    std::allocator< ft::BaseNode<int > > alloc;
    std::allocator< ft::Node<int > >     nalloc;
    ft::BaseNode<int>*                   bb;
    ft::Node<int>*                       aa;
    bb = alloc.allocate(1);
    aa = nalloc.allocate(1);
    int val = 6;
    alloc.construct(bb, val);
    nalloc.construct(aa, int(6));

    std::cout << b->data() << std::endl;
    std::cout << n.data() << std::endl;
    std::cout << n.right()->data() << std::endl;
    (void)b;
    (void)bb;
    // NAMESPACE::RBTree<int, int> r;
    // std::cout << typeid(r).name() << std::endl;
    // std::cout << typeid(r.root()).name() << std::endl;
    // std::cout << typeid(NAMESPACE::RBTree<int, int>::node_type).name() << std::endl;
    // r.root()->color();
    return (0);
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
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

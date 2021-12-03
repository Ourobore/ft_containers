/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:23:12 by lchapren          #+#    #+#             */
/*   Updated: 2021/12/03 13:37:11 by lchapren         ###   ########.fr       */
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

class foo
{
  public:
    foo(void){};
    ~foo(void){};
    void m(void)
    {
        std::cout << "foo::m called [" << this->value << "]" << std::endl;
    };
    void m(void) const
    {
        std::cout << "foo::m const called [" << this->value << "]" << std::endl;
    };
    foo& operator=(int src)
    {
        this->value = src;
        return *this;
    };
    int getValue(void) const
    {
        return this->value;
    };

  private:
    int value;
};

std::ostream& operator<<(std::ostream& o, foo const& bar)
{
    o << bar.getValue();
    return o;
}

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1& first, const Ite_2& second)
{
    std::cout << "###################################################" << std::endl;
    std::cout << (first < second) << std::endl;
    std::cout << (first <= second) << std::endl;
    std::cout << (first > second) << std::endl;
    std::cout << (first >= second) << std::endl;
    std::cout << "###################################################" << std::endl;
    // if (redo)
    //{
    //	std::cout << "redo" << std::endl;
    //	ft_eq_ope(second, first, 0);
    // }
}

int main(int argc, char** argv)
{

    (void)argv;
    if (argc == 2)
    {
        const int                         size = 5;
        ft::vector<foo>                   vct(size);
        ft::vector<foo>::reverse_iterator it_0(vct.rbegin());
        ft::vector<foo>::reverse_iterator it_1(vct.rend());
        ft::vector<foo>::reverse_iterator it_mid;

        ft::vector<foo>::const_reverse_iterator cit_0 = vct.rbegin();
        ft::vector<foo>::const_reverse_iterator cit_1;
        ft::vector<foo>::const_reverse_iterator cit_mid;

        for (int i = size; it_0 != it_1; --i)
            *it_0++ = i;
        printContainer(vct);
        // printSize(vct, 1);
        it_0 = vct.rbegin();
        cit_1 = vct.rend();
        it_mid = it_0 + 3;
        cit_mid = it_0 + 3;
        cit_mid = cit_0 + 3;
        cit_mid = it_mid;

        std::cout << std::boolalpha;
        std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

        std::cout << "\t\tft_eq_ope:" << std::endl;
        // regular it
        std::cout << "95" << std::endl;
        ft_eq_ope(it_0 + 3, it_mid);
        std::cout << "97" << std::endl; // here
        ft_eq_ope(it_0, it_1);
        std::cout << "99" << std::endl; // here
        ft_eq_ope(it_1 - 3, it_mid);
        // const it
        std::cout << "102" << std::endl;
        ft_eq_ope(cit_0 + 3, cit_mid);
        std::cout << "104" << std::endl; // here
        ft_eq_ope(cit_0, cit_1);
        std::cout << "106" << std::endl;
        ft_eq_ope(cit_1 - 3, cit_mid);
        // both it
        std::cout << "109" << std::endl;
        ft_eq_ope(it_0 + 3, cit_mid);
        std::cout << "111" << std::endl;
        ft_eq_ope(it_mid, cit_0 + 3);
        std::cout << "113" << std::endl; // here
        ft_eq_ope(it_0, cit_1);
        std::cout << "115" << std::endl; // here
        ft_eq_ope(it_1, cit_0);
        std::cout << "117" << std::endl; // here
        ft_eq_ope(it_1 - 3, cit_mid);
        std::cout << "119" << std::endl; // here
        ft_eq_ope(it_mid, cit_1 - 3);

        return (0);
    }
    else
    {
        const int                          size = 5;
        std::vector<foo>                   vct(size);
        std::vector<foo>::reverse_iterator it_0(vct.rbegin());
        std::vector<foo>::reverse_iterator it_1(vct.rend());
        std::vector<foo>::reverse_iterator it_mid;

        std::vector<foo>::const_reverse_iterator cit_0 = vct.rbegin();
        std::vector<foo>::const_reverse_iterator cit_1;
        std::vector<foo>::const_reverse_iterator cit_mid;

        for (int i = size; it_0 != it_1; --i)
            *it_0++ = i;
        printContainer(vct);
        // printSize(vct, 1);
        it_0 = vct.rbegin();
        cit_1 = vct.rend();
        it_mid = it_0 + 3;
        cit_mid = it_0 + 3;
        cit_mid = cit_0 + 3;
        cit_mid = it_mid;

        std::cout << std::boolalpha;
        std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

        std::cout << "\t\tft_eq_ope:" << std::endl;
        // regular it
        std::cout << "95" << std::endl;
        ft_eq_ope(it_0 + 3, it_mid);
        std::cout << "97" << std::endl;
        ft_eq_ope(it_0, it_1);
        std::cout << "99" << std::endl;
        ft_eq_ope(it_1 - 3, it_mid);
        // const it
        std::cout << "102" << std::endl;
        ft_eq_ope(cit_0 + 3, cit_mid);
        std::cout << "104" << std::endl;
        ft_eq_ope(cit_0, cit_1);
        std::cout << "106" << std::endl;
        ft_eq_ope(cit_1 - 3, cit_mid);
        // both it
        std::cout << "109" << std::endl;
        ft_eq_ope(it_0 + 3, cit_mid);
        std::cout << "111" << std::endl;
        ft_eq_ope(it_mid, cit_0 + 3);
        std::cout << "113" << std::endl;
        ft_eq_ope(it_0, cit_1);
        std::cout << "115" << std::endl;
        ft_eq_ope(it_1, cit_0);
        std::cout << "117" << std::endl;
        ft_eq_ope(it_1 - 3, cit_mid);
        std::cout << "119" << std::endl;
        ft_eq_ope(it_mid, cit_1 - 3);

        return (0);
    }
}
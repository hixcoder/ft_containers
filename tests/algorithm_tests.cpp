/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:53:53 by hboumahd          #+#    #+#             */
/*   Updated: 2023/01/25 11:23:10 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

// ==> std::equal
void equalTest()
{
    int T1[] = {45, 456, 646, 46345, -45, 45};
    std::vector<int> V1;
    std::vector<int>::iterator it;
    int i = -1;
    for (it = V1.begin(); it != V1.end() ; it++)
        V1.push_back(T1[++i]);

    // TEST1
    if (ft::equal(V1.begin(), V1.end(), T1))
        std::cout << "V1 equal T1\n";
    else
        std::cout << "V1 do not equal T1\n"; 
    
    // TEST2
    V1.push_back(55);
    if (ft::equal(V1.begin(), V1.end(), T1))
        std::cout << "V1 equal T1\n";
    else
        std::cout << "V1 do not equal T1\n"; 
}

// ==> std::lexicographical_compare
void lexicographical_compareTest()
{
    char a[] = "Adobe"; 
    char a2[] = "CAdobe"; 
    char b[] = "Barboza";

    // TEST1
    if (ft::lexicographical_compare(a, a + 5, a2, a2 + 5))
        std::cout << "a less or equal to a2\n";
    else
        std::cout << "a is not less or equal to a2\n"; 
    
    // TEST2
    if (ft::lexicographical_compare(a, a + 5, b, b + 5))
        std::cout << "a less or equal to b\n";
    else
        std::cout << "a is not less or equal to b\n"; 
}

// ==> std::is_integral
void is_integralTest()
{
    // std::integral results
    std::cout << "==> std::is_integral:" << std::endl;
    std::cout << "char: " << std::is_integral<char>::value << std::endl;
    std::cout << "int: " << std::is_integral<int>::value << std::endl;
    std::cout << "float: " << std::is_integral<float>::value << "\n\n";

    // ft::integral results
    std::cout << "==> ft::is_integral:" << std::endl;
    std::cout << "char: " << ft::is_integral<char>::value << std::endl;
    std::cout << "int: " << ft::is_integral<int>::value << std::endl;
    std::cout << "float: " << ft::is_integral<float>::value << std::endl;
}

// ==> std::pair
void pairTest()
{
    // this is the std::pair
    std::pair<int, std::string> stdpair1;
    std::pair<int, std::string> stdpair2;
    stdpair1.first = 10;
    stdpair1.second = "Hello, World!";
    stdpair2.first = 25;
    stdpair2.second = "Hello, man!";
    
    std::cout << "The first element of stdpair1 is: " << stdpair1.first << std::endl;
    std::cout << "The second element of stdpair1 is: " << stdpair1.second << std::endl;
    std::cout << "The first element of stdpair2 is: " << stdpair2.first << std::endl;
    std::cout << "The second element of stdpair2 is: " << stdpair2.second << "\n\n";
    stdpair1.swap(stdpair2);
    std::cout << "The first element of stdpair1 is: " << stdpair1.first << std::endl;
    std::cout << "The second element of stdpair1 is: " << stdpair1.second << std::endl;
    std::cout << "The first element of stdpair2 is: " << stdpair2.first << std::endl;
    std::cout << "The second element of stdpair2 is: " << stdpair2.second << "\n-----------------\n";

    // this is the ft::pair
    ft::pair<int, std::string> ftpair1;
    ft::pair<int, std::string> ftpair2;
    ftpair1.first = 10;
    ftpair1.second = "Hello, World!";
    ftpair2.first = 25;
    ftpair2.second = "Hello, man!";
    
    std::cout << "The first element of ftpair1 is: " << ftpair1.first << std::endl;
    std::cout << "The second element of ftpair1 is: " << ftpair1.second << std::endl;
    std::cout << "The first element of ftpair2 is: " << ftpair2.first << std::endl;
    std::cout << "The second element of ftpair2 is: " << ftpair2.second << "\n\n";
    ftpair1.swap(ftpair2);
    std::cout << "The first element of ftpair1 is: " << ftpair1.first << std::endl;
    std::cout << "The second element of ftpair1 is: " << ftpair1.second << std::endl;
    std::cout << "The first element of ftpair2 is: " << ftpair2.first << std::endl;
    std::cout << "The second element of ftpair2 is: " << ftpair2.second << std::endl;
}

// ==> std::pair
void make_pairTest()
{
    // this is the std::pair
    std::pair <int,int> std_foo;
    std::pair <double, char> std_bar;
    
    std_foo = std::make_pair (10,20);
    std_bar = std::make_pair (10.5,'A'); 
    
    std::cout << "std_foo: " << std_foo.first << ", " << std_foo.second << '\n';
    std::cout << "std_bar: " << std_bar.first << ", " << std_bar.second << '\n';
    std::cout << "\n-----------------\n";

    // this is the ft::pair
    ft::pair <int,int> ft_foo;
    ft::pair <double, char> ft_bar;
    
    ft_foo = ft::make_pair (10,20);
    ft_bar = ft::make_pair (10.5,'A'); 
    
    std::cout << "ft_foo: " << ft_foo.first << ", " << ft_foo.second << '\n';
    std::cout << "ft_bar: " << ft_bar.first << ", " << ft_bar.second << '\n';
}

// ==> std::enable_if
// the return type bool is valid if T is an integral type
// std function
template <class T>
typename std::enable_if<std::is_integral<T>::value, bool>::type is_odd (T t1) 
{
    return bool(t1%2);
}
// ft function
template <class T>
typename ft::enable_if<ft::is_integral<T>::value, bool>::type is_odd2 (T t1) 
{
    return bool(t1%2);
}
void enable_ifTest()
{
    // code does not compile if type of n is not integral
    int n = 1;    
    
    std::cout << "n is odd std: " << is_odd(n) << std::endl;

    std::cout << "n is odd ft: " << is_odd2(n) << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:53:53 by hboumahd          #+#    #+#             */
/*   Updated: 2023/01/23 16:39:14 by hboumahd         ###   ########.fr       */
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
    std::pair<int, std::string> myPair;
    myPair.first = 10;
    myPair.second = "Hello, World!";
    std::cout << "The first element of myPair is: " << myPair.first << std::endl;
    std::cout << "The second element of myPair is: " << myPair.second << std::endl;
}
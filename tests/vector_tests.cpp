/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:29:28 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/13 11:01:57 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <vector>

void test1_construction(int is_std)
{
  if (is_std)
  {
    std::cout << "std:\n";
    std::cout << "------\n";
    
    std::vector<int> v1;
    std::vector<int> v2(7, 13);
    
    v1 = v2;
    std::cout << "v1: ";
    for (size_t i = 0; i < v1.size(); i++)
      std::cout <<  v1[i] << " ";
    std::cout << "\n";
    
    std::vector<int>::iterator itf = v2.begin();
    std::vector<int>::iterator itl = v2.begin() + 5;
    std::vector<int> v3(itf, itl);
    std::cout << "v3: ";
    for (size_t i = 0; i < v3.size(); i++)
      std::cout <<  v3[i] << " ";
    std::cout << "\n";

    std::vector<int> v4(v3);
    std::cout << "v4: ";
    for (size_t i = 0; i < v4.size(); i++)
      std::cout <<  v4[i] << " ";
    std::cout << "\n";
  }
  else
  {
    std::cout << "std:\n";
    std::cout << "------\n";
    
    ft::vector<int> v1;
    ft::vector<int> v2(7, 13);
    
    // v1 = v2;
    // std::cout << "v1: ";
    // for (size_t i = 0; i < v1.size(); i++)
    //   std::cout <<  v1[i] << " ";
    // std::cout << "\n";
    
    // ft::vector<int>::iterator itf = v2.begin();
    // ft::vector<int>::iterator itl = v2.begin() + 5;
    // ft::vector<int> v3(itf, itl);
    // std::cout << "v3: ";
    // for (size_t i = 0; i < v3.size(); i++)
    //   std::cout <<  v3[i] << " ";
    // std::cout << "\n";

    // ft::vector<int> v4(v3);
    // std::cout << "v4: ";
    // for (size_t i = 0; i < v4.size(); i++)
    //   std::cout <<  v4[i] << " ";
    // std::cout << "\n";
  }
}

void vectorTest()
{
  int is_std = 1;
  test1_construction(is_std);
  test1_construction(0);
}
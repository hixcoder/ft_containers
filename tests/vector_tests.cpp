/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:29:28 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/15 13:31:57 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <vector>

void test1_construction(int is_std)
{
  if (is_std)
  {
    std::cout << "std: construction\n";
    std::cout << "-------------------\n";
    
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
    std::cout << "ft: construction\n";
    std::cout << "-------------------\n";
    
    ft::vector<int> v1;
    ft::vector<int> v2(7, 13);
    
    v1 = v2;
    std::cout << "v1: ";
    for (size_t i = 0; i < v1.size(); i++)
      std::cout <<  v1[i] << " ";
    std::cout << "\n";
    
    ft::vector<int>::iterator itf = v2.begin();
    ft::vector<int>::iterator itl = v2.begin() + 5;
    ft::vector<int> v3(itf, itl);
    std::cout << "v3: ";
    for (size_t i = 0; i < v3.size(); i++)
      std::cout <<  v3[i] << " ";
    std::cout << "\n";

    ft::vector<int> v4(v3);
    std::cout << "v4: ";
    for (size_t i = 0; i < v4.size(); i++)
      std::cout <<  v4[i] << " ";
    std::cout << "\n";
    ft::vector<int> v5;
    std::cout << "\ntest1: ok\n";
    std::cout << "-------------------\n";
  }
}

void test2_iterators(int is_std)
{
  if (is_std)
  {
    std::cout << "std: iterators\n";
    std::cout << "-------------------\n";
    std::vector<int> myvector;
    for (int i=1; i<=5; i++) 
      myvector.push_back(i);
  
    std::cout << "myvector contains iterator:";
    for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "myvector contains reverse iterator:";
    for (std::vector<int>::reverse_iterator it = myvector.rbegin() ; it != myvector.rend(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
    
    std::vector<int> v1;
    std::cout << "-------------------\n";
  }
  else
  {
    std::cout << "ft: iterators\n";
    std::cout << "-------------------\n";
    
    ft::vector<int> myvector;
    for (int i=1; i<=5; i++) 
      myvector.push_back(i);
  
    std::cout << "myvector contains iterator:";
    for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "myvector contains reverse iterator:";
    for (ft::vector<int>::reverse_iterator it = myvector.rbegin() ; it != myvector.rend(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
    
    std::vector<int> v1;
    std::cout << "\ntest2: ok\n";
    std::cout << "-------------------\n";

  }
}

void test3_capacity(int is_std)
{
  if (is_std)
  {
    std::cout << "std: capacity\n";
    std::cout << "-------------------\n";
    std::vector<int> v(9, 100);
      
    std::cout << "max_size: " << v.max_size() << "\n";
    std::cout << "size1: " << v.size() << "\n";
    std::cout << "capacity1: " << v.capacity() << "\n";
    v.reserve(15);
    std::cout << "capacity2: " << v.capacity() << "\n";
    v.resize(3);
    std::cout << "size2: " << v.size() << "\n";
    std::cout << "empty1: " << v.empty() << "\n";
    v.clear();
    std::cout << "empty2: " << v.empty() << "\n";
    
    std::cout << "-------------------\n\n";
  }
  else
  {
    std::cout << "ft: capacity\n";
    std::cout << "-------------------\n";
    ft::vector<int> v(9, 100);
      
    std::cout << "max_size: " << v.max_size() << "\n";
    std::cout << "size1: " << v.size() << "\n";
    std::cout << "capacity1: " << v.capacity() << "\n";
    v.reserve(15);
    std::cout << "capacity2: " << v.capacity() << "\n";
    v.resize(3);
    std::cout << "size2: " << v.size() << "\n";
    std::cout << "empty1: " << v.empty() << "\n";
    v.clear();
    std::cout << "empty2: " << v.empty() << "\n";
    
    std::cout << "\ntest3: ok\n";
    std::cout << "-------------------\n";

  }
}

void test4_elementaccess(int is_std)
{
  if (is_std)
  {
    std::cout << "std: capacity\n";
    std::cout << "-------------------\n";
    std::vector<int> v(9, 100);
      
  }
  else
  {
   
    std::cout << "\ntest3: ok\n";
    std::cout << "-------------------\n";

  }
}

void vectorTest()
{
  int is_std = 1;
  // test1_construction(is_std);
  // test2_iterators(is_std);
  // test3_capacity(is_std);
  test4_elementaccess(is_std);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:29:28 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/17 15:41:36 by hboumahd         ###   ########.fr       */
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
    std::cout << "std: Element access\n";
    std::cout << "-------------------\n";
    std::vector<int> v;
    v.push_back(45);
    v.push_back(445);
    v.push_back(345);
    v.push_back(745);
    v.push_back(6);
    v.push_back(32);
    // test operator[]
    std::cout << "v[i]   : ";
    for (size_t i = 0; i < v.size(); i++)
      std::cout << v[i] << " ";
    std::cout << "\n";

    // test at() function
    std::cout << "v.at(i): ";
    for (size_t i = 0; i < v.size(); i++)
      std::cout << v.at(i) << " ";
    std::cout << "\n";
    
    // test other functions
    std::cout << "v.front() = " << v.front() << "\n";
    
    std::cout << "v.back() = " << v.back() << "\n";
    
    int* p = v.data();
    std::cout << "p[i]: ";
    for (size_t i = 0; i < 3; i++)
      std::cout << p[i] << " ";
    std::cout << "\n";
  }
  else
  {
    std::cout << "\nft: Element access\n";
    std::cout << "-------------------\n";
    ft::vector<int> v;
    v.push_back(45);
    v.push_back(445);
    v.push_back(345);
    v.push_back(745);
    v.push_back(6);
    v.push_back(32);
    // test operator[]
    std::cout << "v[i]   : ";
    for (size_t i = 0; i < v.size(); i++)
      std::cout << v[i] << " ";
    std::cout << "\n";

    // test at() function
    std::cout << "v.at(i): ";
    for (size_t i = 0; i < v.size(); i++)
      std::cout << v.at(i) << " ";
    std::cout << "\n";
    
    // test other functions
    std::cout << "v.front() = " << v.front() << "\n";
    
    std::cout << "v.back() = " << v.back() << "\n";
    
    int* p = v.data();
    std::cout << "p[i]: ";
    for (size_t i = 0; i < 3; i++)
      std::cout << p[i] << " ";
    std::cout << "\n";
    
    std::cout << "\ntest4: ok\n";
    std::cout << "-------------------\n";

  }
}

void test5_modifiers(int is_std)
{
  if (is_std)
  {
    std::cout << "std: Element access\n";
    std::cout << "-------------------\n";

    // test assign function -------------------------------------
    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;

    first.assign (7,100);             // 7 ints with a value of 100

    std::vector<int>::iterator it0;
    it0=first.begin()+1;

    second.assign (it0,first.end()-1); // the 5 central values of first

    int myints[] = {1776,7,4};
    third.assign (myints,myints+3);   // assigning from array.

    std::cout << "Size of first: " << int (first.size()) << '\n';
    std::cout << "Size of second: " << int (second.size()) << '\n';
    std::cout << "Size of third: " << int (third.size()) << '\n';


    // test push_back -------------------------------------
    ft::vector<int> v;
    v.push_back(45);
    v.push_back(445);
    v.push_back(34445);
    v.push_back(4345);
    v.push_back(5);
    v.push_back(445);
    v.push_back(3445);
    std::cout << "v[i]   : ";
    for (size_t i = 0; i < v.size(); i++)
      std::cout << v[i] << " ";


    // test pop_back -------------------------------------
    for (size_t i = 0; i < 3; i++)
      v.pop_back();
    for (size_t i = 0; i < v.size(); i++)
      std::cout << v[i] << " ";

    // test insert -------------------------------------
    std::vector<int> myvector (3,100);
    std::vector<int>::iterator it;
    
    it = myvector.begin();
    it = myvector.insert ( it , 200 );
    
    myvector.insert (it,2,300);
    
    // "it" no longer valid, get a new one:
    it = myvector.begin();
    
    std::vector<int> anothervector (2,400);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());
    
    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray+3);
    
    std::cout << "myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';

    
    // test erase -------------------------------------
    
  }
  else
  {
    std::cout << "\nft: Element access\n";


  }
}
void vectorTest()
{
  int is_std = 1;
  // test1_construction(is_std);
  // test2_iterators(is_std);
  // test3_capacity(is_std);
  // test4_elementaccess(is_std);
  test5_modifiers(is_std);
}
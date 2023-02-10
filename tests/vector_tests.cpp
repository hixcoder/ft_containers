/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:29:28 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/10 16:30:46 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <vector>

void vectorTest()
{
  std::vector<int> v1;
  
  v1.push_back(5888);
  v1.push_back(5888);
  v1.push_back(58880);
  v1.push_back(58881);
  v1.push_back(58881);
  v1.push_back(58881);
  v1.push_back(58881);
  v1.push_back(58881);
  v1.push_back(58881);

  std::vector<int> v;
  
  v.push_back(50);
  v.push_back(50);
  v.push_back(550);
  v.push_back(501);
  
  std::cout << "capacity - size: " << v.capacity() << " - " << v.size()<< "\n";
  v.reserve(6);
  std::cout << "capacity - size: " << v.capacity() << " - " << v.size() << "\n";
  v = v1;
  std::cout << "capacity2 - size: " << v.capacity()  << " - " << v.size()<< "\n";
  for (size_t i = 0; i < v.size(); i++)
    std::cout << "v["<< i << "]= "<< v[i] << "\n"; 
  
  std::cout << "\n";
  v.assign (7,100);           
  for (size_t i = 0; i < v.size(); i++)
    std::cout << "v["<< i << "]= "<< v[i] << "\n"; 
  
}
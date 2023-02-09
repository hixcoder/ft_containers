/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:29:28 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/09 16:35:09 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <vector>

void vectorTest()
{
  std::vector<int> v;
  
  v.push_back(50);
  for (size_t i = 0; i < v.size(); i++)
    std::cout << "v["<< i << "]= "<< v[i] << "\n"; 
  
  std::cout << "\n";
  v.assign (7,100);           
  for (size_t i = 0; i < v.size(); i++)
    std::cout << "v["<< i << "]= "<< v[i] << "\n"; 
  
}
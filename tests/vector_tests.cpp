/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:29:28 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/09 12:51:21 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <vector>

void vectorTest()
{
  // std::vector
  // std::vector<int> v1 = {445, 78, 57, 89, 20};
  // std::vector<int>::iterator it = v1.begin();
  
  std::vector<int> myvector (100);
  for (size_t i = 0; i < 50; i++)
  {
    myvector[i] = i;
  }
  
  std::cout << "1. capacity of myvector: " << myvector.size() << '\n';

  myvector.reserve(10);
  std::cout << "2. size of myvector: " << myvector.size() << '\n';

  myvector.shrink_to_fit();
  std::cout << "3. capacity of myvector: " << myvector.size() << "\n\n";


  // ft::vector<int> ft_myvector (100);
  // for (size_t i = 0; i < 50; i++)
  // {
  //   ft_myvector[i] = i;
  // }
  
  // std::cout << "1. capacity of ft_myvector: " << ft_myvector.capacity() << '\n';

  // ft_myvector.resize(10);
  // std::cout << "2. size of ft_myvector: " << ft_myvector.capacity() << '\n';

  // ft_myvector.shrink_to_fit();
  // std::cout << "3. capacity of ft_myvector: " << ft_myvector.capacity() << '\n';
  
}
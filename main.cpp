/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:04:17 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/19 15:58:54 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

int main()
{
    // ==> algorithm tests:
    // equalTest();
    // lexicographical_compareTest();
    // is_integralTest();
    // pairTest();
    // make_pairTest();
    // enable_ifTest();
    
    // ==> iterators tests:
    // iterator_traitsTest();

    // stack tests:
    // stackTest();

    // vector tests
    vectorTest();

// std::cout << "\nstd result\n";
// {
// 	std::vector<int> vector;
// 	std::vector<int> v;
//     vector.assign(2600 * 1000, 1);
//     v.push_back(*(vector.insert(vector.end() - 800 * 1000, 44)));
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
        
//     std::cout << "std v[i]= ";
//     for (size_t i = 0; i < tmp.size(); i++)
//         std::cout << v[i] << " ";    
// }

// std::cout << "\nft result\n";
// {
// 	std::vector<int> v;
// 	ft::vector<int> vector(3, 3);
// 	std::vector<int> tmp(1000 * 1000, 4);
// 	ft::vector<int> tmp2(tmp.begin(), tmp.end());
// 	v.push_back(tmp2.size());
// 	v.push_back(tmp2.capacity());
// 	for (size_t i = 0; i < tmp.size(); ++i)
// 		v.push_back(tmp2[i]);

//     std::cout << "ft v[i]= ";
//     for (size_t i = 0; i < tmp.size(); i++)
//         std::cout << v[i] << " ";    
// }

}


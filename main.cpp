/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:04:17 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/18 16:26:53 by hboumahd         ###   ########.fr       */
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
    // vectorTest();

    int _ratio = 1000;
    std::cout << "test assign:\n";
    std::cout << "std result:\n";

{
    std::vector<int> vector;
    std::vector<int> v;
	std::vector<int> tmp;
	vector.assign(3, 3);
	tmp.assign(4000 * _ratio, 1);
	vector.assign(tmp.begin(), tmp.end());
	// for (size_t i = 0; i < tmp.size(); ++i)
	// 	v.push_back(vector[i]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
    
    std::cout << "std:: v[i]= ";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    
    
}
    std::cout << "\n\nft result:\n";

{
    ft::vector<int> vector;
    std::vector<int> v;
	std::vector<int> tmp;
	vector.assign(3, 3);
	tmp.assign(4000 * _ratio, 1);
	vector.assign(tmp.begin(), tmp.end());
	// for (size_t i = 0; i < tmp.size(); ++i)
	// 	v.push_back(vector[i]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
    
    std::cout << "ft:: v[i]= ";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
}

}


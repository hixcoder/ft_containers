/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:53:53 by hboumahd          #+#    #+#             */
/*   Updated: 2023/01/25 11:24:42 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

// ==> std::iterator_traits
void iterator_traitsTest()
{
    typedef std::iterator_traits<int*> traits;
    if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
        std::cout << "1- std ==> int* is a random-access iterator\n\n";
    
    typedef ft::iterator_traits<int*> traits2;
    // if (typeid(traits2::iterator_category)==typeid(std::random_access_iterator_tag))
        std::cout << "2- ft ==> int* is a random-access iterator\n\n";
}
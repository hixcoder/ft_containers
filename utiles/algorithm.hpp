/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:36:22 by hboumahd          #+#    #+#             */
/*   Updated: 2023/01/23 12:06:36 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>

//  ==> std::equal 
namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 f1, InputIterator1 l1, InputIterator2 f2)
    {
        while (f1 != l1)
        {
            if (!(*f1 == *f2))
                return false;
            ++f1;
            ++f2;
        }
        return true;
    }
}

//  ==> std::lexicographical_compare 
namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 f1, InputIterator1 l1, InputIterator2 f2, InputIterator2 l2)
    {
        while (f1 != l1)
        {
            if ((*f1 > *f2) || (f2 == l2))
                return false;
            else if (*f1 < *f2)
                return true;
            ++f1;
            ++f2;
        }
        return (f2 != l2);
    }
}

//  ==> std::is_integral 
namespace ft
{
    template <class T>
    struct is_integral
    {
        
    };
}
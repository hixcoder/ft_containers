/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:49:57 by hboumahd          #+#    #+#             */
/*   Updated: 2023/01/25 11:24:53 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>

// std::iterator_traits
namespace ft
{
    template <class Iterator> 
    class iterator_traits
    {
        
    };
    template <class T> 
    class iterator_traits<T*>
    {
        
    };
    template <class T> 
    class iterator_traits<const T*>
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        // typedef random_access_iterator_tag iterator_category;
    };
}
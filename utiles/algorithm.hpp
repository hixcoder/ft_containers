/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:36:22 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/14 10:05:28 by hboumahd         ###   ########.fr       */
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
        static const bool value = false;
    };
    
    template <>
    struct is_integral<bool>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<char16_t>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<char32_t>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<wchar_t>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<short int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<long int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<long long int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned short int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned long int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned long long int>
    {
        static const bool value = true;
    };
  
}

//  ==> std::pair
namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        public:
            T1 first;
            T2 second;
        public:
            pair(){}
            pair(T1 t1, T2 t2)
            {
                this->first = t1;
                this->second = t2;
            }
            pair(pair const &other)
            {
                this->first = other.first;
                this->second = other.second;
            }
            pair& operator=(pair const& other) 
            {
                first = other.first;
                second = other.second;
                return *this;
            }
            ~pair(){}

            void swap (pair &p2) 
            {
                pair tmp;
                
                tmp.first = this->first;
                tmp.second = this->second;
                this->first = p2.first;
                this->second = p2.second;
                p2.first = tmp.first;
                p2.second = tmp.second;
            }
    };
}

//  ==> std::pair
namespace ft
{
   template <class T1,class T2>
   pair<T1,T2> make_pair (T1 x, T2 y)
   {
      return ( pair<T1,T2>(x,y) );
   }
}

//  ==> std::enable_if
namespace ft
{
    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };
}
    // **************| other functions|*******************

namespace ft
{
    //  ==> std::distance
    template<class InputIterator>     
    std::ptrdiff_t distance(InputIterator first, InputIterator last)
    {
        std::ptrdiff_t distance = 0;
        while (first != last) {
            ++distance;
            ++first;
        }
        return (distance);
    }

}


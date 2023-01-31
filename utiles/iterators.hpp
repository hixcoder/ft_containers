/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:49:57 by hboumahd          #+#    #+#             */
/*   Updated: 2023/01/31 14:52:30 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <cstddef>

// std::iterator_traits
namespace ft
{
    struct random_access_iterator_tag {};
    
    template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
    struct iterator 
    {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };
    template <class Iterator> 
    class iterator_traits
    {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    };
    template <class T> 
    class iterator_traits<T*>
    {
        typedef ptrdiff_t                   difference_type;
        typedef T                           value_type;
        typedef T*                          pointer;
        typedef T&                          reference;
        typedef random_access_iterator_tag  iterator_category;
    };
    template <class T> 
    class iterator_traits<const T*>
    {
        typedef ptrdiff_t                   difference_type;
        typedef T                           value_type;
        typedef const T*                    pointer;
        typedef const T&                    reference;
        typedef random_access_iterator_tag  iterator_category;
    };

    template <class Iterator>
    class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
                        typename iterator_traits<Iterator>::value_type,
                        typename iterator_traits<Iterator>::difference_type,
                        typename iterator_traits<Iterator>::pointer,
                        typename iterator_traits<Iterator>::reference>
    {
    protected:
        Iterator current;
    public:
        typedef Iterator                                            iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef typename iterator_traits<Iterator>::reference       reference;
        typedef typename iterator_traits<Iterator>::pointer         pointer;

        constexpr reverse_iterator();
        constexpr explicit reverse_iterator(Iterator x);
        template <class U> constexpr reverse_iterator(const reverse_iterator<U>& u);
        template <class U> constexpr reverse_iterator& operator=(const reverse_iterator<U>& u);
        constexpr Iterator base() const;
        constexpr reference operator*() const;
        constexpr pointer   operator->() const;
        constexpr reverse_iterator& operator++();
        constexpr reverse_iterator  operator++(int);
        constexpr reverse_iterator& operator--();
        constexpr reverse_iterator  operator--(int);
        constexpr reverse_iterator  operator+ (difference_type n) const;
        constexpr reverse_iterator& operator+=(difference_type n);
        constexpr reverse_iterator  operator- (difference_type n) const;
        constexpr reverse_iterator& operator-=(difference_type n);
        constexpr reference         operator[](difference_type n) const;
    };
}
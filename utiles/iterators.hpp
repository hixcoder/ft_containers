/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:49:57 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/01 12:19:30 by hboumahd         ###   ########.fr       */
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

    public:
        constexpr reverse_iterator(): current(){}
        constexpr explicit reverse_iterator(Iterator x) : current(x){}
        template <class U> constexpr reverse_iterator(const reverse_iterator<U>& u): current(u.base()){}
        template <class U> reverse_iterator& operator=(const reverse_iterator<U>& u)
        {
            this->current = u.base();
            return *this;
        }
        
        constexpr Iterator base() const 
        {
            return this->current;
        };
        reference operator*() const 
        {
            return *(this->current - 1);
        };
        pointer   operator->() const
        {
            return &(operator*());
        };
        reverse_iterator& operator++()
        {
            --this->current;
            return *this;
        };
        reverse_iterator  operator++(int)
        {
            reverse_iterator tmp(*this);
            --this->current;
            return (tmp);
        };
        reverse_iterator& operator--()
        {
            ++this->current;
            return *this;
        };
        reverse_iterator  operator--(int)
        {
            reverse_iterator tmp(*this);
            ++this->current;
            return (tmp);
        };
        reverse_iterator  operator+ (difference_type n) const
        {
            return reverse_iterator(this->current - n);
        };
        reverse_iterator& operator+=(difference_type n)
        {
            this->current -= n;
            return *this;
        }
        reverse_iterator  operator- (difference_type n) const
        {
            return reverse_iterator(this->current + n);
        };
        reverse_iterator& operator-=(difference_type n)
        {
            this->current += n;
            return *this;
        }
        reference         operator[](difference_type n) const
        {
            return *(*this + n);
        }
    };
}
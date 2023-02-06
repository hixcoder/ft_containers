/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:29:18 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/06 15:48:30 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "../utiles/iterators.hpp"

namespace ft
{
    template <class _Tp, class _Allocator = std::allocator<_Tp> >
    class vector
    {
        public:
            typedef _Tp                                             value_type;
            typedef _Allocator                                      allocator_type;
            typedef typename allocator_type::reference              reference;
            typedef typename allocator_type::const_reference        const_reference;
            typedef typename allocator_type::pointer                pointer;
            typedef typename allocator_type::const_pointer          const_pointer;
            typedef typename allocator_type::size_type              size_type;
            typedef typename allocator_type::difference_type        difference_type;
            
            typedef ft::random_access_iterator<value_type>          iterator;
            typedef ft::random_access_iterator<const value_type>    const_iterator;
            typedef ft::reverse_iterator<iterator>                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
        
        private:
            size_type m_size;
            size_type m_capacity;
            allocator_type m_alloc;
            pointer m_ptr;
            
            
        public:
            explicit vector (const allocator_type& alloc = allocator_type()): m_capacity(0), m_size(0), m_alloc(alloc), m_ptr(NULL){}
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            {
                m_size = n;
                m_capacity = n;
                m_alloc = alloc;
                m_ptr = m_alloc.allocate(n);
                for (size_type i = 0; i < n; i++)
                    m_alloc.construct(&m_ptr[i], val);
            }
            template <class  InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
            {
                size_type n = std::distance(first,last);
                m_size = n;
                m_capacity = n;
                m_alloc = alloc;
                m_ptr = m_alloc.allocate(n);
                int i = 0;
                for (InputIterator it = first; it != last; it++)
                {
                    m_alloc.construct(&m_ptr[i], *it);
                    i++;
                }
            }
            vector (const vector& x);
            ~vector();
            vector& operator= (const vector& x);

            // iterators:
            iterator begin() {return iterator(m_ptr);}
            iterator end() {return iterator(m_ptr + m_size);}
            const_iterator cbegin() const {return const_iterator(m_ptr);}
            const_iterator cend() const {return const_iterator(m_ptr + m_size);}
            reverse_iterator rbegin() {return end();}
            reverse_iterator rend() {return begin();}
            const_reverse_iterator crbegin() const {return cend();}
            const_reverse_iterator crend() const {return cbegin();}

            // capacity:
            size_type size() const {return m_size;}
            size_type max_size() const {return m_alloc.max_size();}
            void resize (size_type n, value_type val = value_type())
            {
                if (n > m_capacity)
                    reserve(n);
                if (n >= m_size)
                {
                    for (size_type i = m_size; i < n; i++)
                        m_alloc.construct(&m_ptr[i], val);
                }
                else
                {
                    for (size_type i = n; i < m_size; i++)
                        m_alloc.destroy(&m_ptr[i]);
                }
                m_size = n;
            }
            
            size_type capacity() const {return m_capacity;}
            bool empty() const {return (m_ptr) ? true: false;}
            void reserve (size_type n)
            {
                if (n > this->max_size())
                    throw (std::length_error("lenght_error ==> ft::vector::reserve"));
                else if (n > m_capacity)
                {
                    pointer new_ptr = m_alloc.allocate(n);
                    for (size_type i = 0; i < m_size; i++)
                        m_alloc.construct(&new_ptr[i], m_ptr[i]);
                    m_alloc.dealloacate(m_ptr, m_capacity);
                    m_ptr = new_ptr;
                    m_capacity = n;
                }
            }
    };
}

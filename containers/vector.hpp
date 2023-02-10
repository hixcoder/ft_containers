/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:29:18 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/10 16:39:29 by hboumahd         ###   ########.fr       */
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
            template <class  InputIterator> vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
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
            vector(const vector& x)
            {
                *this = x;
            }
            ~vector();
            vector& operator=(const vector& x)
            {
                if (this == &x)
                    return *this;
                m_alloc = x.m_alloc;
                m_capacity = x.m_capacity;
                m_size = x.m_size;
                m_alloc.deallocate(m_ptr);
                m_ptr = m_alloc.allocate(m_capacity);
                for (size_type i = 0; i < m_size; i++)
                    m_alloc.construct(&m_ptr[i], x.m_ptr[i]);
                return *this;
            }

            // iterators:
            iterator begin() {return iterator(m_ptr);}
            iterator end() {return iterator(m_ptr + m_size);}
            reverse_iterator rbegin() {return end();}
            reverse_iterator rend() {return begin();}

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
                    m_alloc.deallocate(m_ptr, m_capacity);
                    m_ptr = new_ptr;
                    m_capacity = n;
                }
            }
            
            // element access:
            reference operator[] (size_type n) {return m_ptr[n];}
            const_reference operator[] (size_type n) const {return m_ptr[n];}
            reference at (size_type n)
            {
                if (n >= m_size)
                    throw (std::out_of_range("out_of_range ==> ft::vector::at"));
                else
                    return m_ptr[n];
            }
            const_reference at (size_type n) const
            {
                if (n >= m_size)
                    throw (std::out_of_range("out_of_range ==> ft::vector::at"));
                else
                    return m_ptr[n];
            }
            reference front(){return m_ptr[0];}
            const_reference front() const{return m_ptr[0];}
            reference back(){return m_ptr[m_size - 1];}
            const_reference back() const{return m_ptr[m_size - 1];}
            value_type* data() {return m_ptr;}
            const value_type* data() const {return m_ptr;}

            // modifiers:
            template <class InputIterator>  void assign (InputIterator first, InputIterator last)
            {
                size_type n = std::distance(first,last);
                pointer new_ptr;
                
                if (n >= m_capacity)
                {
                    new_ptr = m_alloc.allocate(n);
                    m_capacity = n;
                }
                else
                    new_ptr = m_alloc.allocate(m_capacity);
                for (size_type i = 0; i < n; i++)
                {
                    m_alloc.construct(&new_ptr[i], *first);
                    first++;
                }
                m_alloc.deallocate(m_ptr, m_capacity);
                m_ptr = new_ptr;
                m_size = n;
            }
            void assign (size_type n, const value_type& val)
            {
                pointer new_ptr;
                
                if (n >= m_capacity)
                {
                    new_ptr = m_alloc.allocate(n);
                    m_capacity = n;
                }
                else
                    new_ptr = m_alloc.allocate(m_capacity);
                for (size_type i = 0; i < n; i++)
                    m_alloc.construct(&new_ptr[i], val);
                m_alloc.deallocate(m_ptr, m_capacity);
                m_ptr = new_ptr;
                m_size = n;
            }
            void push_back (const value_type& val)
            {
                if (m_capacity == m_size)
                {
                    m_capacity += 1;
                    reserve(m_capacity);
                }
                m_alloc.construct(&m_ptr[m_size], val);
                m_size += 1;
            }
            void pop_back()
            {
                if (m_size > 0)
                {
                    m_alloc.destroy(this->end() - 1);
                    m_size--;
                }
            }
            iterator insert (iterator position, const value_type& val)
            {
                
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                
            }
            template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last)
            {
                
            }
    };
}

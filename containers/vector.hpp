/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:29:18 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/18 16:28:59 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "../utiles/iterators.hpp"
#include "../utiles/algorithm.hpp"

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
            explicit vector (const allocator_type& alloc = allocator_type()): m_size(0), m_capacity(0), m_alloc(alloc), m_ptr(NULL){}
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            {
                m_size = n;
                m_capacity = n;
                m_alloc = alloc;
                m_ptr = m_alloc.allocate(n);
                for (size_type i = 0; i < n; i++)
                    m_alloc.construct(&m_ptr[i], val);
            }
             
            template <class  InputIterator> 
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0)
            {
                size_type n = distance(first,last);
                m_size = n;
                m_capacity = n;
                m_alloc = alloc;
                m_ptr = m_alloc.allocate(n);
                size_type i = 0;
                for (InputIterator it = first; it != last; it++)
                {
                    m_alloc.construct(m_ptr + i, *it);
                    i++;
                }
            }
            
            vector(const vector& x)
            {
                *this = x;
            }
            ~vector()
            {
                clear();
                if (m_capacity > 0)
                    m_alloc.deallocate(m_ptr, m_capacity);
            };
            vector& operator=(const vector& other)
            {
                if (this == &other)
                    return *this;
                if (m_size > 0)
                    m_alloc.deallocate(m_ptr, m_capacity);
                m_alloc = other.m_alloc;
                m_capacity = other.m_capacity;
                m_size = other.m_size;
                m_ptr = m_alloc.allocate(m_capacity);
                for (size_type i = 0; i < m_size; i++)
                    m_alloc.construct(&m_ptr[i], other.m_ptr[i]);
                return *this;
            }

            // iterators:
            iterator begin() {return iterator(m_ptr);}
            iterator end() {return iterator(m_ptr + m_size);}
            reverse_iterator rbegin() {return reverse_iterator(end());}
            reverse_iterator rend() {return reverse_iterator(begin());}

            // capacity:
            size_type size() const {return m_size;}
            size_type max_size() const {return m_alloc.max_size();}
            void resize (size_type n, value_type val = value_type())
            {
                if (n > m_capacity)
                    reserve(m_capacity * 2);
                if (n > m_size)
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
            bool empty() const {return (m_size == 0) ? true: false;}
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
            template <class InputIterator>  void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
            {
                pointer new_ptr;
                size_type old_capacity;
                InputIterator tmp = first;
                size_type n = ft::distance(tmp,last);
                
                if (n > m_capacity)
                {
                    new_ptr = m_alloc.allocate(n);
                    old_capacity = m_capacity;
                    m_capacity = n;
                }
                else
                {
                    new_ptr = m_alloc.allocate(m_capacity);
                    old_capacity = m_capacity;
                }
                for (size_type i = 0; i < n; i++)
                {
                    m_alloc.construct(&new_ptr[i], *first);
                    first++;
                }
                m_alloc.deallocate(m_ptr, old_capacity);
                m_ptr = new_ptr;
                m_size = n;

                // this->clear();
			    // while (first != last) {
                //     push_back(*first);
                //     ++first;
			    // }
            }
            
            void assign (size_type n, const value_type& val)
            {
                pointer new_ptr;
                size_type old_capacity;
                
                if (n > m_capacity)
                {
                    new_ptr = m_alloc.allocate(n);
                    old_capacity = m_capacity;
                    m_capacity = n;
                }
                else
                {
                    new_ptr = m_alloc.allocate(m_capacity);
                    old_capacity = m_capacity;
                }
                for (size_type i = 0; i < n; i++)
                    m_alloc.construct(&new_ptr[i], val);
                m_alloc.deallocate(m_ptr, old_capacity);
                m_ptr = new_ptr;
                m_size = n;
            }
            
            void push_back (const value_type& val)
            {
                if (m_size == m_capacity )
                {
                    if (m_capacity == 0)
                        reserve(1);
                    else
                        reserve(m_size * 2);
                }
                m_alloc.construct(&m_ptr[m_size], val);
                m_size++;
            }
            void pop_back()
            {
                if (m_size > 0)
                {
                    m_alloc.destroy(&(*end()) - 1);
                    m_size--;
                }
            }
            iterator insert (iterator position, const value_type& val)
            {
                size_type position_indx = distance(begin(), position);
			    insert(position, 1, val);
			    return (iterator(&this->m_ptr[position_indx]));
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                pointer new_ptr;
                size_type k = 0;
                size_type s_old = m_size;
                int i = 0;
                
                m_size += n;
                if (m_capacity < m_size)
                    m_capacity += (m_size - m_capacity);
                new_ptr = m_alloc.allocate(m_size);
                
                for (iterator it = begin(); it != end(); it++)
                {
                    if (it == position)
                    {
                        for (size_type j = 0; j < n; j++)
                        {
                            m_alloc.construct(&new_ptr[i], val);
                            i++;
                        }
                    }
                    m_alloc.construct(&new_ptr[i], m_ptr[k]);
                    i++;
                    k++;
                }
                m_alloc.deallocate(m_ptr, s_old);
                m_ptr = new_ptr;
            }
            template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
            {
                pointer new_ptr;
                size_type n;
                size_type s_old;
                int i = 0;
                size_type k = 0;
                
                n = distance(first, last);
                s_old = m_capacity;
                m_size += n;
                if (m_capacity < m_size)
                    m_capacity += (m_size - m_capacity);
                new_ptr = m_alloc.allocate(m_capacity);

                for (iterator it = begin(); it != end(); it++)
                {
                    if (it == position)
                    {
                        for (size_type j = 0; j < n; j++)
                        {
                            m_alloc.construct(&new_ptr[i], *(first + k));
                            i++;
                        }
                    }
                    m_alloc.construct(&new_ptr[i], m_ptr[k]);
                    i++;
                    k++;
                }
                m_alloc.deallocate(m_ptr, s_old);
                m_ptr = new_ptr;
            }
            // iterator erase (iterator position)
            // {
            //     pointer new_ptr;
            //     size_type save;
            //     size_type k;
                
            //     new_ptr = m_alloc.allocate(m_capacity);
            //     m_size--;
            //     k = 0;
            //     for (size_type i = 0; i < m_size; i++)
            //     {
            //         if(&m_ptr[k] == position)
            //         {
            //             save = k;
            //             k++;
            //         }
            //         m_alloc.construct(&new_ptr[i], m_ptr[k]);
            //         k++;
            //     }
            //     m_alloc.deallocate(m_ptr, m_capacity);
            //     m_ptr = new_ptr;
            //     return &new_ptr[save];
            // }
            // iterator erase (iterator first, iterator last)
            // {
            //     pointer new_ptr;
            //     size_type save;
            //     size_type k;
            //     size_type n;
            //     iterator position;
                
            //     n = distance(first, last);
            //     m_size -= n;
            //     new_ptr = m_alloc.allocate(m_capacity);
            //     k = 0;
            //     position = first;
            //     for (size_type i = 0; i < m_size; i++)
            //     {
            //         if(&m_ptr[k] == position)
            //         {
            //             if (position == first)
            //                 save = k;
            //             k++;
            //             position++;
            //         }
            //         m_alloc.construct(&new_ptr[i], m_ptr[k]);
            //         k++;
            //     }
            //     m_alloc.deallocate(m_ptr, m_capacity);
            //     m_ptr = new_ptr;
            //     return &new_ptr[save];
            // }
            void swap (vector& x)
            {
                size_type m_size_tmp = x.m_size;
                size_type m_capacity_tmp = x.m_capacity;
                allocator_type m_alloc_tmp = x.m_alloc;
                pointer m_ptr_tmp = x.m_ptr;
                
                x.m_size = m_size;
                x.m_capacity = m_capacity;
                x.m_alloc = m_alloc;
                x.m_ptr = m_ptr;
                
                m_size = m_size_tmp;
                m_capacity = m_capacity_tmp;
                m_alloc = m_alloc_tmp;
                m_ptr = m_ptr_tmp;
            }
            void clear()
            {
                for (size_type i = 0; i < size(); i++)
                    m_alloc.destroy(&m_ptr[i]);
                m_size = 0;
            }

            //  Allocator:
            allocator_type get_allocator() const
            {
                allocator_type m_alloc_copy = m_alloc;
                return m_alloc_copy; 
            };
    };

    // relational operators:
    template <class T, class Alloc>  bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    template <class T, class Alloc>  bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class T, class Alloc>  bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template <class T, class Alloc>  bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ((rhs < lhs));
    }
    template <class T, class Alloc>  bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }
    template <class T, class Alloc>  bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }
    
    // swap:
    template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
}
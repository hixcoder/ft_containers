/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:29:18 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/01 11:16:55 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <memory>

namespace ft
{
    template <class _Tp, class _Allocator = std::allocator<_Tp> >
    class vector
    {
        typedef _Tp                                         value_type;
        typedef _Allocator                                  allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        
        typedef _Allocator      iterator;
        typedef _Allocator      const_iterator;
        typedef _Allocator      reverse_iterator;
        typedef _Allocator      const_reverse_iterator;
        typedef _Allocator      difference_type;
        typedef _Allocator      size_type;

        public:
            explicit vector (const allocator_type& alloc = allocator_type());
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
            template <class  InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
            vector (const vector& x);
            ~vector();
            vector& operator= (const vector& x);
    };
}

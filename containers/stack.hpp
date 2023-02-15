/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:26:57 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/15 11:36:32 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <vector>
# include "vector.hpp"

namespace ft
{
    template <class dataType, class Container = std::vector<dataType> >
    class stack
    {
    public:
        typedef Container                                   container_type;
        typedef typename container_type::value_type         value_type;
        typedef typename container_type::const_reference    const_reference;
        typedef typename container_type::reference          reference;
        typedef typename container_type::size_type          size_type;
        
    protected:
        container_type c;

    public:
        stack(): c() {}
        stack(const stack& other) : c(other.c) {}
        explicit stack(const container_type& __c) : c(__c) {}
        stack& operator=(const stack& other) 
        {
            c = other.c; 
            return *this;
        }

        bool empty() const          {return c.empty();}
        size_type size() const      {return c.size();}
        reference top()             {return c.back();}
        const_reference top() const {return c.back();}
        void push(const value_type& __v)
        {
            c.push_back(__v);
        }
        void pop()
        {
            c.pop_back();
        }

        friend bool operator==(const stack<dataType, container_type>& stack1, const stack<dataType, container_type>& stack2)
        {
            return (stack1.c == stack2.c);
        }

        friend bool operator!=(const stack<dataType, container_type>& stack1, const stack<dataType, container_type>& stack2)
        {
            return (stack1.c != stack2.c);
        }

        friend bool operator<(const stack<dataType, container_type>& stack1, const stack<dataType, container_type>& stack2)
        {
            return (stack1.c < stack2.c);
        }
        
        friend bool operator>(const stack<dataType, container_type>& stack1, const stack<dataType, container_type>& stack2)
        {
            return (stack1.c > stack2.c);
        }

        friend bool operator>=(const stack<dataType, container_type>& stack1, const stack<dataType, container_type>& stack2)
        {
            return (stack1.c >= stack2.c);
        }

        friend bool operator<=(const stack<dataType, container_type>& stack1, const stack<dataType, container_type>& stack2)
        {
            return (stack1.c <= stack2.c);
        }
    };


}

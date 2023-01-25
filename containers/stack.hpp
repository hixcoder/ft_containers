/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:26:57 by hboumahd          #+#    #+#             */
/*   Updated: 2023/01/25 16:39:37 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <vector>


namespace ft
{
    template <class dataType, class containerType = std::vector<dataType> >
    class stack
    {
    public:
        typedef typename containerType::value_type      valueType;
        typedef typename containerType::reference       reference;
        typedef typename containerType::const_reference const_reference;
        typedef typename containerType::size_type       size_type;
        
    protected:
        containerType c;

    public:
        stack(): c() {}
        stack(const stack& other) : c(other.c) {}
        explicit stack(const containerType& __c) : c(__c) {}
        stack& operator=(const stack& other) 
        {
            c = other.c; 
            return *this;
        }


        bool empty()     const      {return c.empty();}
        size_type size() const      {return c.size();}
        reference top()             {return c.back();}
        const_reference top() const {return c.back();}

        void push(const valueType& __v) 
        {
            c.push_back(__v);
        }
        
        void pop() 
        {
            c.pop_back();
        }

        void swap(stack& __s)
        {
            swap(c, __s.c);
        }

        friend bool operator==(const stack<dataType, containerType>& stack1, const stack<dataType, containerType>& stack2)
        {
            return (stack1.c == stack2.c);
        }

        friend bool operator<(const stack<dataType, containerType>& stack1, const stack<dataType, containerType>& stack2)
        {
            return (stack1.c < stack2.c);
        }
        
        friend bool operator!=(const stack<dataType, containerType>& stack1, const stack<dataType, containerType>& stack2)
        {
            return (stack1.c != stack2.c);
        }
        
        friend bool operator>(const stack<dataType, containerType>& stack1, const stack<dataType, containerType>& stack2)
        {
            return (stack1.c > stack2.c);
        }
        
        friend bool operator>(const stack<dataType, containerType>& stack1, const stack<dataType, containerType>& stack2)
        {
            return (stack1.c > stack2.c);
        }

        friend bool operator>=(const stack<dataType, containerType>& stack1, const stack<dataType, containerType>& stack2)
        {
            return (stack1.c >= stack2.c);
        }

        friend bool operator<=(const stack<dataType, containerType>& stack1, const stack<dataType, containerType>& stack2)
        {
            return (stack1.c <= stack2.c);
        }
    };


}

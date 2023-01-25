/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:29:28 by hboumahd          #+#    #+#             */
/*   Updated: 2023/01/25 14:42:00 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <stack>

void stackTest()
{
    // ==> std::stack
    // create a stack of strings
    std::stack<std::string> colors;
    // push elements into the stack
    colors.push("Red");
    colors.push("Orange");
    colors.push("babd");
    colors.pop();
    std::cout << "std Stack: ";
    // print elements of stack
     while(!colors.empty()) {
      std::cout << colors.top() << ", ";
      colors.pop();
    }

    // ==> ft::stack
    // create a stack of strings
    std::cout << "\n---------------\n";
    ft::stack<std::string> colors2;
    // push elements into the stack
    colors2.push("Red");
    colors2.push("Orange");
    colors2.push("bab");
    colors2.pop();
    std::cout << "ft Stack: ";
    // print elements of stack
     while(!colors2.empty()) {
      std::cout << colors2.top() << ", ";
      colors2.pop();
    }
    std::cout << "\n";
}
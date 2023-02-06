/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:12:45 by hboumahd          #+#    #+#             */
/*   Updated: 2023/02/06 15:59:00 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <vector>
#include <utility>
# include "../utiles/algorithm.hpp"
# include "../utiles/iterators.hpp"
# include "../containers/stack.hpp"
# include "../containers/vector.hpp"

// algorithms tests
void equalTest();
void lexicographical_compareTest();
void is_integralTest();
void pairTest();
void make_pairTest();
void enable_ifTest();

// iterators tests
void iterator_traitsTest();


// stack tests
void stackTest();

// vector tests
void vectorTest();
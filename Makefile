# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 17:15:58 by hboumahd          #+#    #+#              #
#    Updated: 2023/01/25 10:00:48 by hboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

SRCS =	main.cpp tests/algorithm_tests.cpp

SRCOBJ = ${SRCS:.cpp=.o}

Include = tests/tests.hpp utiles/algorithm.hpp  utiles/iterators.hpp

# -g for the debugger
%.o:%.cpp ${Include}
		${CPP} ${CPPFLAGS} -g -c $< -o $@

$(NAME): ${SRCOBJ} 
	@$(CPP) ${FLAGS} $(SRCOBJ) -o $(NAME)
	@echo "|+| make the program [${GREEN}DONE${RESET}]"
	
all: ${NAME}

clean:
	@rm -f ${SRCOBJ}

fclean: clean
	@rm -f ${NAME}
	@echo "|-| remove the programs  [${RED}DONE${RESET}]"

re: fclean all

# colors used
GREEN = \033[0;92m
RED = \033[0;91m
RESET = \033[0m
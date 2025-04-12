# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 15:53:59 by vlomakin          #+#    #+#              #
#    Updated: 2025/04/12 12:31:13 by lomakinaval      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRC = 	main.cpp \
		PmergeMe.cpp \

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -O0

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@rm -f $(OBJ)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re
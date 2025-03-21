# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 15:53:59 by vlomakin          #+#    #+#              #
#    Updated: 2025/03/21 15:54:00 by vlomakin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = converter

SRC = 	main.cpp \
		ScalarConverter.cpp \

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

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
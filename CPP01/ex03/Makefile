# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 18:03:07 by lomakinaval       #+#    #+#              #
#    Updated: 2024/08/14 18:28:14 by lomakinaval      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = unnesessaryViolence

SRC =	main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp \

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

$(NAME):$(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@rm -f $(OBJ)

all: $(NAME)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

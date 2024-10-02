# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 12:09:54 by lomakinaval       #+#    #+#              #
#    Updated: 2024/10/02 18:25:11 by lomakinaval      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fragTrap

SRC = 	main.cpp \
		ClapTrap.cpp\
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp \

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@rm -f $(OBJ)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
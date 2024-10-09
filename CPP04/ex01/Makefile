# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 16:51:09 by lomakinaval       #+#    #+#              #
#    Updated: 2024/10/08 17:33:36 by lomakinaval      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = animal

SRC = 	main.cpp \
		Cat.cpp \
		Dog.cpp \
		Animal.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \

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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 13:25:55 by vlomakin          #+#    #+#              #
#    Updated: 2024/08/08 13:32:09 by lomakinaval      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC = 	PhoneBook.cpp \
		Contact.cpp \
		main.cpp \

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


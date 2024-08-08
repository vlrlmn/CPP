# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 13:25:55 by vlomakin          #+#    #+#              #
#    Updated: 2024/08/07 13:30:44 by vlomakin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC = 	PhoneBook.cpp \
		Contact.cpp \

CC = c++;

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ) -o $(NAME)

all: $(NAME)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


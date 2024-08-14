# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 12:44:34 by lomakinaval       #+#    #+#              #
#    Updated: 2024/08/14 12:47:39 by lomakinaval      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = thisIsBrain

SRC = main.cpp \

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@rm -f $(OBJ)

all: $(NAME)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 16:34:27 by lomakinaval       #+#    #+#              #
#    Updated: 2024/08/19 18:40:47 by lomakinaval      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlfilter

SRC =	main.cpp \
		Harl.cpp \

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
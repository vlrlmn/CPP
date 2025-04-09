# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 21:08:29 by lomakinaval       #+#    #+#              #
#    Updated: 2025/04/08 21:08:33 by lomakinaval      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CXX= c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = 	main.cpp \
		BitcoinExchange.cpp \

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
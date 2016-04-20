# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/17 16:35:36 by knzeng-e          #+#    #+#              #
#    Updated: 2016/04/17 19:12:21 by knzeng-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./*.c

#SRC_NAME = $(shell ls $(SRC_PATH) | grep .c)

OBJ_NAME = ./*.o

#SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

CC = gcc

FLAGS = -c -Wall -Werror -Wextra

$(NAME) : all

all :
	@$(CC) $(FLAGS) $(SRC)
	@$(CC) $(OBJ_NAME) -o $(NAME)

clean :
	@make all
	@rm $(OBJ_NAME)

fclean : clean
	@rm $(NAME)

norme :clean
	norminette *.*

re : fclean all

.PHONY : all clean fclean norme re

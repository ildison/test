# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormund <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 18:27:59 by cnikia            #+#    #+#              #
#    Updated: 2019/05/21 15:03:49 by cormund          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS =  -Wall -Werror -Wextra 
SRC = fillit.c sort.c valid.c read_and_take.c
OPTIONS = -I./ -c
CHAHE = $(SRC:.c=.o)
LIB = ./libft/libft.a
all: $(NAME)

$(NAME): lib
	gcc $(FLAGS) -g $(OPTIONS) $(SRC)
	gcc -o $(NAME) $(CHAHE) $(LIB)
	
lib:
	make -C libft
clean:
	/bin/rm -f $(CHAHE)
	make -C libft clean
fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean
re: fclean all

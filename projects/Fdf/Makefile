# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormund <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 18:27:59 by cnikia            #+#    #+#              #
#    Updated: 2019/06/03 14:02:51 by cormund          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS =# -Wall -Werror -Wextra 
SRC = fdf.c init.c read_map.c
OPTIONS = -I./ -c
CHAHE = $(SRC:.c=.o)
LIB = ./libft/libft.a

all:
	gcc $(SRC) $(LIB) -lmlx -framework OpenGL -framework AppKit -g
	./a.out test_maps/42.fdf
#lib:
#	make -C libft
clean:
	/bin/rm -f $(CHAHE)
#	make -C libft clean
fclean: clean
	/bin/rm -f $(NAME)
#	make -C libft fclean
re: fclean all

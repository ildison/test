# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormund <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 10:23:51 by cormund           #+#    #+#              #
#    Updated: 2019/04/05 09:37:40 by cormund          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRC = ft_display_file.c
INCL = mylib.h
BIN = ft_display_file.o
FLAG = -c -Wall -Wextra -Werror

all:
	gcc $(FLAG) -I $(INCL) $(SRC)
	gcc -o $(NAME) $(BIN)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

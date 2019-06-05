# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormund <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 18:56:45 by cormund           #+#    #+#              #
#    Updated: 2019/04/03 19:36:55 by cormund          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ./srcs/
INCL = ./includes/
FUN = $(SRCS)ft_putchar.c $(SRCS)ft_putstr.c $(SRCS)ft_strcmp.c $(SRCS)ft_strlen.c $(SRCS)ft_swap.c
BIN = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all:
	gcc -c $(FUN) -I $(SRCS)
	ar rc $(NAME) $(BIN)

clean:
	/bin/rm -f $(BIN)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

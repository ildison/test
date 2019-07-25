# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 14:32:05 by ksharlen          #+#    #+#              #
#    Updated: 2019/07/18 20:57:08 by ksharlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= libft.a
FLAGS 	:= -Wextra -Werror -Wall
CC 		:= gcc
REMOVE 	:= /bin/rm -rf
DIR_INCLUDE := ../include
LIBFT	:= libft.h
DIR_BIN := bin/
SRC 	:= ft_arrfind.c\
			ft_atoi.c\
			ft_bzero.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_ischar.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_isspace.c\
			ft_isstr.c\
			ft_itoa.c\
			ft_lstadd.c\
			ft_lstadd_end.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lstelem.c\
			ft_lstfreeone.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_lstreplace.c\
			ft_lstsize.c\
			ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memischar.c\
			ft_memisstr.c\
			ft_memmove.c\
			ft_memnjoin.c\
			ft_memnlen.c\
			ft_memset.c\
			ft_memsub.c\
			ft_pow.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_revers.c\
			ft_size_num.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnjoin.c\
			ft_strnlen.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_swap.c\
			ft_tolower.c\
			ft_toupper.c\
			get_next_line.c\
			ft_set_bit.c\
			ft_set_bits.c\
			ft_bitscpy.c\
			ft_wcslen.c\
			ft_ustrdel.c

OBJ := $(SRC:.c=.o)

vpath %.h $(DIR_INCLUDE)
vpath %.o $(DIR_BIN)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(addprefix $(DIR_BIN), $^)
	ranlib $@

$(OBJ):%.o: %.c $(LIBFT) | $(DIR_BIN)
	$(CC) $(FLAGS) -c $< -o $(DIR_BIN)$@ $(addprefix -I, $(DIR_INCLUDE)) -pipe

$(DIR_BIN):
	mkdir -p $@

clean:
	$(REMOVE) $(OBJ)
	$(REMOVE) $(DIR_BIN)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

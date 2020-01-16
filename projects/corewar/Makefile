# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormund <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/23 17:26:57 by cormund           #+#    #+#              #
#    Updated: 2020/01/16 11:21:08 by cormund          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := asm
LIBFT := libft.a
HEADERS := libft.h asm.h op.h
CC := clang
CFLAGS := -Wall -Wextra -Werror -O3
REMOVE := /bin/rm -rf
DIR_BIN := bin
DIR_INCLUDE := -I include
DIR_LIBFT := src/libft
DIR_SRC := src/$(NAME)

vpath %.c $(DIR_SRC)
vpath %.o $(DIR_BIN)/$(NAME)
vpath %.h $(DIR_INCLUDE)
vpath %.a $(DIR_LIBFT)

SRC_NAME := asm.c\
			read_input.c\
			parser.c\
			error_manager.c\
			op.c\
			parsing_header.c\
			parsing_args.c\
			parsing_oper.c\
			parsing_labels.c\
			replace_args2numbers.c\
			translator.c\
			options.c\
			cleanup.c\
			dissasembler.c

OBJ_NAME := $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_NAME)
	@$(CC) $(CFLAGS) $(addprefix $(DIR_BIN)/, $(addprefix $(NAME)/, $(OBJ_NAME))) -lft -L $(DIR_LIBFT) -o $@
	@printf "\r\e[J\e[32m$@\e[0m done!\n\e[?25h"

$(OBJ_NAME): %.o: %.c $(HEADERS)
	@mkdir -p $(DIR_BIN)/$(NAME)
	@$(CC) $(CFLAGS) -c $< $(DIR_INCLUDE) -o $(DIR_BIN)/$(NAME)/$@
	@printf "\r\e[?25l\e[Jcompiling \e[32m$(notdir $<)\e[0m"

$(LIBFT):
	@$(MAKE) -C $(DIR_LIBFT)
	@$(MAKE) -C $(DIR_LIBFT) clean

clean:
	@rm -rf $(DIR_BIN)
	@$(MAKE) -C $(DIR_LIBFT) fclean

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

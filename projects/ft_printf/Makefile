# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 17:04:37 by ksharlen          #+#    #+#              #
#    Updated: 2019/07/24 17:04:38 by ksharlen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
LIBFT := libft.a
HEADERS := ft_printf.h
CC := gcc
CFLAGS := -Wall -Wextra -Werror
REMOVE := /bin/rm -rf
DIR_BIN := bin/
DIR_INCLUDE := -I ./include
DIR_LIBFT := libft/
DIR_BUF := buf/
DIR_BONUS := bonus/
DIR_NUM := src_num_to_str/
DIR_SRC := src/
DIRS := $(addprefix $(DIR_SRC), $(DIR_BUF) $(DIR_NUM) $(DIR_BONUS)) $(DIR_SRC)

vpath %.c $(DIRS)
vpath %.o $(DIR_BIN)
vpath %.h $(DIR_INCLUDE)

SRC_MAIN 	:= 	ft_printf.c\
					other.c\
					work_spec_form.c\
					work_to_format.c

SRC_BUF 	:= 	buf.c\
					work_buf_by_hand.c

SRC_BONUS 	:= color.c\
					date.c\
					for_date.c\
					invisible_sym.c\
					size_formats.c\
					write_to_file.c\
					utf_8.c\
					work_wchar.c

SRC_NUM 	:= 	base_to_str.c\
					long_arithmetic.c\
					char_to_str.c\
					double_to_str.c\
					double_to_str2.c\
					double_to_str3.c\
					int_to_str.c\
					not_spec.c\
					other_spec.c\
					select_num_sys.c\
					str_to_str.c

OBJ1 := $(SRC_MAIN:.c=.o)
OBJ2 := $(SRC_BUF:.c=.o)
OBJ3 := $(SRC_BONUS:.c=.o)
OBJ4 := $(SRC_NUM:.c=.o)

OBJS := $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(DIR_LIBFT)
	cp $(DIR_LIBFT)$(LIBFT) .
	mv $(LIBFT) $(NAME)
	ar rc $(NAME) $(addprefix $(DIR_BIN), $(OBJS))

$(OBJS):%.o:%.c $(HEADERS) | $(DIR_BIN)
	$(CC) -c $(CFLAGS) $< -o $(DIR_BIN)$@ $(DIR_INCLUDE)

$(DIR_BIN):
	mkdir -p $@

clean: clean_libft
	$(REMOVE) $(addprefix $(DIR_BIN), $(OBJS))
	$(REMOVE) $(DIR_BIN)

fclean: clean fclean_libft
	$(REMOVE) $(NAME)

re: fclean all

clean_libft:
	make clean -C $(DIR_LIBFT)

fclean_libft: clean_libft
	make fclean -C $(DIR_LIBFT)

.PHONY: clean fclean re clean_libft fclean_libft
.SILENT: all $(OBJS) $(DIR_BIN) clean fclean re echo clean_libft fclean_libft

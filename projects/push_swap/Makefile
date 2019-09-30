# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormund <cormund@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/27 14:26:39 by cormund           #+#    #+#              #
#    Updated: 2019/09/30 19:36:13 by cormund          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER := checker
# VISUAL := visual
LIBFT := libft.a
HEADERS := libft.h ps_checker.h ps_shared.h
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g
REMOVE := /bin/rm -rf
DIR_BIN := bin
DIR_INCLUDE := -I include
DIR_LIBS := src/libs
DIR_LIBFT := $(DIR_LIBS)/libft
DIR_SRC := src/checker src/shared

# DIR_SDLLIBS := $(DIR_LIBS)/libSDL2
# DIR_INCLUDE_SDL := -I $(DIR_SDLLIBS)/SDL2.framework/Headers -I $(DIR_SDLLIBS)/SDL2_ttf.framework/Headers
# SDL_LIBS := -Wl,-rpath,$(DIR_SDLLIBS) -F $(DIR_SDLLIBS) -framework SDL2 -framework SDL2_ttf

vpath %.c $(DIR_SRC)
vpath %.o $(DIR_BIN) $(DIR_BIN)/$(CHECKER)
vpath %.h $(DIR_INCLUDE)
vpath %.a $(DIR_LIBFT)

SRC_SHARED := read_input.c

SRC_CHECKER := checker.c

# SRC_VIS := 

OBJ_SHARED := $(SRC_SHARED:.c=.o)
OBJ_CHECKER := $(SRC_CHECKER:.c=.o)
# OBJ_VIS := $(SRC_VIS:.c=.o)

all: $(CHECKER)

$(CHECKER): $(LIBFT) $(OBJ_CHECKER) $(OBJ_SHARED)
	@$(CC) $(CFLAGS) $(addprefix $(DIR_BIN)/, $(addprefix $(CHECKER)/, $(OBJ_CHECKER)) $(OBJ_SHARED)) -lft -L $(DIR_LIBFT) -o $@
	@printf "\r\e[J\e[32m$@\e[0m done!\n\e[?25h"

# $(VISUAL): $(LIBFT) $(OBJ_VIS)
# 	@$(CC) $(CFLAGS) $(addprefix $(DIR_BIN)/$(VISUAL)/, $(OBJ_VIS)) -lft -L $(DIR_LIBFT) $(SDL_LIBS) -o $@
# 	@printf "\r\e[J\e[32m$@\e[0m done!\n\e[?25h"

$(OBJ_CHECKER): %.o: %.c $(HEADERS)
	@mkdir -p $(DIR_BIN)/$(CHECKER)
	@$(CC) $(CFLAGS) -c $< $(DIR_INCLUDE) -o $(DIR_BIN)/$(CHECKER)/$@
	@printf "\r\e[?25l\e[Jcompiling \e[32m$(notdir $<)\e[0m"

# $(OBJ_VIS): %.o: %.c $(HEADERS)
# 	@mkdir -p $(DIR_BIN)/$(VISUAL)
# 	@$(CC) $(CFLAGS) -c $< $(DIR_INCLUDE) $(DIR_INCLUDE_SDL) -o $(DIR_BIN)/$(VISUAL)/$@
# 	@printf "\r\e[?25l\e[Jcompiling \e[32m$(notdir $<)\e[0m"

$(OBJ_SHARED): %.o: %.c $(HEADERS)
	@mkdir -p $(DIR_BIN)
	@$(CC) $(CFLAGS) -c $< $(DIR_INCLUDE) -o $(DIR_BIN)/$@
	@printf "\r\e[?25l\e[Jcompiling \e[32m$(notdir $<)\e[0m"

$(LIBFT):
	@$(MAKE) -C $(DIR_LIBFT)
	@$(MAKE) -C $(DIR_LIBFT) clean

clean:
	@rm -rf $(DIR_BIN)
	@$(MAKE) -C $(DIR_LIBFT) fclean

fclean: clean
	@$(REMOVE) $(CHECKER)
	@$(REMOVE) $(VISUAL)

re: fclean all

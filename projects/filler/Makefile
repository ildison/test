# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormund <cormund@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/16 11:31:00 by cormund           #+#    #+#              #
#    Updated: 2019/09/24 12:18:12 by cormund          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cormund.filler
VISUAL := visual
LIBFT := libft.a
HEADERS := filler.h fl_visualizer.h libft.h SDL.h SDL_ttf.h
CC := gcc
CFLAGS := -Wall -Wextra -Werror
REMOVE := /bin/rm -rf
DIR_BIN := bin
DIR_INCLUDE := -I src/include
DIR_LIBS := src/libs
DIR_LIBFT := $(DIR_LIBS)/libft
DIR_SRC := src/filler src/visualizer

DIR_SDLLIBS := $(DIR_LIBS)/libSDL2
DIR_INCLUDE_SDL := -I $(DIR_SDLLIBS)/SDL2.framework/Headers -I $(DIR_SDLLIBS)/SDL2_ttf.framework/Headers
SDL_LIBS := -Wl,-rpath,$(DIR_SDLLIBS) -F $(DIR_SDLLIBS) -framework SDL2 -framework SDL2_ttf

vpath %.c $(DIR_SRC)
vpath %.o $(DIR_BIN) $(DIR_BIN)/$(NAME) $(DIR_BIN)/$(VISUAL)
vpath %.h $(DIR_INCLUDE) $(DIR_INCLUDE_SDL)
vpath %.a $(DIR_LIBFT)

SRC :=	filler.c\
			sort.c\
			heat_map.c\
			read_board.c

SRC_VIS := main_vis.c\
			parsing_board.c\
			init.c\
			loop.c\
			background.c\
			render_bgrnd.c\
			info.c\
			render_info.c\
			parsing_step.c\
			logo.c

OBJ := $(SRC:.c=.o)
OBJ_VIS := $(SRC_VIS:.c=.o)

all: $(NAME) $(VISUAL)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(addprefix $(DIR_BIN)/$(NAME)/, $(OBJ)) -lft -L $(DIR_LIBFT) -o $@
	@printf "\r\e[J\e[32m$@\e[0m done!\n\e[?25h"

$(VISUAL): $(LIBFT) $(OBJ_VIS)
	@$(CC) $(CFLAGS) $(addprefix $(DIR_BIN)/$(VISUAL)/, $(OBJ_VIS)) -lft -L $(DIR_LIBFT) $(SDL_LIBS) -o $@
	@printf "\r\e[J\e[32m$@\e[0m done!\n\e[?25h"

$(OBJ): %.o: %.c $(HEADERS)
	@mkdir -p $(DIR_BIN)/$(NAME)
	@$(CC) $(CFLAGS) -c $< $(DIR_INCLUDE) -o $(DIR_BIN)/$(NAME)/$@
	@printf "\r\e[?25l\e[Jcompiling \e[32m$(notdir $<)\e[0m"

$(OBJ_VIS): %.o: %.c $(HEADERS)
	@mkdir -p $(DIR_BIN)/$(VISUAL)
	@$(CC) $(CFLAGS) -c $< $(DIR_INCLUDE) $(DIR_INCLUDE_SDL) -o $(DIR_BIN)/$(VISUAL)/$@
	@printf "\r\e[?25l\e[Jcompiling \e[32m$(notdir $<)\e[0m"

$(LIBFT):
	@$(MAKE) -C $(DIR_LIBFT)
	@$(MAKE) -C $(DIR_LIBFT) clean

clean:
	@rm -rf $(DIR_BIN)
	@$(MAKE) -C $(DIR_LIBFT) fclean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(VISUAL)

re: fclean all

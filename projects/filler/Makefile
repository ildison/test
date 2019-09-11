# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormund <cormund@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/16 11:31:00 by cormund           #+#    #+#              #
#    Updated: 2019/09/11 19:36:05 by cormund          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cormund.filler
LIBFT := libft.a
HEADERS := filler.h
CC := gcc
CFLAGS := -Wall -Wextra -Werror
REMOVE := /bin/rm -rf
DIR_BIN := bin/
DIR_INCLUDE := -I include/
DIR_LIBFT := libft/
DIR_SRC := src/

DIR_VIS_SRC := src/visualizer/

NAMESDL := rending
LIBSDL := libSDL2-2.0.0.dylib
LIBSDL_TTF :=libSDL2_ttf-2.0.0.dylib
DIR_INCLUDE_SDL := -I libSDL2/include/SDL2/
DIR_LIBSDL := libSDL2/libsdl2/
DIR_LIBSDL_TTF := libSDL2/libsdl2_ttf/

DIR_SDLLIBS := libSDL2/

ADERS_SDL_DIR := $(DIR_SDLLIBS)/SDL2.framework/Headers $(DIR_SDLLIBS)/SDL2_ttf.framework/Headers
SDL_LIBS := -Wl,-rpath,$(DIR_SDLLIBS) -F $(DIR_SDLLIBS) -framework SDL2 -framework SDL2_ttf

vpath %.c $(DIR_SRC)
vpath %.o $(DIR_BIN)
vpath %.h $(DIR_INCLUDE)

SRC :=	filler.c\
			sort.c\
			heat_map.c\
			read_board.c

VIS_SRC := main_vis.c\
			parsing_board.c

OBJ := $(SRC:.c=.o)

all:
	$(CC) -o $(NAME) $(CFLAGS) $(addprefix $(DIR_SRC), $(SRC)) $(DIR_INCLUDE) $(DIR_LIBFT)$(LIBFT)

sdl:
	$(CC) -o testsdl testsdl.c $(DIR_INCLUDE_SDL) $(SDL_LIBS) $(DIR_INCLUDE) $(DIR_LIBFT)$(LIBFT)

visual:
	$(CC) -o vis $(addprefix $(DIR_VIS_SRC), $(VIS_SRC)) $(DIR_INCLUDE_SDL) $(SDL_LIBS) $(DIR_INCLUDE) $(DIR_LIBFT)$(LIBFT)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all
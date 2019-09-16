/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_visualizer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:42:22 by cormund           #+#    #+#             */
/*   Updated: 2019/09/16 18:05:37 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FL_VISUALIZER_H
# define FL_VISUALIZER_H

# include "libft.h"
# include "SDL.h"
# include "SDL_ttf.h"

# define STD_OUT 0
# define P1 'O'
# define P2 'X'
# define LOWER_P1 'o'
# define LOWER_P2 'x'

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1024

# define BGRND_BOARD_X SCREEN_WIDTH / 6
# define BGRND_BOARD_Y SCREEN_HEIGHT / 15

# define COLOR_BGRND_R 19
# define COLOR_BGRND_G 26
# define COLOR_BGRND_B 42

# define COLOR_O 0x8afa6c
# define COLOR_X 0xfe6e7e
# define COLOR_P 0xd8d8d8
# define COLOR_BGRND 0x1b2437

#define H printf("HERE\n")

typedef struct		s_pnt
{
	short			y;
	short			x;
}					t_pnt;

typedef struct		s_step
{
	SDL_Color		*colors;
	int				n_colors;
	int				p1_tokens;
	int				p2_tokens;
	SDL_bool		fin;
	struct s_step	*prev;
	struct s_step	*next;
}					t_step;

typedef struct		s_vis
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	TTF_Font		*font_logo;
	TTF_Font		*font_text;
	SDL_Color		color_logo;
	SDL_Color		color_text;
	SDL_Event		e;
	SDL_Rect		bgrnd_board;
	SDL_Rect		*lattice;
	SDL_bool		quit;
	SDL_bool		pause;
	int				cof;
	int				delay;
	const Uint8 	*keyState;
	int				n_ltc;
}					t_vis;

typedef struct		s_game
{
	char			*p1;
	char			*p2;
	int				p1_tokens;
	int				p2_tokens;
	int				token_flag;
	t_pnt			size_rect;
	t_pnt			size_board;
	t_step			**start_step;
	t_vis			*vis;
}					t_game;

void				error(const char *err_msg);
void        		loop(t_game *game, t_vis *vis, t_step *step);
t_step				*next_step(t_game *game, t_step *step);
void        		background(t_game *game, t_vis *vis);
void				init(t_game *game);
void				destroy_init(t_vis *vis);

# endif
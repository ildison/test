/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_visualizer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:42:22 by cormund           #+#    #+#             */
/*   Updated: 2019/09/20 19:51:53 by cormund          ###   ########.fr       */
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

# define LOGO "FILLER"
# define INFO "INFORMATION"
# define KEYS "CONTROL KEYS"
# define PROGRESS "PROGRESSION"
# define SCORE "SCORE"

# define PLAY_PAUSE "Play/pause  :  space"
# define PREV_NEXT "Prev/next  :  left/right"
# define EDIT_CLR "Edir color  :  up/down"
# define SPEED "Speed  :  plus/minus"

# define SCREEN_WIDTH 1420
# define SCREEN_HEIGHT 800

# define BG_BOARD_X SCREEN_WIDTH / 5
# define BG_BOARD_Y SCREEN_HEIGHT / 12

# define CLR_BG_R 19
# define CLR_BG_G 26
# define CLR_BG_B 42

# define CLR_O 0x039482
# define CLR_X 0x820199
# define CLR_P 0xbebebe
# define CLR_BG 0x1b2437

# define CLR_LOGO 0x2ea491
# define CLR_INFO_WIN 0x1c243b
# define CLR_UP_WIN 0x242b47

typedef struct		s_pnt
{
	int				y;
	int				x;
}					t_pnt;

typedef struct		s_step
{
	int				*clrs;
	int				n_clrs;
	int				p1_tokens;
	int				p2_tokens;
	int				n_stp;
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
	SDL_Texture		*logo;
	SDL_Texture		*head[4];
	SDL_Texture		*info[3];
	SDL_Texture		*cntrl_key[4];
	t_pnt			progress[2];
	t_pnt			score[2];
	SDL_Rect		size_logo;
	SDL_Rect		size_text;
	SDL_Rect		info_win[4];
	SDL_Rect		up_win[5];
	SDL_Rect		fin_win;
	SDL_Color		color_text;
	SDL_Event		e;
	SDL_Rect		bgrnd_board;
	SDL_bool		quit;
	SDL_bool		pause;
	int				clr_cof;
	int				delay;
	const Uint8 	*keyState;
	int				n_ltc;
}					t_vis;

typedef struct		s_game
{
	char			*p1;
	char			*p2;
	char			*p_win;
	char			*p1_score;
	char			*p2_score;
	int				p1_tokens;
	int				p2_tokens;
	int				n_stp;
	int				token_flag;
	t_pnt			size_rect;
	t_pnt			size_board;
	t_step			**start_step;
	t_vis			*vis;
}					t_game;

void				print_vm_error();
void				error(const char *err_msg);
void        		loop(t_game *game, t_vis *vis, t_step *step);
t_step				*next_step(t_game *game, t_step *step);
void        		background(t_game *game, t_vis *vis);
void				init(t_game *game);
void				destroy_init(t_vis *vis);
void				render_bgrnd(t_game *game, t_vis *vis, t_step *step);
void				info_win(t_vis *vis, t_game *game);
void				head(t_vis *vis);
void				ren_info(t_vis *vis, t_game *game);
void				control_keys(t_vis *vis);
void				ren_cntrl_key(t_vis *vis);
void				progression(t_vis *vis);
void				ren_progression(t_vis *vis, t_game *game, t_step *stp);
SDL_Texture			*create_texture(TTF_Font *font, char *text,\
										SDL_Renderer *ren, SDL_Color color);
void				score(t_vis *vis, t_game *game);
void				ren_score(t_vis *vis, t_game *game, t_step *stp);
SDL_Color			get_color(int clr, int clr_cof, int fin);
void				ren_fin(t_vis *vis, t_game *game);

# endif
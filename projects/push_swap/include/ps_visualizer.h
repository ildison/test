/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visualizer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:42:22 by cormund           #+#    #+#             */
/*   Updated: 2019/10/25 09:52:57 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_VISUALIZER_H
# define PS_VISUALIZER_H

# include "ps_checker.h"
# include "SDL.h"
# include "SDL_ttf.h"

# define SCREEN_WIDTH 2040
# define SCREEN_HEIGHT 1240

# define SDL_EVENT vis->e.type
# define SDL_KEYSTATE vis->keystate
# define SDL_ESCAPE SDL_SCANCODE_ESCAPE
# define SDL_SPACE SDL_SCANCODE_SPACE
# define SDL_RIGHT SDL_SCANCODE_RIGHT
# define SDL_LEFT SDL_SCANCODE_LEFT
# define SDL_UP SDL_SCANCODE_UP
# define SDL_DOWN SDL_SCANCODE_DOWN

# define FIRST_STEP "begin"

# define CLR_TEXT 0xf09e62
# define CLR_BG 0x313131
# define CLR_RECT 0x664cf6

typedef struct		s_pnt
{
	int				y;
	int				x;
}					t_pnt;

typedef struct		s_step
{
	short			*a;
	short			*b;
	SDL_Texture		*oper;
	SDL_Rect		oper_rect;
	SDL_bool		fin;
	struct s_step	*prev;
	struct s_step	*next;
}					t_step;

typedef struct		s_vis
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	TTF_Font		*font_text;
	SDL_Color		text_clr;
	SDL_Color		bgrnd_clr;
	SDL_Color		rect_clr;
	SDL_Event		e;
	SDL_bool		quit;
	SDL_bool		pause;
	SDL_Texture		*stack_a;
	SDL_Texture		*stack_b;
	SDL_Rect		stack_a_rect;
	SDL_Rect		stack_b_rect;
	t_step			*first_step;
	t_pnt			oper_sz;
	t_pnt			rect;
	int				delay;
	const Uint8		*keystate;
	int				between_rect;
}					t_vis;

t_step				*next_step(t_vis *vis, t_step *step, t_checker *chkr);
t_step				*new_step(t_checker *chkr, t_vis *vis, char *oper);
void				loop(t_vis *vis, t_checker *chkr);
void				background(t_vis *vis, t_checker *chkr);
void				render_rects(t_vis *vis, t_step *stp);
void				render_texts(t_vis *vis, t_step *stp);
SDL_Texture			*create_texture(TTF_Font *font, char *text,\
										SDL_Renderer *ren, SDL_Color color);

#endif

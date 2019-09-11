/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_visualizer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:42:22 by cormund           #+#    #+#             */
/*   Updated: 2019/09/11 18:00:25 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FL_VISUALIZER_H
# define FL_VISUALIZER_H

# include "libft.h"
# include "SDL.h"
# include "SDL_ttf.h"

# define STD_OUT 0
# define SDL_ERR 1
# define P1 'O'
# define P2 'X'
# define LOWER_P1 'o'
# define LOWER_P2 'x'

#define H printf("HERE\n")

typedef struct		s_pnt
{
	short			y;
	short			x;
}					t_pnt;

typedef struct		s_step
{
	SDL_Rect		*p1;
	int				n_p1;
	SDL_Rect		*p2;
	int				n_p2;
	SDL_Rect		*piece;
	int				n_pc;
	int				p1_tokens;
	int				p2_tokens;
	int				fin;
	struct s_step	*prev;
	struct s_step	*next;
}					t_step;

typedef struct		s_game
{
	char			*p1;
	char			*p2;
	int				p1_tokens;
	int				p2_tokens;
	int				token_flag;
	t_pnt			size_board;
	t_step			**start_step;
}					t_game;

void				error();
t_step				*read_board(t_game *game);

# endif
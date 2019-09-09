/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_visualizer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:42:22 by cormund           #+#    #+#             */
/*   Updated: 2019/09/09 18:37:41 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FL_VISUALIZER_H
# define FL_VISUALIZER_H

# include "libft.h"
# include "SDL.h"
# include "SDL_ttf.h"

# define STD_OUT 1
# define SDL_ERR 1
# define P1 'O'
# define P2 'X'


typedef struct		s_pnt
{
	short				y;
	short				x;
}					t_pnt;

typedef struct	s_game
{
	char		*p1;
	char		*p2;
	int			p1_tokens;
	int			p2_tokens;
	char		**board;
	t_pnt		size_board;
}				t_game;

void			read_board(t_game *game);

# endif
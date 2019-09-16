/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:37:05 by cormund           #+#    #+#             */
/*   Updated: 2019/09/16 12:22:46 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

static void		bgrnd_lattice(t_vis *vis, t_game *game)
{
	int			x;
	int			y;

	if (!(vis->lattice = (SDL_Rect *)malloc(sizeof(SDL_Rect) * game->size_rect.x * game->size_rect.y)))
		error(strerror(errno));
	y = 0;
	while (y < game->size_board.y)
	{
		x = 0;
		while (x < game->size_board.x)
		{
			vis->lattice[vis->n_ltc].x = x * game->size_rect.x + BGRND_BOARD_X;
			vis->lattice[vis->n_ltc].y = y * game->size_rect.y + BGRND_BOARD_Y;
			vis->lattice[vis->n_ltc].w = game->size_rect.x;
			vis->lattice[vis->n_ltc].h = game->size_rect.y;
			++vis->n_ltc;
			++x;
		}
		++y;
	}
}

static void		bgrnt_board(t_vis *vis, t_game *game)
{
	vis->bgrnd_board.x = BGRND_BOARD_X;
	vis->bgrnd_board.y = BGRND_BOARD_Y;
	game->size_rect.x = BGRND_BOARD_X * 4 / game->size_board.x;
	game->size_rect.y = BGRND_BOARD_Y * 13 / game->size_board.y;
	vis->bgrnd_board.w = game->size_rect.x * game->size_board.x;
	vis->bgrnd_board.h = game->size_rect.y * game->size_board.y;
}

void			background(t_game *game, t_vis *vis)
{
	bgrnt_board(vis, game);
	// bgrnd_lattice(vis, game);
}
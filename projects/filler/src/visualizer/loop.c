/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:28:31 by cormund           #+#    #+#             */
/*   Updated: 2019/09/16 14:45:06 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

void		events(t_vis *vis)
{
	if (vis->e.type == SDL_QUIT || vis->keyState[SDL_SCANCODE_ESCAPE])
		vis->quit = SDL_TRUE;
	else if (vis->e.type == SDL_KEYDOWN && vis->keyState[SDL_SCANCODE_ESCAPE] && vis->pause == SDL_FALSE)
		vis->pause = SDL_TRUE;
	else if (vis->e.type == SDL_KEYDOWN && vis->keyState[SDL_SCANCODE_ESCAPE] && vis->pause == SDL_TRUE)
		vis->pause = SDL_FALSE;
}

void		render_rects(t_game *game, t_vis *vis, t_step *stp)
{
	SDL_Rect	rect;
	int			n;

	rect.h = game->size_rect.y - 1;
	rect.w = game->size_rect.x - 1;
	rect.y = BGRND_BOARD_Y;
	rect.x = BGRND_BOARD_X;
	n = 0;
	while (rect.y < (vis->bgrnd_board.h + BGRND_BOARD_Y))
	{
		rect.x = BGRND_BOARD_X;
		while (rect.x < (vis->bgrnd_board.w + BGRND_BOARD_X))
		{
			SDL_SetRenderDrawColor(vis->ren, stp->colors[n].r, stp->colors[n].g, stp->colors[n].b, SDL_ALPHA_OPAQUE);
			SDL_RenderFillRect(vis->ren, &rect);
			rect.x += game->size_rect.x;
			++n;
		}
		rect.y += game->size_rect.y;
	}
}

void		render_update(t_game *game, t_vis *vis, t_step *step)
{
	SDL_SetRenderDrawColor(vis->ren, COLOR_BGRND_R, COLOR_BGRND_G,\
									COLOR_BGRND_B, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(vis->ren);
	if (step)
		render_rects(game, vis, step);
	SDL_RenderPresent(vis->ren);
}

void		loop(t_game *game, t_vis *vis, t_step *step)
{
	char	b;

	while(!vis->quit)
	{
		SDL_Delay(2);
		if (step && !step->fin && !vis->pause)
			step = step->next;
		if (!vis->pause && !step && read(STD_OUT, &b, 1) > 0)
			step = read_board(game);
		while (SDL_PollEvent(&vis->e))
			events(vis);
		render_update(game, vis, step);
	}
}
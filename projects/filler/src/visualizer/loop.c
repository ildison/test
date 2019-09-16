/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:28:31 by cormund           #+#    #+#             */
/*   Updated: 2019/09/16 10:40:02 by cormund          ###   ########.fr       */
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

void		render_update(t_game *game, t_vis *vis, t_step *step)
{
	SDL_SetRenderDrawColor(vis->ren, COLOR_BGRND_R, COLOR_BGRND_G,\
									COLOR_BGRND_B, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(vis->ren);
	if (step)
	{
		SDL_SetRenderDrawColor(vis->ren, 27, 36, 55, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(vis->ren, &vis->bgrnd_board);
		SDL_SetRenderDrawColor(vis->ren, 254, 110, 125, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRects(vis->ren, step->p1, step->n_p1);
		SDL_SetRenderDrawColor(vis->ren, 199, 89, 156, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRects(vis->ren, step->p2, step->n_p2);
		SDL_SetRenderDrawColor(vis->ren, 216, 216, 216, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRects(vis->ren, step->piece, step->n_pc);
		SDL_SetRenderDrawColor(vis->ren, COLOR_BGRND_R, COLOR_BGRND_G,\
										COLOR_BGRND_B, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawRects(vis->ren, vis->lattice, vis->n_ltc);
	}
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
		if (!vis->pause && !step)
			step = read_board(game);
		while (SDL_PollEvent(&vis->e))
			events(vis);
		// H;
		render_update(game, vis, step);
	}
}
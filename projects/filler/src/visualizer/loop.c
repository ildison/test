/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:28:31 by cormund           #+#    #+#             */
/*   Updated: 2019/09/17 18:04:55 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

void		events(t_vis *vis, t_step **step)
{
	if (vis->e.type == SDL_QUIT || vis->keyState[SDL_SCANCODE_ESCAPE])
		vis->quit = SDL_TRUE;
	else if (vis->e.type == SDL_KEYDOWN && vis->keyState[SDL_SCANCODE_SPACE])
		vis->pause ^= SDL_TRUE;
	else if (vis->pause && vis->e.type == SDL_KEYDOWN &&\
		vis->keyState[SDL_SCANCODE_RIGHT] && *step && (*step)->next)
		*step = (*step)->next;
	else if (vis->pause && vis->e.type == SDL_KEYDOWN &&\
		vis->keyState[SDL_SCANCODE_LEFT] && *step && (*step)->prev)
		*step = (*step)->prev;
	else if (vis->e.type == SDL_KEYDOWN && vis->keyState[SDL_SCANCODE_UP] &&\
															vis->delay < 100)
		++vis->delay;
	else if (vis->e.type == SDL_KEYDOWN && vis->keyState[SDL_SCANCODE_DOWN] &&\
																vis->delay > 0)
		--vis->delay;
	else if (vis->e.type == SDL_KEYDOWN && vis->keyState[SDL_SCANCODE_KP_PLUS])
		++vis->cof;
	else if (vis->e.type == SDL_KEYDOWN && vis->keyState[SDL_SCANCODE_KP_MINUS]
															&& vis->cof > 1)
		--vis->cof;
}

void		render_rects(t_game *game, t_vis *vis, t_step *stp)
{
	SDL_Rect	rect;
	SDL_Color	color;
	int			n;

	rect.h = game->size_rect.y - 1;
	rect.w = game->size_rect.x - 1;
	rect.y = BG_BOARD_Y;
	rect.x = BG_BOARD_X;
	n = 0;
	while (rect.y < (vis->bgrnd_board.h + BG_BOARD_Y))
	{
		color.r = stp->clrs[n].r * (stp->clrs[n].r != (CLR_BG >> 16\
						& 0xff) && stp->clrs[n].r != 216 ? vis->cof : 1);
		color.g = stp->clrs[n].g * (stp->clrs[n].g != (CLR_BG >> 8\
						& 0xff) && stp->clrs[n].g != 216 ? vis->cof : 1);
		color.b = stp->clrs[n].b * (stp->clrs[n].b != (CLR_BG\
						& 0xff) && stp->clrs[n].b != 216 ? vis->cof : 1);
		SDL_SetRenderDrawColor(vis->ren, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(vis->ren, &rect);
		++n;
		rect.x += game->size_rect.x;
		if (rect.x >= (vis->bgrnd_board.w + BG_BOARD_X))
		{
			rect.y += game->size_rect.y;
			rect.x = BG_BOARD_X;
		}
	}
}

void		render_update(t_game *game, t_vis *vis, t_step *step)
{
	SDL_SetRenderDrawColor(vis->ren, CLR_BG_R, CLR_BG_G, CLR_BG_B,\
													SDL_ALPHA_OPAQUE);
	SDL_RenderClear(vis->ren);
	if (step)
	{
		render_bgrnd(game, vis, step);
		render_rects(game, vis, step);
	}
	SDL_RenderPresent(vis->ren);
}

void		loop(t_game *game, t_vis *vis, t_step *step)
{
	int		delay;

	delay = 0;
	while(!vis->quit)
	{
		SDL_Delay(2);
		if (!vis->pause && !delay)
			step = next_step(game, step);
		delay += delay ? -1 : vis->delay;
		while (SDL_PollEvent(&vis->e))
			events(vis, &step);
		render_update(game, vis, step);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:28:31 by cormund           #+#    #+#             */
/*   Updated: 2019/09/24 12:20:05 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

SDL_Color		get_color(int clr, int clr_cof, int fin)
{
	SDL_Color	color;

	if (clr != CLR_O && clr != CLR_X)
		clr_cof = 1;
	color.r = ((clr >> 16) & 0xff) * clr_cof;
	color.g = ((clr >> 8) & 0xff) * clr_cof;
	color.b = (clr & 0xff) * clr_cof;
	color.a = 0xff;
	if (fin && (clr == CLR_O || clr == CLR_X || clr == CLR_P))
	{
		color.r /= 5;
		color.g /= 5;
		color.b /= 5;
	}
	return (color);
}

static void		render_rects(t_game *game, t_vis *vis, t_step *stp)
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
		color = get_color(stp->clrs[n], vis->clr_cof, stp->fin);
		SDL_SetRenderDrawColor(vis->ren, color.r, color.g, color.b,\
													SDL_ALPHA_OPAQUE);
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

static void		events(t_vis *vis, t_step **step)
{
	if (SDL_EVENT == SDL_QUIT || SDL_KEYSTATE[SDL_ESCAPE])
		vis->quit = SDL_TRUE;
	else if (SDL_EVENT == SDL_KEYDOWN && SDL_KEYSTATE[SDL_SPACE])
		vis->pause ^= SDL_TRUE;
	else if (vis->pause && SDL_EVENT == SDL_KEYDOWN &&\
			SDL_KEYSTATE[SDL_RIGHT] && *step && (*step)->next)
		*step = (*step)->next;
	else if (vis->pause && SDL_EVENT == SDL_KEYDOWN &&\
			SDL_KEYSTATE[SDL_LEFT] && *step && (*step)->prev)
		*step = (*step)->prev;
	else if (SDL_EVENT == SDL_KEYDOWN && SDL_KEYSTATE[SDL_PLUS] &&\
													vis->delay < 100)
		++vis->delay;
	else if (SDL_EVENT == SDL_KEYDOWN && SDL_KEYSTATE[SDL_MINUS] &&\
													vis->delay > 0)
		--vis->delay;
	else if (SDL_EVENT == SDL_KEYDOWN && SDL_KEYSTATE[SDL_UP])
		++vis->clr_cof;
	else if (SDL_EVENT == SDL_KEYDOWN && SDL_KEYSTATE[SDL_DOWN] &&\
													vis->clr_cof > 1)
		--vis->clr_cof;
}

static void		render_update(t_game *game, t_vis *vis, t_step *step)
{
	SDL_SetRenderDrawColor(vis->ren, CLR_BG_R, CLR_BG_G, CLR_BG_B,\
													SDL_ALPHA_OPAQUE);
	SDL_RenderClear(vis->ren);
	if (step)
	{
		render_rects(game, vis, step);
		render_bgrnd(game, vis, step);
	}
	SDL_RenderPresent(vis->ren);
}

void			loop(t_game *game, t_vis *vis, t_step *step)
{
	int			delay;

	delay = 0;
	while (!vis->quit)
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

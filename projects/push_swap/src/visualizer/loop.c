/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:02:47 by cormund           #+#    #+#             */
/*   Updated: 2019/10/23 18:00:31 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visualizer.h"

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
}

static void		render_update(t_vis *vis, t_step *step)
{
	SDL_SetRenderDrawColor(vis->ren, vis->bgrnd_clr.r, vis->bgrnd_clr.g,\
										vis->bgrnd_clr.b, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(vis->ren);
	render_rects(vis, step);
	render_texts(vis);
	SDL_RenderPresent(vis->ren);
}

void			loop(t_vis *vis, t_checker *chkr)
{
	t_step		*step;
	int			delay;

	step = new_step(chkr, &vis->first_step);
	vis->delay = 10;
	delay = vis->delay;
	while (!vis->quit)
	{
		SDL_Delay(2);
		while (SDL_PollEvent(&vis->e))
			events(vis, &step);
		render_update(vis, step);
		if (!vis->pause && !delay)
			step = next_step(vis, step, chkr);
		delay += delay ? -1 : vis->delay;
	}
}

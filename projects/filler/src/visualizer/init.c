/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:57:16 by cormund           #+#    #+#             */
/*   Updated: 2019/09/19 11:26:35 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

void		destroy_init(t_vis *vis)
{
	int		i;

	TTF_CloseFont(vis->font_logo);
	TTF_CloseFont(vis->font_text);
	SDL_DestroyTexture(vis->logo);
	SDL_DestroyTexture(vis->progress[0]);
	SDL_DestroyTexture(vis->progress[1]);
	i = 3;
	while (i)
	{
		SDL_DestroyTexture(vis->head[i]);
		SDL_DestroyTexture(vis->cntrl_key[i]);
		--i;
		if (i)
			SDL_DestroyTexture(vis->info[i]);
	}
	SDL_DestroyRenderer(vis->ren);
	SDL_DestroyWindow(vis->win);
	SDL_Quit();
	TTF_Quit();
}

static void	open_font(t_vis *vis)
{
	vis->font_logo = TTF_OpenFont("/font/filler_logo.ttf", 40);
	if (!vis->font_logo)
		error(TTF_GetError());
	vis->font_text = TTF_OpenFont("/font/FuturaPT-Light.ttf", 18);
	if (!vis->font_logo)
		error(TTF_GetError());
}

void		init(t_game *game)
{
	t_vis	*vis;

	if (!(vis = (t_vis *)ft_memalloc(sizeof(t_vis))))
		error(strerror(errno));
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
		error(SDL_GetError());
	if (TTF_Init() < 0)
		error(TTF_GetError());
	vis->win = SDL_CreateWindow("Cormund's Filler", SDL_WINDOWPOS_CENTERED,\
	SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!vis->win)
		error(TTF_GetError());
	if (!(vis->ren = SDL_CreateRenderer(vis->win, -1, 0)))
		error(TTF_GetError());
	open_font(vis);
	vis->keyState = SDL_GetKeyboardState(NULL);
	vis->cof = 1;
	game->vis = vis;
}
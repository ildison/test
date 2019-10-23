/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   visualization.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cormund <cormund@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/22 11:44:22 by cormund		   #+#	#+#			 */
/*   Updated: 2019/10/22 12:11:10 by cormund		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ps_visualizer.h"

static void	destroy_init(t_vis *vis)
{
	TTF_CloseFont(vis->font_text);
	SDL_DestroyRenderer(vis->ren);
	SDL_DestroyWindow(vis->win);
	TTF_Quit();
	SDL_Quit();
}

static void	open_font(t_vis *vis)
{
		vis->font_text = TTF_OpenFont("/src/visualizer/font/FuturaPT-Light.ttf", 20);
		if (!vis->font_text)
				error(TTF_GetError());
}

static void	init(t_vis *vis)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
			error(SDL_GetError());
	if (TTF_Init() < 0)
			error(TTF_GetError());
	vis->win = SDL_CreateWindow("Cormund's Push swap", SDL_WINDOWPOS_CENTERED,\
	SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!vis->win)
			error(TTF_GetError());
	if (!(vis->ren = SDL_CreateRenderer(vis->win, -1, 0)))
			error(TTF_GetError());
	open_font(vis);
	vis->keystate = SDL_GetKeyboardState(NULL);
}

void		visualiser(t_checker *chkr)
{
	t_vis	*vis;

	if (!(vis = (t_vis *)ft_memalloc(sizeof(t_vis))))
		error(PS_ERROR_MALLOC);
	init(vis);
	background(vis, chkr);
	loop(vis, chkr);
	destroy_init(vis);
	// cleaning_up(vis);
}

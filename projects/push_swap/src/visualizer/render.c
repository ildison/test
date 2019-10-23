/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:33:37 by cormund           #+#    #+#             */
/*   Updated: 2019/10/23 14:05:35 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visualizer.h"

void		render_rects(t_vis *vis, t_step *stp)
{
	SDL_Rect	rect;
	int			i;

	SDL_SetRenderDrawColor(vis->ren, vis->rect_clr.r, vis->rect_clr.g,\
										vis->rect_clr.b, SDL_ALPHA_OPAQUE);
	rect.w = vis->rect.x;
	rect.x = rect.w + vis->between_rect;
	i = 0;
	if (stp->a)
		while (stp->a[i])
		{
			rect.h = vis->rect.y * stp->a[i];
			rect.x += rect.x;
			rect.y = SCREEN_HEIGHT / 2 - rect.h;
			SDL_RenderFillRect(vis->ren, &rect);
			++i;
		}
	rect.x = 0;
	i = 0;
	if (stp->b)
		while (stp->b[i])
			{
				rect.h = vis->rect.y * stp->b[i];
				rect.x += rect.x;
				rect.y = SCREEN_HEIGHT - rect.h;
				SDL_RenderFillRect(vis->ren, &rect);
				++i;
			}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bgrnd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:24:43 by cormund           #+#    #+#             */
/*   Updated: 2019/09/17 19:01:53 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fl_visualizer.h"

static void		ren_info(t_vis *vis)
{
	SDL_SetRenderDrawColor(vis->ren, CLR_INFO >> 16 & 0xff, CLR_INFO >> 8 & 0xff, CLR_INFO & 0xff, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRects(vis->ren, vis->info, 3);
	SDL_SetRenderDrawColor(vis->ren, CLR_UP_INFO >> 16 & 0xff, CLR_UP_INFO >> 8 & 0xff, CLR_UP_INFO & 0xff, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRects(vis->ren, vis->up_info, 4);
}

static void		ren_logo(t_vis *vis)
{
	// SDL_SetRenderDrawColor(vis->ren, 0x26, 0x2e, 0x4a, SDL_ALPHA_OPAQUE);
	// SDL_RenderFillRect(vis->ren, &vis->rect_logo);
	SDL_RenderCopy(vis->ren, vis->logo, NULL, &vis->size_logo);
}

void		render_bgrnd(t_game *game, t_vis *vis, t_step *step)
{
	ren_info(vis);
	ren_logo(vis);
}
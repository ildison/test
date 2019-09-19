/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bgrnd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:24:43 by cormund           #+#    #+#             */
/*   Updated: 2019/09/19 19:16:14 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fl_visualizer.h"

static void		ren_info_win(t_vis *vis)
{
	SDL_SetRenderDrawColor(vis->ren, CLR_INFO_WIN >> 16 & 0xff,\
			CLR_INFO_WIN >> 8 & 0xff, CLR_INFO_WIN & 0xff, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRects(vis->ren, vis->info_win, 4);
	SDL_SetRenderDrawColor(vis->ren, CLR_UP_WIN >> 16 & 0xff,\
				CLR_UP_WIN >> 8 & 0xff, CLR_UP_WIN & 0xff, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRects(vis->ren, vis->up_win, 5);
}

static void		ren_head(t_vis *vis)
{
	t_pnt		sz;
	t_pnt		indent;

	TTF_SizeText(vis->font_text, INFO, &sz.x, &sz.y);
	indent.x = (vis->up_win[1].w - sz.x) / 2;
	indent.y = (vis->up_win[2].h - sz.y) / 2;
	SDL_RenderCopy(vis->ren, vis->head[0], NULL, &(SDL_Rect){vis->up_win[1].x\
						+ indent.x, vis->up_win[1].y + indent.y, sz.x, sz.y});
	TTF_SizeText(vis->font_text, KEYS, &sz.x, &sz.y);
	indent.x = (vis->up_win[2].w - sz.x) / 2;
	SDL_RenderCopy(vis->ren, vis->head[1], NULL, &(SDL_Rect){vis->up_win[2].x\
						+ indent.x, vis->up_win[2].y + indent.y, sz.x, sz.y});
	TTF_SizeText(vis->font_text, PROGRESS, &sz.x, &sz.y);
	indent.x = (vis->up_win[3].w - sz.x) / 2;
	SDL_RenderCopy(vis->ren, vis->head[2], NULL, &(SDL_Rect){vis->up_win[3].x\
						+ indent.x, vis->up_win[3].y + indent.y, sz.x, sz.y});
	TTF_SizeText(vis->font_text, SCORE, &sz.x, &sz.y);
	indent.x = (vis->up_win[4].w - sz.x) / 2;
	SDL_RenderCopy(vis->ren, vis->head[3], NULL, &(SDL_Rect){vis->up_win[4].x\
						+ indent.x, vis->up_win[4].y + indent.y, sz.x, sz.y});
}

static void		ren_logo(t_vis *vis)
{
	SDL_RenderCopy(vis->ren, vis->logo, NULL, &vis->size_logo);
}

void		render_bgrnd(t_game *game, t_vis *vis, t_step *step)
{
	ren_info_win(vis);
	ren_head(vis);
	ren_logo(vis);
	ren_info(vis, game);
	ren_cntrl_key(vis);
	ren_progression(vis, game, step);
	ren_score(vis, game, step);
}
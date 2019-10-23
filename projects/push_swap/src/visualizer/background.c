/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:33:51 by cormund           #+#    #+#             */
/*   Updated: 2019/10/23 12:52:00 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_visualizer.h"

SDL_Texture		*create_texture(TTF_Font *font, char *text, SDL_Renderer *ren,\
															SDL_Color color)
{
	SDL_Texture	*tex;
	SDL_Surface	*surf;

	surf = TTF_RenderText_Blended(font, text, color);
	tex = SDL_CreateTextureFromSurface(ren, surf);
	SDL_FreeSurface(surf);
	return (tex);
}

SDL_Color		get_color(int clr)
{
	SDL_Color	color;

	color.r = clr >> 16;
	color.g = (clr >> 8) & 0xff;
	color.b = clr & 0xff;
	color.a = 0xff;
	return (color);
}

void			rect_size(t_vis *vis, t_checker *chkr)
{
	int			count_rects;

	count_rects = size_stack(chkr->a);
	vis->rect.x = (SCREEN_WIDTH) / count_rects > 20 ? 20 : (SCREEN_WIDTH) /
																 count_rects;
	vis->between_rect = vis->rect.x / 2;
	vis->rect.y = (SCREEN_HEIGHT / 2 - 20) / count_rects;
}

void			text(t_vis *vis)
{
	SDL_Color	color;

	TTF_SizeText(vis->font_text, "Stack a", &vis->sz_st_a.w, &vis->sz_st_a.h);
	vis->sz_st_a.x = 10;
	vis->sz_st_a.y = 10;
	color = get_color(CLR_TEXT);
	vis->stack_a = create_texture(vis->font_text, "Stack a", vis->ren, color);
	vis->sz_st_b.w = vis->sz_st_a.w;
	vis->sz_st_b.h = vis->sz_st_a.h;
	vis->sz_st_b.x = vis->sz_st_a.x;
	vis->sz_st_b.y = vis->sz_st_a.y + SCREEN_HEIGHT / 2;
	vis->stack_b = create_texture(vis->font_text, "Stack b", vis->ren, color);
}

void			background(t_vis *vis, t_checker *chkr)
{
	vis->bgrnd_clr = get_color(CLR_BG);
	vis->rect_clr = get_color(CLR_RECT);
	rect_size(vis, chkr);
	text(vis);
}

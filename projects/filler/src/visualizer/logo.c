/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:24:38 by cormund           #+#    #+#             */
/*   Updated: 2019/09/23 17:28:48 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

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

void			logo(t_vis *vis)
{
	SDL_Color	color;

	color = get_color(CLR_LOGO, 1, 0);
	TTF_SizeText(vis->font_logo, LOGO, &vis->size_logo.w, &vis->size_logo.h);
	vis->size_logo.x = 30;
	vis->size_logo.y = 20;
	vis->logo = create_texture(vis->font_logo, LOGO, vis->ren, color);
}

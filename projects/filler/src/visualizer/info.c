/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:53:01 by cormund           #+#    #+#             */
/*   Updated: 2019/09/19 11:36:09 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fl_visualizer.h"

SDL_Texture		*creat_texture(TTF_Font *font, char *text, SDL_Renderer *ren,\
															SDL_Color color)
{
	SDL_Texture	*tex;
	SDL_Surface	*surf;

	surf = TTF_RenderText_Blended(font, text, color);
	tex = SDL_CreateTextureFromSurface(ren, surf);
	SDL_FreeSurface(surf);
	return (tex);
}

void			head(t_vis *vis)
{
	SDL_Color	color;

	color.r = CLR_P >> 16 & 0xff;
	color.g = CLR_P >> 8 & 0xff;
	color.b = CLR_P & 0xff;
	vis->color_text = color;
	vis->head[0] = creat_texture(vis->font_text, INFO, vis->ren,color);
	vis->head[1] = creat_texture(vis->font_text, KEYS, vis->ren, color);
	vis->head[2] = creat_texture(vis->font_text, PROGRESS, vis->ren, color);
	vis->head[3] = creat_texture(vis->font_text, SCORE, vis->ren, color);
}

void			info_win(t_vis *vis, t_game *game)
{
	char		*tmp;

	if (game->size_board.x == 17)
		tmp = "Map size  :  15X17";
	else
		tmp = (game->size_board.x == 40 ? "Map size  :  24X40" :\
													"Map size  :  100X99");
	vis->info[0] = creat_texture(vis->font_text, tmp, vis->ren,\
														vis->color_text);
	tmp = ft_strjoin("Player 1  :  ", game->p1);
	vis->info[1] = creat_texture(vis->font_text, tmp, vis->ren,\
														vis->color_text);
	free(tmp);
	tmp = ft_strjoin("Player 2  :  ", game->p2);
	vis->info[2] = creat_texture(vis->font_text, tmp, vis->ren,\
														vis->color_text);
	free(tmp);
}

void			control_keys(t_vis *vis)
{
	vis->cntrl_key[0] = creat_texture(vis->font_text, PLAY_PAUSE, vis->ren,\
															vis->color_text);
	vis->cntrl_key[1] = creat_texture(vis->font_text, PREV_NEXT, vis->ren,\
															vis->color_text);
	vis->cntrl_key[2] = creat_texture(vis->font_text, EDIT_CLR, vis->ren,\
															vis->color_text);
	vis->cntrl_key[3] = creat_texture(vis->font_text, SPEED, vis->ren,\
															vis->color_text);
}

void			progression(t_vis *vis)
{
	vis->progress[0] = creat_texture(vis->font_text, "Current step  :  ",\
													vis->ren, vis->color_text);
	vis->progress[1] = creat_texture(vis->font_text, "Total step  :  ", vis->ren,\
															vis->color_text);
}

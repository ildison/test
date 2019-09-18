/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:53:01 by cormund           #+#    #+#             */
/*   Updated: 2019/09/18 16:31:21 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fl_visualizer.h"

void			info_win(t_vis *vis, t_game *game)
{
	SDL_Surface	*text;
	SDL_Color	color;
	char		*tmp;

	color = vis->color_text;
	if (game->size_board.x == 17)
		tmp = "Map size : 15X17";
	else
		tmp = (game->size_board.x == 40 ? "Map size : 24X40" :\
											"Map size : 100X99");
	text = TTF_RenderText_Blended(vis->font_text, tmp, color);
	vis->info[0] = SDL_CreateTextureFromSurface(vis->ren, text);
	tmp = ft_strjoin("Player 1 : ", game->p1);
	text = TTF_RenderText_Blended(vis->font_text, tmp, color);
	free(tmp);
	vis->info[1] = SDL_CreateTextureFromSurface(vis->ren, text);
	tmp = ft_strjoin("Player 2 : ", game->p2);
	text = TTF_RenderText_Blended(vis->font_text, tmp, color);
	free(tmp);
	vis->info[2] = SDL_CreateTextureFromSurface(vis->ren, text);
	SDL_FreeSurface(text);
}

void			control_keys(t_vis *vis)
{
	SDL_Surface	*text;
	SDL_Color	color;

	color = vis->color_text;
	text = TTF_RenderText_Blended(vis->font_text, PLAY_PAUSE, color);
	vis->cntrl_key[0] = SDL_CreateTextureFromSurface(vis->ren, text);
	text = TTF_RenderText_Blended(vis->font_text, PREV_NEXT, color);
	vis->cntrl_key[1] = SDL_CreateTextureFromSurface(vis->ren, text);
	text = TTF_RenderText_Blended(vis->font_text, EDIT_CLR, color);
	vis->cntrl_key[2] = SDL_CreateTextureFromSurface(vis->ren, text);
	text = TTF_RenderText_Blended(vis->font_text, SPEED, color);
	vis->cntrl_key[3] = SDL_CreateTextureFromSurface(vis->ren, text);
	SDL_FreeSurface(text);
}

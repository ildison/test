/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:53:01 by cormund           #+#    #+#             */
/*   Updated: 2019/09/19 19:58:16 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fl_visualizer.h"

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

void			head(t_vis *vis)
{
	vis->color_text = get_color(CLR_P, 1);
	vis->head[0] = create_texture(vis->font_text, INFO, vis->ren,\
													vis->color_text);
	vis->head[1] = create_texture(vis->font_text, KEYS, vis->ren,\
													vis->color_text);
	vis->head[2] = create_texture(vis->font_text, PROGRESS, vis->ren,\
													vis->color_text);
	vis->head[3] = create_texture(vis->font_text, SCORE, vis->ren,\
													vis->color_text);
}

void			info_win(t_vis *vis, t_game *game)
{
	char		*tmp;

	if (game->size_board.x == 17)
		tmp = "Map size  :  15X17";
	else
		tmp = (game->size_board.x == 40 ? "Map size  :  24X40" :\
													"Map size  :  100X99");
	vis->info[0] = create_texture(vis->font_text, tmp, vis->ren,\
														vis->color_text);
	tmp = ft_strjoin("Player 1  :  ", game->p1);
	vis->info[1] = create_texture(vis->font_text, tmp, vis->ren,\
														vis->color_text);
	free(tmp);
	tmp = ft_strjoin("Player 2  :  ", game->p2);
	vis->info[2] = create_texture(vis->font_text, tmp, vis->ren,\
														vis->color_text);
	free(tmp);
}

void			control_keys(t_vis *vis)
{
	vis->cntrl_key[0] = create_texture(vis->font_text, PLAY_PAUSE, vis->ren,\
															vis->color_text);
	vis->cntrl_key[1] = create_texture(vis->font_text, PREV_NEXT, vis->ren,\
															vis->color_text);
	vis->cntrl_key[2] = create_texture(vis->font_text, EDIT_CLR, vis->ren,\
															vis->color_text);
	vis->cntrl_key[3] = create_texture(vis->font_text, SPEED, vis->ren,\
															vis->color_text);
}

void			progression(t_vis *vis)
{
	t_pnt		indent;

	TTF_SizeText(vis->font_text, "Current step  :  ", &vis->progress[0].x,\
														&vis->progress[0].y);
	vis->progress[0].x = vis->up_win[3].x + vis->up_win[3].w / 2 -\
														vis->progress[0].x;
	vis->progress[0].y = vis->up_win[3].y + vis->progress[0].y * 2 - 5;
	TTF_SizeText(vis->font_text, "Total step  :  ", &vis->progress[1].x,\
														&vis->progress[1].y);
	vis->progress[1].x = vis->up_win[3].x + vis->up_win[3].w / 2 -\
														vis->progress[1].x;
	vis->progress[1].y = vis->up_win[3].y + vis->progress[1].y * 3 - 5;
}

void			score(t_vis *vis, t_game *game)
{
	t_pnt		indent;

	game->p1_score = ft_strjoin(game->p1, "  :  ");
	game->p2_score = ft_strjoin(game->p2, "  :  ");
	TTF_SizeText(vis->font_text, game->p1_score, &vis->score[0].x,\
														&vis->score[0].y);
	vis->score[0].x = vis->up_win[4].x + vis->up_win[4].w / 2 -\
														vis->score[0].x;
	vis->score[0].y = vis->up_win[4].y + vis->score[0].y * 2 - 5;
	TTF_SizeText(vis->font_text, game->p2_score, &vis->score[1].x,\
														&vis->score[1].y);
	vis->score[1].x = vis->up_win[4].x + vis->up_win[4].w / 2 -\
														vis->score[1].x;
	vis->score[1].y = vis->up_win[4].y + vis->score[1].y * 3 - 5;
}

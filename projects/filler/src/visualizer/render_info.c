/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:14:17 by cormund           #+#    #+#             */
/*   Updated: 2019/09/19 11:35:43 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fl_visualizer.h"

void			ren_info(t_vis *vis, t_game *game)
{
	t_pnt		sz;
	t_pnt		sz2;
	t_pnt		indent;

	TTF_SizeText(vis->font_text, "Map size  :  ", &sz.x, &sz.y);
	TTF_SizeText(vis->font_text, game->size_board.x < 42 ? "24X40" : "100X99", &sz2.x, &sz2.y);
	indent.x = vis->up_win[1].w / 2 - sz.x;
	SDL_RenderCopy(vis->ren, vis->info[0], NULL, &(SDL_Rect){vis->up_win[1].x\
				+ indent.x, vis->up_win[1].y + sz.y * 2 - 5, sz.x + sz2.x, sz.y});
	TTF_SizeText(vis->font_text, "Player 1  :  ", &sz.x, &sz.y);
	TTF_SizeText(vis->font_text, game->p1, &sz2.x, &sz2.y);
	indent.x = vis->up_win[1].w / 2 - sz.x;
	SDL_RenderCopy(vis->ren, vis->info[1], NULL, &(SDL_Rect){vis->up_win[1].x\
				+ indent.x, vis->up_win[1].y + sz.y * 3 - 5, sz.x + sz2.x, sz.y});
	TTF_SizeText(vis->font_text, game->p2, &sz2.x, &sz2.y);
	SDL_RenderCopy(vis->ren, vis->info[2], NULL, &(SDL_Rect){vis->up_win[1].x\
				+ indent.x, vis->up_win[1].y + sz.y * 4 - 5, sz.x + sz2.x, sz.y});
}

void			ren_cntrl_key(t_vis *vis)
{
	t_pnt		sz;
	t_pnt		sz2;
	t_pnt		indent;

	TTF_SizeText(vis->font_text, "Play/pause  :  ", &sz.x, &sz.y);
	TTF_SizeText(vis->font_text, PLAY_PAUSE, &sz2.x, &sz2.y);
	indent.x = vis->up_win[2].w / 2 - sz.x;
	SDL_RenderCopy(vis->ren, vis->cntrl_key[0], NULL, &(SDL_Rect){vis->up_win[2].x\
				+ indent.x, vis->up_win[2].y + sz.y * 2 - 5, sz2.x, sz2.y});
	TTF_SizeText(vis->font_text, "Prev/next  :  ", &sz.x, &sz.y);
	TTF_SizeText(vis->font_text, PREV_NEXT, &sz2.x, &sz2.y);
	indent.x = vis->up_win[2].w / 2 - sz.x;
	SDL_RenderCopy(vis->ren, vis->cntrl_key[1], NULL, &(SDL_Rect){vis->up_win[2].x\
				+ indent.x, vis->up_win[2].y + sz.y * 3 - 5, sz2.x, sz2.y});
	TTF_SizeText(vis->font_text, "Edir color  :  ", &sz.x, &sz.y);
	TTF_SizeText(vis->font_text, EDIT_CLR, &sz2.x, &sz2.y);
	indent.x = vis->up_win[2].w / 2 - sz.x;
	SDL_RenderCopy(vis->ren, vis->cntrl_key[2], NULL, &(SDL_Rect){vis->up_win[2].x\
				+ indent.x, vis->up_win[2].y + sz.y * 4 - 5, sz2.x, sz2.y});
	TTF_SizeText(vis->font_text, "Speed  :  ", &sz.x, &sz.y);
	TTF_SizeText(vis->font_text, SPEED, &sz2.x, &sz2.y);
	indent.x = vis->up_win[2].w / 2 - sz.x;
	SDL_RenderCopy(vis->ren, vis->cntrl_key[3], NULL, &(SDL_Rect){vis->up_win[2].x\
				+ indent.x, vis->up_win[2].y + sz.y * 5 - 5, sz2.x, sz2.y});
}

void			ren_progression(t_vis *vis, t_game *game, t_step *stp)
{
	SDL_Texture	*tex;
	t_pnt		sz;
	t_pnt		indent;
	char		*tmp;

	TTF_SizeText(vis->font_text, "Current step  :  ", &sz.x, &sz.y);
	indent.x = vis->up_win[3].w / 2 - sz.x;
	SDL_RenderCopy(vis->ren, vis->progress[0], NULL, &(SDL_Rect){vis->up_win[3].x\
				+ indent.x, vis->up_win[3].y + sz.y * 2 - 5, sz.x, sz.y});
	tmp = ft_itoa(stp->n_stp);
	tex = creat_texture(vis->font_text, tmp, vis->ren, vis->color_text);
	TTF_SizeText(vis->font_text, tmp, &sz.x, &sz.y);
	free(tmp);
	indent.x = vis->up_win[3].w / 2 + 2;
	SDL_RenderCopy(vis->ren, tex, NULL, &(SDL_Rect){vis->up_win[3].x\
				+ indent.x, vis->up_win[3].y + sz.y * 2 - 5, sz.x, sz.y});
	TTF_SizeText(vis->font_text, "Total step  :  ", &sz.x, &sz.y);
	indent.x = vis->up_win[2].w / 2 - sz.x;
	SDL_RenderCopy(vis->ren, vis->progress[1], NULL, &(SDL_Rect){vis->up_win[3].x\
				+ indent.x, vis->up_win[3].y + sz.y * 3 - 5, sz.x, sz.y});
	tmp = ft_itoa(game->n_stp);
	tex = creat_texture(vis->font_text, tmp, vis->ren, vis->color_text);
	TTF_SizeText(vis->font_text, tmp, &sz.x, &sz.y);
	free(tmp);
	indent.x = vis->up_win[3].w / 2 + 2;
	SDL_RenderCopy(vis->ren, tex, NULL, &(SDL_Rect){vis->up_win[3].x\
				+ indent.x, vis->up_win[3].y + sz.y * 3 - 5, sz.x, sz.y});
	SDL_DestroyTexture(tex);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:14:17 by cormund           #+#    #+#             */
/*   Updated: 2019/09/20 18:12:16 by cormund          ###   ########.fr       */
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
	char		*tmp;
	char		*text;

	tmp = ft_itoa(stp->n_stp);
	text = ft_strjoin("Current step  :  ", tmp);
	TTF_SizeText(vis->font_text, text, &sz.x, &sz.y);
	tex = create_texture(vis->font_text, text, vis->ren, vis->color_text);
	SDL_RenderCopy(vis->ren, tex, NULL, &(SDL_Rect){vis->progress[0].x,\
										vis->progress[0].y, sz.x, sz.y});
	free(tmp);
	free(text);
	tmp = ft_itoa(game->n_stp);
	text = ft_strjoin("Total step  :  ", tmp);
	TTF_SizeText(vis->font_text, text, &sz.x, &sz.y);
	tex = create_texture(vis->font_text, text, vis->ren, vis->color_text);
	SDL_RenderCopy(vis->ren, tex, NULL, &(SDL_Rect){vis->progress[1].x,\
										vis->progress[1].y, sz.x, sz.y});
	free(tmp);
	free(text);
	SDL_DestroyTexture(tex);
}

void			ren_score(t_vis *vis, t_game *game, t_step *stp)
{
	SDL_Texture	*tex;
	t_pnt		sz;
	char		*tmp;
	char		*text;
	SDL_Color	color;

	color.a = 255;
	color = get_color(CLR_O, vis->clr_cof, 0);
	tmp = ft_itoa(stp->p1_tokens);
	text = ft_strjoin(game->p1_score, tmp);
	TTF_SizeText(vis->font_text, text, &sz.x, &sz.y);
	tex = create_texture(vis->font_text, text, vis->ren, color);
	SDL_RenderCopy(vis->ren, tex, NULL, &(SDL_Rect){vis->score[0].x,\
										vis->score[0].y, sz.x, sz.y});
	free(tmp);
	free(text);
	color = get_color(CLR_X, vis->clr_cof, 0);
	tmp = ft_itoa(stp->p2_tokens);
	text = ft_strjoin(game->p2_score, tmp);
	TTF_SizeText(vis->font_text, text, &sz.x, &sz.y);
	tex = create_texture(vis->font_text, text, vis->ren, color);
	SDL_RenderCopy(vis->ren, tex, NULL, &(SDL_Rect){vis->score[1].x,\
										vis->score[1].y, sz.x, sz.y});
	free(tmp);
	free(text);
	SDL_DestroyTexture(tex);
}

void			ren_fin(t_vis *vis, t_game *game)
{
	SDL_Rect	rect;
	SDL_Color	clr;
	SDL_Texture	*tex;
	t_pnt		sz;
	char		*text;

	clr = get_color(CLR_UP_WIN, 1, 0);
	SDL_SetRenderDrawColor(vis->ren, clr.r, clr.g, clr.b, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(vis->ren, &vis->fin_win);
	if (!game->p_win)
		game->p_win = game->p1_tokens > game->p2_tokens ? game->p1 : game->p2;
	clr = get_color(CLR_LOGO, 1, 0);
	text = ft_strjoin(game->p_win, " win");
	TTF_SizeText(vis->font_logo, text, &sz.x, &sz.y);
	tex = create_texture(vis->font_logo, text, vis->ren, clr);
	SDL_RenderCopy(vis->ren, tex, NULL, &(SDL_Rect){(vis->fin_win.w - sz.x) / 2 + vis->fin_win.x,
							(vis->fin_win.h - sz.y) / 2 + vis->fin_win.y, sz.x, sz.y});
	free(text);
	SDL_DestroyTexture(tex);
}
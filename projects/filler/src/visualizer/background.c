/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:37:05 by cormund           #+#    #+#             */
/*   Updated: 2019/09/20 18:13:15 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

static void		bgrnt_board(t_vis *vis, t_game *game)
{
	vis->bgrnd_board.x = BG_BOARD_X;
	vis->bgrnd_board.y = BG_BOARD_Y;
	game->size_rect.x = (SCREEN_WIDTH - BG_BOARD_X - 25) / game->size_board.x;
	game->size_rect.y = (SCREEN_HEIGHT - BG_BOARD_Y - 25) / game->size_board.y;
	vis->bgrnd_board.w = game->size_rect.x * game->size_board.x;
	vis->bgrnd_board.h = game->size_rect.y * game->size_board.y;
}

static void		logo(t_vis *vis)
{
	SDL_Surface	*text;
	SDL_Color	color;

	color = get_color(CLR_LOGO, 1, 0);
	TTF_SizeText(vis->font_logo, LOGO, &vis->size_logo.w, &vis->size_logo.h);
	vis->size_logo.x = 30;
	vis->size_logo.y = 20;
	text = TTF_RenderText_Blended(vis->font_logo, LOGO, color);
	vis->logo = SDL_CreateTextureFromSurface(vis->ren, text);
	SDL_FreeSurface(text);
}

static void		head_wins(t_vis *vis)
{
	t_pnt		size_text;

	TTF_SizeText(vis->font_text, INFO, &size_text.x, &size_text.y);
	vis->up_win[0].x = vis->size_logo.x - 10;
	vis->up_win[0].y = vis->size_logo.y - 10;
	vis->up_win[0].w = vis->size_logo.w + 20;
	vis->up_win[0].h = vis->size_logo.h + 25;
	vis->up_win[1].x = vis->info_win[0].x;
	vis->up_win[1].y = vis->info_win[0].y;
	vis->up_win[1].w = vis->up_win[0].w;
	vis->up_win[1].h = size_text.y * 1.5;
	vis->up_win[2].x = vis->info_win[0].x;
	vis->up_win[2].y = vis->info_win[1].y;
	vis->up_win[2].w = vis->up_win[0].w;
	vis->up_win[2].h = vis->up_win[1].h;
	vis->up_win[3].x = vis->info_win[0].x;
	vis->up_win[3].y = vis->info_win[2].y;
	vis->up_win[3].w = vis->up_win[0].w;
	vis->up_win[3].h = vis->up_win[1].h;
	vis->up_win[4].x = vis->info_win[0].x;
	vis->up_win[4].y = vis->info_win[3].y;
	vis->up_win[4].w = vis->up_win[0].w;
	vis->up_win[4].h = vis->up_win[1].h;
}

static void		wins_for_info(t_vis *vis)
{
	t_pnt		size_text;

	TTF_SizeText(vis->font_text, INFO, &size_text.x, &size_text.y);
	vis->info_win[0].x = vis->size_logo.x - 10;
	vis->info_win[0].y = vis->size_logo.y + vis->size_logo.h + 50;
	vis->info_win[0].w = vis->size_logo.w + 20;
	vis->info_win[0].h = size_text.y * 5;
	vis->info_win[1].x = vis->info_win[0].x;
	vis->info_win[1].y = vis->info_win[0].y + vis->info_win[0].h + 50;
	vis->info_win[1].w = vis->info_win[0].w;
	vis->info_win[1].h = size_text.y * 6;
	vis->info_win[2].x = vis->info_win[1].x;
	vis->info_win[2].y = vis->info_win[1].y + vis->info_win[1].h + 50;
	vis->info_win[2].w = vis->info_win[0].w;
	vis->info_win[2].h = size_text.y * 4;
	vis->info_win[3].x = vis->info_win[2].x;
	vis->info_win[3].y = vis->info_win[2].y + vis->info_win[2].h + 50;
	vis->info_win[3].w = vis->info_win[0].w;
	vis->info_win[3].h = size_text.y * 4;
}

static void		fin_win(t_vis *vis)
{
	t_pnt		size_text;

	TTF_SizeText(vis->font_logo, "cormund win", &size_text.x, &size_text.y);
	vis->fin_win.h = size_text.y * 8;
	vis->fin_win.w = size_text.x * 1.4;
	vis->fin_win.x = (vis->bgrnd_board.w - vis->fin_win.w) / 2 + BG_BOARD_X;
	vis->fin_win.y = (vis->bgrnd_board.h - vis->fin_win.h) / 2 + BG_BOARD_Y;
}

void			background(t_game *game, t_vis *vis)
{
	bgrnt_board(vis, game);
	logo(vis);
	wins_for_info(vis);
	head_wins(vis);
	head(vis);
	info_win(vis, game);
	control_keys(vis);
	progression(vis);
	score(vis, game);
	fin_win(vis);
}
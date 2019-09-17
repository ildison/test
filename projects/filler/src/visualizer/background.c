/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:37:05 by cormund           #+#    #+#             */
/*   Updated: 2019/09/17 19:02:20 by cormund          ###   ########.fr       */
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

	color.r = CLR_LOGO >> 16 & 0xff;
	color.g = CLR_LOGO >> 8 & 0xff;
	color.b = CLR_LOGO & 0xff;
	TTF_SizeText(vis->font_logo, LOGO, &vis->size_logo.w, &vis->size_logo.h);
	vis->size_logo.x = 20;
	vis->size_logo.y = 15;
	text = TTF_RenderText_Blended(vis->font_logo, LOGO, color);
	vis->logo = SDL_CreateTextureFromSurface(vis->ren, text);
	SDL_FreeSurface(text);
}

static void		up_info_board(t_vis *vis)
{
	vis->up_info[0].x = vis->size_logo.x - 10;
	vis->up_info[0].y = vis->size_logo.y - 5;
	vis->up_info[0].w = vis->size_logo.w + 20;
	vis->up_info[0].h = vis->size_logo.h + 15;
	vis->up_info[1].x = vis->info[0].x;
	vis->up_info[1].y = vis->info[0].y;
	vis->up_info[1].w = vis->up_info[0].w;
	vis->up_info[1].h = vis->size_text.h * 1.5;
	vis->up_info[2].x = vis->info[0].x;
	vis->up_info[2].y = vis->info[1].y;
	vis->up_info[2].w = vis->up_info[0].w;
	vis->up_info[2].h = vis->up_info[1].h;
	vis->up_info[3].x = vis->info[0].x;
	vis->up_info[3].y = vis->info[2].y;
	vis->up_info[3].w = vis->up_info[0].w;
	vis->up_info[3].h = vis->up_info[1].h;
}

static void		info_board(t_vis *vis)
{
	vis->info[0].x = vis->size_logo.x - 10;
	vis->info[0].y = vis->size_logo.y + vis->size_logo.h + 30;
	vis->info[0].w = vis->size_logo.w + 20;
	vis->info[0].h = vis->size_text.h * 6;
	vis->info[1].x = vis->info[0].x;
	vis->info[1].y = vis->info[0].y + vis->info[0].h + 20;
	vis->info[1].w = vis->info[0].w;
	vis->info[1].h = vis->size_text.h * 6;
	vis->info[2].x = vis->info[1].x;
	vis->info[2].y = vis->info[1].y + vis->info[1].h + 20;
	vis->info[2].w = vis->info[0].w;
	vis->info[2].h = vis->size_text.h * 5;
}

void			background(t_game *game, t_vis *vis)
{
	bgrnt_board(vis, game);
	logo(vis);
	TTF_SizeText(vis->font_text, LOGO, &vis->size_text.w, &vis->size_text.h); //? need put to her fun
	info_board(vis);
	up_info_board(vis);
}
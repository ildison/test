/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:40:26 by cormund           #+#    #+#             */
/*   Updated: 2019/09/13 12:36:53 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

static void	parsing_plrs(t_game *game)
{
	char	*line;
	char	*tmp;

	while(get_next_line(STD_OUT, &line) && *line != '$')
		free(line);
	tmp = ft_strchr(line, '/');
	game->p1 = ft_strcut(tmp + 1, '.');
	free(line);
	get_next_line(STD_OUT, &line);
	tmp = ft_strchr(line, '/');
	game->p2 = ft_strcut(tmp + 1, '.');
	free(line);
}

static void	parsing_size(t_pnt *size)
{
	char	*line;
	char	*tmp;

	while (get_next_line(STD_OUT, &line) && *line != 'P')
		free(line);
	tmp = line;
	while (!ft_isdigit(*tmp))
		++tmp;
	size->y = ft_atoi(tmp);
	while (ft_isdigit(*tmp))
		++tmp;
	size->x = ft_atoi(tmp + 1);
	free(line);
}

SDL_Rect		*malloc_rect(size_t size)
{
	SDL_Rect	*rect;

	if (!(rect = (SDL_Rect *)malloc(size)))
		error(strerror(errno));
	// memset for w, h
	return (rect);
}

t_step		*new_lst_step(t_game *game)
{
	t_step	*new_step;
	int		square;

	new_step = (t_step *)ft_memalloc(sizeof(t_step));
	if (!new_step)
		error(strerror(errno));
	square = game->size_board.x * game->size_board.y;
	new_step->p1 = malloc_rect(sizeof(SDL_Rect) * square);
	new_step->p2 = malloc_rect(sizeof(SDL_Rect) * square);
	new_step->piece = malloc_rect(sizeof(SDL_Rect) * (square / 2));
	return (new_step);
}

void		add_top_step(t_step **beg, t_step *step)
{
	t_step	*lst;

	if (!*beg)
		*beg = step;
	else
	{
		lst = *beg;
		while (lst->next)
			lst = lst->next;
		step->prev = lst;
		lst->next = step;
	}
}

void 		parsing_step(t_game *game, t_step *stp, char *board, int y)
{
	int		x;

	x = 0;
	while (board[x])
	{
		if (ft_isupper(board[x]))
		{
			if (board[x] == P1)
			{
				stp->p1[stp->n_p1].x = x * game->size_rect.x + BGRND_BOARD_X;
				stp->p1[stp->n_p1].y = y * game->size_rect.y + BGRND_BOARD_Y;
				stp->p1[stp->n_p1].w = game->size_rect.x;
				stp->p1[stp->n_p1].h = game->size_rect.y;
				++stp->n_p1;
			}
			else
			{
				stp->p2[stp->n_p2].x = x * game->size_rect.x + BGRND_BOARD_X;
				stp->p2[stp->n_p2].y = y * game->size_rect.y + BGRND_BOARD_Y;
				stp->p2[stp->n_p2].w = game->size_rect.x;
				stp->p2[stp->n_p2].h = game->size_rect.y;
				++stp->n_p2;
			}
		}
		else if (ft_islower(board[x]))
		{
			stp->piece[stp->n_pc].x = x * game->size_rect.x + BGRND_BOARD_X;
			stp->piece[stp->n_pc].y = y * game->size_rect.y + BGRND_BOARD_Y;
			stp->piece[stp->n_pc].w = game->size_rect.x;
			stp->piece[stp->n_pc].h = game->size_rect.y;
			++stp->n_pc;
			if (!game->token_flag && ++game->token_flag)
				board[x] == LOWER_P1 ? ++game->p1_tokens : ++game->p2_tokens;
		}
		++x;
	}
}

static t_step	*parsing_board(t_game *game)
{
	t_step		*stp;
	char		*line;
	int			y;

	stp = new_lst_step(game);
	add_top_step(game->start_step, stp);
	while (get_next_line(STD_OUT, &line) && (*line != ' ' || *line == '='))
		ft_memdel((void *)&line);
	if (!line)
	{
		ft_memcpy(stp, stp->prev, sizeof(t_step) - sizeof(t_step *) * 2);
		stp->fin = SDL_TRUE;
		return (stp);
	}
	else
		free(line);
	y = 0;
	game->token_flag = 0;
	while (y < game->size_board.y && get_next_line(STD_OUT, &line))
	{
		parsing_step(game, stp, line, y);
		free(line);
		++y;
	}
	stp->p1_tokens = game->p1_tokens;
	stp->p1_tokens = game->p1_tokens;
	return(stp);
}

t_step		*read_board(t_game *game)
{
	if (!game->p1)
	{
		parsing_plrs(game);
		parsing_size(&game->size_board);
		background(game, game->vis);
	}
		// H;
	return (parsing_board(game));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:40:26 by cormund           #+#    #+#             */
/*   Updated: 2019/09/16 17:49:17 by cormund          ###   ########.fr       */
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

t_step		*new_lst_step(t_game *game)
{
	t_step	*new_step;
	int		square;

	new_step = (t_step *)ft_memalloc(sizeof(t_step));
	if (!new_step)
		error(strerror(errno));
	square = game->size_board.x * game->size_board.y;
	new_step->colors = (SDL_Color *)ft_memalloc(sizeof(SDL_Color) * square);
	if (!new_step->colors)
		error(strerror(errno));
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
	while (*board)
	{

		if (*board == P1)
		{
			stp->colors[stp->n_colors].r = (COLOR_O >> 16) & 0xff;
			stp->colors[stp->n_colors].g = (COLOR_O >> 8) & 0xff;
			stp->colors[stp->n_colors].b = COLOR_O & 0xff;
		}
		else if (*board == P2)
		{
			stp->colors[stp->n_colors].r = (COLOR_X >> 16) & 0xff;
			stp->colors[stp->n_colors].g = (COLOR_X >> 8) & 0xff;
			stp->colors[stp->n_colors].b = COLOR_X & 0xff;
		}
		else if (ft_islower(*board))
		{
			stp->colors[stp->n_colors].r = (COLOR_P >> 16) & 0xff;
			stp->colors[stp->n_colors].g = (COLOR_P >> 8) & 0xff;
			stp->colors[stp->n_colors].b = COLOR_P & 0xff;
		}
		else
		{
			stp->colors[stp->n_colors].r = (COLOR_BGRND >> 16) & 0xff;
			stp->colors[stp->n_colors].g = (COLOR_BGRND >> 8) & 0xff;
			stp->colors[stp->n_colors].b = COLOR_BGRND & 0xff;
		}
		++stp->n_colors;
		++board;
	}
}

static t_step	*parsing_board(t_game *game)
{
	t_step		*stp;
	char		*line;
	int			y;

	stp = new_lst_step(game);
	add_top_step(game->start_step, stp);
	while (get_next_line(STD_OUT, &line) > 0 && (*line != ' ' || *line == '='))
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
	while (y < game->size_board.y && get_next_line(STD_OUT, &line) > 0)
	{
		parsing_step(game, stp, line + 4, y);
		ft_memdel((void *)&line);
		++y;
	}
	stp->p1_tokens = game->p1_tokens;
	stp->p1_tokens = game->p1_tokens;
	return(stp);
}

t_step		*next_step(t_game *game, t_step *step)
{
	char	b;

	if (step && step->next && !step->fin)
		return (step->next);
	if (step && step->fin)
		return (step);
	if (!game->p1)
	{
		parsing_plrs(game);
		parsing_size(&game->size_board);
		background(game, game->vis);
	}
	if (read(STD_OUT, &b, 1) > 0)
		return (parsing_board(game));
	return (step);
}

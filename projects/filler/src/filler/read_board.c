/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:26:50 by cormund           #+#    #+#             */
/*   Updated: 2019/09/23 18:23:59 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	parsing_size(t_pnt *size)
{
	char	*line;
	char	*s;

	while (get_next_line(FL_FD, &line) > 0 && *line != 'P')
		free(line);
	s = line;
	while (!ft_isdigit(*s))
		++s;
	size->y = ft_atoi(s);
	while (ft_isdigit(*s))
		++s;
	size->x = ft_atoi(s + 1);
	free(line);
}

static void	parsing_plr(t_fl *fl)
{
	char	*line;

	while (get_next_line(FL_FD, &line) > 0 && *line != '$')
		ft_memdel((void *)line);
	if (ft_strstr(line, "p1"))
		fl->plr = 'o';
	else
		fl->plr = 'x';
	free(line);
	if (get_next_line(FL_FD, &line) == 0)
		exit(0);
	free(line);
}

static void	parsing_board(t_fl *fl)
{
	char	*line;
	int		y;

	while (get_next_line(FL_FD, &line) > 0 && *line != ' ')
		free(line);
	free(line);
	y = 0;
	while (y < fl->size_board.y && get_next_line(FL_FD, &line) > 0)
	{
		prep_heat_map(fl, line + 4, y);
		free(line);
		++y;
	}
}

static void	parsing_piece(t_fl *fl)
{
	int		y;
	int		x;
	char	*line;

	fl->n_piece = 0;
	parsing_size(&fl->size_piece);
	y = 0;
	while (y < fl->size_piece.y && get_next_line(FL_FD, &line) > 0)
	{
		x = 0;
		while (line[x])
		{
			if (line[x] == '*')
			{
				fl->piece[fl->n_piece].x = x;
				fl->piece[fl->n_piece++].y = y;
			}
			++x;
		}
		++y;
	}
}

void		read_board(t_fl *fl)
{
	if (!fl->plr)
	{
		parsing_plr(fl);
		parsing_size(&fl->size_board);
		malloc_heat_map_and_piece(fl);
	}
	parsing_board(fl);
	parsing_piece(fl);
}

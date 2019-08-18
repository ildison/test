/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:26:50 by cormund           #+#    #+#             */
/*   Updated: 2019/08/18 21:54:41 by cormund          ###   ########.fr       */
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
	while(ft_isdigit(*s))
		++s;
	size->x = ft_atoi(s + 1);
	free(line);
}

static void	parsing_plr(t_fl *fl)
{
	char	*line;

	while (get_next_line(FL_FD, &line) > 0 && *line != '$')
		free(line);
	if (ft_strstr(line, "p1"))
		fl->plr = 'o';
	else
		fl->plr = 'x';
	free(line);
}

void		malloc_board_heat_map_and_piece(t_fl *fl)
{
	int		i;

	fl->piece = (t_pnt *)malloc(sizeof(t_pnt) * fl->size_board.y * fl->size_board.x);
	fl->heat_map = (int **)malloc(sizeof(int *) * (fl->size_board.y + 1));
	// fl->board = (char **)malloc(sizeof(char *) * (fl->size_board.y + 1));
	i = 0;
	while (i < fl->size_board.y)
	{
		// fl->board[i] = (char *)malloc(fl->size_board.x + 1);
		fl->heat_map[i] = (int *)malloc(sizeof(int) *fl->size_board.x);
		++i;
	}
	// fl->board[fl->size_board.y] = NULL;
	fl->heat_map[fl->size_board.y] = NULL;
}

static void	parsing_board(t_fl *fl)
{
	char	*line;
	int		y;

	while (get_next_line(FL_FD, &line) > 0 && *line != ' ')
		free(line);
	free(line);
	y = 0;
	while(y < fl->size_board.y && get_next_line(FL_FD, &line) > 0)
	{
		prep_heat_map(fl, line + 4, y);
		// ft_strcpy(fl->board[y], line + 4);
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
	while(y < fl->size_piece.y && get_next_line(FL_FD, &line) > 0)
	{
		x = 0;
		while(line[x])
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
	if(!fl->plr)
	{
		parsing_plr(fl);
		parsing_size(&fl->size_board);
		malloc_board_heat_map_and_piece(fl);
	}
		parsing_board(fl);
		parsing_piece(fl);
}
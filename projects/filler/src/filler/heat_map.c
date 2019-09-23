/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:33:09 by cormund           #+#    #+#             */
/*   Updated: 2019/09/23 18:24:25 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	isopponent(char plr, char c)
{
	if (c == '.')
		return (0);
	else
		return (!ISMYBOT(plr, c));
}

void		prep_heat_map(t_fl *fl, char *line, int y)
{
	int		x;

	x = 0;
	while (line[x])
	{
		if (line[x] == '.' && !fl->heat_map[y][x])
			fl->heat_map[y][x] = SHRT_MAX;
		else if (ISMYBOT(fl->plr, line[x]))
			fl->heat_map[y][x] = -1;
		else if (isopponent(fl->plr, line[x]))
		{
			fl->heat_map[y][x] = 0;
			fl->begin.x = x;
			fl->begin.y = y;
		}
		++x;
	}
}

void		malloc_heat_map_and_piece(t_fl *fl)
{
	int		i;

	fl->piece = (t_pnt *)malloc(sizeof(t_pnt) * fl->size_board.y *\
													fl->size_board.x);
	if (!fl->piece)
		error(strerror(errno));
	fl->heat_map = (int **)ft_memalloc(sizeof(int *) * (fl->size_board.y + 1));
	if (!fl->heat_map)
		error(strerror(errno));
	i = 0;
	while (i < fl->size_board.y)
	{
		fl->heat_map[i] = (int *)ft_memalloc(sizeof(int) * fl->size_board.x);
		if (!fl->heat_map[i])
			error(strerror(errno));
		++i;
	}
	fl->heat_map[fl->size_board.y] = NULL;
}

static void	heating(t_fl *fl, int y, int x, int cold)
{
	if (!CHECK_SIZE(fl->size_board, x, y) || fl->heat_map[y][x] < 0)
		return ;
	if (cold < fl->heat_map[y][x])
		fl->heat_map[y][x] = cold;
	else if (!fl->heat_map[y][x])
	{
		cold = 0;
		fl->heat_map[y][x] = -2;
	}
	else
		return ;
	heating(fl, y - 1, x - 1, cold + 1);
	heating(fl, y - 1, x, cold + 1);
	heating(fl, y - 1, x + 1, cold + 1);
	heating(fl, y, x + 1, cold + 1);
	heating(fl, y + 1, x + 1, cold + 1);
	heating(fl, y + 1, x, cold + 1);
	heating(fl, y + 1, x - 1, cold + 1);
	heating(fl, y, x - 1, cold + 1);
}

void		heat_map(t_fl *fl)
{
	t_pnt	begin;

	begin = fl->begin;
	fl->heat_map[begin.y][begin.x] = -2;
	heating(fl, begin.y - 1, begin.x - 1, 1);
	heating(fl, begin.y - 1, begin.x + 1, 1);
	heating(fl, begin.y + 1, begin.x + 1, 1);
	heating(fl, begin.y + 1, begin.x - 1, 1);
	heating(fl, begin.y - 1, begin.x, 1);
	heating(fl, begin.y, begin.x + 1, 1);
	heating(fl, begin.y + 1, begin.x + 1, 1);
	heating(fl, begin.y, begin.x - 1, 1);
}

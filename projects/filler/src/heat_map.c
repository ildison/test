/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:33:09 by cormund           #+#    #+#             */
/*   Updated: 2019/08/18 21:46:24 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		prep_heat_map(char *line, int *heat_map, int y)
{
	int 	x;

	x = 0;
	while(line[x])
	{
		if (line[x] == '.')
			heat_map[x] = SHRT_MAX;
		else if (line[x] == fl->plr || line[x] == ft_toupper(fl->plr))
			heat_map[x] = -1;
		else
		{
			heat_map[x] = 0;
			fl->begin->x = x;
			fl->begin->y = y;
		}
		++x;
	}
}

static void	preparation_heat_map(t_fl *fl, t_pnt *beg)
{
	int		x;
	int		y;

	y = 0;
	while(y < fl->size_board.y)
	{
		x = 0;
		while(fl->board[y][x])
		{
			if (fl->board[y][x] == '.')
				fl->heat_map[y][x] = SHRT_MAX;
			else if (fl->board[y][x] == fl->plr || fl->board[y][x] == ft_toupper(fl->plr))
				fl->heat_map[y][x] = -1;
			else
			{
				fl->heat_map[y][x] = 0;
				beg->x = x;
				beg->y = y;
				// H;
			}
			++x;
		}
		++y;
	}
}

static void	heating(t_fl *fl, int y, int x, int cold)
{
	if (!check_size(fl->size_board, x, y) || fl->heat_map[y][x] < 0)
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
	// preparation_heat_map(fl, &begin);
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
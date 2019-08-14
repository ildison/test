/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:33:09 by cormund           #+#    #+#             */
/*   Updated: 2019/08/14 15:34:42 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	preparation_heat_map(t_fl *fl, t_pnt *beg)
{
	int		x;
	int		y;

	y = 0;
	while(fl->board[y])
	{
		x = 0;
		while(fl->board[y][x])
		{
			if (fl->board[y][x] == '.')
				fl->heat_map[y][x] = __INT_MAX__;
			else if (fl->board[y][x] == fl->plr_letter || fl->board[y][x] == ft_toupper(fl->plr_letter))
				fl->heat_map[y][x] = -1;
			else
			{
				fl->heat_map[y][x] = 0;
				beg->x = x;
				beg->y = y;
			}
			++x;
		}
		++y;
	}
}

// int			check_size(t_pnt size, int x, int y)
// {
// 	return (x >= 0 && y >= 0 && y < size.y && x < size.x);
// }

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

	preparation_heat_map(fl, &begin);
	heating(fl, begin.y - 1, begin.x - 1, 1);
	heating(fl, begin.y - 1, begin.x + 1, 1);
	heating(fl, begin.y + 1, begin.x + 1, 1);
	heating(fl, begin.y + 1, begin.x - 1, 1);
}
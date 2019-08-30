/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:33:09 by cormund           #+#    #+#             */
/*   Updated: 2019/08/30 10:15:16 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ismybot(char plr, char c)
{
	return (ft_toupper(plr) == ft_toupper(c));
}

static int	isopponent(char plr, char c)
{
	if (c == '.')
		return (0);
	else
		return (!ismybot(plr, c));
}

void		prep_heat_map(t_fl *fl, char *line, int y)
{
	int 	x;

	x = 0;
	while(line[x])
	{
		if (line[x] == '.' && !fl->heat_map[y][x])
			fl->heat_map[y][x] = SHRT_MAX;
		else if (ismybot(fl->plr, line[x]))
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
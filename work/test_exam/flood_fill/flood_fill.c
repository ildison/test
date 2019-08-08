/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:26:56 by cormund           #+#    #+#             */
/*   Updated: 2019/08/08 10:12:28 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"


char		**make_area(char **zone, t_point z)
{
	char	**frsh;
	char	i = 0;

	frsh = (char **)malloc(sizeof(char *) * (z.y + 1));
	while (i != z.y)
	{
		frsh[i] = ft_strnew(z.x);
		ft_strcpy(frsh[i], zone[i]);
		++i;
	}
	frsh[i] = NULL;
	return (frsh);
}

void		print_tab(char **mas)
{
	while(*mas)
		ft_putendl(*mas++);
}

int			check_size(t_point size, t_point p)
{
	return (p.x >= 0 && p.y >= 0 && p.y < size.y && p.x < size.x);
}

void		colors(char **tab, t_point size, t_point begin,  char chr)
{
	if (!check_size(size, begin) || tab[begin.y][begin.x] != chr)
		return ;
	tab[begin.y][begin.x] = 'F';
	begin.y -= 1;
	colors(tab, size, begin, chr);
	begin.y += 2;
	colors(tab, size, begin, chr);
	begin.y -= 1;
	begin.x -= 1;
	colors(tab, size, begin, chr);
	begin.x += 2;
	colors(tab, size, begin, chr);
}

void		flood_fill(char **tab, t_point size, t_point begin)
{
	char	chr;

	if (!check_size(size, begin) && !size.x && !size.y)
		return ;
	chr = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	begin.y -= 1;
	colors(tab, size, begin, chr);
	begin.y += 2;
	colors(tab, size, begin, chr);
	begin.y -= 1;
	begin.x -= 1;
	colors(tab, size, begin, chr);
	begin.x += 2;
	colors(tab, size, begin, chr);
}

int			main(void)
{
	char	**area;
	t_point	size = { 8, 5 };
	t_point	begin = { 0, 0 };
	char	*zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10100001",
		"11100001",
	};

	area = make_area(zone, size);
	print_tab(area);
	flood_fill(area, size, begin);
	ft_putchar('\n');
	print_tab(area);
	return (0);
}
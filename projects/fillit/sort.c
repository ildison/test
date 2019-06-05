/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 09:47:47 by cormund           #+#    #+#             */
/*   Updated: 2019/05/20 18:01:46 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt_rt(int num)
{
	int		i;

	i = 2;
	while (i * i < num)
		++i;
	return (i);
}

void		ft_replace_nchr(char *s, char from, char to, size_t n)
{
	while (*s && n)
	{
		if (*s == from)
		{
			*s = to;
			--n;
		}
		++s;
	}
}

void		ft_tet_entrance(t_coord **t, char *tetris, int step, int l)
{
	int		i1;
	int		i2;
	int		i3;

	(*t)->index ? ft_replace_nchr(tetris, (*t)->chr, '.', 4) : 0;
	i1 = (*t)->tet[1] + (*t)->tet[1] / 5 * (step - 4);
	i2 = (*t)->tet[2] + (*t)->tet[2] / 5 * (step - 4);
	i3 = (*t)->tet[3] + (*t)->tet[3] / 5 * (step - 4);
	tetris = &tetris[(*t)->index++];
	l = l - i3 - (*t)->index;
	while (l-- > 0 && (tetris[(*t)->tet[0]] != '.' || tetris[i1] != '.' ||
		tetris[i2] != '.' || tetris[i3] != '.'))
	{
		(*t)->index++;
		tetris++;
	}
	if (l < 0)
		(*t)->index = 0;
	else
	{
		tetris[(*t)->tet[0]] = (*t)->chr;
		tetris[i1] = (*t)->chr;
		tetris[i2] = (*t)->chr;
		tetris[i3] = (*t)->chr;
	}
}


int			ft_recursive_sort(t_coord **beg, char *tetris, int step, int len)
{
	if (!(*beg))
		return (1);
	ft_tet_entrance(beg, tetris, step, len);
	if ((*beg)->index)
		return (ft_recursive_sort(&(*beg)->next, tetris, step, len) ?\
				1 : ft_recursive_sort(beg, tetris, step, len));
		return (0);
}

int			ft_sort(t_coord **beg, int n_tet)
{
	char	*fin_tet;
	int		i;
	int		res;

	if (!n_tet)
		return (0);
	res = 0;
	fin_tet = NULL;
	n_tet = ft_sqrt_rt(n_tet * 4);
	while (!res)
	{
		fin_tet ? free(fin_tet) : 0;
		if (!(fin_tet = ft_strnew(n_tet * n_tet + n_tet)))
			return (0);
		ft_memset(fin_tet, '.', n_tet * n_tet + n_tet);
		i = n_tet;
		while ((fin_tet[i++] = '\n') && fin_tet[i])
			i += n_tet;
		res = ft_recursive_sort(beg, fin_tet, n_tet, n_tet * n_tet + n_tet);
		++n_tet;
	}
	ft_putstr(fin_tet);
	free(fin_tet);
	ft_del_lst(beg);
	return (1);
}

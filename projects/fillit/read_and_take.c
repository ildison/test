/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_take.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:37:11 by cormund           #+#    #+#             */
/*   Updated: 2019/05/20 18:29:06 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_del_lst(t_coord **beg)
{
	if (*beg)
	{
		if ((*beg)->next)
			ft_del_lst(&(*beg)->next);
		free((*beg)->tet);
		ft_memdel((void **)beg);
	}
}

static int	ft_add_newelem(t_coord **beg, int *tetrim, char chr)
{
	t_coord	*lst;

	if (!tetrim)
		return (0);
	lst = *beg;
	if (!*beg)
	{
		if (!((*beg) = (t_coord*)malloc(sizeof(t_coord))))
			return (0);
		(*beg)->chr = chr;
		(*beg)->index = 0;
		(*beg)->tet = tetrim;
		(*beg)->next = NULL;
		return (1);
	}
	while (lst->next)
		lst = lst->next;
	if (!(lst->next = (t_coord*)malloc(sizeof(t_coord))))
		return (0);
	lst->next->chr = chr;
	lst->next->index = 0;
	lst->next->tet = tetrim;
	lst->next->next = NULL;
	return (1);
}

static void	ft_cut_coor_tetrim(char *pole, int *coor)
{
	int		i;
	int		n_x;
	int		n_y;

	n_y = 0;
	i = 0;
	while (pole[i] != '#')
		if (pole[i++] == '\n')
			++n_y;
	i = n_y;
	n_x = 0;
	while (pole[i * 5 + n_x] != '#')
		if (i++ == 3)
		{
			i = 0;
			++n_x;
		}
	pole = pole + n_y * 5 + n_x;
	i = -1;
	while (pole[++i])
		if (pole[i] == '#')
			*coor++ = i;
}

static int	ft_take_tetrim(t_coord **lst, char *pole, char chr)
{
	int		*coor;

	if ((coor = (int*)malloc(sizeof(int) * 4)))
		ft_cut_coor_tetrim(pole, coor);
	return (ft_add_newelem(lst, coor, chr));
}

int			ft_read_input(char *file, t_coord **tet)
{
	ssize_t	fd;
	ssize_t	n_byte;
	size_t	n_tetrim;
	char	*buf;
	char	chr;

	chr = 'A';
	n_tetrim = 0;
	if ((buf = ft_strnew(21)) &&
	(fd = open(file, O_RDONLY)) != -1)
		while ((n_byte = read(fd, buf, 21)) > 0)
		{
			buf[n_byte] = '\0';
			if (!ft_take_tetrim(tet, buf, chr++))
			{
				ft_del_lst(tet);
				n_tetrim = 0;
				break ;
			}
			++n_tetrim;
		}
	if (buf)
		free(buf);
	return (n_tetrim);
}

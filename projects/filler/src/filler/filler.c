/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:56:19 by cormund           #+#    #+#             */
/*   Updated: 2019/09/24 11:54:18 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	cleaning_up(t_fl *fl)
{
	int		**tmp;
	char	*line;

	while (get_next_line(FL_FD, &line))
		free(line);
	if ((tmp = fl->heat_map))
		while (*tmp)
		{
			free(*tmp);
			++tmp;
		}
	ft_memdel((void **)fl->heat_map);
	ft_memdel((void *)&fl->piece);
	free(fl);
}

void		error(const char *err_msg)
{
	if (err_msg)
		ft_putstr(err_msg);
	exit(-1);
}

void		filler(void)
{
	t_fl	*fl;
	char	b;
	int		delay;

	delay = 10000;
	if (!(fl = (t_fl *)ft_memalloc(sizeof(t_fl))))
		error(strerror(errno));
	while (1 && delay--)
		if (read(FL_FD, &b, 1))
		{
			fl->fl_exit = 1;
			if (read_board(fl))
				break ;
			heat_map(fl);
			sort(fl);
			ft_printf("%d %d\n", fl->place.y, fl->place.x);
			if (fl->fl_exit)
				exit(0);
			delay = 10000;
		}
	cleaning_up(fl);
}

int			main(void)
{
	filler();
	return (0);
}

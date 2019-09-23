/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:56:19 by cormund           #+#    #+#             */
/*   Updated: 2019/09/23 18:22:58 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	if (!(fl = (t_fl *)malloc(sizeof(t_fl))))
		error(strerror(errno));
	fl->plr = 0;
	while (1 && delay--)
		if (read(FL_FD, &b, 1))
		{
			fl->fl_exit = 1;
			read_board(fl);
			heat_map(fl);
			sort(fl);
			ft_printf("%d %d\n", fl->place.y, fl->place.x);
			if (fl->fl_exit)
				exit(0);
			delay = 10000;
		}
}

int			main(void)
{
	filler();
	return (0);
}

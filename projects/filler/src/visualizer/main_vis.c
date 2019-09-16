/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:16:22 by cormund           #+#    #+#             */
/*   Updated: 2019/09/16 10:06:06 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

void			error(const char *err_msg)
{
	if (err_msg)
		ft_putstr(err_msg);
	H;
	exit(-1);
}

void			visualizer()
{
	t_step		*step;
	t_game		*game;

	step = NULL;
	if (!(game = (t_game*)ft_memalloc(sizeof(t_game))))
		error(strerror(errno));
	game->start_step = &step;
	init(game);
	loop(game, game->vis, step);
	destroy_init(game->vis);
}

int				main()
{
	visualizer();
	return (0);
}
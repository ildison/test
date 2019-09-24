/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:16:22 by cormund           #+#    #+#             */
/*   Updated: 2019/09/24 12:25:01 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

void			cleaning_up(t_game *game, t_step *stp)
{
	char		*line;
	t_step		*tmp;

	if (get_next_line(STD_OUT, &line))
	{
		ft_printf("Wait for the VM to finish.\n");
		free(line);
		while (get_next_line(STD_OUT, &line))
			free(line);
		ft_printf("VM finished.\n");
	}
	if (stp)
		while ((tmp = stp))
		{
			stp = stp->next;
			ft_memdel((void **)&tmp->clrs);
			ft_memdel((void *)&tmp);
		}
	ft_memdel((void *)&game->vis);
	ft_memdel((void *)&game->p1);
	ft_memdel((void *)&game->p2);
	ft_memdel((void *)&game->p1_score);
	ft_memdel((void *)&game->p2_score);
}

void			print_vm_error(void)
{
	char		*line;

	if (get_next_line(STD_OUT, &line))
	{
		ft_printf("error:\n%s\n", line);
		free(line);
	}
	exit(-1);
}

void			error(const char *err_msg)
{
	if (err_msg)
		ft_putstr(err_msg);
	exit(-1);
}

void			visualizer(void)
{
	t_step		*step;
	t_game		*game;

	step = NULL;
	if (!(game = (t_game*)ft_memalloc(sizeof(t_game))))
		error(strerror(errno));
	game->start_step = &step;
	game->n_stp = ZERO_STEP;
	init(game);
	loop(game, game->vis, step);
	destroy_init(game->vis);
	cleaning_up(game, step);
}

int				main(void)
{
	visualizer();
	return (0);
}

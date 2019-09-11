/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:16:22 by cormund           #+#    #+#             */
/*   Updated: 2019/09/11 16:17:14 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

void			error()
{
	exit(1);
}

void			visualizer()
{
	t_step		*step;
	t_game		*game;
	char		b;

	step = NULL;
	game = (t_game*)malloc(sizeof(t_game));
	game->start_step = &step;
	game->p1 = NULL;
	game->p1_tokens = 0;
	game->p2_tokens = 0;
	while (read(STD_OUT, &b, 1)) //? while
		read_board(game);
	int fd = open("test", O_WRONLY);
	ft_printf("%vcormund %d\nsmorty %d", fd, game->p1_tokens, game->p2_tokens);
}

int				main()
{
	visualizer();
	return (0);
}
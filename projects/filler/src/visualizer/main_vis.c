/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:16:22 by cormund           #+#    #+#             */
/*   Updated: 2019/09/10 12:30:27 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

void			error()
{
	exit(1);
}

void			visualizer()
{
	t_game		*game;
	char		b;

	game = (t_game*)malloc(sizeof(t_game));
	game->p1 = NULL;
	game->p1_tokens = 0;
	game->p2_tokens = 0;
	if (read(STD_OUT, &b, 1)) //? while
		read_board(game);
}

int				main()
{
	visualizer();
	return (0);
}
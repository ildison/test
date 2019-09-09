/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:16:22 by cormund           #+#    #+#             */
/*   Updated: 2019/09/09 19:48:34 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

void			visualizer()
{
	t_game		*game;

	game = (t_game*)malloc(sizeof(t_game));
	game->p1 = NULL;
	game->p1_tokens = 0;
	game->p2_tokens = 0;
	read_board(game);
}

int				main()
{
	visualizer();
	return (0);
}
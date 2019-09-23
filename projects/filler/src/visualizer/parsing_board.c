/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:40:26 by cormund           #+#    #+#             */
/*   Updated: 2019/09/23 13:31:52 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

static void	parsing_plrs(t_game *game)
{
	char	*line;
	char	*tmp;

	while (get_next_line(STD_OUT, &line) && *line != '$' && *line != 'e' &&\
																*line != 'r')
		free(line);
	if (*line == 'e' || *line == 'r')
		print_vm_error();
	tmp = ft_strrchr(line, '/');
	game->p1 = ft_strcut(tmp + 1, '.');
	free(line);
	get_next_line(STD_OUT, &line);
	if (*line == 'e')
		print_vm_error();
	tmp = ft_strrchr(line, '/');
	game->p2 = ft_strcut(tmp + 1, '.');
	free(line);
}

static void	parsing_size(t_pnt *size)
{
	char	*line;
	char	*tmp;

	while (get_next_line(STD_OUT, &line) && *line != 'P')
		free(line);
	tmp = line;
	while (!ft_isdigit(*tmp))
		++tmp;
	size->y = ft_atoi(tmp);
	while (ft_isdigit(*tmp))
		++tmp;
	size->x = ft_atoi(tmp + 1);
	free(line);
}

t_step		*next_step(t_game *game, t_step *step)
{
	char	b;

	if (step && step->next && !step->fin)
		return (step->next);
	else if (step && step->fin)
		return (step);
	if (!game->p1)
	{
		parsing_plrs(game);
		parsing_size(&game->size_board);
		background(game, game->vis);
	}
	if (read(STD_OUT, &b, 1) > 0)
	{
		return (parsing_board(game));
	}
	return (step);
}

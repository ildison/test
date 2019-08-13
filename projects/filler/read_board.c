/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:26:50 by cormund           #+#    #+#             */
/*   Updated: 2019/08/12 20:41:42 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		parsing_size(t_fl *fl, char *s)
{
	while (!is_digit(*s))
		++s;
	fl->n_lines = ft_atoi(s);
	while(is_digit(*s))
		++s;
	fl->n_col = ft_atoi(s + 1);
}

void		parsing_plr_and_size(t_fl *fl)
{
	char	*line;

	while (get_next_line(0, &line) && *line != '$')
		free(line);
	if (!ft_strcmp(line, FL_PLAYER_NAME))
		fl->plr_letter = 'o';
	else
		fl->plr_letter = 'x';
	free(line);
	while (get_next_line(0, &line) && *line != 'P')
		free(line);
	parsing_size(fl, line);
	free(line);
}

void		read_board(t_fl *fl)
{
	if(!fl->plr_letter)
	{
		parsing_plr_and_size(fl);
		malloc_board(fl);
	}
		parsing_board(fl);
}
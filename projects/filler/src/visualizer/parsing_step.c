/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:19:07 by cormund           #+#    #+#             */
/*   Updated: 2019/09/23 17:20:57 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

static t_step	*new_lst_step(t_game *game)
{
	t_step		*new_step;
	int			square;

	new_step = (t_step *)ft_memalloc(sizeof(t_step));
	if (!new_step)
		error(strerror(errno));
	square = game->size_board.x * game->size_board.y;
	new_step->clrs = (int *)ft_memalloc(sizeof(int) * square);
	if (!new_step->clrs)
		error(strerror(errno));
	return (new_step);
}

static void		add_top_step(t_step **beg, t_step *step)
{
	t_step		*lst;

	if (!*beg)
		*beg = step;
	else
	{
		lst = *beg;
		while (lst->next)
			lst = lst->next;
		step->prev = lst;
		lst->next = step;
	}
}

static void		parsing_line(t_game *game, t_step *stp, char *board)
{
	while (*board)
	{
		if (*board == P1)
			stp->clrs[stp->n_clrs] = CLR_O;
		else if (*board == P2)
			stp->clrs[stp->n_clrs] = CLR_X;
		else if (ft_islower(*board))
		{
			stp->clrs[stp->n_clrs] = CLR_P;
			if (!game->token_flag)
			{
				if (*board == LOWER_P1)
					++game->p1_tokens;
				else
					++game->p2_tokens;
				++game->token_flag;
			}
		}
		else
			stp->clrs[stp->n_clrs] = CLR_BG;
		++stp->n_clrs;
		++board;
	}
}

static void		parsing_step(t_game *game, t_step *stp)
{
	int			y;
	char		*line;

	y = 0;
	while (y < game->size_board.y && get_next_line(STD_OUT, &line) > 0)
	{
		parsing_line(game, stp, line + 4);
		ft_memdel((void *)&line);
		++y;
	}
}

t_step			*parsing_board(t_game *game)
{
	t_step		*stp;
	char		*line;

	stp = new_lst_step(game);
	add_top_step(game->start_step, stp);
	while (get_next_line(STD_OUT, &line) > 0 && (*line != ' ' || *line == '='))
		ft_memdel((void *)&line);
	if (!line)
	{
		ft_memcpy(stp, stp->prev, sizeof(t_step) - sizeof(t_step *) * 2 -\
															sizeof(int *));
		ft_memcpy(stp->clrs, stp->prev->clrs, sizeof(int) * stp->n_clrs);
		stp->fin = SDL_TRUE;
		return (stp);
	}
	else
		free(line);
	game->token_flag = 0;
	parsing_step(game, stp);
	stp->n_stp = ++game->n_stp;
	stp->p1_tokens = game->p1_tokens;
	stp->p2_tokens = game->p2_tokens;
	return (stp);
}

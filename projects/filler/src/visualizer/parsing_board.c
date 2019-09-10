/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:40:26 by cormund           #+#    #+#             */
/*   Updated: 2019/09/10 16:47:18 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_visualizer.h"

static void	parsing_plrs(t_game *game)
{
	char	*line;
	char	*tmp;

	while(get_next_line(STD_OUT, &line) && *line != '$')
		free(line);
	tmp = ft_strchr(line, '/');
	game->p1 = ft_strcut(tmp + 1, '.');
	free(line);
	get_next_line(STD_OUT, &line);
	tmp = ft_strchr(line, '/');
	game->p2 = ft_strcut(tmp + 1, '.');
	free(line);
	printf("%s\n%s\n", game->p1, game->p2);
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

SDL_Rect		*malloc_rect(size_t size)
{
	SDL_Rect	*rect;

	if (!(rect = (SDL_Rect *)malloc(size)))
		error();
	//memset for w, h
}

void 		parsing_step(char *board, int y)
{
	int		x;
	int		token_flag;

	x = 0;
	token_flag = 0;
	while (board[x])
	{
		if (ft_isupper(board[x]))
		{
			if (board[x] == P1)
			{
				p1.x = x;
				p1.y = y;
				++n_p1;
			}
			else
			{
				p2.x = x;
				p2.y = y;
				++n_p2;
			}
		}
		else if (ft_islower(board[x]))
		{
			piece.x = x;
			piece.y = y;
			++n_piece;
			if (!token_flag && ++token_flag)
				board[x] == LOWER_P1 ? ++p1_tokens : ++p2_tokens;
		}
		++x;
	}
}

static void	parsing_board(t_game *game)
{
	char	*line;
	int		y;

	y = 0;
	while (get_next_line(STD_OUT, &line) && *line != ' ')
		free(line);
	free(line);
	while (y < game->size_board.y && get_next_line(STD_OUT, &line))
	{
		parsing_step(line, y);
		++y;
	}
}

void		read_board(t_game *game)
{
	if (!game->p1)
	{
		parsing_plrs(game);
		parsing_size(&game->size_board);
		malloc_rect(game);
	}
		parsing_board(game);
}

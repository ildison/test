/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:40:26 by cormund           #+#    #+#             */
/*   Updated: 2019/09/09 19:47:22 by cormund          ###   ########.fr       */
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
	game->p1 = ft_strcut(tmp, '.');
	free(line);
	get_next_line(STD_OUT, &line);
	tmp = ft_strchr(line, '/');
	game->p2 = ft_strcut(tmp, '.');
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

static void	malloc_board(t_game *game)
{
	int		i;

	game->board = (char **)malloc(sizeof(char *) * (game->size_board.y + 1));
	if (!game->board)
		error();
	i = 0;
	while (i < game->size_board.y)
	{
		game->board[i] = (char *)malloc(sizeof(char) *game->size_board.x);
		if (!game->board[i])
			error();
		ft_bzero(game->board[i], sizeof(char) *game->size_board.x);
		++i;
	}
	game->board[game->size_board.y] = NULL;
}

void 		parsing_move(char *fresh_board, char *board, int y)
{
	int		x;
	int		token_flag;

	x = 0;
	token_flag = 0;
	while (fresh_board[x])
	{
		if (fresh_board[x] != board[x])
		{
			board[x] = fresh_board[x];
			if (ft_isalpha(board[x]))
			{
				if (ft_islower(board[x]))
				{
					//? !flag ? p1/p2_tokens++;
					//? add_in_rec or add in mas_piece
				}
			}
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
		if (ft_strcmp(line, game->board[y]))
			parsing_move(line, game->board[y], y)
	}
}

void		read_board(t_game *game)
{
	if (!game->p1)
	{
		parsing_plrs(game);
		parsing_size(&game->size_board);
		malloc_board(game);
	}
		parsing_board(game);
}

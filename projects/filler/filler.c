/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:56:19 by cormund           #+#    #+#             */
/*   Updated: 2019/08/14 19:43:52 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


void		print_heatmap(t_fl *fl)
{
	int x;
	int y;

	y = 0;
	while (y < fl->size_board.y)
	{
		x = 0;
		while(x < fl->size_board.x)
		{
			ft_printf("%2d ", fl->heat_map[y][x]);
			++x;
		}
		ft_printf("\n");
		++y;
	}
}

void		print_board(t_fl *fl)
{
	printf("plr_letter - %c\n", fl->plr_letter);
	printf("size_board %d %d\n", fl->size_board.y, fl->size_board.x);
	printf("place %d %d\n", fl->place.y, fl->place.x);
	while (fl->n_piece--)
	{
		fl->board[fl->piece->y + fl->place.y][fl->piece->x + fl->place.x] = fl->plr_letter;
		++fl->piece;
	}
	while(*fl->board)
	{
		ft_putendl(*fl->board);
		++fl->board;
	}
}

void		print_piece(t_fl *fl)
{
	printf("size_piece %d %d\n", fl->size_piece.y, fl->size_piece.x);
	printf("n_piece = %d\n", fl->n_piece);
	while(fl->n_piece--)
	{
		printf("y = %d x = %d\n", fl->piece->y, fl->piece->x);
		++fl->piece;
	}
}

void		filler()
{
	t_fl	*fl;
	char	b[1];

	fl = (t_fl *)malloc(sizeof(t_fl));
	fl->plr_letter = 0;
	// fd = open("testmap", O_RDONLY); //! delete after
	fd = FL_FD;
	while (1)
	{
		if (read(0, b, 1))
		{
			read_board(fl);
			heat_map(fl);
			sort(fl);
			printf("%d %d\n", fl->place.y, fl->place.x);
			// write(1, "8 2\n", 4);
		}
	}
	// sleep(1);
	// print_board(fl);
	// print_heatmap(fl);
	// print_piece(fl);
}

int			main()
{
	filler();
	return (0);
}
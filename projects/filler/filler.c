/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:56:19 by cormund           #+#    #+#             */
/*   Updated: 2019/08/15 13:34:17 by cormund          ###   ########.fr       */
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
	int y;

	printf("plr_letter - %c\n", fl->plr);
	printf("size_board %d %d\n", fl->size_board.y, fl->size_board.x);
	printf("place %d %d\n", fl->place.y, fl->place.x);
	while (fl->n_piece--)
	{
		fl->board[fl->piece->y + fl->place.y][fl->piece->x + fl->place.x] = fl->plr;
		++fl->piece;
	}
	y = 0;
	while(fl->board[y])
	{
		ft_putendl(fl->board[y]);
		++y;
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
	fl->plr = 0;
	// fd = open("testmap", O_RDONLY);
	fd = FL_FD;
	while (1)
	{
		if (read(fd, b, 1))
		{
			fl->fl_exit = 1;
			read_board(fl);
			heat_map(fl);
			// print_heatmap(fl);
			sort(fl);
			// print_board(fl);
			ft_printf("%d %d\n", fl->place.y, fl->place.x);
			if (fl->fl_exit)
				exit(0);
		}
	}

//			printf("HERE\n");
	// print_piece(fl);
}

int			main()
{
	filler();
	return (0);
}
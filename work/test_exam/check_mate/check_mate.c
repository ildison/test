/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:11:00 by cormund           #+#    #+#             */
/*   Updated: 2019/08/02 22:33:41 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define	SUC "Success\n"
#define FAIL "Fail\n"
#define ERR "Error\n"

#define size_control(i, j, size) (i >= 0 && j >= 0 && i < size && j < size)

int			strl(char *s)
{
	char	*s2;

	s2 = s;
	while (*s2)
		++s2;
	return (s2 - s);
}

int			validation(int n, char **board)
{
	int		size;
	int		king;
	int		i;

	size = n;
	if (!n)
		return (write(1, "\n", 1));
	king = 0;
	while(n--)
	{
		if (strl(board[n]) != size)
			return (write(1, ERR, strl(ERR)));
		i = 0;
		while (board[n][i])
		{
			if (board[n][i] == 'K')
				++king;
			++i;
		}
	}
	return(king == 1 ? 0 : write(1, ERR, strl(ERR)));
}

int			pawn(int i, int j, int size, char **board)
{
	if ((size_control(i + 1, j - 1, size) && board[i + 1][j - 1] == 'P') ||\
			(size_control(i + 1, j + 1, size) && board[i + 1][j + 1] == 'P'))
		return(1);
	else
		return(0);
}

int			diagonals(int i, int j, int sz, char **brd)
{
	int		k;

	k = 0;
	while (size_control(i + k, j - k, sz) && brd[i + k][j - k] != 'P' && brd[i + k][j - k] != 'R')
	{
		if (brd[i + k][j - k] == 'Q' || brd[i + k][j - k] == 'B')
			return (1);
		++k;
	}
	k = 0;
	while (size_control(i + k, j + k, sz) && brd[i + k][j + k] != 'P' && brd[i + k][j + k] != 'R')
	{
		if (brd[i + k][j + k] == 'Q' || brd[i + k][j + k] == 'B')
			return (1);
		++k;
	}
	k = 0;
	while (size_control(i - k, j - k, sz) && brd[i - k][j - k] != 'P' && brd[i - k][j - k] != 'R')
	{
		if (brd[i - k][j - k] == 'Q' || brd[i - k][j - k] == 'B')
			return (1);
		++k;
	}
	k = 0;
	while (size_control(i - k, j + k, sz) && brd[i - k][j + k] != 'P' && brd[i - k][j + k] != 'R')
	{
		if (brd[i - k][j + k] == 'Q' || brd[i - k][j + k] == 'B')
			return (1);
		++k;
	}
	return (0);
}

int			cross(int i, int j, int sz, char **brd)
{
	int		k;

	k = 0;
	while (size_control(i + k, j, sz) && brd[i + k][j] != 'P' && brd[i + k][j] != 'B')
	{
		if (brd[i + k][j] == 'Q' || brd[i + k][j] == 'R')
			return (1);
		++k;
	}
	k = 0;
	while (size_control(i, j + k, sz) && brd[i][j + k] != 'P' && brd[i][j + k] != 'B')
	{
		if (brd[i][j + k] == 'Q' || brd[i][j + k] == 'R')
			return (1);
		++k;
	}
	k = 0;
	while (size_control(i - k, j, sz) && brd[i - k][j] != 'P' && brd[i - k][j] != 'B')
	{
		if (brd[i - k][j] == 'Q' || brd[i - k][j] == 'R')
			return (1);
		++k;
	}
	k = 0;
	while (size_control(i, j - k, sz) && brd[i][j - k] != 'P' && brd[i][j - k] != 'B')
	{
		if (brd[i][j - k] == 'Q' || brd[i][j - k] == 'R')
			return (1);
		++k;
	}
	return (0);
}

void		check_position(int i, int j, int size, char **board)
{
	if (pawn(i, j, size, board) || diagonals(i, j, size, board) || cross(i, j, size, board))
		write(1, SUC, strl(SUC));
	else
		write(1, FAIL, strl(FAIL));
}

void		capture(int size, char **board)
{
	int		i;
	int		j;

	i = 0;
	while (i != size)
	{
		j = 0;
		while (j != size)
		{
			if (board[i][j] == 'K')
			{
				check_position(i, j, size, board);
				return ;
			}
			++j;
		}
		++i;
	}
}

void		check_mate(int size, char **board)
{
	if (!validation(size, board))
		capture(size, board);
}

int			main(int ac, char **av)
{
	check_mate(ac - 1, av + 1);
	return(0);
}
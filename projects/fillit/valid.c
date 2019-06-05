/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:04:06 by cormund           #+#    #+#             */
/*   Updated: 2019/05/21 14:50:53 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** проверка на валидность фигуры
*/

int			ft_tetrim(char **tetrim, size_t x, size_t y)
{
	if (x > 3 || y > 3 || tetrim[y][x] != '#')
		return (0);
	else
		tetrim[y][x] = '*';
	return (1 + ft_tetrim(tetrim, x - 1, y) + ft_tetrim(tetrim, x, y - 1)
			+ ft_tetrim(tetrim, x + 1, y) + ft_tetrim(tetrim, x, y + 1));
}

/*
** подготовка для проверки фигуры. записываем входную строку
** в 2мерный массив и ищем начальную координату #
*/

int			ft_valid_tetrimino(char *pole)
{
	char	**tetrim;
	int		n_tet;
	int		x;
	int		y;

	if (!(tetrim = ft_strsplit(pole, '\n')))
		return (0);
	y = 0;
	while (y != 4)
	{
		x = 0;
		while (tetrim[y][x] != '#' && tetrim[y][x])
			x++;
		if (tetrim[y][x] == '#')
			break ;
		y++;
	}
	n_tet = ft_tetrim(tetrim, x, y);
	while (*tetrim)
		free(*tetrim++);
	free(tetrim - 4);
	if (n_tet == 4)
		return (1);
	return (0);
}

/*
** проверяем на валидность входное поле
*/

int			ft_valid_input(char *pole)
{
	int		n_block;
	int		i;

	i = 1;
	n_block = 0;
	while (*pole)
	{
		if ((i % 5 == 0 || i == 21) && i != 1)
		{
			if (*pole != '\n')
				return (0);
		}
		else if (*pole != '.' && *pole != '#')
			return (0);
		if (*pole == '#')
			++n_block;
		++pole;
		++i;
	}
	if (n_block == 4)
		return (1);
	return (0);
}

int			ft_valid(char *file)
{
	ssize_t	fd;
	ssize_t	n_byte;
	char	*buf;
	int		n;

	n = 0;
	if ((buf = ft_strnew(21)) &&
	(fd = open(file, O_RDONLY)) != -1)
		while ((n_byte = read(fd, buf, 21)) >= 0)
		{
			buf[n_byte] = '\0';
			if (n_byte < 20 || ++n == 27 || !ft_valid_input(buf) ||
			!ft_valid_tetrimino(buf))
				break ;
			if (n_byte == 20)
			{
				free(buf);
				close(fd);
				return (1);
			}
		}
	ft_putendl("error");
	exit(1);
}

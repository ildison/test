/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:33:38 by cormund           #+#    #+#             */
/*   Updated: 2019/06/04 13:37:16 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** len of number use for step - *(s+len)
*/

int			ft_nbrlen(int n)
{
	int		l;

	l = 0;
	if (n <= 0)
		++l;
	while (n)
	{
		++l;
		n /= 10;
	}
	return (l);
}

/*
** take nbr from string
*/

void		ft_getnbr(char *s, int *d)
{
	while (*s)
	{
		while (*s && *s == ' ')
			s++;
		if (*s)
		{
			*d = ft_atoi(s);
			s += ft_nbrlen(*d++);
		}
	}
}

/*
** write all altitude in int mas_pnt
*/

t_f			*ft_get_coor(char *s, t_f *f)
{
	size_t	i;

	f->pnt =(t_pnt *)malloc(f->height * f->width * sizeof(t_pnt));
	if (f->pnt == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == ' ')
			s++;
		if (*s)
		{
			f->pnt[i].z = ft_atoi(s);
			f->pnt[i].x = i % f->width;
			f->pnt[i].y = i / f->width;
			s += ft_nbrlen(f->pnt[i].z);
			++i;
		}
	}
	return (f);
}

/*
** count nbrs in string
*/

size_t		ft_count_nbrs(char const *s, char c)
{
	size_t	count_nbrs;
	int		check_in;

	count_nbrs = 0;
	check_in = 0;
	while (*s)
	{
		if (*s == c)
			check_in = 0;
		else if (check_in == 0)
		{
			count_nbrs++;
			check_in = 1;
		}
		s++;
	}
	return (count_nbrs);
}

/*
** read map with gnl
*/

t_f			*ft_read_map(char *file)
{
	ssize_t	fd;
	char	*line;
	t_f		*f;
	char	*mas;
	char	*tmp;

	f = (t_f*)malloc(sizeof(t_f));
	f->height = 0;
	f->width = 0;
	if (!(mas = ft_strnew(0)))
		return (NULL);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		++f->height;
		if (!f->width)
			f->width = ft_count_nbrs(line, ' ');
		else if (f->width != ft_count_nbrs(line, ' '))
			error();
		tmp = ft_strnew(ft_strlen(mas) + ft_strlen(line) + 1);
		ft_strcat(ft_strcat(ft_strcpy(tmp, mas), " "), line);
		free(line);
		free(mas);
		mas = tmp;
	}
	return (ft_get_coor(mas, f));
}

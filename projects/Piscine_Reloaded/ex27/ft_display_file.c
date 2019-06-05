/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:34:05 by cormund           #+#    #+#             */
/*   Updated: 2019/04/05 12:30:43 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void		ft_errors(char *str)
{
	int l;

	l = 0;
	while (str[l] != '\0')
		l++;
	write(2, str, l);
}

void		ft_putstr(char *str)
{
	int l;

	l = 0;
	while (str[l] != '\0')
		l++;
	write(1, str, l);
}

int			main(int ac, char **av)
{
	int		fd;
	char	buf[BUF + 1];
	int		n;

	if (ac == 1)
		ft_errors("File name missing.\n");
	else if (ac > 2)
		ft_errors("Too many arguments.\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd != -1)
		{
			while ((n = read(fd, buf, BUF)) > 0)
			{
				buf[n] = '\0';
				ft_putstr(buf);
			}
			close(fd);
		}
		else
			ft_errors("not open file.\n");
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:39:44 by cormund           #+#    #+#             */
/*   Updated: 2019/08/02 18:16:52 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define USAGE		"options: abcdefghijklmnopqrstuvwxyz\n"
#define INVALID		"Invalid Option\n"
#define	ALPHABET	"abcdefghijklmnopqrstuvwxyz"

static int	strl(char *s)
{
	char	*s2;

	s2 = s;
	while (*s2)
		++s2;
	return(s2 - s);
}

int			ft_bit_shift(char c)
{
	int		bit_shift;

	bit_shift = 0;
	while (ALPHABET[bit_shift] && c != ALPHABET[bit_shift])
		++bit_shift;
	return (bit_shift);
}

int			collect_bits(int *bytes, int n, char **opt)
{
	int		bit_shift;
	int		i;
	while (n--)
	{
		i = 0;
		while (opt[n][i])
		{
			if (opt[n][0] != '-')
				return(write(1, INVALID, strl(INVALID)));
			if (!i)
				++i;
			if (opt[n][i] == 'h')
				return(write(1, USAGE, strl(USAGE)));
			if ((bit_shift = ft_bit_shift(opt[n][i])) == 26)
				return(write(1, INVALID, strl(INVALID)));
			*bytes |= (1 << bit_shift);
			++i;
		}
		if (!i)
			return(write(1, USAGE, strl(USAGE)));
	}
	return (0);
}

void		print_bits(int bytes)
{
	int		bit_shift;

	bit_shift = 32;
	while (bit_shift--)
	{
		write(1, bytes & (1 << bit_shift) ? "1" : "0", 1);
		if (!(bit_shift % 8) && bit_shift)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

void		options(int n, char **opt)
{
	int		bytes;

	bytes = 0;
	if (!collect_bits(&bytes, n, opt))
		print_bits(bytes);
}

int			main(int ac, char **av)
{
	if (ac > 1)
		options(ac - 1, av + 1);
	else
		write(1, USAGE, strl(USAGE));
	return (0);
}

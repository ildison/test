/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:48:52 by cormund           #+#    #+#             */
/*   Updated: 2019/04/14 13:28:42 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		my_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

int		sort_p(char *str, int c, char **av, int i)
{
	int ks;
	int j;

	ks = 0;
	j = 1;
	while (j < c)
	{
		if (my_strcmp(str, av[j]) > 0)
			ks++;
		if (my_strcmp(str, av[j]) == 0 && j < i)
			ks++;
		j++;
	}
	return (ks);
}

void	print_sort_params(int c, char **av)
{
	int j;
	int i;
	int k;

	j = 1;
	k = 0;
	while (k < (c - 1))
	{
		if (sort_p(av[j], c, av, j) != k)
			j++;
		else
		{
			i = 0;
			while (av[j][i] != '\0')
			{
				ft_putchar(av[j][i]);
				i++;
			}
			ft_putchar('\n');
			k++;
			j = 1;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		print_sort_params(ac, av);
	}
	return (0);
}

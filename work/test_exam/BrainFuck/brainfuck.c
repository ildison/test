/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:38:41 by cormund           #+#    #+#             */
/*   Updated: 2019/07/31 17:08:05 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE_BF 2048

char		*skip_loop(char *operator)
{
	int		open_bracket;

	open_bracket = 0;
	while (*operator != ']' || open_bracket)
	{
		if (*operator == '[')
			++open_bracket;
		else if (*operator == ']')
			--open_bracket;
		++operator;
	}
	return (operator);
}

int			interpretation(char *operator, char *bf)
{
	while (*operator)
	{
		if (*operator == '+')
			++(*bf);
		else if (*operator == '-')
			--(*bf);
		else if (*operator == '>')
			++bf;
		else if (*operator == '<')
			--bf;
		else if (*operator == ']')
			return (*bf);
		else if (*operator == '[')
		{
			if (*bf)
				while (interpretation(operator + 1, bf))
					;
			operator = skip_loop(operator + 1);
		}
		else if (*operator == '.')
			write(1, bf, 1);
		++operator;
	}
	return (0);
}

void		brainfuck(char *operator)
{
	char 	*bf;
	int		i;

	i = 0;
	bf = (char *)malloc(SIZE_BF);
	while (i < SIZE_BF)
		bf[i++] = 0;
	interpretation(operator, bf);
}

int			main(int ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
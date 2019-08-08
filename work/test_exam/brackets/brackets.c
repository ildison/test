/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 10:16:57 by cormund           #+#    #+#             */
/*   Updated: 2019/08/08 15:01:52 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define is_open_b(b) (b == '(' || b == '{' || b == '[')
#define is_close_b(b) (b == ')' || b == '}' || b == ']')
#define is_b(b) (is_open_b(b) || is_close_b(b))

int			strl(char *s)
{
	char	*s2;

	s2 = s;
	while(*s)
		++s;
	return (s - s2);
}

void		puts(char *s)
{
	write(1, s, strl(s));
}

char		ret_close_b(char b)
{
	if (b == '(')
		return (')');
	if (b == '{')
		return ('}');
	return (']');
}

int			rec_b(char *b, char close_b)
{
	int		skip;
	char	next_close_b;
	int		ret;

	if (!*b)
		return (0);
	skip = 0;
	while(*b)
	{
		++skip;
		if (is_close_b(*b) && *b == close_b)
			return(skip);
		else if (is_open_b(*b) && (ret = rec_b(b + 1, ret_close_b(*b))))
		{
			skip += ret;
			b += ret;
		}
		else if (is_b(*b))
			return (0);
		++b;
	}
	return (0);
}

void		brackets(int ac, char **av)
{
	int		ret;
	char	*b;

	while (ac--)
	{
		b = *av++;
		while (*b)
		{
			if (is_open_b(*b) && (ret = rec_b(b + 1, ret_close_b(*b))))
				b += ret;
			else if (is_b(*b))
			{
				puts("Error\n");
				break ;
			}
			++b;
		}
		if (!*b)
			puts("OK\n");
	}
}

int			main(int ac, char **av)
{
	if (ac > 1)
		brackets(ac - 1, av + 1);
	else
		puts("\n");
	return (0);
}
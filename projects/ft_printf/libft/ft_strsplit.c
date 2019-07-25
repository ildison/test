/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 07:22:29 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/23 11:25:23 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void		ft_free_mem(char **p_str, size_t size_free)
{
	size_t i;

	i = 0;
	while (i < size_free)
	{
		ft_strdel(&p_str[i]);
		++i;
	}
	free(p_str);
}

static void		ft_numbers_of_lines(char const *str, int n, size_t *sum)
{
	*sum = 0;
	while (*str)
	{
		while (*str == n)
			str++;
		if (*str != '\0' && *str != n)
			(*sum)++;
		while (*str != '\0' && *str != n)
			str++;
	}
}

static void		ft_input_str(char const *s, char **p_str, char c, size_t sum)
{
	size_t		len;
	size_t		i;
	size_t		j;
	char const	*beg_line;

	j = 0;
	i = 0;
	while (j++ < sum && *s)
	{
		len = 0;
		while (*s == c)
			s++;
		beg_line = s;
		len = ft_strnlen(s, c);
		s += len;
		p_str[i] = ft_strnew(len);
		if (!(p_str[i]))
		{
			ft_free_mem(p_str, i);
			p_str = NULL;
			return ;
		}
		ft_strncpy(p_str[i++], beg_line, len);
	}
	p_str[i] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char		**p_str;
	size_t		sum;

	p_str = NULL;
	if (s)
	{
		ft_numbers_of_lines(s, c, &sum);
		if (!(p_str = (char **)malloc((sum + 1) * sizeof(char *))))
			return (NULL);
		ft_input_str(s, p_str, c, sum);
	}
	return (p_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 18:12:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/05 11:27:33 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

static char			check_opt(const char argv, const char *stringopt)
{
	if (argv)
		return (ft_strchr(stringopt, argv) ? argv : '?');
	else
		return (0);
}

int					ft_getopt_internal(int argc,
char *const argv[], const char *stringopt)
{
	static t_opt	opt;

	while (opt.index < argc)
	{
		if (argv[opt.index][opt.jindex] == '-' || opt.opt)
		{
			++opt.jindex;
			opt.opt = check_opt(argv[opt.index][opt.jindex], stringopt);
			if (!opt.opt)
				continue;
			return (opt.opt);
		}
		else
		{
			++opt.index;
			opt.jindex = 0;
			opt.opt = 0;
		}
	}
	return (-1);
}

static int			check_opt_on_val(const char *stringopt,
int opt, char *const argv[], int argc)
{
	static	int		flag;
	int				index;

	index = 1;
	stringopt = ft_strchr(stringopt, opt);
	if (*(stringopt + 1) == ':')
	{
		if (flag)
			return (opt);
		while (index < argc)
		{
			if (argv[index][0] != '-')
			{
				flag = 1;
				return (opt);
			}
			++index;
		}
		opt = '?';
	}
	return (opt);
}

int					ft_getopt(int argc,
char *const argv[], const char *stringopt)
{
	int				opt;
	char			*p_stringopt;

	opt = -1;
	if (argc > 1)
	{
		p_stringopt = (char *)stringopt;
		p_stringopt = ft_skipfirst(p_stringopt, ':');
		opt = ft_getopt_internal(argc, argv, stringopt);
		if (opt != -1 && opt != '?')
			opt = check_opt_on_val(p_stringopt, opt, argv, argc);
	}
	return (opt);
}

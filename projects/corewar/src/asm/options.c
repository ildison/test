/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:29:39 by cormund           #+#    #+#             */
/*   Updated: 2020/01/17 12:39:02 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		asm_usage(void)
{
	ft_printf("Usage: asm [-dh] [file]\n\
	-h Show help for all options\n\
	-d Dissamble file.cor\n");
	exit(-1);
}

static void		parse_options(char *options, char *flag)
{
	while (*options)
	{
		if (*options == ASM_DISASM_OPTION)
			*flag |= ASM_ON_DISSASM_OPTION;
		else if (*options == ASM_HELP_OPTION)
			asm_usage();
		else
			asm_usage();
		++options;
	}
}

void			check_options(int argc, char **argv, char *flag)
{
	int			i;

	if (!argc)
		asm_usage();
	i = 0;
	while (i < argc)
	{
		if (*argv[i] == '-')
			parse_options(argv[i] + 1, flag);
		++i;
	}
}

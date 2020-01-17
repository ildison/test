/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:20:12 by cormund           #+#    #+#             */
/*   Updated: 2020/01/17 10:40:35 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*new_filename(char *file, char flag)
{
	char		*new;
	int			len_file;

	flag &= ASM_ON_DISSASM_OPTION;
	len_file = ft_strlen(file);
	new = ft_strnew(len_file + (flag ? -2 : 2));
	if (!new)
		error(strerror(errno));
	ft_strncpy(new, file, len_file - (flag ? 3 : 1));
	ft_strcat(new, flag ? "s" : "cor");
	return (new);
}

static void		check_filename(char *file, char flag)
{
	int			len;

	len = ft_strlen(file);
	if (!(flag & ASM_ON_DISSASM_OPTION))
	{
		if (!len || file[len - 2] != '.' || file[len - 1] != 's')
			error(ASM_ERR_WRONG_FILENAME);
	}
	else if (!len || !ft_strstr(file, ".cor"))
		error(ASM_ERR_WRONG_FILENAME);
}

static void		check_files(int argc, char **argv, char flag)
{
	int			n_files;

	n_files = 0;
	while (argc > 0)
	{
		if (*argv[argc] != '-')
		{
			check_filename(argv[argc], flag);
			++n_files;
		}
		--argc;
	}
	if (!n_files)
		error("File not specified");
}

static t_champ	*init_champ(void)
{
	t_champ	*champ;

	champ = ft_memalloc(sizeof(t_champ));
	if (!champ)
		error(strerror(errno));
	return (champ);
}

int				main(int argc, char **argv)
{
	t_champ		*champ;
	char		flag;

	check_options(argc - 1, argv + 1, &flag);
	check_files(argc - 1, argv, flag);
	champ = init_champ();
	while (--argc > 0)
		if (*argv[argc] != '-')
		{
			champ->file_name = new_filename(argv[argc], flag);
			ASM_INPUT = read_data(argv[argc]);
			ASM_EOL = NULL;
			if (!(flag & ASM_ON_DISSASM_OPTION))
			{
				clean_comments(ASM_INPUT);
				parsing_champ(champ);
				translate_in_byte_code(champ);
			}
			else
				dissasembler(champ);
			ft_printf("Writing output program to %s\n", champ->file_name);
			clean_up(champ);
		}
	free(champ);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:20:12 by cormund           #+#    #+#             */
/*   Updated: 2020/01/15 15:28:29 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*new_filename(char *file)
{
	char	*new;
	int		len_file;

	len_file = ft_strlen(file);
	new = ft_strnew(len_file + 2);
	if (!new)
		error(strerror(errno));
	ft_strncpy(new, file, len_file - 1);
	ft_strcat(new, "cor");
	return (new);
}

static void	check_filename(char *file)
{
	int		len;

	len = ft_strlen(file);
	if (!len || file[len - 2] != '.' || file[len - 1] != 's')
		error("Wrong filename (need .s)");
}

static void	check_files(int argc, char **argv)
{
	int		n_files;

	n_files = 0;
	while (argc > 0)
	{
		if (*argv[argc] != '-')
		{
			check_filename(argv[argc]);
			++n_files;
		}
		--argc;
	}
	if (!n_files)
		error("File not specified");
}

int			main(int argc, char **argv)
{
	t_champ	*champ;
	char	flag;

	check_options(argc - 1, argv + 1, &flag);
	check_files(argc - 1, argv);
	champ = ft_memalloc(sizeof(t_champ));
	if (!champ)
		error(strerror(errno));
	while (--argc > 0)
		if (*argv[argc] != '-')
		{
			champ->file_name = new_filename(argv[argc]);
			ASM_INPUT = read_data(argv[argc]);
			ASM_EOL = NULL;
			clean_comments(ASM_INPUT);
			parsing_champ(champ);
			translate_in_byte_code(champ);
			ft_printf("Writing output program to %s\n", champ->file_name);
			clean_up(champ);
		}
	free(champ);
	return (0);
}

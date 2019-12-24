/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:06:28 by cormund           #+#    #+#             */
/*   Updated: 2019/12/24 10:54:42 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		clean_comments(char *input)
{
	int		in;

	in = 0;
	while (*input)
	{
		if (*input == '"')
			in ^= 1;
		if (!in && *input == '#')
			while (*input && *input != '\n')
				*input++ = ' ';
		++input;
	}
}

char		*read_input(char *file)
{
	char	buf[ASM_SIZE_BUF + 1];
	char	*input;
	char	*tmp;
	int		count_read;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == ASM_ERROR)
		error(NULL);
	input = ft_strnew(0);
	if (!input)
		error(strerror(errno));
	while((count_read = read(fd, buf, ASM_SIZE_BUF)) > 0)
	{
		buf[count_read] = ASM_END_OF_STR;
		tmp = input;
		if ((input = ft_strjoin(input, buf)) == 0)
			error(strerror(errno));
		free(tmp);
	}
	if (count_read == ASM_ERROR)
		error(strerror(errno));
	close(fd);
	return (input);
}

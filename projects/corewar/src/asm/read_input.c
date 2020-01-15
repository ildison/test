/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:06:28 by cormund           #+#    #+#             */
/*   Updated: 2020/01/15 09:05:52 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		clean_comments(char *data)
{
	int		in;

	in = 0;
	while (*data)
	{
		if (*data == '"')
			in ^= 1;
		if (!in && (*data == COMMENT_CHAR || *data == ALT_COMMENT_CHAR))
			while (*data && *data != '\n')
				*data++ = ' ';
		++data;
	}
}

char		*read_data(char *file)
{
	char	buf[ASM_SIZE_BUF + 1];
	char	*tmp;
	int		count_read;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == ASM_ERROR)
		error(strerror(errno));
	ASM_DATA = ft_strnew(0);
	if (!ASM_DATA)
		error(strerror(errno));
	while ((count_read = read(fd, buf, ASM_SIZE_BUF)) > 0)
	{
		buf[count_read] = ASM_END_OF_STR;
		tmp = ASM_DATA;
		if ((ASM_DATA = ft_strjoin(ASM_DATA, buf)) == 0)
			error(strerror(errno));
		free(tmp);
	}
	if (count_read == ASM_ERROR)
		error(strerror(errno));
	close(fd);
	return (ASM_DATA);
}

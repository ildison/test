/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:06:28 by cormund           #+#    #+#             */
/*   Updated: 2020/01/17 10:09:16 by cormund          ###   ########.fr       */
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
	int		n;

	if ((fd = open(file, O_RDONLY)) == ASM_ERROR)
		error(strerror(errno));
	if (!(ASM_DATA = ft_strnew(1)))
		error(strerror(errno));
	n = 0;
	while ((count_read = read(fd, buf, ASM_SIZE_BUF)) > 0)
	{
		buf[count_read] = ASM_END_OF_STR;
		tmp = ASM_DATA;
		ASM_DATA = ft_memnjoin(ASM_DATA, buf, ASM_SIZE_BUF * n, count_read + 1);
		if (!ASM_DATA)
			error(strerror(errno));
		free(tmp);
		++n;
	}
	if (count_read == ASM_ERROR)
		error(strerror(errno));
	close(fd);
	return (ASM_DATA);
}

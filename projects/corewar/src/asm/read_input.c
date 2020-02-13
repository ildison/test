/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:06:28 by cormund           #+#    #+#             */
/*   Updated: 2020/02/10 16:43:33 by cormund          ###   ########.fr       */
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

	if ((fd = open(file, O_RDONLY)) == ASM_ERROR ||\
						!(g_data.data = ft_strnew(1)))
		ERROR(strerror(errno));
	n = 0;
	while ((count_read = read(fd, buf, ASM_SIZE_BUF)) > 0)
	{
		buf[count_read] = ASM_END_OF_STR;
		tmp = g_data.data;
		g_data.data = ft_memnjoin(g_data.data, buf, ASM_SIZE_BUF * n,\
														count_read + 1);
		if (!g_data.data)
			ERROR(strerror(errno));
		free(tmp);
		++n;
	}
	if (count_read == ASM_ERROR)
		ERROR(strerror(errno));
	close(fd);
	return (g_data.data);
}

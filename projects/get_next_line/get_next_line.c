/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:59:54 by cormund           #+#    #+#             */
/*   Updated: 2019/05/07 18:39:48 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_lst		*lst_new(int fd)
{
	t_lst			*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new->str_line = ft_strnew(0);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

static char			**lst_find_or_add(t_lst **begin, int fd)
{
	t_lst			*lst;

	lst = *begin;
	if (!lst)
	{
		if (!(*begin = lst_new(fd)))
			return (NULL);
		return (&(*begin)->str_line);
	}
	while (lst->next && lst->fd != fd)
		lst = lst->next;
	if (fd == lst->fd)
		return (&lst->str_line);
	if (!(lst->next = lst_new(fd)))
		return (NULL);
	return (&lst->next->str_line);
}

static char			*ft_strcut(char *s, char c)
{
	char		*p;
	char		*fresh;

	if ((p = ft_strchr(s, c)))
		fresh = ft_strndup(s, p - s);
	else
		fresh = ft_strdup(s);
	return (fresh);
}

static void			ft_str_chr_clr(char *s, char c)
{
	char			*p;

	if ((p = ft_strchr(s, c)))
		ft_strcpy(s, p + 1);
	else
		ft_strclr(s);
}

int					get_next_line(const int fd, char **line)
{
	static t_lst	*lst_fd = NULL;
	char			*buf;
	char			**str_line;
	char			*tmp_free;
	int				n;

	if (line && (str_line = lst_find_or_add(&lst_fd, fd)) &&
			(buf = ft_strnew(BUFF_SIZE)))
		while ((n = read(fd, buf, BUFF_SIZE)) >= 0)
		{
			tmp_free = *str_line;
			*str_line = ft_strjoin(*str_line, buf);
			free(tmp_free);
			ft_bzero(buf, n);
			if (!ft_strchr(*str_line, '\n') && n == BUFF_SIZE)
				continue;
			free(buf);
			*line = ft_strcut(*str_line, '\n');
			if (n == 0 && !**str_line && !**line)
				return (0);
			ft_str_chr_clr(*str_line, '\n');
			return (1);
		}
	return (-1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:56:17 by cormund           #+#    #+#             */
/*   Updated: 2019/05/23 20:18:02 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100

# include "libft/libft.h"

typedef struct		s_lst
{
	int				fd;
	char			*str_line;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(const int fd, char **line);

#endif
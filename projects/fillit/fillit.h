/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:48:01 by cormund           #+#    #+#             */
/*   Updated: 2019/05/20 17:08:26 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct				s_coord
{
	char					chr;
	int						index;
	int						*tet;
	struct s_coord			*next;
}							t_coord;

int							ft_valid(char *file);
int							ft_read_input(char *file, t_coord **tet);
int							ft_sort(t_coord **beg, int n_tet);
void						ft_del_lst(t_coord **beg);

#endif

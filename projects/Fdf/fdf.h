/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:59:22 by cormund           #+#    #+#             */
/*   Updated: 2019/06/03 15:35:08 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h> // delete

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_pnt;

typedef struct		s_f
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	size_t			width;
	size_t			height;
	int				**coor;
	int				flag_color;
	int				x;
	int				y;
	struct s_point	*pnt;
}					t_f;

t_f					*ft_read_map(char *file);
void				ft_new_init(t_f *f);
void				error();

#endif

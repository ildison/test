/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:24:44 by cormund           #+#    #+#             */
/*   Updated: 2019/06/04 11:31:14 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_creat_pixel_image(t_f *f, t_pnt *pnt);

static void ft_iso(t_f *f, t_pnt *pnt)
{
	size_t	i;
    int previous_x;
    int previous_y;

	i = 0;
	while (i != f->width * f->height)
	{
    	previous_x = pnt[i].x;
    	previous_y = pnt[i].y;
  		pnt[i].x = (previous_x - previous_y) * cos(0.523599);
  		pnt[i].y = -pnt[i].z + (previous_x + previous_y) * sin(0.523599);
		++i;
	}
	ft_creat_pixel_image(f, f->pnt);
}

/*
** fun function for workind with keybutton
*/

int			key_release(int key, t_f *f)
{
	if (key == 49)
		f->flag_color = 0;
	return (0);
}

int			key_press(int key, t_f *f)
{
	int		color;

	color = 1215614;
	if (key == 49)
		f->flag_color = 1;
	if (key == 0)
		f->x -= 5;
	if (key == 13)
		f->y -= 5;
	if (key == 2)
		f->x += 5;
	if (key == 1)
		f->y += 5;
	if (key == 8)
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
	if (key == 53)
	{
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		exit (0);
	}
	if (key == 34)
	{
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		ft_iso(f, f->pnt);
	}
	if (f->flag_color == 1)
		color = (int)0x943126;
	mlx_pixel_put(f->mlx_ptr, f->win_ptr, f->x * 20, f->y * 20, color);
	return (0);
}

void		ft_creat_pixel_image(t_f *f, t_pnt *pnt)
{
	size_t	i;

	i = 0;
	while (i != f->width * f->height)
	{
		mlx_pixel_put(f->mlx_ptr, f->win_ptr, 255 + pnt[i].x * 20, 255 + pnt[i].y * 20, 0xAAFFFF);
		++i;
	}
}

void		ft_test(t_f *f, t_pnt *pnt)
{
	int		i;

	i = 0;
	while (i != f->width * f->height)
	{
		ft_putnbr(pnt[i].z);
		++i;
	}
}

/*
** function for working with server
*/

void		ft_new_init(t_f *f)
{
	f->x = 500;
	f->y = 500;
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, 1000, 1000, "PycTuK");
//	ft_test(f, f->pnt);
//	mlx_pixel_put(f->mlx_ptr, f->win_ptr, 255, 255, 0xAAFFFF);
	//mlx_key_hook(f->win_ptr, deal_key, &f);
	mlx_hook(f->win_ptr, 2, 0, key_press, f);
	mlx_hook(f->win_ptr, 3, 0, key_release, f);
//	f->img_ptr = mlx_new_image(f->mlx_ptr, 200, 200);
	//mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 40, 100);
//	ft_creat_pixel_image(f, f->pnt);
	mlx_loop(f->mlx_ptr);
}

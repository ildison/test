/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:46:50 by cormund           #+#    #+#             */
/*   Updated: 2019/05/20 16:10:52 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		n_tetrim;
	t_coord	*new_tet;

	new_tet = NULL;
	if (argc == 2)
	{
		ft_valid(argv[1]);
		n_tetrim = ft_read_input(argv[1], &new_tet);
		if (!ft_sort(&new_tet, n_tetrim))
		{
			ft_putendl("error");
			return (0);
		}
	}
	else
		ft_putendl("usage: ./fillit file");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:17:19 by cormund           #+#    #+#             */
/*   Updated: 2019/07/30 09:26:51 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_num(num)
{
	if (!num)
		return ;
	print_num(num - 1);
	printf("%d\n", num);
}

int		main(int ac, char **av)
{
	print_num(atoi(av[1]));
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:26:18 by cormund           #+#    #+#             */
/*   Updated: 2019/07/25 17:00:19 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void	fprime(int num)
{
	int		prm;

	prm = 2;
	if (num == 1)
		printf("1");
	while (num > 1)
	{
		while (num % prm)
			++prm;
		num /= prm;
		num != 1 ? printf("%d*", prm) : printf("%d", prm);
	}
}

int			main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}

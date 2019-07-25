/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:35:04 by ksharlen          #+#    #+#             */
/*   Updated: 2019/04/30 09:19:01 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_atoi(const char *s)
{
	unsigned long long int	res;
	int						sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
		if (*(s++) == '-')
			sign = -1;
	while (ft_isdigit(*s) && res <= MAXLONG / 10)
		res = res * 10 + (*(s++) - '0');
	if (sign == -1 && (res > MAXLONG || ft_isdigit(*s)))
		res = 0;
	else if (res > MAXLONG || ft_isdigit(*s))
		res = -1;
	return (res * sign);
}

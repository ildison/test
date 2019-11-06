/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:30:09 by cormund           #+#    #+#             */
/*   Updated: 2019/11/06 10:20:21 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

static void	validation_operation(char *oper)
{
	if (!ft_strstr(PS_OPERATIONS, oper))
	{
		printf("\n%s\n", oper);
		error(PS_ERROR_OPER);
	}
}

static void	application_operation(t_stack **a, t_stack **b, char *oper)
{
	if (ft_strequ(oper, "sa") || ft_strequ(oper, "sb"))
		*(oper + 1) == 'a' ? swap(a) : swap(b);
	else if (ft_strequ(oper, "ss"))
	{
		swap(a);
		swap(b);
	}
	else if (ft_strequ(oper, "pa") || ft_strequ(oper, "pb"))
		*(oper + 1) == 'a' ? push(a, b) : push(b, a);
	else if (ft_strequ(oper, "ra") || ft_strequ(oper, "rb"))
		*(oper + 1) == 'a' ? rotate(a) : rotate(b);
	else if (ft_strequ(oper, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strequ(oper, "rra") || ft_strequ(oper, "rrb"))
		*(oper + 2) == 'a' ? reverse(a) : reverse(b);
	else if (ft_strequ(oper, "rrr"))
	{
		reverse(a);
		reverse(b);
	}
}

char		*read_operations(t_checker *chkr, char flag_vis)
{
	char	*oper;

	while ((oper = gnl(PS_STDIN)))
	{
		validation_operation(oper);
		application_operation(&chkr->a, &chkr->b, oper);
		if (flag_vis)
			return (oper);
		free(oper);
	}
	return (NULL);
}

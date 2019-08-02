/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:44:20 by cormund           #+#    #+#             */
/*   Updated: 2019/08/02 15:29:14 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

t_rpn		*new_elem(int num, char oper)
{
	t_rpn	*fresh;

	if (!(fresh = (t_rpn *)malloc(sizeof(t_rpn))))
		error();
	fresh->oper = oper;
	fresh->num = num;
	fresh->prev = NULL;
	fresh->next = NULL;
	return(fresh);
}

void		add_elem_end_lst(t_rpn **beg, t_rpn *new_lst)
{
	t_rpn	*lst;

	lst = *beg;
	if (beg)
	{
		if (*beg)
		{
			while (lst->next)
				lst = lst->next;
			new_lst->prev = lst;
			lst->next = new_lst;
		}
		else
			(*beg) = new_lst;
	}
}

int		collect_elems(t_rpn **beg, char *av)
{
	t_rpn	*rpn;
	int		n_num;
	int		n_op;

	n_num = 0;
	n_op = 0;
	rpn = *beg;
	while (*av)
	{
		if ((is_oper(*av) && is_digit(*(av + 1))) || is_digit(*av))
		{
			rpn = new_elem(atoi(av), 0);
			++n_num;
		}
		else if (is_oper(*av))
		{
			rpn = new_elem(0, *av);
			++n_op;
		}
		add_elem_end_lst(beg, rpn);
		while (*av && *av++ != ' ')
			;
		rpn = rpn->next;
	}
	return (n_num - n_op);
}

int		operation(char op, int a, int b)
{
	if (op == '+')
		return(a + b);
	if (op == '-')
		return(a - b);
	if (op == '*')
		return(a * b);
	if (op == '/')
		return(a / b);
	return(a % b);
}

void		delete_lst(t_rpn **beg, t_rpn *rpn)
{
	if (rpn->prev->prev == *beg)
	{
		*beg = rpn;
		rpn->prev = NULL;
	}
	else
	{
		rpn->prev->prev->prev->next = rpn;
		rpn->prev = rpn->prev->prev->prev;
	}
}

void		calc(t_rpn **beg)
{
	t_rpn	*rpn;

	rpn = *beg;
	while (rpn)
	{
		if (rpn->oper && rpn->prev && rpn->prev->prev &&\
		((!rpn->prev->num && rpn->oper != '/' && rpn->oper != '%') || rpn->prev->num))
		{
			rpn->num = operation(rpn->oper, rpn->prev->num, rpn->prev->prev->num);
			delete_lst(beg, rpn);
		}
		else if (rpn->oper)
		{
			error();
			break;
		}
		rpn = rpn->next;
	}
}

void		print_cal(t_rpn *rpn)
{
	if (!rpn->next && !rpn->prev)
		printf("%d\n", rpn->num);
}

void		rpn_calc(char *av)
{
	t_rpn	*rpn;

	rpn = NULL;
	if (collect_elems(&rpn, av) == 1)
	{
		calc(&rpn);
		print_cal(rpn);
	}
	else
		error();
}


int			main(int ac, char **av)
{
	if (ac != 2)
		error();
	else
		rpn_calc(av[1]);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:44:20 by cormund           #+#    #+#             */
/*   Updated: 2019/08/01 18:56:19 by cormund          ###   ########.fr       */
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

void		collect_elems(t_rpn **beg, char *av)
{
	t_rpn	*rpn;

	rpn = *beg;
	while (*av)
	{
		while(*av == ' ')
			++av;
		if ((is_oper(*av) && is_digit(*(av + 1))) || is_digit(*av))
			rpn = new_elem(atoi(av), 0);
		else if (is_oper(*av))
			rpn = new_elem(0, *av);
		add_elem_end_lst(beg, rpn);
		while (*av && *av != ' ')
			++av;
		rpn = rpn->next;
	}
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

void		delete_lst(t_rpn *rpn1, t_rpn *rpn2)
{
	if (rpn2->prev)
		rpn2->prev->next = rpn1;
	rpn1->prev = rpn2->prev;
}

void		calc(t_rpn *rpn)
{
	while (rpn)
	{
		if (rpn->oper && rpn->prev && rpn->prev->prev)
		{
			if ((!rpn->num && rpn->oper != '/' && rpn->oper != '%') || rpn->num)
			{
				rpn->num = operation(rpn->oper, rpn->prev->num, rpn->prev->prev->num);
				delete_lst(rpn, rpn->prev->prev);
			}
			else
			{
				error();
				break;
			}
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
	collect_elems(&rpn, av);
	calc(rpn);
	print_cal(rpn);
}


int			main(int ac, char **av)
{
	if (ac != 2)
		error();
	else
		rpn_calc(av[1]);
	return (0);
}
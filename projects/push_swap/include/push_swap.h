/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:54:39 by cormund           #+#    #+#             */
/*   Updated: 2019/10/25 10:31:18 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ps_shared.h"

# define PS_FIRST_INDEX				1
# define PS_MAX_INDEX_IN_STACK_B	ps->sz_a - 3
# define PS_PREVIOUS_MAX			PS_MAX_INDEX_IN_STACK_B - 1
# define PS_MEDIAN					PS_MAX_INDEX_IN_STACK_B / 2
# define PS_COUNT_MIN_AT_BOTTOM		0
# define SIZE_A						ps->sz_a
# define SIZE_B						ps->sz_b
# define TOP_A						(*a)->i
# define SECOND_A					(*a)->next->i
# define TOP_B						(*b)->i
# define SECOND_B					(*b)->next->i
# define IS_OPER_OF_STACK_A			(op->next->oper[1] == 'a' || op->next->oper[2] == 'a')
# define IS_OPER_OF_STACK_B			(op->next->oper[1] == 'b' || op->next->oper[2] == 'b')

typedef struct		s_oper
{
	char			oper[4];
	struct s_oper	*next;
}					t_oper;

typedef struct		s_ps
{
	t_stack			*a;
	t_stack			*b;
	int				sz_a;
	int				sz_b;
	t_oper			*opers;
}					t_ps;

typedef struct		s_max_min
{
	int				max;
	int				pmax;
	int				min;
	int				mid;
}					t_max_min;

void				sort(t_ps *ps);
void				ps_swap(t_ps *ps, t_stack **top);
void				ps_push(t_ps *ps, t_stack **dst, t_stack **src);
void				ps_rotate(t_ps *ps, t_stack **top);
void				ps_reverse(t_ps *ps, t_stack **top);
void				sort_three_elem(t_ps *ps, t_stack **stk, int sz);
void				sort_first_hundred(t_ps *ps, t_stack **a, t_stack **b);
void				optimization_opers(t_oper *op);

# endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:54:39 by cormund           #+#    #+#             */
/*   Updated: 2019/11/05 15:44:12 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ps_shared.h"

# define PS_FIRST_INDEX				1
# define PS_SECOND_INDEX			2
# define PS_MAX_INDEX_IN_STACK_B	(ps->sz_a - 3)
# define PS_PREVIOUS_MAX_IN_STACK_B	(PS_MAX_INDEX_IN_STACK_B - 1)
# define PS_MEDIAN					PS_MAX_INDEX_IN_STACK_B / 2
# define PS_COUNT_MIN_AT_BOTTOM		0
# define STACK_A					&ps->a
# define STACK_B					&ps->b
# define STK_A						ps->a
# define STK_B						ps->b
# define SIZE_A						ps->sz_a
# define SIZE_B						ps->sz_b
# define TOP_A						ps->a->i
# define TOP_B						ps->b->i
# define SECOND_A					ps->a->next->i
# define SECOND_B					ps->b->next->i
# define LAST_A						ps->a->prev->i
# define LAST_B						ps->b->prev->i
# define PRELAST_A					ps->a->prev->prev->i
# define PRELAST_B					ps->b->prev->prev->i
# define A							'a'
# define B							'b'
# define IS_OPER_OF_STACK_A	(op->next->oper[1] == A || op->next->oper[2] == A)
# define IS_OPER_OF_STACK_B	(op->next->oper[1] == B || op->next->oper[2] == B)

# define IS_STACK_A(x)				STACK_A == x
# define IS_NEIGHBOURS(a, b)		(a - b) == 1
# define INCREMENT_MIN(m, pm)		++m && ++pm
# define DECREMENT_MAX(m, pm)		--m && --pm

typedef struct		s_oper
{
	char			oper[4];
	struct s_oper	*next;
	struct s_oper	*prev;
}					t_oper;

typedef struct		s_ps
{
	t_stack			*a;
	t_stack			*b;
	int				sz_a;
	int				sz_b;
	t_oper			*opers;
}					t_ps;

typedef struct		s_splitter
{
	int				split;
	int				min;
}					t_splitter;

typedef struct		s_max_min
{
	int				max;
	int				pmax;
	int				min;
	int				pmin;
}					t_max_min;

void				sort(t_ps *ps);
void				ps_swap(t_ps *ps, t_stack **top);
void				ps_push(t_ps *ps, t_stack **dst, t_stack **src);
void				ps_rotate(t_ps *ps, t_stack **top);
void				ps_reverse(t_ps *ps, t_stack **top);
void				sort_three_elem(t_ps *ps, t_stack **stk, int sz);
void				sort_first_hundred(t_ps *ps, t_splitter s, int max);
void				sort_five_hundred(t_ps *ps, t_stack **a, t_stack **b,\
																int size);
void				optimization_opers(t_oper *op);

#endif

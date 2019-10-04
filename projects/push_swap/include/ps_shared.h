/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_shared.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:55:15 by cormund           #+#    #+#             */
/*   Updated: 2019/10/04 18:57:39 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SHARED_H
# define PS_SHARED_H

# include "libft.h"

# define PS_ERROR "Error\n"
# define PS_ERROR_OPER "Error: unvalid operation\n"
# define PS_ERROR_MALLOC "Error: malloc\n"
# define PS_FIRST_INDEX 1
# define PS_MAX_INDEX_IN_STACK_B ps->sz_a - 3
# define PS_PREVIOUS_MAX PS_MAX_INDEX_IN_STACK_B - 1
# define PS_COUNT_MIN_AT_BOTTOM 0

# define VISUAL_FLAG 1

typedef struct		s_stack
{
	int				num;
	int				i;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				error(char *error);
void				read_arg(t_stack **a, int n_arg, char **arg, char *flags);
void				add_int_to_stack(t_stack **a, int num);
int					swap(t_stack **top);
int					push(t_stack **dst, t_stack **src);
int					rotate(t_stack **top);
int					reverse(t_stack **top);
int					check_sorted(t_stack *a, t_stack *b, int sz);
int					size_stack(t_stack *s);
void				indexation(t_stack *stk, int size);

# endif
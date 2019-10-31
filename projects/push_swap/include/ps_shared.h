/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_shared.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:55:15 by cormund           #+#    #+#             */
/*   Updated: 2019/10/31 13:30:57 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SHARED_H
# define PS_SHARED_H

# include "libft.h"

# define PS_ERROR "Error\n"
# define PS_ERROR_OPER "Error: unvalid operation\n"
# define PS_ERROR_MALLOC "Error: malloc\n"

# define PS_OPERATIONS "sa/sb/ss/pa/pb/ra/rb/rr/rra/rrb/rrr"
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
# define VISUAL_FLAG 1

typedef struct		s_stack
{
	int				num;
	int				i;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				error(const char *error);
void				read_arg(t_stack **a, int n_arg, char **arg, char *flags);
void				add_int_to_stack(t_stack **a, int num);
int					swap(t_stack **top);
int					push(t_stack **dst, t_stack **src);
int					rotate(t_stack **top);
int					reverse(t_stack **top);
int					check_sorted(t_stack *a, t_stack *b, int sz);
int					check_des_sorted(t_stack *a, t_stack *b, int sz);
int					size_stack(t_stack *s);
void				indexation(t_stack *stk, int size);

# endif
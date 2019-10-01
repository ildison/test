/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_shared.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:55:15 by cormund           #+#    #+#             */
/*   Updated: 2019/10/01 13:03:37 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SHARED_H
# define PS_SHARED_H

# include "libft.h"

# define PS_ERROR "Error\n"
# define PS_ERROR_OPER "Error: unvalid operation\n"
# define PS_ERROR_MALLOC "Error: malloc\n"

# define VISUAL_FLAG 1

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				error(char *error);
void				read_arg(t_stack **a, int n_arg, char **arg, char *flags);
void				swap(t_stack **top);
void				push(t_stack **dst, t_stack **src);
void				rotate(t_stack **top);
void				reverse(t_stack **top);

# endif
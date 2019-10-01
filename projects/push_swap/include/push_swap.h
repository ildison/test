/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:54:39 by cormund           #+#    #+#             */
/*   Updated: 2019/10/01 16:46:41 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ps_shared.h"

typedef struct		s_oper
{
	char			oper[4];
	struct s_oper	*next;
}					t_oper;

typedef struct		s_ps
{
	t_stack			*a;
	t_stack			*b;
	t_oper			**opers;
}					t_ps;

# endif
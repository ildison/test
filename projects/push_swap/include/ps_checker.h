/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 14:30:32 by cormund           #+#    #+#             */
/*   Updated: 2019/10/06 20:38:05 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHECKER_H
# define PS_CHECKER_H

# include "ps_shared.h"

# define PS_STDIN 0

# define PS_OK ft_printf("OK\n")
# define PS_KO ft_printf("KO\n")

typedef struct	s_checker
{
	t_stack		*a;
	t_stack		*b;
	char		flags;
}				t_checker;

void			read_operations(t_checker *chkr);

# endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 14:30:32 by cormund           #+#    #+#             */
/*   Updated: 2019/11/05 15:44:18 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CHECKER_H
# define PS_CHECKER_H

# include "ps_shared.h"

# define PS_STDIN 0
# define VISUALIZATION_MODE (chkr->flags & VISUAL_FLAG) && chkr->a

# define PS_OK ft_printf("OK\n")
# define PS_KO ft_printf("KO\n")

typedef struct	s_checker
{
	t_stack		*a;
	t_stack		*b;
	char		flags;
}				t_checker;

void			visualiser(t_checker *chkr);
char			*read_operations(t_checker *chkr, char flag_vis);

#endif

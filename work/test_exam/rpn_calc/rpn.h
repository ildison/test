/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:52:41 by cormund           #+#    #+#             */
/*   Updated: 2019/08/01 18:42:54 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include <stdio.h>
#include <stdlib.h>

#define error()		printf("Error\n")
#define is_digit(a)	(a >= 48 && a <= 57)
#define is_oper(a)	(a == 37 || a == 42 || a == 43 || a == 45 || a == 47)

typedef struct		s_rpn
{
	int				num;
	char			oper;
	struct s_rpn	*prev;
	struct s_rpn	*next;
}					t_rpn;


#endif
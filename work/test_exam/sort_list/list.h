/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:44:48 by cormund           #+#    #+#             */
/*   Updated: 2019/07/30 14:26:43 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

int					ascending(int a, int b)
{
	return (a <= b);
}

typedef struct		s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

t_list				*sort_list(t_list* lst, int (*cmp)(int, int));

#endif
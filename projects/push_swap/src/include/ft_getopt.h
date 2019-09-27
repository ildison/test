/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 18:12:23 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/05 11:28:18 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

# include "libft.h"

typedef struct	s_opt
{
	int			index;
	size_t		jindex;
	char		opt;
}				t_opt;

int				ft_getopt_internal(int argc,
	char *const argv[], const char *stringopt);
int				ft_getopt(int argc, char *const argv[], const char *stringopt);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:54:56 by cormund           #+#    #+#             */
/*   Updated: 2019/09/30 19:27:23 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_shared.h"

void			error(char *error)
{
	if (error)
		write(1, error, ft_strlen(error));
	exit(-1);
}

void		valid_correctly_format(char *s, int *num_int)
{
	char	*num_alph;

	*num_int = ft_atoi(s);
	num_alph = ft_itoa(*num_int);
	if (*num_alph == '-' || *num_alph == '0')
		++num_alph;
	if (*s == '-' || *s == '+')
		++s;
	if (!*s)
		error(ERROR);
	while (*s && *s == '0')
		++s;
	if (!ft_strequ(s, num_alph))
		error(ERROR);
}

void		check_dublicate(t_stack **a, int num)
{
	t_stack	*lst;

	lst = *a;
	if (lst)
	{
		if (lst->num == num)
			error(ERROR);
		while ((lst = lst->next) != *a)
			if (lst->num == num)
				error(ERROR);
	}
}

void		add_int_to_stack(t_stack **a, int num)
{
	t_stack	*lst;

	lst = *a;
	if (!lst)
	{
		if (!(*a = (t_stack *)ft_memalloc(sizeof(t_stack))))
			error(ERROR_MALLOC);
		(*a)->num = num;
		(*a)->next = (*a);
	}
	else
	{
		while (lst->next != *a)
			lst = lst->next;
		if (!(lst->next = (t_stack *)ft_memalloc(sizeof(t_stack))))
			error(ERROR_MALLOC);
		lst->next->num = num;
		lst->next->next = *a;
		lst->next->prev = lst;
		(*a)->prev = lst->next;
	}
}

int			parsing_flag(char *s, char *flags)
{
	char	flag_collector;

	if (*s == '-')
		++s;
	else
		return(0);
	if (ft_isdigit(*s))
		return(0);
	flag_collector = 0;
	while (*s)
	{
		if (*s == 'v')
			flag_collector |= VISUAL_FLAG;
		else
			error(ERROR);
		++s;
	}
	*flags |= flag_collector;
	return (1);
}

void		validation_and_create_stack(t_stack **a, char **mas, char *flags)
{
	int		num;

	while (*mas)
	{
		if (!flags || !parsing_flag(*mas, flags))
		{
			valid_correctly_format(*mas, &num);
			check_dublicate(a, num);
			add_int_to_stack(a, num);
		}
		++mas;
	}
}

void		read_arg(t_stack **a, int n_arg, char **arg, char *flags)
{
	char	**mas;

	while (n_arg)
	{
		mas = ft_strsplit(*arg, ' ');
		validation_and_create_stack(a, mas, flags);
		ft_free_2x_mas((void **)mas);
		--n_arg;
		++arg;
	}
}
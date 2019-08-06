/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormund <cormund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:07:31 by cormund           #+#    #+#             */
/*   Updated: 2019/08/06 14:11:54 by cormund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define is_print(a) (a > 31 && a < 127)

void				ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void				print_hex(unsigned char byte)
{
	char			hex[16] = "0123456789abcdef";

	ft_putchar(*(hex + byte / 16 % 16));
	ft_putchar(*(hex + byte % 16));
}

void				print_space(int count_space)
{
	while (count_space--)
		ft_putchar(' ');
}

void				print_ascii(unsigned char *bytes, int i)
{
	int				index;

	index = 0;
	if (!i)
		i = 16;
	else
		print_space((16 - i) / 2 * 5);
	while (index != i)
	{
		if (is_print(*(bytes + index)))
			ft_putchar(*(bytes + index));
		else
			ft_putchar('.');
		++index;
	}
	ft_putchar('\n');
}
void				print_memory(void *addr, size_t size)
{
	unsigned char	*bytes;
	int				i;

	bytes = (unsigned char *)addr;
	i = 0;
	while (i != size)
	{
		print_hex(bytes[i]);
		if (i & 1)
			ft_putchar(' ');
		++i;
		if (!(i % 16) || i == size)
			print_ascii(bytes + i - (i % 16 ? i % 16: 16), i % 16);
	}
}

int					main()
{
	int				tab[13] = {0, 23, 150, 255,
	              				12, 16,  21, 42, 78, 12, 0};

	print_memory(tab, sizeof(tab));
	return (0);
}
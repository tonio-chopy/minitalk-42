/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:42:56 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/03 18:42:58 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_long_as_hex(long unsigned addr)
{
	char	c;
	int		total;

	total = 0;
	if (addr >= 16)
	{
		total += print_long_as_hex(addr / 16);
		total += print_long_as_hex(addr % 16);
	}
	else
	{
		c = (addr % 16) + '0';
		if ((addr % 16) > 9)
			c = ((addr % 16) + 87);
		write(1, &c, 1);
		total++;
	}
	return (total);
}

static int	get_hex_size(long unsigned addr)
{
	int	total;

	total = 0;
	if (addr >= 16)
	{
		total += get_hex_size(addr / 16);
		total += get_hex_size(addr % 16);
	}
	else
		total++;
	return (total);
}

int	pf_printpointer(void *ptr, t_opt opt)
{
	long	addr;
	int		total;
	int		len;

	addr = (long unsigned)ptr;
	total = 0;
	len = get_hex_size(addr) + 2;
	while (len + total < opt.min_width)
		total += print_char(' ');
	total += print_str("0x");
	total += print_long_as_hex(addr);
	while (total < opt.offset)
		total += print_char(' ');
	return (total);
}

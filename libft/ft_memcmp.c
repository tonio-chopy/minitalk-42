/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaualik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:51:16 by alaualik          #+#    #+#             */
/*   Updated: 2025/03/03 18:07:33 by alaualik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cur;
	char	*d1;
	char	*d2;

	if (n == 0)
		return (0);
	cur = 0;
	d1 = (char *)s1;
	d2 = (char *)s2;
	while (n--)
	{
		if (d1[cur] != d2[cur])
			return ((unsigned char)d1[cur] - (unsigned char)d2[cur]);
		cur++;
	}
	return (0);
}

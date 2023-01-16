/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:30:50 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/11 11:50:20 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*b;

	b = (const char *)s;
	if (c < 0 || c > 255)
		c = c % 256;
	while (b && n > 0)
	{
		if (*b == c)
			return ((void *)b);
		b++;
		n--;
	}
	return (0);
}

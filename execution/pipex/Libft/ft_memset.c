/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:30:25 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/11 11:13:08 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			n;
	unsigned char	*pt;

	pt = b;
	n = 0;
	while (n < len && pt)
	{
		*pt++ = c;
		n++;
	}
	return (b);
}

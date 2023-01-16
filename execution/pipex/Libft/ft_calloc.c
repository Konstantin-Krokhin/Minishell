/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:30:40 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2022/05/20 16:55:47 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*rtn;
	size_t			i;

	i = 0;
	rtn = malloc(size * count);
	if (!rtn)
		return (NULL);
	while (i < (count * size) && rtn)
	{
		rtn[i] = '\0';
		i++;
	}
	return (rtn);
}

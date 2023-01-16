/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:31:57 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/11 11:38:27 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				diff;
	unsigned char	*str1;
	unsigned char	*str2;

	diff = 0;
	if (n < 1)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (*str1 == *str2 && n > 1 && (*str1 != '\0' && *str2 != '\0'))
	{
		str1++;
		str2++;
		n--;
	}
	return (*str1 - *str2);
}

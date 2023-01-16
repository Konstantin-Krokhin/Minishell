/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:31:26 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/11 11:20:54 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*f;
	int		i;
	int		len;

	i = 0;
	f = (char *)s;
	len = ft_strlen(f);
	if (c < 0 || c > 255)
		return (f);
	while (i <= len)
	{
		if (f[i] == c)
			return (&f[i]);
		i++;
	}
	return (NULL);
}

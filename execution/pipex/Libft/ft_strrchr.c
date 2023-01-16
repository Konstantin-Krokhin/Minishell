/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:32:07 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/11 11:27:28 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*f;
	char	*r;
	int		flag;
	int		i;
	int		len;

	i = 0;
	flag = 0;
	f = (char *)s;
	len = ft_strlen(f);
	if (c < 0 || c > 255)
		return (f);
	while (i <= len)
	{
		if (f[i] == c)
		{
			r = &f[i];
			flag++;
		}
		i++;
	}
	if (flag > 0)
		return (r);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:00:10 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/09 12:32:49 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s1) + 1;
	if (size < 1)
	{
		str = malloc(sizeof(char));
		str = NULL;
		return (str);
	}
	else
		str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, size);
	return (str);
}

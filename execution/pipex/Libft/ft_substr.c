/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:32:15 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/11 17:03:46 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i;

	i = ft_strlen(s);
	if (!s)
		return (NULL);
	if ((size_t)start > i)
		return (ft_strdup(""));
	if (start + len <= i)
		i = len;
	else if (start + len > i)
		i -= start;
	rtn = malloc((i + 1) * sizeof(char));
	if (!rtn)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		rtn[i] = s[start + i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:31:53 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/08 11:33:31 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rtn;
	unsigned int	i;

	i = 0;
	rtn = ft_strdup(s);
	if (!rtn)
		return (rtn = NULL);
	while (s[i])
	{
		rtn[i] = f(i, s[i]);
		i++;
	}
	return (rtn);
}

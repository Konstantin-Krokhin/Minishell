/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:10:24 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/21 12:02:46 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.

Parameters:
s:  The string on which to iterate.
f:  The function to apply to each character.

Return:
The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails.

char *ft_strmapi(char const *s, char (*f)(unsigned
int, char));
*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	size_s;
	char	*str_out;

	i = 0;
	if (s == 0 || f == 0)
		return (NULL);
	size_s = ft_strlen(s);
	str_out = (char *)malloc((size_s + 1) * sizeof(char));
	if (str_out == 0)
		return (0);
	while (s[i] != '\0')
	{
		str_out[i] = f(i, *(s + i));
		i++;
	}
	str_out[i] = '\0';
	return (str_out);
}

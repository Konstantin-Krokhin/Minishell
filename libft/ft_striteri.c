/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:52:34 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/21 12:00:02 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument.  Each character is passed by
address to ’f’ to be modified if necessary.

Parameter:
s:  The string on which to iterate.
f:  The function to apply to each character.

void ft_striteri(char *s, void (*f)(unsigned int,
char*));
*/
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (f == 0 || s == 0)
		return ;
	while (s[i] != '\0')
	{
		f(i, (s + i));
		i++;
	}
}

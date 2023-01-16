/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:50:24 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/21 12:06:38 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.

Parameters:
	s1:  The prefix string.
	s2:  The suffix string

Returns:
	The new string. NULL if the allocation fails.

char *ft_strjoin(char const *s1, char const *s2);
*/

#include "libft.h"

static void	ft_fill_string(char const *s1, char const *s2, char *str_out);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*str_out;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str_out = (char *)malloc(size_s1 + size_s2 + 1);
	if (str_out == 0)
		return (0);
	ft_fill_string(s1, s2, str_out);
	return (str_out);
}

static void	ft_fill_string(char const *s1, char const *s2, char *str_out)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		str_out[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		str_out[i] = s2[j];
		i++;
		j++;
	}
	str_out[i] = '\0';
}

/*
#include <stdio.h>

int	main(void)
{
	// char	s1[] = "part A+";
	// char	s2[] = "part B";

	// char	s1[] = "";
	// char	s2[] = "part B";

	// char	s1[] = "part A+";
	// char	s2[] = "";

	char	s1[] = "";
	char	s2[] = "";
	char	*ptr;

	ptr = ft_strjoin(s1,s2);
	printf("ist: '%s'\n", ptr);
	free (ptr);
	return (0);
}*/
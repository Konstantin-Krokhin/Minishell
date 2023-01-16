/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:17:22 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/22 10:33:59 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.

Inputs:
	s:  The string from which to create the substring.
	
	start:  The start index of the substring in the
	string ’s’.

	len:  The maximum length of the substring.

Return: 
	The substring NULL if the allocation fails.

Prototype:
char *ft_substr(char const *s, unsigned int start, size_t len);

if the maximum lenght of the string is used, you can be creating
a much bigger memory allocation than required. -> len is only
the maximum not the mandatory size
line 52 is a protection to create the required memory size and
not something too big
*/

#include "libft.h"

static char	*ft_get_substrg(char const *s, char *new_s,
				unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	size;

	if (s == 0)
		return (NULL);
	size = ft_strlen(s);
	if (start > (size - 1))
	{
		new_s = (char *)malloc(1 * sizeof(char));
		new_s[0] = '\0';
		return (new_s);
	}
	if ((size + 1 - start) < len)
		new_s = (char *)malloc((size + 1 - start) * sizeof(char));
	else
		new_s = (char *)malloc((len + 1) * sizeof(char));
	if (new_s == 0)
		return (NULL);
	new_s = ft_get_substrg(s, new_s, start, len);
	return (new_s);
}

static char	*ft_get_substrg(char const *s, char *new_s,
				unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = start;
	j = 0;
	size = ft_strlen(s);
	if ((start == size && len > 0) || (start > size))
	{
		new_s[j] = '\0';
		return (new_s);
	}
	while (s[i] != '\0' && i < (len + start))
	{
		new_s[j] = s[i];
		i++;
		j++;
	}
	new_s[j] = '\0';
	return (new_s);
}

/*
#include <stdio.h>

int	main(void)
{
	//char str[]="cut this string";
	//char str[]="";
	
	//char *str = "i just want this part #############";
	//size_t size = 22;
	//int start = 0;
	
	char *str = "i just want this part #############";
	size_t size = 20;
	int start = 5;
	
	// char *str = "01234";
	// size_t size = 10;
	// int start = 10;
	

	char *ret = ft_substr(str, start, size);
	
	printf("ist: '%s'", ret);
	free(ret);
	return (0);
}*/
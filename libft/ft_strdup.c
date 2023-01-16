/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:55:42 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/17 10:57:21 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>
NAME
strdup, strndup -- save a copy of a string

DESCRIPTION
The strdup() function allocates sufficient memory for a copy of the string s1,
does the copy, and returns a pointer to it.  The pointer may subsequently be
used as an argument to the function free(3).
If insufficient memory is available, NULL is returned and errno is set to
ENOMEM.

The strndup() function copies at most n characters from the string s1 always 
NULL terminating the copied string. 

char *strdup(const char *s1);
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s1);
	ptr = (char *) malloc((size + 1) * sizeof(char));
	if (ptr == 0)
	{
		return (ptr);
	}
	ft_memcpy(ptr, s1, (size + 1) * sizeof(char));
	return (ptr);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char str[] = "copy this string";
	char *dest_soll;
	char *dest_ist;
	
	
	dest_soll = strdup(str);
	dest_ist  = ft_strdup(str);
	printf("SOLL: Adress %p containing '%s'\n", (void *)dest_soll, dest_soll);
	printf("IST : Adress %p containing '%s'\n", (void *)dest_ist, dest_ist);
	free((void *) dest_soll);
	free((void *) dest_ist);
	return (0);
}
*/
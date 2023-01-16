/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:05:56 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/17 10:55:30 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>

NAME
memchr -- locate byte in byte string

DESCRIPTION
The memchr() function locates the first occurrence of c (converted to an 
unsigned char) in string s.

RETURN VALUES
The memchr() function returns a pointer to the byte located, or NULL if no 
such byte exists within n bytes.

void *memchr(const void *s, int c, size_t n);
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*word;
	unsigned char	letter;
	void			*ptr;

	letter = c;
	word = (unsigned char *)s;
	i = 0;
	while (i < n)
	{	
		if (word[i] == letter)
		{
			ptr = (void *)(word + i);
			return (ptr);
		}
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char		s[] = "my apple is not configured";
	int			c = 'a';
	size_t	n = 24;
	void		*ptr_soll;
	void		*ptr_ist;

	ptr_soll = memchr( (void *)s, c, n);
	printf("SOLL: '%s'\n", (char *)ptr_soll);
	ptr_ist =  ft_memchr( (void *)s, c, n);
	printf("IST:  '%s'\n", (char *)ptr_ist);
	return (0);
}

#include <string.h>
#include <stdio.h>

int	main(void)
{
	char		s[] = "my apple is not configured";
	//char		c = '/0';
	size_t	n = 27;
	void		*ptr_soll;
	void		*ptr_ist;

	//c = '\0';
	ptr_soll = memchr( (void *)s,  '\0', n);
	printf("SOLL: '%s'\n", (char *)ptr_soll);
	ptr_ist =  ft_memchr( (void *)s,  '\0', n);
	printf("IST:  '%s'\n", (char *)ptr_ist);
	return (0);
}*/
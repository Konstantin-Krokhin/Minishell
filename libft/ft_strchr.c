/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:47:14 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/22 09:45:20 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>
NAME
     strchr, strrchr -- locate character in string

DESCRIPTION
The strchr() function locates the first occurrence of c (converted to a char) 
in the string pointed to by s.  The terminating null character is considered 
to be part of the string; therefore if c is `\0', the functions locate the 
terminating `\0'.

RETURN VALUES
The functions strchr() and strrchr() return a pointer to the located 
character, or NULL if the character does not appear in the string.

char *strchr(const char *s, int c);
*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			sw;
	size_t		i;
	size_t		size;

	sw = 0;
	i = 0;
	size = ft_strlen(s);
	if (c > 255)
		c = c - 256;
	while (sw == 0 && i < size + 1)
	{
		if (s[i] == '\0')
		{
			sw = 1;
		}
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (0);
}

/*
// #include <string.h>
// #include <stdio.h>
//
// int main(void)
// {
// 	char	str[] = "pn9a8 zg+-.a";
// 	//char	c = 'p';
// 	char	c = 'a';
// 	//char	c = '8';
// 	//char	c = ' ';
// 	//char	c = '\0';
// 	char	*p_ist = NULL;
// 	char	*p_soll = NULL;
//
// 	p_ist = ft_strchr(str, c);
// 	p_soll = strchr(str, c);
// 	printf("IST:  find '%c': result : '%c'\n", c, *p_ist);
// 	printf("SOLL: find '%c': result : '%c'\n", c, *p_soll);
//
// 	return (0);
// }*/
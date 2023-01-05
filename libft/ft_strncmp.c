/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:41:43 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/17 10:56:32 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>

NAME
strcmp, strncmp -- compare strings

DESCRIPTION
The strcmp() and strncmp() functions lexicographically compare the 
null-terminated strings s1 and s2.

The strncmp() function compares not more than n characters.  Because 
strncmp() is designed for comparing strings rather than binary data, 
characters that appear after a `\0' character are not compared.

RETURN VALUES
The strcmp() and strncmp() functions return an integer greater than, 
equal to, or less than 0, according as the string s1 is greater than,
equal to, or less than the string s2.  The comparison is done using 
unsigned characters, so that `\200' is greater than `\0'.

int strncmp(const char *s1, const char *s2, size_t n);
*/
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	u_s1;
	unsigned char	u_s2;

	i = 0;
	while (i < n)
	{
		u_s1 = (unsigned char) s1[i];
		u_s2 = (unsigned char) s2[i];
		if (u_s1 == u_s2)
		{
			i++;
		}
		else
		{
			return (u_s1 - u_s2);
		}
		if (u_s1 == '\0' || u_s2 == '\0')
			break ;
	}
	return (0);
}

/*

#include <string.h>

int	main(void)
{
	char	str1[] = "hotel";
	char	str2[] = "hotiz";
	char	str3[] = "ha";

	// str1 lower value than str2
	printf("compare: '%s' TO '%s", str1, str2);
	printf("\nIST:  %d\n", ft_strncmp(str1, str2, 5));
	printf("SOLL: %d\n", strncmp(str1, str2, 5));

	// str2 and str1 for zero elements
	printf("compare: '%s' TO '%s", str1, str2);
	printf("\nIST:  %d\n", ft_strncmp(str1, str2, 0));
	printf("SOLL: %d\n", strncmp(str1, str2, 0));

	// str2 compare few elements that are equal
	printf("compare: '%s' TO '%s", str1, str2);	
	printf("\nIST:  %d\n", ft_strncmp(str1, str2, 3));
	printf("SOLL: %d\n", strncmp(str1, str2, 3));

	// str3 higher value than str1, test elements equal d
	printf("compare: '%s' TO '%s", str1, str3);
	printf("\nIST:  %d\n", ft_strncmp(str1, str3, 2));
	printf("SOLL: %d\n", strncmp(str1, str3, 2));

	// str3 smaller than str1, test elements bigger than range
	printf("compare: '%s' TO '%s", str1, str3);
	printf("\nIST:  %d\n", ft_strncmp(str1, str3, 5));
	printf("SOLL: %d\n", strncmp(str1, str3, 5));

	return (0);
}


int main(void)
{
	char *s1 = "\x12\xff\x65\x12\xbd\xde\xad";
	char *s2 = "\x12\x02";
	size_t size = 6;
	
	int i1 = (strncmp(s1, s2, size));
	int i2 = (ft_strncmp(s1, s2, size));
	printf("SOLL: %d\n", i1);
	printf("IST : %d\n", i2);
	return (0);
}*/
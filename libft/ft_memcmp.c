/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:21:12 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/17 10:52:57 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>

NAME
memcmp -- compare byte string

DESCRIPTION
The memcmp() function compares byte string s1 against byte string s2.  Both 
strings are assumed to be n bytes long.

RETURN VALUES
The memcmp() function returns zero if the two strings are identical, otherwise 
returns the difference between the first two differing bytes (treated as 
unsigned char values, so that `\200' is greater than `\0', for example).  
Zero-length strings are always identical.  This behavior is not required by
C and portable code should only depend on the sign of the returned value.

int memcmp(const void *s1, const void *s2, size_t n);

*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*u_s1;
	unsigned char		*u_s2;

	i = 0;
	u_s1 = (unsigned char *) s1;
	u_s2 = (unsigned char *) s2;
	while (i < n)
	{
		if (u_s1[i] == u_s2[i])
		{
			i++;
		}
		else
		{
			return (u_s1[i] - u_s2[i]);
		}
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "hotel";
	char	str2[] = "hotiz";
	char	str3[] = "ha";

	// str1 lower value than str2
	printf("compare: '%s' TO '%s", str1, str2);
	printf("\nIST:  %d\n", ft_memcmp(str1, str2, 5));
	printf("SOLL: %d\n", memcmp(str1, str2, 5));

	// str2 and str1 for zero elements
	printf("compare: '%s' TO '%s", str1, str2);
	printf("\nIST:  %d\n", ft_memcmp(str1, str2, 0));
	printf("SOLL: %d\n", memcmp(str1, str2, 0));

	// str2 compare few elements that are equal
	printf("compare: '%s' TO '%s", str1, str2);	
	printf("\nIST:  %d\n", ft_memcmp(str1, str2, 3));
	printf("SOLL: %d\n", memcmp(str1, str2, 3));

	// str3 higher value than str1, test elements equal d
	printf("compare: '%s' TO '%s", str1, str3);
	printf("\nIST:  %d\n", ft_memcmp(str1, str3, 2));
	printf("SOLL: %d\n", memcmp(str1, str3, 2));

	// str3 smaller than str1, test elements bigger than range
	printf("compare: '%s' TO '%s", str1, str3);
	printf("\nIST:  %d\n", ft_memcmp(str1, str3, 5));
	printf("SOLL: %d\n", memcmp(str1, str3, 5));

	return (0);
}
*/
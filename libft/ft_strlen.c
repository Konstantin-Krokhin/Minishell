/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:37:21 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/17 10:52:43 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 #include <string.h>

NAME
strlen, strnlen -- find length of string

DESCRIPTION
The strlen() function computes the length of the string s.  The strnlen() 
function attempts to compute the length of s, but
never scans beyond the first maxlen bytes of s.

RETURN VALUES
The strlen() function returns the number of characters that precede the 
terminating NUL character. 

do not count the NULL char

size_t strlen(const char *s);
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char	c;
	size_t	count;
	int		i;	

	count = 0;
	i = 0;
	c = s[i];
	while (c != '\0')
	{
		i++;
		count++;
		c = s[i];
	}
	return (count);
}

/*
#include <string.h>
#include <stdio.h>

int main(void)
{
//     Test Cases Inputs
	char str1[] = "maira";
	char str2[] = "Banana 2x";
	char str3[] = "";

    printf("\n--TEST CASES: ft_strlen--\n\n");
	
	printf("Input is %s - ", str1);
	if (ft_strlen(str1) == strlen(str1))
	{
		printf("PASS\n");
	}
	else
	{
	printf("FAIL: \n"); 
	printf("      IST:  ft_strlen output: %lu\n", ft_strlen(str1));
	printf("      SOLL:    strlen output: %lu\n", strlen(str1));    
	}
	printf("\n");
	//
	printf("Input is %s - ", str2);
	if (ft_strlen(str2) == strlen(str2))
	{
		printf("PASS\n");
	}
	else
	{
	printf("FAIL: \n"); 
	printf("      IST:  ft_strlen output: %lu\n", ft_strlen(str2));
	printf("      SOLL:    strlen output: %lu\n", strlen(str2));    
	}
	printf("\n");
	//

	printf("Input is %s - ", str3);
	if (ft_strlen(str3) == strlen(str3))
	{
		printf("PASS\n");
	}
	else
	{
	printf("FAIL: \n"); 
	printf("      IST:  ft_strlen output: %lu\n", ft_strlen(str3));
	printf("      SOLL:    strlen output: %lu\n", strlen(str3));    
	}
	printf("\n");

    return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:16:59 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/17 10:46:15 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 #include <strings.h>

NAME
bzero -- write zeroes to a byte string

DESCRIPTION
The bzero() function writes n zeroed bytes to the string s.  If n is zero, 
bzero() does nothing.

All bzero() does is memset everything to zeros
memset (foo, 0, sizeof(myStruct_t));

void bzero(void *s, size_t n);

A função bzero pode ser usada para apagar a área de memória 
fornecida com zero bytes (\0)
*/

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*u_char;

	i = 0;
	u_char = (unsigned char *)str;
	while (i < n)
	{
		u_char[i] = '\0';
		i++;
	}
	str = u_char;
}

/*
// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     char str1[] = "almost every programmer should know memset!";
// 	char str2[] = "almost every programmer should know memset!";

//     printf("Input is ('%s', 6) \n", str1);

// 	ft_bzero(str1, 6);
// 	bzero(str2, 6);
// 	if (strcmp(str1, str2) == 0)
// 	{
// 		printf("PASS\n");
// 		printf("      IST:  ft_bzero output: '%s'\n", str1 );
// 		printf("      SOLL:    bzero output: '%s'\n", str2 );    
// 	}
// 	else
// 	{
// 	printf("FAIL: \n"); 
// 	printf("      IST:  ft_bzero output: %s\n", str1);
// 	printf("      SOLL:    bzero output: %s\n", str2);    
// 	}
// 	printf("\n");
// }*/
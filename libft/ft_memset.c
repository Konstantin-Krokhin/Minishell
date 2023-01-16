/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:47:13 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/17 10:55:50 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>

Description
The C library function void *memset(void *str, int c, size_t n) copies the 
character c (an unsigned char) to the first n characters of the string 
pointed to, by the argument str.

Parameters
str − This is a pointer to the block of memory to fill.

c − This is the value to be set. The value is passed as an int, but the 
function fills the block of memory using the unsigned char conversion of 
this value.

n − This is the number of bytes to be set to the value.

Return Value
This function returns a pointer to the memory area str

void *memset(void *str, int c, size_t n)
*/
//typedef unsigned int size_t;

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*u_str;

	i = 0;
	u_str = (unsigned char *) str;
	while (i < n)
	{
		u_str[i] = (unsigned char) c;
		i++;
	}
	str = u_str;
	return (str);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
char str1[] = "almost every programmer should know memset!";
char str2[] = "almost every programmer should know memset!";

printf("Input is ('%s', '-', 6) \n", str1);
ft_memset(str1,'-',6);
memset (str2,'-',6);
if (strcmp(str1, str2) == 0)
{
     printf("PASS\n");
     printf("      IST:  ft_memset output: '%s'\n", 
                           (char(*))ft_memset (str1,'-',6));
     printf("      SOLL:    memset output: '%s'\n", 
                           (char(*))memset (str2,'-',6));    
}
else
{
printf("FAIL: \n"); 
printf("      IST:  ft_memset output: %s\n", 
                           (char(*))ft_memset (str1,'-',6));
printf("      SOLL:    memset output: %s\n", 
                           (char(*))memset (str2,'-',6));    
}
printf("\n");
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
char str1[] = "almost every programmer should know memset!";
char str2[] = "almost every programmer should know memset!";
//

char c = '\5';
//char c = 'A';
void *ptr_ist = 0;
void *ptr_soll = 0;

printf("Input is ('%s', %c, 6) \n", str1, '\5');
ptr_ist = ft_memset(str1,c,6);
ptr_soll = memset (str2,c,6);
if (strcmp(str1, str2) == 0)
{
     printf("PASS\n");
     printf("      IST:  ft_memset output: '%s'\n", 
                           (char(*))ptr_ist);
     printf("      SOLL:    memset output: '%s'\n", 
                           (char(*))ptr_soll);    
}
else
{
printf("FAIL: \n"); 
printf("      IST:  ft_memset output: %s\n", 
                            (char(*))ptr_ist);
printf("      SOLL:    memset output: %s\n", 
                           (char(*))ptr_soll);    
}
printf("\n");
}



int main(void)
{

	char *b1 = (char*)malloc(sizeof(char) * (0xF0000 + 1));
	char *b2 = (char*)malloc(sizeof(char) * (0xF0000 + 1));
	*b1 = 0;
	*b2 = 0;
	
	ft_memset(b1,'A', 6);
	memset (b2,'A',6);

	printf("      IST:  ft_memset output: '%s'\n", (char(*))b1);
     printf("      SOLL:    memset output: '%s'\n", (char(*))b2);    
	free(b1);
	free(b2);
	return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:42:57 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/17 10:54:14 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>
Description
The C library function void *memcpy(void *dest, const void *src, size_t n) 
copies n characters from memory area src to memory area dest.

Parameters
dest − This is pointer to the destination array where the content is to be 
copied, type-casted to a pointer of type void*.

src − This is pointer to the source of data to be copied, type-casted to 
a pointer of type void*.

n − This is the number of bytes to be copied.

Return Value
This function returns a pointer to destination, which is str1.

void *memcpy(void *dest, const void * src, size_t n)
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*u_src;
	unsigned char		*u_dest;

	i = 0;
	u_src = (unsigned char *) src;
	u_dest = (unsigned char *) dest;
	if (dest == 0 && src == 0)
	{
		return (0);
	}
	while (i < n)
	{
		u_dest[i] = u_src[i];
		i++;
	}
	dest = u_dest;
	return (dest);
}

/*
 #include <stdio.h>
#include <string.h>

// int main(void)
// {
// const char src[44] = "almost every programmer should know memset!";
// char dest1[44] = "";
// char dest2[44] = "";
// int size = 44;

// printf("Input is ('%s', %d) \n", src, size);
// ft_memcpy (dest1, src, size);
// memcpy(dest2, src, size);

// if (strcmp(dest1, dest2) == 0)
// {
//      printf("PASS\n");
//      printf("      IST:  ft_memcpy output: '%s'\n", 
//                            (char(*))dest1);
//      printf("      SOLL:    memset output: '%s'\n", 
//                            (char(*))dest2);    
// }
// else
// {
// printf("FAIL: \n"); 
// printf("      IST:  ft_memcpy output: '%s'\n", 
//                            (char(*))dest1);
// printf("      SOLL:    memset output: '%s'\n", 
//                            (char(*))dest2);   
// }
// printf("\n");
// }


// int main(void)
// {
// 	// void	*ptr_ist = 0;
// 	// void	*ptr_soll = 0;
// 	void 	*ptr_out = 0;

// 	// ptr_ist = ft_memcpy(((void *)0), ((void *)0), 3);
// 	// ptr_soll = memcpy(((void *)0), ((void *)0), 3);
// 	// printf("SOLL: %s\n", (char*)ptr_soll);
// 	// printf("IST : %s\n", (char*)ptr_ist);

// 	ptr_out = ft_memcpy(((void *)0), "segfaulter tu dois", 17);
// 	printf("IST2 : %s\n", (char*)ptr_out);

// 	ptr_out = memcpy(((void *)0), "segfaulter tu dois", 17);
// 	printf("SOLL2 : %s\n", (char*)ptr_out);
// 	return (0);
// } */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:08:35 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/20 17:43:17 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description
The C library function void *memmove(void *str1, const void *str2, size_t n) 
copies n characters from str2 to str1, but for overlapping memory blocks, 
memmove() is a safer approach than memmove().

Parameters
str1 − This is a pointer to the destination array where the content is to be 
copied, type-casted to a pointer of type void*.

str2 − This is a pointer to the source of data to be copied, type-casted to 
a pointer of type void*.

n − This is the number of bytes to be copied.

Return Value
This function returns a pointer to the destination, which is str1.

void *memmove(void *str1, const void *str2, size_t n)

In general, memmove is implemented in a simple (but fast) manner. 
Simplistically, it just loops over the data (in order), copying from 
one location to the other. This can result in the source being overwritten 
while it's being read.

The C11 N1570 standard draft says:

7.24.2.1 "The memcpy function":

2 The memcpy function copies n characters from the object pointed to by s2
 into the object pointed to by s1. If copying takes place between objects 
 that overlap, the behavior is undefined.
 
7.24.2.2 "The memmove function":

2 The memmove function copies n characters from the object pointed to 
by s2 into the object pointed to by s1. Copying takes place as if the n 
characters from the object pointed to by s2 are first copied into a 
temporary array of n characters that does not overlap the objects 
pointed to by s1 and s2, and then the n characters from the temporary 
array are copied into the object pointed to by s1

change from pointer casting to unsigned char to char
*/
#include "libft.h"

static void	ft_memloop(void *dest, const void *src, size_t n,
				char *u_src);
static void	ft_src_smaller_dest(char *u_dest,
				char *u_src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*u_src;

	u_src = (char *) src;
	if (src == 0 && dest == 0)
		return (NULL);
	else if (n == 0 || src == dest)
		return (dest);
	ft_memloop(dest, src, n, u_src);
	return (dest);
}

static void	ft_src_smaller_dest(char *u_dest,
				char *u_src, size_t n)
{
	int	i;

	i = (int)n - 1;
	while (i >= 0)
	{
		*(u_dest + i) = *(u_src + i);
		i--;
	}
}

static void	ft_memloop(void *dest, const void *src, size_t n,
				char *u_src)
{
	int		i;
	int		n_i;
	char	*u_dest;

	u_dest = (char *) dest;
	if (src < dest)
	{
		ft_src_smaller_dest(u_dest, u_src, n);
	}
	else
	{
		i = 0;
		n_i = (int)n;
		while (i < n_i)
		{
			*(u_dest + i) = *(u_src + i);
			i++;
		}
	}
}

/*
#include <stdio.h>
#include <string.h>

// int main(void)
// {
// 	const char src[44] = "almost every programmer should know memset!";
// 	char dest1[44] = "";
// 	char dest2[44] = "";
// 	int size = 44;

// 	printf("Input is ('%s', %d) \n", src, size);
// 	ft_memmove (dest1, src, size);
// 	memmove(dest2, src, size);

// 	if (strcmp(dest1, dest2) == 0)
// 	{
// 		printf("PASS\n");
// 		printf("      IST:  ft_memmove output: '%s'\n", 
// 							(char(*))dest1);
// 		printf("      SOLL:    memset output: '%s'\n", 
// 							(char(*))dest2);    
// 	}
// 	else
// 	{
// 		printf("FAIL: \n"); 
// 		printf("      IST:  ft_memmove output: '%s'\n", 
// 								(char(*))dest1);
// 		printf("      SOLL:    memset output: '%s'\n", 
// 								(char(*))dest2);   
// 	}
// 		printf("\n");
// }

int main(void)
{
	//char dst1[0xF0];
	//char dst2[0xF0];
	//char *data = "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !\r\n";
	//char dst1[] = "thiß ß\xde\xad\xbe";
	char dst2[] = "banana maca";
	int size = strlen(dst2) + 1;

	ft_memmove(dst2 , dst2 + 2, size);
	//memmove(dst1 + 2, dst1, size);
	printf("IST : '%s'\n", (dst2 + 2));
	//printf("SOLL: '%s'\n", dst2);
	//if (! memcmp(dst1, dst2, size))
	//	printf("PASS");
	//else
	//	printf("FAIL");
	// return (0);
}

int main (void)
{
	char	*ptr_ist;
	char	*ptr_soll;
	
	ptr_ist = (char *)ft_memmove(((void *)0), ((void *)0), 5);
	ptr_soll = (char *) memmove(((void *)0), ((void *)0), 5);
	printf("SOLL: pointer %p and inside '%s'\n", ptr_soll, ptr_soll);
	printf("IST : pointer %p and inside '%s'\n", ptr_ist, ptr_ist);

}

int  main(void)
{
	char str1[] = "Geeks"; // Array of size 100
    char str2[] = "Quiz"; // Array of size 5
  
    puts("str1 before memmove ");
    puts(str1);
  
    // Copies contents of str2 to sr1 
    memmove(str1, str2, sizeof(str2));
  
    puts("\nstr1 after memmove ");
    puts(str1);
	return (0);
}



#include <stdio.h>
#include <string.h>
int main(void)
{
	//char *src = "thanks to @apellicc for this test !\r\n";
	char *src = "";
	char dst1[] = "";
	char dst2[] = "";
	int size = strlen(src);

	ft_memmove(dst1 , src, size);
	memmove(dst2, src, size);
	printf("IST : adress %p and '%s'\n", (void*) dst1, (dst1));
	printf("SOLL: adress %p and '%s'\n", (void*) dst2, (dst2));
	return (0);
} 


#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
// Error Moulinette 1 - Expected \00 - received \x61
 char src[16] = "8VrOAKvzCfMEJL";
// char *src2 = "8VrOAKvzCfMEJL";

 size_t size  = 1;
 //char dst[16];
 //char dst2[2];

 char *pt_ist = ft_memmove(src, src + 1, size);

	write(1, src, 1 );
	write(1, "\n", 1 );
  write(1, pt_ist, 1 );

//ft_memmove(dst2, src, size);

 //memmove(src + 5, src, size);
//ft_memmove((src2 + 5), src2, size);

//  if (*dst == '\0')
// 	printf("return NULL Terminator \n");
// if (dst[0] == '\0')
// 	dst[0] = '*';
// if (dst2[0] == '\0')
// 	dst2[0] = '*';
// if (dst[1] == '\0')
// 	dst[1] = '#';
// if (dst2[1] == '\0')
// 	dst2[1] = '#';
 //printf("SOLL: '%s'\n", src);
//     write(1, "'", 1);
//  write(1, src2, size);
//     write(1, "'", 1);
//  write(1, "\n", 1);
//  printf("IST : '%s'\n", src2);
//     write(1, "'", 1);
//   write(1, src2, 2);
//    write(1, "'", 1);



//  size_t size = 20;
//  char from[20] = "Learning Lad Rocks";
//  char *receive = memmove(from, from + 9, size );

// 	//printf("from: %s\n", from);
// 	write(1, receive, 20);
// 	write(1, "\n", 1);
// 	write(1, from, 20);
// 		write(1, "\n", 1);


 return (0);


}
*/

/*
Prototype:
int             verify_memmove(void * v, size_t mem_size, size_t size)

todos casos onde size <= mem_size

count += verify_memmove((void const *)
"8VrOAKvzCfMEJL", 1, 1); Expected: \x00
count += verify_memmove((void const *)"eTZ7brMJGU", 1, 1);
Expected: \x00


count += verify_memmove((void const *)"FWsnSyRjEwdxI", 8, 1); [!] 
Expected: \x00

count += verify_memmove((void const *)"XVDmyw2p95bJhHxo", 7, 1); [!]
 Expected: \x00

count += verify_memmove((void const *)"EN6gDHT", 2, 2);
 Expected: \x00\x00
count += verify_memmove((void const *)"a0QPjVAibq8y7", 4, 2); 
Expected: \x00\x00

count += verify_memmove((void const *)"FvcUmxl", 8, 3); 
Expected: \x00\x00\x00 -> src = src + 8, out of range. 
Fill al dest with \0 -> memset dest == \0

count += verify_memmove((void const *)"z1LtoEvFcrkJQSY", 4, 2);
Expected: \x00\x00 


count += verify_memmove((void const *)"aKrIMl3HuZ", 6, 7); 
[!] Expected: \x49\x4d\x6c\x33\ ->xd0<- \x00\x33 - 
Got: \x49\x4d\x6c\x33\x00\x00\x33


count += verify_memmove((void const *)"8CanKOIe0", 6, 7); 
Expected: \x6e\x4b\x4f\x49\  ->xd0<--- \x00\x49 - 
Got: \x6e\x4b\x4f\x49\x00\x00\x49



 


*/
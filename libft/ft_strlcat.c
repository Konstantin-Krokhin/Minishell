/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:51:26 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/17 10:49:35 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>
NAME
strlcpy, strlcat -- size-bounded string copying and concatenation

DESCRIPTION
The strlcpy() and strlcat() functions copy and concatenate strings with the
same input parameters and output result as snprintf(3).  They are designed
to be safer, more consistent, and less error prone replacements for the
easily misused functions strncpy(3) and strncat(3).

strlcpy() and strlcat() take the full size of the destination buffer and
guarantee NUL-termination if there is room.  Note that room for the NUL
should be included in dstsize.

strlcat() appends string src to the end of dst.  
It will append at most dstsize - strlen(dst) - 1 characters.  
It will then NUL-terminate, 
	-> unless dstsize is 0 
	-> or the original dst string was longer than dstsize
(in practice this should not happen as it means that either dstsize is 
incorrect or that dst is not a proper string).

RETURN VALUES
Besides quibbles over the return type (size_t versus int) and signal han-
dler safety (snprintf(3) is not entirely safe on some systems), the follow-
ing two are equivalent:

	n = strlcpy(dst, src, len);
	n = snprintf(dst, len, "%s", src);

Like snprintf(3), the strlcpy() and strlcat() functions return the total
length of the string they tried to create.  For strlcat() that means the 
initial length of dst plus the length of src.

If the return value is >= dstsize, the output string has been truncated.
It is the caller's responsibility to handle this.

size_t
strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
	 
first version:
size_t	ft_strlcat(char *restrict dst, const char *restrict src, 
		size_t dstsize)	 

version without restrict
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
	 */
#include "libft.h"

static void	ft_loop_dst(char *dst, const char *src,
				size_t dstsize, size_t *p_i);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size_src;
	size_t	i;
	size_t	*p_i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	p_i = &i;
	size_src = ft_strlen(src);
	while (dst[i])
	{
		i = i + 1;
		if (i == dstsize)
			return (size_src + dstsize);
		cnt ++;
	}
	ft_loop_dst(dst, src, dstsize, p_i);
	if (dstsize == 0)
		return (size_src);
	if (dstsize < i)
		return (size_src + dstsize);
	return (cnt + size_src);
}

static void	ft_loop_dst(char *dst, const char *src,
				size_t dstsize, size_t *p_i)
{
	size_t	j;

	j = 0;
	while (dstsize > 0 && (*p_i) < (dstsize - 1) && src[j] != '\0')
	{
		dst[(*p_i)] = src[j];
		(*p_i) = (*p_i) + 1;
		j++;
		if ((*p_i) == (dstsize - 1))
		{	
			dst[(*p_i)] = '\0';
			break ;
		}
	}
	dst[(*p_i)] = '\0';
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
// src and dst completly copied
// size dst1 + size src < dst_size => size src + size dst2
char *src = "this is the source"; // 18
char dst1[40] = "destination "; //12
printf("1 - returns: %lu - dest: '%s'\n", 
	strlcat(dst1, src, 40), dst1);
char dst1_b[40] = "destination "; //12
printf("1b - returns: %lu - dest: '%s'\n\n", 
	ft_strlcat(dst1_b, src, 40), dst1_b);


// src and dst partially copied - because of dst_size
// size dst2 > dst_size ,   

// --->dst_size >=(size dst + size src)  => size src + size dst2 
char dst2[40] = "destination "; //12
printf("2 - returns: %lu - dest: '%s'\n", 
	strlcat(dst2, src, 30), dst2);
char dst2_b[40] = "destination "; //12
printf("2b - returns: %lu - dest: '%s'\n\n", 
	ft_strlcat(dst2_b, src, 30), dst2_b);

// src and dst partially copied - because of dst too small
//char dst3[20] = "destination ";
//printf("3 - returns: %lu - dest: '%s'\n\n", 
//	strlcat(dst3, src, 35), dst3);
//ft_strlcat2.c:126:44: error: 'strlcat' will always overflow; 
//destination buffer has size 20, but size
//  argument is 35 [-Werror,-Wbuiltin-memcpy-chk-size]

// dstsize == 0 -> dst_size
char dst4[20] = "destination ";
printf("4 - returns: %lu - dest: '%s'\n", 
	strlcat(dst4, src, 0), dst4);
char dst4_b[20] = "destination ";
printf("4b - returns: %lu - dest: '%s'\n\n",
	 strlcat(dst4_b, src, 0), dst4_b);


// src == "ignored" and dstsize < size_dst (cut dst string) 
//						-> returns buff size
char *src2 = "ignored";
char dst5[20] = "destination ";
printf("5 - returns: %lu - dest: '%s'\n", 
	strlcat(dst5, src2, 10), dst5);
char dst5_b[20] = "destination ";
printf("5b - returns: %lu - dest: '%s'\n\n", 
	strlcat(dst5_b, src2, 10), dst5_b);

// src == "" && dstsize > size dest -> returns dst size
//				dstsize < size dest -> retursn dstsize
char *src3 = "\0";
char dst6[20] = "destination "; // 12
printf("6 - returns: %lu - dest: '%s'\n", 
	strlcat(dst6, src3, 20), dst6);
char dst6_b[20] = "destination "; // 12
printf("6b - returns: %lu - dest: '%s'\n\n", 
	strlcat(dst6_b, src3, 20), dst6_b);
return (0);
}

//UNIT MAIN

int main(void)
{
// src = 19
// dst = 28
// dst_size = 19 + 4 = 23 

// dst_size < len dst
// should be : src + dst
char *str = "the cake is a lie !\0I'm hidden lol\r\n";
char buff1[0xF00] = "there is no stars in the sky";
char buff2[0xF00] = "there is no stars in the sky";
size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
printf("max: %lu\n", max);

printf("A   - returns: %lu - dest: '%s'\n", 
	strlcat(buff1, str, max), buff1);
printf("A_2 - returns: %lu - dest: '%s'\n\n", 
	ft_strlcat(buff2, str, max), buff2);

char s1[4] = "";
char s2[4] = "";
printf("B     - returns: %lu - dest: '%s'\n", 
	strlcat(s1, "thx to ntoniolo for this test !", 4), s1);
printf("B_2   - returns: %lu  - dest: '%s'\n\n", 
	ft_strlcat(s2, "thx to ntoniolo for this test !", 4), s2);

char *str2 = "the cake is a lie !\0I'm hidden lol\r\n";
char buff3[0xF00] = "there is no stars in the sky";
char buff4[0xF00] = "there is no stars in the sky";
size_t max2 = strlen("the cake is a lie !\0I'm hidden lol\r\n") 
	+ strlen("there is no stars in the sky");
printf("C     - returns: %lu - dest: '%s'\n", 
	strlcat(buff3,str2,max2), buff3);
printf("C_2   - returns: %lu - dest: '%s'\n\n", 
	ft_strlcat(buff4, str2, max2), buff4);


	char *src = "aaa";
	char dst1[20];
	char dst2[20];
	int ret1;
	int ret2;

	printf("D     - returns: %lu - dest: '%s'\n",
		 strlcat(dst1,src,20), dst1);
	printf("D_2   - returns: %lu - dest: '%s'\n\n", 
		ft_strlcat(dst2, src, 20), dst2);

	
	//[no crash]: your strlcat does not segfault
						 when null parameter is sent
	char b[0xF] = "nyan !";
	printf("Must Crash - SEGFAULT\n");
	ft_strlcat(b, ((void *)0), 2);


	return(0);
}



// warmaschine
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	
		// Test 05



		// Test 05 - warmaschine

		// src > dst && dst_size == 0 -> return (src_size)
		// dst len = 15
		// src len =  26
		// dst_size = 0
		// rerturns 26
		char	*dest;  
		char	*dest2;

		dest = (char *)malloc(sizeof(*dest) * 15);
		memset(dest, 0, 15);
		memset(dest, 'r', 6);
		dest[10] = 'a';
		dest2 = (char *)malloc(sizeof(*dest2) * 15);
		memset(dest2, 0, 15);
		memset(dest2, 'r', 6);
		dest2[10] = 'a';

		printf("100      - returns: %lu - dest: '%s'\n", 
			strlcat(dest,"lorem ipsum dolor sit amet",0), dest);
		write(1, "'", 1);
		write(1, dest, 15);
		write(1, "'", 1);
		printf("\n100_2    - returns: %lu - dest: '%s'\n\n", 
			ft_strlcat(dest2,"lorem ipsum dolor sit amet",0), dest2);
		write(1, "'", 1);
		write(1, dest2, 15);
		write(1, "'", 1);
		free(dest);
		free(dest2);


		// size src > size dst && dst_size == 0 -> return src_size
		// len src 18
		// len dst 11
		// dst size = 0
		char *src = "this is the source"; // 18
		// dstsize == 0 -> dst_size
		char dst4[20] = "destination ";
		printf("4 - returns: %lu - dest: '%s'\n", 
			strlcat(dst4, src, 0), dst4);
		char dst4_b[20] = "destination ";
		printf("4b - returns: %lu - dest: '%s'\n\n", 
			ft_strlcat(dst4_b, src, 0), dst4_b);


		// size src < size dst && dst_size == 0 -> return src_size
		// len src 7
		// len dst 11
		// dst size = 0
		char *src2 = "this is"; // 7
		// dstsize == 0 -> dst_size
		char dst5[20] = "destination ";
		printf("4 - returns: %lu - dest: '%s'\n", 
			strlcat(dst5, src2, 0), dst5);
		char dst5_b[20] = "destination ";
		printf("4b - returns: %lu - dest: '%s'\n\n", 
			ft_strlcat(dst5_b, src2, 0), dst5_b);

	
		/// Test 07 - Abort
		char	*dest30;  
		char	*dest40;

		dest30 = (char *)malloc(sizeof(*dest30) * 15);
			if (dest30 == 0)
				return (1);
		memset(dest30, 'r', 15);
		//dest30[14] = '\0';
		dest40 = (char *)malloc(sizeof(*dest40) * 15);
			if (dest40 == 0)
				return (1);
		memset(dest40, 'r', 15);
		//dest40[14] = '\0';
	
		//printf("101 - returns: %lu - dest: '%s'\n", 
		//	ft_strlcat(dest30, "lorem ipsum dolor sit amet", 5), dest30);
		write(1, "'", 1);
		write(1, dest30, 15);
		write(1, "'", 1);
		
			
		//printf("\n101b - returns: %lu - dest: '%s'\n", 
		//	ft_strlcat(dest40,"lorem ipsum dolor sit amet", 5), dest40);
		write(1, "'", 1);
		write(1, dest40, 15);
		write(1, "'", 1);

		free(dest30);
		free(dest40);

		return (0);
} */
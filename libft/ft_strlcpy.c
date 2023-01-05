/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:08:43 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/21 11:52:03 by mgranero         ###   ########.fr       */
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

strlcpy() copies up to dstsize - 1 characters from the string src to dst,
NUL-terminating the result if dstsize is not 0

RETURN VALUES
Besides quibbles over the return type (size_t versus int) and signal han-
dler safety (snprintf(3) is not entirely safe on some systems), the follow-
ing two are equivalent:

	n = strlcpy(dst, src, len);
	n = snprintf(dst, len, "%s", src);

Like snprintf(3), the strlcpy() and strlcat() functions return the total
length of the string they tried to create.  For strlcpy() that means the
length of src.  For strlcat() that means the initial length of dst plus the
length of src.

If the return value is >= dstsize, the output string has been truncated.
It is the caller's responsibility to handle this.

size_t
strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);

first version
size_t	ft_strlcpy(char *restrict dst,
	const char *restrict src, size_t dstsize)

version without restrict

*/

#include "libft.h"

size_t	ft_strlcpy(char *dst,
	const char *src, size_t dstsize)
{
	size_t	cnt;
	int		i;
	int		sw;

	cnt = 0;
	i = 0;
	sw = 0;
	if (dstsize == 1)
	{
		dst[0] = '\0';
		return (ft_strlen(src));
	}
	while (src[cnt] != '\0')
	{
		cnt++;
		if (dstsize > 0 && cnt < dstsize)
		{
			sw = 1;
			dst[i] = src[i];
			i++;
		}
	}
	if (sw == 1 || (src[0] == '\0' && dstsize > 0))
		dst[i] = '\0';
	return (cnt);
}

/*
#include <string.h>
#include <stdio.h>


int main(void)
{	
	const char 	somestring[] = "foo2sdlksjflkj";
	char 		buf[13] = "";
	char 		buf2[13] = "";
	size_t	output;
	size_t	output2;

	// test values for buf
	// buffer smaller than somestring buf[3] and somestring [14]
	// buffer equal than somestring buf[14] and somestring [14]
	// buffer bigger than somestring buf[15] and somestring [14]
	// buffer bigger than somestring buf[20] and somestring [14]
	
	output = 0;
	output = ft_strlcpy(buf, somestring, sizeof(buf));
	printf("Ist:  buffer is: '%s' and return value = %lu\n",
		buf, output);

	output2 = strlcpy(buf2, somestring, sizeof(buf2));
	printf("Soll: buffer is: '%s' and return value = %lu",
		buf2, output2);

	return (0);
}

int main(void)
{
	//char *str = "BBBB";
	char *str = "";
	char buff1[15] = "B";
	char buff2[15] = "B";
	//size_t size = 0;

	printf("IST  : returns %lu and '%s'\n",
				ft_strlcpy(buff1, str, sizeof(buff1)), buff1);
	printf("SOLL : returns %lu and '%s'\n",
				strlcpy(buff2, str, sizeof(buff2)),buff2);
	return (0);
}

//libft


int main(void)
{
		//3
		//check(ft_strlcpy(dest, src, 2) == strlen(src)//
		 //&& dest[0] == 'c' && dest[1] == 0 
		 //&& dest[2] == 'A'); showLeaks();
		char src[] = "coucou";
		char dest[10]; memset(dest, 'A', 10);
		char dest2[10]; memset(dest, 'A', 10);
		//ft_strlcpy(dest, src, 2);

			printf("IST  : returns %lu and '%s'\n",
				ft_strlcpy(dest, src,1), dest);
			printf("SOLL : returns %lu and '%s'\n",
				strlcpy(dest2, src, 1),dest2);
		if(ft_strlcpy(dest, src, 1) == strlen(src) &&
		dest[0] == 'c' && dest[1] == 0  &&
		dest[2] == 'A') //showLeaks();
			printf("Pass");
		else	
			printf("Fail");

	return (0);

}*/
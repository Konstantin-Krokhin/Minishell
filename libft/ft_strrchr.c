/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:27:16 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/22 09:45:36 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>

NAME
strchr, strrchr -- locate character in string

DESCRIPTION
The strchr() function locates the first occurrence of c (converted to a char) 
in the string pointed to by s.  The terminating null character is considered 
to be part of the string;
therefore if c is `\0', the functions locate the terminating `\0'.

The strrchr() function is identical to strchr(), except it locates the last 
occurrence of
c.

RETURN VALUES
The functions strchr() and strrchr() return a pointer to the located 
character, or NULL if the character does not appear in the string.	

char *
     strrchr(const char *s, int c);

*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_out;
	char	*st_out;
	int		i;

	if (s == 0)
		return (NULL);
	if (c > 255)
		c = c - 256;
	c_out = '\0';
	st_out = &c_out;
	i = ft_strlen(s);
	while (i >= 0)
	{		
		if (s[i] == c)
		{
			st_out = (char *)s;
			return (st_out + i);
		}
		else if (i == 0)
			break ;
		i--;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
//
int main(void)
{
char	str[] = "pn9a8 zg+-.a";
//char	c = 'p';
//char	c = 'a';
char	c = '8';
// 	//char	c = ' ';
// 	//char	c = '\0';
char	*p_ist = NULL;
char	*p_soll = NULL;
//
p_ist = ft_strrchr(str, c);
p_soll = strrchr(str, c);
if (p_ist == p_soll)
{
	printf("\nPASS\n");
}
else
{
	printf("FAIL");
}

printf("IST:  find '%c': result : '%c'\n", c, *p_ist);
printf("SOLL: find '%c': result : '%c'\n", c, *p_soll);
//
 	return (0);
}


#include <string.h>
#include <stdio.h>

// int	main(void)
// {
// 	char *src = "\0";
// 	char *d1 = strrchr(src, 'a');
// 	char *d2 = ft_strrchr(src, 'a');

// 	printf("SOLL: '%s'\n", d1);
// 	printf("IST : '%s'\n", d2);
// 	if (d1 == d2)
// 		printf("Pass");
// 	printf("Fail");
// 	return (0);
// }


int	main(void)
{
	char 	*src = "123456789";
	char	*ptr_ist = 0;
	char 	*ptr_soll = 0;

	ptr_ist = ft_strrchr(src, 'a');
	ptr_soll = strrchr(src, 'a');
	printf("SOLL: '%s' and address %p\n", ptr_soll, (void *)ptr_soll);
	printf("IST : '%s' and address %p\n", ptr_ist, (void *)ptr_ist);
	return (0);
}


#include <stdio.h>

int main(void)
{
	char	str3[] = "";
	char		*str;

	if (!(str = ft_strrchr(str3, '\0')))
		printf("PASS\n");
	printf("IST: '%s'",ft_strrchr(str3, '\0') );	
	return (0);
}

#include <stdio.h>
#include <string.h>


int main(void)
{
	char	str[] = "tripouille";
	char	*str_ist;
	char	*str_soll;
	char	str_leer[] = "";

	str_ist = ft_strrchr(str, 't');
	str_soll = strrchr(str, 't');
	printf("SOLL: '%s'\n", str_soll);	
	printf("IST: '%s'\n", str_ist);	

	str_ist = ft_strrchr(str, 0);
	str_soll = strrchr(str, 0);
	printf("SOLL: '%s'\n", str_soll);	
	printf("IST: '%s'\n", str_ist);	

	str_ist = ft_strrchr(str_leer, 0);
	str_soll = strrchr(str_leer, 0);
	printf("SOLL: '%s'\n", str_soll);	
	printf("IST: '%s'\n", str_ist);	

	str_ist = ft_strrchr(NULL, 0);
	str_soll = strrchr(NULL, 0);
	printf("SOLL: '%s'\n", str_soll);	
	printf("IST: '%s'\n", str_ist);	

	return (0);
}*/
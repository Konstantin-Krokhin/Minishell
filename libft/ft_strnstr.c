/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:16:31 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/19 17:55:42 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>
NAME
strstr, strcasestr, strnstr -- locate a substring in a string

DESCRIPTION
The strstr() function locates the first occurrence of the null-terminated 
string needle in the null-terminated string haystack.

The strcasestr() function is similar to strstr(), but ignores the case of 
both strings.

The strnstr() function locates the first occurrence of the null-terminated 
string needle in the string haystack, where not more than len characters 
are searched.  Characters that appear after a `\0' character are not 
searched.  Since the strnstr() function is a FreeBSD specific API, it 
should only be used when portability is not a concern.

While the strcasestr() function uses the current locale, the 
strcasestr_l() function may be passed a locale directly. See 
xlocale(3) for more information.

RETURN VALUES
If needle is an empty string, haystack is returned; if needle occurs
nowhere in haystack, NULL is returned; otherwise a pointer to the 
first character of the first occurrence of needle is returned.

If little is an empty string, big is returned; if little occurs 
nowhere in big, NULL is returned; otherwise a pointer to the first 
character of the first occurrence of little is returned.

char *strnstr(const char *haystack, const char *needle, size_t len);

*/
#include "libft.h"

static char	*ft_loop(const char *haystack, const char *needle, size_t len,
				size_t size_need);
static void	ft_init_parameters(size_t *i, size_t *j, size_t *f1, int *sw);
static void	ft_rst_parameters(size_t *i, size_t *j, size_t *f1, int *sw);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*ptr;
	size_t		size_need;

	ptr = 0;
	size_need = ft_strlen(needle);
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	ptr = ft_loop(haystack, needle, len, size_need);
	return (ptr);
}

static char	*ft_loop(const char *haystack, const char *needle, size_t len,
				size_t size_need)
{
	size_t	i;
	size_t	j;
	size_t	f1;
	int		sw;

	ft_init_parameters(&i, &j, &f1, &sw);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i] == needle[j] && i < len && j < size_need)
		{
			if (sw == 0)
				f1 = i;
			sw = 1;
			if (j == size_need - 1)
				return ((char *)haystack + i - j);
			j++;
			i++;
		}
		if (sw == 1)
			ft_rst_parameters(&i, &j, &f1, &sw);
		i++;
	}
	return (0);
}

static void	ft_init_parameters(size_t *i, size_t *j, size_t *f1, int *sw)
{
	*i = 0;
	*j = 0;
	*sw = 0;
	*f1 = 0;
}	

static void	ft_rst_parameters(size_t *i, size_t *j, size_t *f1, int *sw)
{
	*j = 0;
	*sw = 0;
	*i = *f1;
}	

/*
 #include <string.h>
 #include <stdio.h>

int main(void)
{

	printf("%s", ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15));
	//lorem ipsum dolor sit amet


	//printf("%s", ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
	//NULL
	return(0);
}




// int	main(void)
// {
// 	char		haystack[] = "buscar nessa frase";
// 	// char		needle1[]= "frase";
// 	// char		needle2[]= "buscar";
// 	char		needle3[]= " ";
// 	// char		needle4[]= "\0";
// 	size_t	len_correct = 18;
// 	// size_t	len_smaller = 5;
// 	// size_t	len_bigger = 10;

// 	// printf("SOLL: %s\n", strnstr(haystack, needle1, len_correct));
// 	// printf("IST : %s\n\n", ft_strnstr(haystack, needle1, len_correct));

// 	// printf("SOLL:  %s\n", strnstr(haystack, needle1, len_smaller));
// 	// printf("IST :  %s\n\n", ft_strnstr(haystack, needle1, len_smaller));

// 	// printf("SOLL:  %s\n", strnstr(haystack, needle1, len_bigger));
// 	// printf("IST :  %s\n\n", ft_strnstr(haystack, needle1, len_bigger));

// 	// printf("SOLL:  %s\n", strnstr(haystack, needle2, len_correct));
// 	// printf("IST :  %s\n\n", ft_strnstr(haystack, needle2, len_correct));

// 	printf("SOLL:  %s\n", strnstr(haystack, needle3, len_correct));
// 	printf("IST :  %s\n\n", ft_strnstr(haystack, needle3, len_correct));

// 	//printf("SOLL:  %s\n", strnstr(haystack, needle4, len_correct));
// 	//printf("IST :  %s\n\n", ft_strnstr(haystack, needle4, len_correct));

// 	return (0);
// }


int main(void)
{
	char *s1 = "see FF your FF return FF now FF";
	char *s2 = "FF";
	size_t max = strlen(s1);
	char *i1 = strnstr(s1, s2, max);
	char *i2 = ft_strnstr(s1, s2, max);

	printf("SOLL: pointer: %p and string %c\n", (void *)i1, *i1);
	printf("IST : pointer: %p and string %c\n", (void *)i2, *i2);

	if (i1 == i2)
		printf("PASS");
	else
		printf("FAIL");
	return (0);
}

// libft tester
#include <stdio.h>
#include <string.h>
int main(void)
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	//char * empty = (char*)"";


	char *str = ft_strnstr(haystack, needle, -1);
	printf("%s", str);
	// int t2 = ft_strncmp(ft_strnstr(haystack, needle, -1), 
	// 		(haystack + 1), sizeof(haystack)); //showLeaks();
	//int t2_original = strncmp(ft_strnstr(haystack, needle, -1), 
	//(haystack + 1), sizeof(haystack)); //showLeaks();
	 
	 

	 //int t10 = ft_strncmp(ft_strnstr(haystack, "abcd", 9) , 
	//  (haystack + 5), sizeof(haystack));
	// char *str10 = ft_strnstr(haystack, "abcd", 9);
	// printf("IST : %s\n", str10);
	// printf("SOLL: %s\n", ((haystack + 5)));
	//printf("t2 is %d\n", t2);
	//printf("t2 Original is %d\n", t2_original);
	//printf("t11 is %d\n", t10);

	return (0);

}

#include <stdio.h>
int main(void)
{
	char *str = ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30);
	printf("%s\n", str);

	return (0);
}*/
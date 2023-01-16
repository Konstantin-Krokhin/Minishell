/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:32:02 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2022/05/20 16:49:09 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	substractions(char **ndl, char **hay, size_t *flag, size_t *len)
{
	*ndl -= *flag;
	*hay = *hay - *flag + 1;
	*len += *flag - 1;
	*flag = 0;
}

static char	*ft_loop(char *ndl, char *hay, size_t ndl_size, size_t len)
{
	size_t	flag;

	flag = 0;
	while (len > 0)
	{
		if (*hay == '\0' || *ndl == '\0')
			break ;
		if (*ndl == *hay)
		{
			flag++;
			if (flag == ndl_size)
				break ;
			ndl++;
		}
		else if (ft_strlen(ndl) != ndl_size && flag > 0)
		{
			substractions(&ndl, &hay, &flag, &len);
			continue ;
		}
		len--;
		hay++;
	}
	if (flag == ndl_size && flag != 0)
		return (hay - flag + 1);
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*hay;
	char		*ndl;
	size_t		ndl_size;
	size_t		hay_size;

	hay = (char *)haystack;
	ndl = (char *)needle;
	ndl_size = ft_strlen(ndl);
	hay_size = ft_strlen(hay);
	if (ndl_size == 0 || haystack == needle)
		return ((char *)hay);
	return (ft_loop(ndl, hay, ndl_size, len));
}

// char	*ft_strnstr(const char	*big, const char *little, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	lenl;
// 	char	*src;
// 	i = 0;
// 	src = (char *)big;
// 	lenl = ft_strlen(little);
// 	if (lenl == 0 || big == little)
// 		return (src);
// 	while (big[i] != '\0' && i < len)
// 	{
// 		j = 0;
// 		while (src[i + j] != '\0' && little[j] != '\0'
// 			&& src[i + j] == little[j] && i + j < len)
// 			j++;
// 		if (j == lenl)
// 			return (src + i);
// 		i++;
// 	}
// 	return (NULL);
// }
// int main()
// {
// 	char haystack[30] = "aaabcabcd";
// 	char	*s2 = "MZIRIBMZE";
// 	//size_t	max = ft_strlen(s2);
// 	printf("%s, %s", ft_strnstr(haystack, "cd", 8), strnstr(haystack, "cd", 8));
// 	return(0);
// }
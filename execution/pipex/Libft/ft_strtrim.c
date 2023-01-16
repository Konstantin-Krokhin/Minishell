/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:32:11 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/12 21:24:04 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	start;
	unsigned char	i;
	unsigned char	len;
	char			*rlt;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	len = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (start == len)
		return (ft_strdup(""));
	while (start < len && ft_strchr(set, s1[len]))
		len--;
	len = (len - start + 2);
	rlt = (char *)malloc(sizeof(char) * (len));
	if (!rlt)
		return (NULL);
	len -= 1;
	while (i < len)
		rlt[i++] = s1[start++];
	rlt[i] = '\0';
	return (rlt);
}
// char    *ft_strtrim(char const *s1, char const *set)
// {
//     char    *str;
//     char    *chrset;
//     char    *start;
//     char    *end;
//     char    *result = "";
//     int        setsize;
//     int        i;
//     int        j;
//     if(!s1 || !set)
//         return (0);
//     str = (char *)s1;
//     chrset = (char *)set;
//     setsize = ft_strlen(chrset);
//     i = 0;
//     j = 0;
//     while (*chrset != '\0')
//     {
//         if (*str == *chrset)
//         {
//             str++;
//             chrset -= i;
//             i = 0;
//             j++;
//             continue;
//         }
//         i++;
//         chrset++;
//     }
//     start = str;
//     chrset -= i;
//     str -= j;
//     str += ft_strlen(str) - 1;
//     i = 0;
//     j = 0;
//     while (*chrset != '\0')
//     {
//         if (*str == *chrset)
//         {
//             str--;
//             chrset -= i;
//             i = 0;
//             j++;
//             continue;
//         }
//         i++;
//         chrset++;
//     }
//     end = str;
//     if (start > end)
//         return (0);
//     int size = 0;
//     while (!(start > end))
//     {
//         size++;
//         start++;
//     }
//     start -= size;
//     result = malloc(size * sizeof(char));
//     if (!result)
//         return (0);
//     while (!(start > end))
//     {
//         *result = *start;
//         if (start < end)
//             result++;
//         else
//             result -= (size - 1);
//         start++;
//     }
//     return (result);
// }
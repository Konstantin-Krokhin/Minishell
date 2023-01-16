/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsta <konsta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:31:39 by Konstantin        #+#    #+#             */
/*   Updated: 2022/01/09 18:35:53 by konsta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_size;
	size_t	s2_size;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if ((!s1 && !s2)
		|| (ft_strncmp(s1, s2, s1_size) == 0
			&& ft_strncmp("", s2, s2_size) == 0))
		return (ft_strdup(""));
	str = malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, s1_size);
	ft_memmove(str + s1_size, s2, s2_size);
	str[s1_size + s2_size] = '\0';
	return (str);
}
// static char	*loop(char *str, size_t i, char *ss1, char *ss2)
// {
// 	size_t	s1_len;
// 	size_t	s2_len;
// 	s1_len = ft_strlen(ss1);
// 	s2_len = ft_strlen(ss2);
// 	while (i < s1_len)
// 	{
// 		*str++ = *ss1++;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < s2_len)
// 	{
// 		*str++ = *ss2++;
// 		i++;
// 	}
// 	return (str);
// }
// str = loop(str, i, ss1, ss2);
// if (*s1 == '\0' && *s2 == '\0')
// 		return (ft_strdup(""));
// 	if (*s2 == '\0')
// 		return (str - s1_size);
// 	if (*s1 == '\0')
// 		return (str - ft_strlen(s2));
// if (s1 && !s2)
// 	return (ft_strdup(s1));
// if (!s1 && s2)
// 	return (ft_strdup(s2));
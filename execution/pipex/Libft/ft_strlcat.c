/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:56:28 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/09 14:25:41 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	j = dst_len;
	if (dst_len > dstsize)
		return (src_len + dstsize);
	else
	{
		while (src[i] && (dst_len + i) < dstsize)
			dst[j++] = src[i++];
		if ((dst_len + i) == dstsize && dst_len < dstsize)
			dst[--j] = '\0';
		else
			dst[j] = '\0';
	}
	return (src_len + dst_len);
}

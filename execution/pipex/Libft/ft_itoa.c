/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:06:27 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/07 21:06:49 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*return_null_rtn(char **rtn)
{
	*rtn = malloc(sizeof(char) * 2);
	if (!(*rtn))
		return (NULL);
	**rtn = '0';
	(*rtn)++;
	**rtn = '\0';
	return (*rtn - 1);
}

static char	*loop(long nm, int sign, int size, long num)
{
	char	*rtn;

	rtn = 0;
	nm *= sign;
	num = nm;
	while (num >= 1)
	{
		num /= 10;
		size++;
	}
	rtn = malloc(sizeof(char) * (size + 1));
	if (sign == -1)
		rtn[0] = '-';
	rtn[size] = '\0';
	while (nm >= 1 && size > 0)
	{
		rtn[size - 1] = nm % 10 + '0';
		nm /= 10;
		size--;
	}
	return (rtn);
}

char	*ft_itoa(int n)
{
	char	*rtn;
	int		sign;
	long	num;
	int		size;
	long	nm;

	num = 0;
	nm = n;
	rtn = 0;
	sign = 1;
	size = 0;
	if (nm < 0)
	{
		sign = -1;
		size++;
	}
	else if (nm == 0)
		return (return_null_rtn(&rtn));
	rtn = loop(nm, sign, size, num);
	return (rtn);
}

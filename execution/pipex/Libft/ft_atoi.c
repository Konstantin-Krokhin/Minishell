/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:30:33 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/11 12:01:05 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	checks(const char *str, int i)
{
	if ((!(str[i] >= 48 && str[i] <= 57))
		&& (str[i] != '\f' && str[i] != '\t' && str[i] != '\n'
			&& str[i] != '\r' && str[i] != '\v' && str[i] != '\e'
			&& str[i] != '-' && str[i] != '+' && str[i] != ' '))
		return (false);
	if (str[i] == '\e')
		return (false);
	return (true);
}

static int	check_sign(const char *str, size_t i, int sign)
{
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
		sign = -1;
	else if (str[i + 1] >= '0' && str[i + 1] <= '9')
		sign = 1;
	return (sign);
}

static int	loop(const char *str, int sign, size_t i, int numb)
{
	while (i < ft_strlen(str))
	{
		if (checks(str, i) == false)
			break ;
		if (str[i] == '-' || str[i] == '+')
		{
			if (numb != 0)
				break ;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				break ;
			sign = check_sign(str, i, sign);
		}
		if (str[i] >= '0' && str[i] <= '9')
			numb = (numb * 10) + (str[i] - '0');
		else if (numb != 0)
			break ;
		i++;
	}
	return (numb * sign);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	i;
	int		numb;

	i = 0;
	numb = 0;
	sign = 1;
	return (loop(str, sign, i, numb));
}

// static bool check2(const char *str, size_t i)
// {
// 	if (!(str[i + 1] >= 48 && str[i + 1] <= 57)
// 		&& str[i] >= 48 && str[i] <= 57)
// 		return false;
// 	return true;
// }
// static int	loop(const char *str, size_t i, int numb, char sign)
// {
// 	while (i < len)
// 	{	
// 		if ((str[i] == '-' || str[i] == '+')
// 			&& str[i + 1] >= 48 && str[i + 1] <= 57 && numb == 0)
// 		{		
// 			if (i > 0 && (str[i - 1] == '-' || str[i - 1] == '+'))
// 				break ;
// 			i++;
// 			continue ;
// 		}
// 		if (check2(str, i) == false)
// 			break ;
// 	}
// 	if (sign == '-')
// 		return (numb *= -1);
// 	return (numb);
// }
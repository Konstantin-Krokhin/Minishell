/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:48:08 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/07/09 13:31:17 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdecimal(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_printstring("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		i += ft_printchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		i += ft_printdecimal(n / 10);
		i += ft_printdecimal(n % 10);
	}
	if (n < 10 && n != -2147483648)
		i += ft_printchar(n + '0');
	return (i);
}

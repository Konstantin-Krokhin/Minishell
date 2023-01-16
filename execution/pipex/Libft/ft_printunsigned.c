/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:00:45 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/07/09 13:30:43 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
		return (0);
	if (n >= 10)
	{
		i += ft_printunsigned(n / 10);
		i += ft_printunsigned(n % 10);
	}
	if (n < 10)
		i += ft_printchar(n + '0');
	return (i);
}

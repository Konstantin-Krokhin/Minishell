/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:12:49 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/07/09 13:30:21 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int hex, const char format)
{
	int	length;

	length = 0;
	if (hex >= 16)
	{
		length += ft_printhex(hex / 16, format);
		length += ft_printhex(hex % 16, format);
	}
	else
	{
		if (hex < 10)
			length += ft_printchar(hex + '0');
		else if (format == 'x')
			length += ft_printchar(hex - 10 + 'a');
		else if (format == 'X')
			length += ft_printchar(hex - 10 + 'A');
	}
	return (length);
}

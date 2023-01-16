/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:35:24 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/07/09 13:31:28 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		length += ft_printstring(va_arg(args, char *));
	else if (format == '%')
		length += ft_printchar('%');
	else if (format == 'p')
		length += ft_printvoid(va_arg(args, unsigned long int));
	else if (format == 'd' || format == 'i')
		length += ft_printdecimal(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		length += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == 'u')
		length += ft_printunsigned(va_arg(args, unsigned int));
	else
		length += ft_printchar(format);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			length += ft_formats(args, *(++format));
		else
			length += ft_printchar(*format);
		format++;
	}
	va_end(args);
	return (length);
}

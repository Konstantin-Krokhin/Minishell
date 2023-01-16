/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:37:14 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/07/09 13:31:11 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printchar(int c);
int	ft_printf(const char *format, ...);
int	ft_printstring(char *str);
int	ft_printvoid(unsigned long int ptr);
int	ft_printdecimal(int n);
int	ft_printhex(unsigned int hex, const char format);
int	ft_printunsigned(unsigned int n);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:22:26 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/22 10:52:49 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.

Paramenter:
	n:  the integer to convert.

Return:
	The string representing the integer.
	NULL if the allocation fails.

char *ft_itoa(int n);
*/

#include "libft.h"

static char	*ft_check_special_case(int n, char *str_out, char *str);
static int	ft_power(int a, int b);
static int	ft_check_negativ(int n, char *str_out);
static int	ft_calcu_write_str(int n, int pow, int *g_i, char *str_out);

char	*ft_itoa(int n)
{
	char	*str;
	int		g_i;
	int		pow;
	char	str_out[12];

	g_i = 9;
	ft_memset(str_out, '\0', 12);
	str = 0;
	str = ft_check_special_case(n, str_out, str);
	if (str != 0)
		return (str);
	n = ft_check_negativ(n, str_out);
	while (g_i >= 0)
	{
		pow = ft_power(10, g_i);
		if (n >= pow)
			n = ft_calcu_write_str(n, pow, &g_i, str_out);
		else
			g_i = g_i - 1;
	}
	str = (char *)ft_calloc((ft_strlen(str_out) + 1), sizeof(char));
	ft_memcpy((void *)str, (void *)str_out, ft_strlen(str_out));
	str[ft_strlen(str_out)] = '\0';
	return (str);
}

static int	ft_calcu_write_str(int n, int pow, int *g_i, char *str_out)
{
	int		h;
	char	c;
	int		i;

	h = n / pow;
	c = h + 48;
	i = 0;
	while (str_out[i] != '\0')
		i++;
	str_out[i] = c;
	n = n - h * pow;
	*g_i = *g_i - 1;
	pow = ft_power(10, *g_i);
	while (n < pow && *g_i >= 0)
	{	
		i = 0;
		while (str_out[i] != '\0')
			i++;
		str_out[i] = '0';
		*g_i = *g_i - 1;
		pow = ft_power(10, *g_i);
	}
	return (n);
}

static int	ft_power(int a, int b)
{
	int	out;
	int	j;

	out = 1;
	j = 1;
	while (j <= b)
	{
		out = out * a;
		j = j + 1;
	}
	return (out);
}

static int	ft_check_negativ(int n, char *str_out)
{
	if (n < 0)
	{
		str_out[0] = '-';
		n = -1 * n;
	}
	return (n);
}

static char	*ft_check_special_case(int n, char *str_out, char *str)
{
	if (n == 0)
	{
		str_out[0] = '0';
		str_out[1] = '\0';
		str = (char *)ft_calloc((ft_strlen(str_out) + 1), sizeof(char));
		ft_memcpy((void *)str, (void *)str_out, ft_strlen(str_out));
		str[ft_strlen(str_out)] = '\0';
		return (str);
	}
	else if (n == -2147483648)
	{
		ft_memcpy(str_out, "-2147483648", (11));
		str_out[12] = '\0';
		str = (char *)ft_calloc((ft_strlen(str_out) + 1), sizeof(char));
		ft_memcpy((void *)str, (void *)str_out, ft_strlen(str_out));
		str[ft_strlen(str_out)] = '\0';
		return (str);
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main(void)
{

	// int		n = -2147483648LL;

	// char	*str_out;

	// check special case function
	//str_out = ft_check_special_case(n);
	
	// str_out = ft_itoa(n);
	// char *soll = "-2147483648";

	// if (ft_strncmp(str_out, soll, strlen(soll)) == 0)
	// 	printf("PASS\n");	
	// else 
	// 	printf("FAIL\n");

	//char *res = ft_itoa(-2147483648LL);
	char *res = ft_itoa(2147483647);
		ft_print_result(res);

	//printf("IST: '%s' and lenght %lu", str_out, strlen(str_out));
	//printf("IST: '%s'\n", str_out);
	free(res);
	return (0);
}


#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(void)
{
	char *s_ist = ft_itoa(-2147483648LL);
	//char *s_soll = itoa(2);

	printf("ist : '%s'\n", s_ist);
	//printf("soll: %s\n", s_soll);

	printf("size output %lu\n", ft_strlen(s_ist));
	printf("Null terminator %d\n", s_ist[ft_strlen(s_ist)]);
	free(s_ist);
	return (0);
}
*/

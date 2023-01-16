/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:59:10 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/22 10:45:35 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_number_char_array(const char *str, int i, char *c_number);
static int	power(int a, int b);
static int	ft_parse_char2int(const char *c_number);
static int	ft_loop(const char *str, int i, int sw, char *c_number);

int	ft_atoi(const char *str)
{
	char	c_number[21];
	int		sw;
	int		out;
	int		i;

	sw = 0;
	out = 0;
	i = 0;
	ft_bzero(c_number, 21);
	if (str[0] != '\0')
		out = ft_loop(str, sw, i, c_number);
	return (out);
}

static int	ft_loop(const char *str, int sw, int i, char *c_number)
{
	int		factor;

	factor = 1;
	while (ft_isdigit(str[i]) == 1 || str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' && sw == 0)
		{
			sw = 1;
			factor = -1;
		}
		else if (str[i] == '+' && sw == 0)
			sw = 1;
		else if (sw == 1 && (str[i] == '+' || str[i] == '-'))
			return (0);
		else if (ft_isdigit(str[i]) == 1 || sw == 1)
		{
			ft_write_number_char_array(str, i, c_number);
			return (factor * ft_parse_char2int(c_number));
		}
		i++;
	}
	return (0);
}

static void	ft_write_number_char_array(const char *str, int i, char *c_number)
{
	int	j;

	j = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]) == 1 && j < 21)
	{
		c_number[j] = str[i];
		i++;
		j++;
	}
	c_number[j] = '\0';
}

static int	power(int a, int b)
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

static int	ft_parse_char2int(const char *c_number)
{
	int		size;
	int		i;
	int		output;

	size = ft_strlen(c_number);
	output = 0;
	i = 0;
	while (i < size)
	{
		output = output + (c_number[i] - 48) * power (10, (size -1 - i));
		i++;
	}
	return (output);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	str1[] = "123";
	char	str2[] = "0.123";
	char	str3[] = "ascvbgree123";
	char	str4[] = "   123";
	char	str5[] = "-123";
	char	str6[] = "-evds123";
	char	str7[] = "evds-123";
	char	str8[] = "evds-0.123";
	char	str9[] = "evds-.123";
	char	str10[] = "evds-.123fesdf22";
	char	str11[] = "123 -21";
	char	str12[] = "asdsaf";
	char	str13[] = "asda -s";
	char	str14[] = "   -444";

	printf("SOLL: input str%d = %d\n", 1, atoi(str1));
	printf("IST: input str%d = %d\n", 1, ft_atoi(str1));
	printf("\n");

	printf("SOLL: input str%d = %d\n", 2, atoi(str2));
	printf("IST: input str%d = %d\n", 2, ft_atoi(str2));
	printf("\n");

	printf("SOLL: input str%d = %d\n", 3, atoi(str3));
	printf("IST: input str%d = %d\n", 3, ft_atoi(str3));
	printf("\n");

	printf("SOLL: input str%d = %d\n", 4, atoi(str4));
	printf("IST: input str%d = %d\n", 4, ft_atoi(str4));
	printf("\n");

	printf("SOLL: input str%d = %d\n", 5, atoi(str5));
	printf("IST: input str%d = %d\n", 5, ft_atoi(str5));
	printf("\n");

	printf("SOLL: input str%d = %d\n", 6, atoi(str6));
	printf("IST: input str%d = %d\n", 6, ft_atoi(str6));
	printf("\n");

	printf("SOLL: input str%d = %d\n", 7, atoi(str7));
	printf("IST: input str%d = %d\n", 7, ft_atoi(str7));
	printf("\n");

	printf("SOLL: input str%d = %d\n", 8, atoi(str8));
	printf("IST: input str%d = %d\n", 8, ft_atoi(str8));
	printf("\n");

	printf("SOLL: input str%d = %d\n", 9, atoi(str9));
	printf("IST: input str%d = %d\n", 9, ft_atoi(str9));
	printf("\n");

	printf("SOLL: input str%d = %d\n", 10, atoi(str10));
	printf("IST: input str%d = %d\n", 10, ft_atoi(str10));
	printf("\n");

	printf("SOLL: input str%d = %d\n", 11, atoi(str11));
	printf("IST: input str%d = %d\n", 11, ft_atoi(str11));
	printf("\n");

	printf("SOLL: input str%d = %d\n", 12, atoi(str12));
	printf("IST: input str%d = %d\n", 12, ft_atoi(str12));
	printf("\n");

	printf("SOLL: input str%d = %d\n", 13, atoi(str13));
	printf("IST: input str%d = %d\n", 13, ft_atoi(str13));	
	printf("\n");

	printf("SOLL: input str%d = %d\n", 14, atoi(str14));
	printf("IST: input str%d = %d\n", 14, ft_atoi(str14));	
	printf("\n");		
	return (0);
}

int main(void)
{
	//char *n = "\t\v\f\r\n \f-06050";

	//char *n = "\t\v\f\r\n \f-06050";
	//char *n = "2147483647";
	//char *n = "-2147483648";

	//int i1 = atoi(n);
	//int i2 = ft_atoi(n);
	//char n[40] = "\t\v\f\r\n \f+\t\v\f\r\n \f1234"; // should return 0
	//char n[40] = "+\t\v\f\r\n \f1234"; // should return 0
	//char *n = "\t\v\f\r\n \f	06050"; // should return 0

	//char n[40] = "999999999999";
	char n[40] = "99999999999999999999999999";
	//char n[40] = "-99999999999999999999999999";
	//char n[40] = "18446744073709551615";

	//printf("TEST Print :   %d\n",-1);			
	printf("input string: '%s'\n", n);
	printf("SOLL:   %d\n", atoi(n));
	int i2 = ft_atoi(n);
	printf("IST :   %d\n",i2);	
	
	
	return (0);
}


#include <stdio.h>

int main(void)
{

	printf("%d\n", ft_atoi("-54"));

	return (0);
}*/
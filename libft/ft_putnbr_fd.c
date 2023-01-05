/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:13:31 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/09 15:14:14 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Outputs the integer ’n’ to the given file
descriptor.

Parameters:
	n:  The integer to output.
	fd:  The file descriptor on which to write.

void ft_putnr_fd(int n, int fd);

Piscine C01:

ex07
Create a function that displays the number entered as a parameter. 
The function has to be able to display all possible values within an 
int type variable.

Range of int type
2 bytes : -32,768 to 32,767 
4 bytes : -2,147,483,648 to 2,147,483,647

Prototype:
void ft_putnbr(int nb)

helper function expon 
helper functions calculates the power of a number : expon(a,b) = a^b

First Check : if input value is zero, write 0 and finish the function
if the value was not "0", check if it is negative. If negative, insert 
the "-" sign
if the input values is higher or equal to the current value of e
divide the value of nb for the exponential i in the base 10 go 
the multiplier
Calculates the rest
if the next value is not one power less the before, a "0" should be 
placed in decrements the value of i and calculates the new power of 10

*/

#include "libft.h"

static int		expon(int a, int b);
static int		ft_check_special_case(int n, int fd);
static int		ft_check_print_negativ(int n, int fd);
static int		ft_calcu_print(int n, int e, int fd, int *g_i);

void	ft_putnbr_fd(int n, int fd)
{
	int		e;
	int		i;
	int		*g_i;

	i = 9;
	g_i = &i;
	if (ft_check_special_case(n, fd) == 1)
		return ;
	else
	{	
		n = ft_check_print_negativ(n, fd);
		while (i >= 0)
		{
			e = expon(10, i);
			if (n >= e)
			{
				n = ft_calcu_print(n, e, fd, g_i);
			}
			else
			{
				i = i - 1;
			}
		}
	}
}

static int	expon(int a, int b)
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

static int	ft_check_print_negativ(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		c = 45;
		write(fd, &c, 1);
		n = -1 * n;
	}
	return (n);
}

static int	ft_calcu_print(int n, int e, int fd, int *g_i)
{
	char	c;
	int		h;

	h = n / e;
	c = h + 48;
	write(fd, &c, 1);
	n = n - h * e;
	*g_i = *g_i - 1;
	e = expon(10, *g_i);
	while (n < e && *g_i >= 0)
	{	
		write(fd, "0", 1);
		*g_i = *g_i - 1;
		e = expon(10, *g_i);
	}
	return (n);
}

static int	ft_check_special_case(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	return (0);
}

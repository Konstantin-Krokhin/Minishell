/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:39:30 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/16 23:29:33 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <ctype.h>

NAME
tolower, tolower_l -- upper case to lower case letter conversion

DESCRIPTION
The tolower() function converts an upper-case letter to the corresponding 
lower-case letter.  The
argument must be representable as an unsigned char or the value of EOF.

Although the tolower() function uses the current locale, the tolower_l() 
function may be passed a
locale directly. See xlocale(3) for more information.
RETURN VALUES
If the argument is an upper-case letter, the tolower() function returns 
the corresponding lower-
case letter if there is one; otherwise, the argument is returned unchanged.

+32 = Shift from range of 'A' = 65 to 'a' = 97 

int tolower(int c);
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
	}
	return (c);
}

/*
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char c = 'A';
	char c2 = 'Z';
	char c3 = '+';
	char c4 = 'h';

	printf("IST:  input = %c and return = %c\n", c, ft_tolower(c));
	printf("SOLL: input = %c and return = %c\n\n", c, tolower(c));

	printf("IST:  input = %c and return = %c\n", c2, ft_tolower(c2));
	printf("SOLL: input = %c and return = %c\n\n", c2, tolower(c2));

	printf("IST:  input = %c and return = %c\n", c3, ft_tolower(c3));
	printf("SOLL: input = %c and return = %c\n\n", c3, tolower(c3));

	printf("IST:  input = %c and return = %c\n", c4, ft_tolower(c4));
	printf("SOLL: input = %c and return = %c\n\n", c4, tolower(c4));

	return (0);
	
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:22:51 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/17 10:50:42 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <ctype.h>
NAME
toupper, toupper_l -- lower case to upper case letter conversion

DESCRIPTION
The toupper() function converts a lower-case letter to the corresponding 
upper-case letter.  The argument must be representable as an
unsigned char or the value of EOF.

Although the toupper() function uses the current locale, the toupper_l() 
function may be passed a locale directly. See xlocale(3) for
more information.

RETURN VALUES
If the argument is a lower-case letter, the toupper() function returns 
the corresponding upper-case letter if there is one; other-
wise, the argument is returned unchanged.

-32 = Shift from range of 'a' = 97 to 'A' = 65

int toupper(int c);
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return (c);
}

/*
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char c = 'a';
	char c2 = 'z';
	char c3 = '+';
	char c4 = 'H';

	printf("IST:  input = %c and return = %c\n", c, ft_toupper(c));
	printf("SOLL: input = %c and return = %c\n\n", c, toupper(c));

	printf("IST:  input = %c and return = %c\n", c2, ft_toupper(c2));
	printf("SOLL: input = %c and return = %c\n\n", c2, toupper(c2));

	printf("IST:  input = %c and return = %c\n", c3, ft_toupper(c3));
	printf("SOLL: input = %c and return = %c\n\n", c3, toupper(c3));

	printf("IST:  input = %c and return = %c\n", c4, ft_toupper(c4));
	printf("SOLL: input = %c and return = %c\n\n", c4, toupper(c4));

	return (0);
	
}*/
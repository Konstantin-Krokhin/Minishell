/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:03:23 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/16 23:16:27 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <ctype.h>

NAME
isdigit, isnumber -- decimal-digit character test

DESCRIPTION
The isdigit() function tests for a decimal digit character.  Regardless 
of locale, this includes the following characters only:

``0''         ``1''         ``2''         ``3''         ``4''
``5''         ``6''         ``7''         ``8''         ``9''

The isnumber() function behaves similarly to isdigit(), but may 
recognize additional characters, depending on the current locale setting.

The value of the argument must be representable as an unsigned char
or the value of EOF.

RETURN VALUES
The isdigit() and isnumber() functions return zero if the 
character tests false and return non-zero if the character
tests true.

int isdigit(int c);
*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int main(void)
{
//     Test Cases Inputs
    int size_a = 10;
    char c[10] = {'0', '9', 'A', '+', '@', 
                   '5', ' ', '*', '#', '\0' };
    int i;

    i = 0;
    printf("\n--TEST CASES: ft_isdigit--\n\n");
    while (i < size_a)
    {
        printf("Input is %c - ", c[i]);
        if (ft_isdigit(c[i]) == isdigit(c[i]))
        {
            printf("PASS\n");
        }
        else
        {
        printf("FAIL: \n"); 
        printf("      IST:  ft_isdigit output: %d\n", ft_isdigit(c[i]));
        printf("      SOLL:    isdigit output: %d\n", isdigit(c[i]));    
        }
        printf("\n");
        i++;
    }
    return (0);
}*/
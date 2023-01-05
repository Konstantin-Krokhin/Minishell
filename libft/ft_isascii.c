/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:13:42 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/16 23:16:04 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <ctype.h>

NAME
isascii -- test for ASCII character

DESCRIPTION
The isascii() function tests for an ASCII character, which is any character 
between 0 and octal 0177 inclusive.

int isascii(int c);
*/

int	ft_isascii(int c)
{
	if (c >= '\0' && c <= '\177')
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
                   '5', ' ', '*', '#', '\0'};
    int i;

    i = 0;
    printf("\n--TEST CASES: ft_isascii--\n\n");
    while (i < size_a)
    {
        printf("Input is %c - ", c[i]);
        if (ft_isascii(c[i]) == isascii(c[i]))
        {
            printf("PASS\n");
        }
        else
        {
        printf("FAIL: \n"); 
        printf("      IST:  ft_isascii output: %d\n", ft_isascii(c[i]));
        printf("      SOLL:    isascii output: %d\n", isascii(c[i]));    
        }
        printf("\n");
        i++;
    }
    return (0);
}*/
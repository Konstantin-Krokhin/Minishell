/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:49:00 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/16 23:22:32 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Outputs the character ’c’ to the given file
descriptor.

Parameter:
	c:  The character to output.
	fd:  The file descriptor on which to write.
		0 standard input
		1 standard output
		2 standard error


Return Value:
	Outputs the character ’c’ to the given file
	descriptor.

void ft_putchar_fd(char c, int fd);
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int	main(void)
{

	char	c = 'z';

	ft_putchar_fd(c , 1);
	c = 'K';
	ft_putchar_fd(c , 0);
	c = '+';
	ft_putchar_fd(c , 2);

}*/
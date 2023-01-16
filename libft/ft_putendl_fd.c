/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:08:44 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/21 12:07:48 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Outputs the string ’s’ to the given file descriptor
followed by a newline.

Parameters:
	s:  The string to output.
	fd:  The file descriptor on which to write.

void ft_putendl_fd(char *s, int fd);
*/
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (s == 0)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

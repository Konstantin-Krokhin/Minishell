/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:17:21 by Konstantin        #+#    #+#             */
/*   Updated: 2022/08/01 20:45:36 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef PUTCHAR
# define PUTCHAR

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
#endif

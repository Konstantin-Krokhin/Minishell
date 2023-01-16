/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:06:27 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/07 21:06:49 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	nm;

	nm = 0;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n == 0)
			ft_putchar_fd(0 + '0', fd);
		else if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
		else if (n < 0)
		{
			n *= -1;
			write (fd, "-", 1);
			ft_putnbr_fd(n, fd);
		}
		else if (n > 0)
			ft_putchar_fd(n + '0', fd);
	}
}
// nbrs = "";
// while (n >= 1)
// {
// 	nbrs[i] = (n % 10) + '0';
// 	n /= 10;
// 	i++;
// }
// i -= 1;
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:26:04 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/07/28 19:03:33 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printstring(char *str)
{
	if (!str)
		return (ft_printstring("(null)"));
	return (write(1, str, ft_strlen(str)));
}

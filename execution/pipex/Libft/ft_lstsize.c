/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:06:26 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/10 13:30:58 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;

	len = 1;
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
			len++;
		}
	}
	else
		return (0);
	return (len);
}

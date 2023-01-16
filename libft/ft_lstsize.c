/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:21:15 by mgranero          #+#    #+#             */
/*   Updated: 2022/10/28 14:17:57 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Counts the number of nodes in a list.

Parameter:
lst: The beginning of the list.

Return:
The length of the list

int ft_lstsize(t_list *lst);
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		cnt;

	if (lst == 0)
		return (0);
	cnt = 0;
	curr = lst;
	while (curr != 0)
	{
		curr = curr->next;
		cnt++;
	}
	return (cnt);
}

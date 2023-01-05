/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:38:07 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/16 18:23:50 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns the last node of the list.

Parameter:
	lst:  The beginning of the list.
Return:
	Last node of the list
t_list *ft_lstlast(t_list *lst);
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (lst == 0)
		return (0);
	curr = lst;
	while (curr->next != 0)
	{
		curr = curr->next;
	}
	return (curr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:28:36 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/20 18:14:12 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Adds the node ’new’ at the end of the list.

Parameter:
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.

Return Values:
None

Loop to find the root node when next = 0

void ft_lstadd_back(t_list **lst, t_list *new);
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}	
	curr = *lst;
	while (curr->next != 0)
	{
		curr = curr->next;
	}
	curr->next = new;
}

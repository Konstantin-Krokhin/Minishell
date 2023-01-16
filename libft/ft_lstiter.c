/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:39:58 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/16 19:09:28 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Iterates the list ’lst’ and applies the function ’f’ on the content of 
each node.

Parameters:
lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.

Return:
None

void ft_lstiter(t_list *lst, void (*f)(void *));

*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	curr = lst;
	while (curr != 0)
	{
		f(curr->content);
		curr = curr->next;
	}
}

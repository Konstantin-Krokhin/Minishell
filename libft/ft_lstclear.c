/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:14:28 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/20 19:24:13 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Deletes and frees the given node and every successor of that node, using the 
function ’del’ and free(3). 
Finally, the pointer to the list must be set to NULL.

Parameter:
lst: The address of a pointer to a node.
del: The address of the function used to delete the content of the node.

Return:
None

void ft_lstclear(t_list **lst, void (*del)(void *));

*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*tmp;

	curr = *lst;
	while (curr != 0)
	{
		tmp = curr;
		curr = curr->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = 0;
}

/*

#include <stdio.h>
#include <unistd.h>

void	print_list(t_list *list)
{
	char	*str;

	printf("main list pointer: %p\n", list);
	str = (char *)(list->content);
	while (list)
	{
		str = (char *)list->content;
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
		list = list -> next;
		printf("created print list pointer: %p\n", list);
	}
}


int main(void)
{
	t_list *l = ft_lstnew("contentA");

	l->next = ft_lstnew("contentB");

	printf("\nList created: \n");
	print_list(l);
	printf("\n");
	ft_lstclear(&l, (void *)ft_lstdelone);
	//write(2, "", 1);
	// if (!l)
	// 	printf("PASS");
	// printf("PASS");
}*/
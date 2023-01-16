/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:35:11 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/16 23:19:09 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’.  The variable
’next’ is initialized to NULL.

Parameter:
	content:  The content to create the node with
Return:
	The new node

t_list *ft_lstnew(void *content);
First call to create the first element of the list
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list0;

	list0 = 0;
	list0 = malloc(sizeof(t_list));
	if (list0)
	{
		list0->content = content;
		list0->next = NULL;
	}
	return (list0);
}

/*
void	print_list(t_list *list)
{
	char	*str;

	str = (char *)(list->content);
	while (list)
	{
		str = (char *)list->content;
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
		list = list -> next;
	}
}


#include <stdio.h>
int main(void)
{
	char *data = "hello, i'm a data";
	t_list *l = ft_lstnew(data);
	printf("Adreess: %p\n", l);
	print_one_list(l);
	return (0);
}
*/
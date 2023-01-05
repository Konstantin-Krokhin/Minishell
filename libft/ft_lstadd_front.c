/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:57:50 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/16 21:38:41 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Adds the node ’new’ at the beginning of the list.

Parameter:
	lst:  The address of a pointer to the first link of
	a list.
	new:  The address of a pointer to the node to be
	added to the list.

Return:
	Nothing

void ft_lstadd_front(t_list **lst, t_list *new);

*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>
#include <string.h>

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

int main(void)
{
	t_list *l = ft_lstnew(strdup("nyacat"));
	t_list *n = ft_lstnew(strdup("OK"));
	ft_lstadd_front(&l, n);
	//print_list(n);
	printf("%s\n", l->content);
	if (l == n && !strcmp(l->content, "OK"))
		printf("PASS\n");
	else	
		printf("PASS\n");
	return (0);
}*/
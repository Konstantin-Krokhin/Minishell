/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranero <mgranero@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:39:04 by mgranero          #+#    #+#             */
/*   Updated: 2022/05/21 11:29:34 by mgranero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Iterates the list ’lst’ and applies the function
’f’ on the content of each node.  Creates a new
list resulting of the successive applications of
the function ’f’.  The ’del’ function is used to
delete the content of a node if needed.

Parameter:
	lst:  The address of a pointer to a node.
	f:  The address of the function used to iterate on
	the list.
	del:  The address of the function used to delete
	the content of a node if needed.
Returns:
	The new list.
	NULL if the allocation fails.

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*new_root;
	t_list	*new_node;

	if ((f == 0 && del == 0) || lst == 0)
		return (NULL);
	curr = lst;
	new_root = ft_lstnew(f(curr->content));
	curr = curr->next;
	while (curr != 0)
	{	
		new_node = ft_lstnew(f(curr->content));
		if (new_node == 0 && del != 0)
		{
			ft_lstclear(&new_root, del);
			return (NULL);
		}
		ft_lstadd_back(&new_root, new_node);
		curr = curr->next;
	}
	return (new_root);
}

/*

#include <string.h>
#include <stdio.h>

void *		lstmap_f(void *content) {
	(void)content;
	//return (content);
	return ("OK !");
}

void	print_list_int(const t_list *list)
{
	char	*str;
	int    *pt;


	while (list)
	{
		pt = (int *)(list->content);
		str = ft_itoa(*pt);
		//ft_putstr_fd(str, 1);
		printf("%s", str);
		printf(" - adress: %p\n", list);
		ft_putchar_fd('\n', 1);
		list = list -> next;
	}
}

void	print_list_char(const t_list *list)
{
	char	*str;

	printf(" - adress: %p", list);
	while (list)
	{
		printf(" - adress: %p", list);
		str = (char *)(list->content);
		ft_putstr_fd(str, 1);
		
		ft_putchar_fd('\n', 1);
		list = list -> next;
	}
}




//warmaschine
int main(void)
{
	t_list *l = ft_lstnew(" 1 2 3 ");
	t_list *ret;

	l->next = ft_lstnew("ss");
	l->next->next = ft_lstnew("-_-");
	printf("before lstmap \n");
	print_list(l);
	ret = ft_lstmap(l, lstmap_f, ((void *)0));
	printf("\n\nafter lstmap \n");
	print_list(ret);
	// if (!strcmp(ret->content, "OK !") && 
	// !strcmp(ret->next->content, "OK !") && 
	// !strcmp(ret->next->next->content, "OK !") 
	// && !strcmp(l->content, " 1 2 3 ") &&
	 !strcmp(l->next->content, "ss") 
	// && !strcmp(l->next->next->content, "-_-"))
	// 	printf("PASS");
	// else	
	// 	printf("FALSE");
	return (0);
}


//libft_tester
void * addOne(void * p) {void * r = malloc(sizeof(int));
*(int*)r = *(int*)p * 10 + 2; return (r);}
void freeList(t_list *head) {if (head)
freeList(head->next); free(head);}


int main(void)
{
	int tab[] = {0, 1, 2, 3};
	t_list * l =  ft_lstnew(tab);
	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	
	printf("before lstmap \n");
	print_list_int(l);
	//t_list * m = ft_lstmap(l, addOne, NULL);
	t_list * m = ft_lstmap(l, addOne, free);
	// t_list * m = ft_lstmap(l, lstmap_f, free);

	printf("\nafter lstmap m =  \n");
	 print_list_int(m);
	 //printf("\nnand inputs is still\n");
	  //print_list_int(l);
	// printf("\nafter lstmap l =  \n");
	// print_list_int(l);

	return (1);
}
*/
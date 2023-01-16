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

t_list	*ft_lstmap(t_list *lst,
						void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstprev;
	t_list	*ret;
	t_list	*new;
	void	*nailed;

	ret = NULL;
	new = NULL;
	lstprev = lst;
	while (lstprev)
	{
		nailed = f(lstprev->content);
		if (nailed)
		{
			new = ft_lstnew(nailed);
			if (!new)
			{
				ft_lstclear(&lst, del);
				ret = NULL;
			}
			ft_lstadd_back(&ret, new);
		}
		lstprev = lstprev->next;
	}
	return (ret);
}
// while (lst && f && del)
// {
// 	l = ft_lstnew(f(lst->content));
// 	ft_lstdelone(lst, del);
// 	l = l->next;
// 	lst = lst->next;
// }
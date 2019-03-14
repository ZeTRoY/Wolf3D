/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 11:54:27 by aroi              #+#    #+#             */
/*   Updated: 2018/03/30 16:19:10 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freelst(t_list **lst)
{
	t_list *buff;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		buff = *lst;
		*lst = (*lst)->next;
		free(buff);
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*new_first;

	if (lst == 0 || lst->content == 0 || f == 0)
		return (0);
	new = ft_lstnew(lst->content, lst->content_size);
	if (!new)
		return (0);
	new = f(new);
	new_first = new;
	lst = lst->next;
	while (lst)
	{
		new_first->next = ft_lstnew(lst->content, lst->content_size);
		if (!new_first->next)
		{
			freelst(&new);
			return (0);
		}
		new_first->next = f(new_first->next);
		lst = lst->next;
		new_first = new_first->next;
	}
	return (new);
}

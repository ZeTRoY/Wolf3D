/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 10:57:29 by aroi              #+#    #+#             */
/*   Updated: 2018/03/28 18:44:48 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == 0)
		return (0);
	if (content == 0)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->content = (void *)malloc(content_size);
		if (lst->content == 0)
		{
			free(lst);
			return (0);
		}
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	lst->next = 0;
	return (lst);
}

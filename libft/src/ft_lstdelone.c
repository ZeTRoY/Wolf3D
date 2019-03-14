/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 11:20:55 by aroi              #+#    #+#             */
/*   Updated: 2018/03/28 15:44:58 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;

	if (alst == 0 || *alst == 0 || del == 0)
		return ;
	lst = *alst;
	del(lst->content, lst->content_size);
	free(lst);
	lst = 0;
	*alst = lst;
}

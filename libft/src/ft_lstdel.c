/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 11:31:02 by aroi              #+#    #+#             */
/*   Updated: 2018/03/27 21:17:24 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;

	if (alst == 0 || del == 0 || *alst == 0)
		return ;
	while (*alst)
	{
		lst = *alst;
		*alst = (*alst)->next;
		ft_lstdelone(&lst, del);
	}
}

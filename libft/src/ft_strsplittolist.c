/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplittolist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:58:15 by aroi              #+#    #+#             */
/*   Updated: 2018/03/29 16:47:56 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_strsplittolist(char const *s, char c)
{
	int		i;
	char	**strarr;
	t_list	*list;
	t_list	*iter;

	i = 0;
	if (s == 0)
		return (0);
	strarr = ft_strsplit(s, c);
	if (strarr == 0 || strarr[0] == 0)
		return (0);
	if (!(list = ft_lstnew(strarr[i], ft_strlen(strarr[i]))))
		return (0);
	iter = list;
	while (strarr[++i])
	{
		iter->next = ft_lstnew(strarr[i], ft_strlen(strarr[i]));
		if (iter->next == 0)
			return (list);
		iter = iter->next;
	}
	ft_freearr((void **)strarr);
	return (list);
}

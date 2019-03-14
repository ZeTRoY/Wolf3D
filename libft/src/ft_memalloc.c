/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:45:40 by aroi              #+#    #+#             */
/*   Updated: 2018/04/01 11:52:18 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*memarea;
	int		i;

	i = 0;
	memarea = (char *)malloc(size);
	if (memarea && (int)size >= 0)
	{
		while ((size_t)i < size)
			memarea[i++] = 0;
		return ((void *)memarea);
	}
	return ((void *)0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:58:07 by aroi              #+#    #+#             */
/*   Updated: 2018/03/30 16:05:49 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	if (dst && src)
	{
		if (size > j)
		{
			while (i < size - j - 1 && src[i])
			{
				dst[j + i] = src[i];
				i++;
			}
			dst[j + i] = '\0';
			return (ft_strlen(src) + j);
		}
		else
			return (ft_strlen(src) + size);
	}
	return (ft_strlen(src));
}

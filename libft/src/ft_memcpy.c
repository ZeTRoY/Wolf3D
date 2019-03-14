/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:11:30 by aroi              #+#    #+#             */
/*   Updated: 2018/03/25 16:51:00 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *new_dst;
	unsigned char *new_src;

	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	while (n-- > 0)
		*new_dst++ = *new_src++;
	return (dst);
}

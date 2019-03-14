/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:25:16 by aroi              #+#    #+#             */
/*   Updated: 2018/07/14 04:12:57 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uitoa_base(uintmax_t n, int base)
{
	char	*str;
	int		i;

	str = 0;
	i = ft_count_udigits_base(n, base) + 1;
	if (!(str = (char *)malloc(i)))
		return (str);
	str[--i] = '\0';
	if (n == 0)
		str[0] = '0';
	while (i-- > 0)
	{
		if (n % base <= 9)
			str[i] = n % base + '0';
		else
			str[i] = n % base + 87;
		n /= base;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 09:06:56 by aroi              #+#    #+#             */
/*   Updated: 2018/07/14 04:26:19 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_uitoa(uintmax_t n)
{
	char	*str;
	int		i;

	i = ft_count_udigits_base(n, 10);
	str = 0;
	if (!(str = (char *)malloc(i + 1)))
		return (str);
	if (n == 0)
		str[0] = '0';
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:48:59 by aroi              #+#    #+#             */
/*   Updated: 2018/07/14 04:21:26 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t		ft_upow(uintmax_t n, int base)
{
	uintmax_t	z;

	z = (uintmax_t)n;
	if (base < 0)
	{
		ft_putstr("\tEnter positive base, please.\n");
		return (0);
	}
	if (base == 0)
		return (1);
	while (base-- > 1)
		z *= n;
	return (z);
}

intmax_t		ft_pow(intmax_t n, int base)
{
	intmax_t	z;

	z = n;
	if (base < 0)
	{
		ft_putstr("\tEnter positive base, please.\n");
		return (0);
	}
	if (base == 0)
		return (1);
	while (base-- > 1)
		z *= n;
	return (z);
}

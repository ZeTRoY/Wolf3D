/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 18:26:55 by aroi              #+#    #+#             */
/*   Updated: 2018/07/14 04:20:35 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_udigits_base(uintmax_t n, int base)
{
	int qnt;

	qnt = 0;
	if (n == 0)
		qnt++;
	while (n > 0)
	{
		n /= base;
		qnt++;
	}
	return (qnt);
}

int		ft_count_digits_base(intmax_t n, int base)
{
	int	qnt;

	qnt = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		qnt++;
	}
	return (qnt);
}

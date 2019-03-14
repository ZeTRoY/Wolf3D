/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:22:25 by aroi              #+#    #+#             */
/*   Updated: 2018/07/14 04:24:09 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(uintmax_t n)
{
	uintmax_t	i;
	int			counter;
	uintmax_t	left;
	uintmax_t	right;

	if (n <= 1)
		return (n);
	left = 0;
	counter = 0;
	i = n / 2;
	right = n;
	while (n != i * i)
	{
		if (i * i > n)
			right = i;
		else if (i * i < n)
			left = i;
		else
			return (i);
		i = (right + left) / 2;
		if (counter > 1000)
			return (-1);
		counter++;
	}
	return (i);
}

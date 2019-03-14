/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_sqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 20:03:52 by aroi              #+#    #+#             */
/*   Updated: 2018/07/07 20:09:13 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_is_sqrt(t_printf **printf, va_list apointer)
{
	int i;

	i = ft_sqrt(va_arg(apointer, int));
	if (i < 0)
	{
		write(1, "This number has no square root.", 31);
		(*printf)->num += 31;
	}
	else
	{
		ft_putnbr(i);
		i = ft_count_digits_base(i, 10);
		while (i--)
			(*printf)->num++;
	}
	(*printf)->str++;
	(*printf)->i++;
}

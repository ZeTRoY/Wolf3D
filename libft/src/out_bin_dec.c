/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_bin_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:39:36 by aroi              #+#    #+#             */
/*   Updated: 2018/07/07 19:14:32 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			ft_transf_to_bin_dec(uintmax_t n, int qnt)
{
	int i;

	i = ft_count_digits_base(n, 10);
	n = n / ft_pow(10, qnt);
	n = n % 10;
	return (n);
}

static uintmax_t	cast(t_printf **printf, va_list apointer)
{
	uintmax_t	n;

	n = va_arg(apointer, uintmax_t);
	if ((*printf)->cast == LL)
		n = (unsigned long long)n;
	else if ((*printf)->cast == Z)
		n = (size_t)n;
	else if ((*printf)->cast == L)
		n = (unsigned long)n;
	else if ((*printf)->cast == H)
		n = (unsigned short)n;
	else if ((*printf)->cast == HH)
		n = (unsigned char)n;
	else if ((*printf)->cast != J)
		n = (unsigned int)n;
	return (n);
}

void				ft_is_bin_dec(t_printf **printf, va_list apointer)
{
	uintmax_t	n;
	int			i;
	int			qnt;
	char		*str;

	n = cast(printf, apointer);
	qnt = ft_count_digits_base(n, 10);
	while (--qnt >= 0)
	{
		str = ft_uitoa_base(ft_transf_to_bin_dec(n, qnt), 2);
		i = ft_strlen(str);
		while (++i <= 4 && ++(*printf)->num)
			ft_putchar('0');
		ft_putstr(str);
		if (qnt > 0 && ++(*printf)->num)
			ft_putchar(' ');
		i = -1;
		while (str[++i])
			(*printf)->num++;
		ft_strdel(&str);
	}
	(*printf)->str++;
	(*printf)->i++;
}

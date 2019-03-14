/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:33:30 by aroi              #+#    #+#             */
/*   Updated: 2018/07/12 18:10:21 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			ft_sign_and_width(t_printf **printf, intmax_t i)
{
	int qnt;

	qnt = ft_count_digits_base(i, 10);
	if ((*printf)->apostrophe)
		(*printf)->apostrophe = (qnt - 1) / 3;
	if (i < 0 || (*printf)->plus)
		(*printf)->width--;
	else if ((*printf)->space)
	{
		write(1, " ", 1);
		(*printf)->num++;
		(*printf)->width--;
	}
	if (i == 0 && (*printf)->precision >= 0)
		qnt = 0;
	else
		qnt = ft_count_digits_base(i, 10);
	if ((*printf)->zero && (*printf)->precision < 0)
	{
		(*printf)->precision = (*printf)->width;
		(*printf)->width = 0;
	}
	return (qnt);
}

static void			ft_print_width_int(t_printf **printf, intmax_t qnt)
{
	while ((intmax_t)(*printf)->width - qnt - (*printf)->apostrophe > 0 &&
			(*printf)->width > (*printf)->precision)
	{
		write(1, " ", 1);
		(*printf)->num++;
		(*printf)->width--;
	}
}

static void			ft_print_nbr(t_printf **printf, intmax_t n, int qnt)
{
	char	*str;
	int		precision;

	precision = (*printf)->precision;
	if (!(*printf)->minus)
		ft_print_width_int(printf, qnt);
	if (n < 0)
		write(1, "-", 1);
	else if ((*printf)->plus)
		write(1, "+", 1);
	while (precision-- - qnt - (*printf)->apostrophe > 0 && ++(*printf)->num)
		write(1, "0", 1);
	str = ft_itoa(n);
	ft_print_number(printf, qnt, str);
	ft_strdel(&str);
	if ((*printf)->minus)
		ft_print_width_int(printf, qnt);
}

static intmax_t		di_cast(t_printf **printf, va_list apointer)
{
	intmax_t i;

	i = va_arg(apointer, intmax_t);
	if ((*printf)->cast == LL)
		i = (long long)i;
	else if ((*printf)->cast == Z || (*printf)->cast == T)
		i = (ptrdiff_t)i;
	else if ((*printf)->cast == L || (*printf)->conv == 'D')
		i = (long)i;
	else if ((*printf)->cast != J)
		i = (int)i;
	if ((*printf)->conv != 'D')
	{
		if ((*printf)->cast == H)
			i = (short)i;
		else if ((*printf)->cast == HH)
			i = (char)i;
	}
	return (i);
}

void				ft_is_decimal(t_printf **printf, va_list apointer)
{
	int			qnt;
	intmax_t	i;

	if (*((*printf)->str) == 'd' || *((*printf)->str) == 'i')
		(*printf)->conv = 'd';
	else
		(*printf)->conv = 'D';
	while ((*printf)->sigil-- > 0)
		i = di_cast(printf, apointer);
	qnt = ft_sign_and_width(printf, i);
	ft_print_nbr(printf, i, qnt);
	if (i < 0 || (*printf)->plus)
		(*printf)->num++;
	while (qnt-- > 0)
		(*printf)->num++;
	(*printf)->str += 1;
	(*printf)->i += 1;
}

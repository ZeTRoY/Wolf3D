/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 20:40:19 by aroi              #+#    #+#             */
/*   Updated: 2018/07/12 18:10:01 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			ft_print_width_o(t_printf **printf, int qnt)
{
	while ((*printf)->width - qnt > 0 &&
			(*printf)->width > (*printf)->precision)
	{
		write(1, " ", 1);
		(*printf)->num++;
		(*printf)->width--;
	}
}

static void			ft_o_precision_n_width(t_printf **printf, char *str,
						uintmax_t z)
{
	int		precision;
	int		qnt;
	int		qnt2;

	if ((*printf)->sharp && !z)
		qnt = 1;
	else if (!z && (*printf)->precision >= 0)
		qnt = 0;
	else
		qnt = ft_count_letters(str);
	qnt2 = qnt;
	if ((*printf)->zero && (*printf)->precision < 0)
	{
		(*printf)->precision = (*printf)->width;
		(*printf)->width = 0;
	}
	precision = (*printf)->precision;
	if (!(*printf)->minus)
		ft_print_width_o(printf, qnt);
	while (precision-- - qnt > 0 && ++(*printf)->num)
		write(1, "0", 1);
	while (qnt-- > 0 && *str && ++(*printf)->num)
		write(1, str++, 1);
	if ((*printf)->minus)
		ft_print_width_o(printf, qnt2);
}

static uintmax_t	o_cast(t_printf **printf, va_list apointer)
{
	uintmax_t	i;

	i = va_arg(apointer, uintmax_t);
	if ((*printf)->cast == LL)
		i = (unsigned long long)i;
	else if ((*printf)->cast == Z || (*printf)->cast == T)
		i = (size_t)i;
	else if ((*printf)->cast == L || *((*printf)->str) == 'O')
		i = (unsigned long)i;
	else if ((*printf)->cast != J)
		i = (unsigned int)i;
	if (*((*printf)->str) == 'o')
	{
		if ((*printf)->cast == H)
			i = (unsigned short)i;
		else if ((*printf)->cast == HH)
			i = (unsigned char)i;
	}
	return (i);
}

void				ft_is_octo(t_printf **printf, va_list apointer)
{
	size_t		i;
	uintmax_t	z;
	char		*str;
	char		*tmp;

	i = 0;
	if (*((*printf)->str) == 'o')
		(*printf)->conv = 'o';
	else
		(*printf)->conv = 'O';
	while ((*printf)->sigil-- > 0)
		z = o_cast(printf, apointer);
	str = ft_uitoa_base(z, 8);
	if ((*printf)->sharp)
	{
		tmp = ft_strjoin("0", str);
		ft_strdel(&str);
		str = tmp;
	}
	ft_o_precision_n_width(printf, str, z);
	ft_strdel(&str);
	(*printf)->str++;
	(*printf)->i++;
}

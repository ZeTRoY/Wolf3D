/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:38:22 by aroi              #+#    #+#             */
/*   Updated: 2018/07/30 15:29:45 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			ft_print_width_base(t_printf **printf, int qnt)
{
	while ((*printf)->width - qnt > 0 &&
			(*printf)->width > (*printf)->precision)
	{
		write(1, " ", 1);
		(*printf)->num++;
		(*printf)->width--;
	}
}

static void			ft_precision_n_width(t_printf **printf, char *str,
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
		ft_print_width_base(printf, qnt);
	while (precision-- - qnt > 0 && ++(*printf)->num)
		write(1, "0", 1);
	while (qnt-- > 0 && *str && ++(*printf)->num)
		write(1, str++, 1);
	if ((*printf)->minus)
		ft_print_width_base(printf, qnt2);
}

static uintmax_t	cast(t_printf **printf, va_list apointer)
{
	uintmax_t	z;

	z = va_arg(apointer, uintmax_t);
	if ((*printf)->cast == LL)
		z = (unsigned long long)z;
	else if ((*printf)->cast == Z)
		z = (size_t)z;
	else if ((*printf)->cast == L || *((*printf)->str) == 'Q')
		z = (unsigned long)z;
	else if ((*printf)->cast != J)
		z = (unsigned int)z;
	if (*((*printf)->str) == 'q')
	{
		if ((*printf)->cast == H)
			z = (unsigned short)z;
		else if ((*printf)->cast == HH)
			z = (unsigned char)z;
	}
	return (z);
}

static int			ft_what_is_base(t_printf **printf,
						va_list apointer, int base)
{
	if (base == 2)
	{
		ft_is_bin(printf, apointer);
		return (0);
	}
	else if (base == 8)
	{
		ft_is_octo(printf, apointer);
		return (0);
	}
	else if (base == 16)
	{
		ft_is_hexa(printf, apointer);
		return (0);
	}
	return (1);
}

void				ft_is_base(t_printf **printf, va_list apointer)
{
	int			base;
	size_t		i;
	uintmax_t	z;
	char		*str;
	char		*tmp;

	i = 0;
	base = va_arg(apointer, int);
	if (!ft_what_is_base(printf, apointer, base))
		return ;
	while ((*printf)->sigil-- > 0)
		z = cast(printf, apointer);
	str = ft_uitoa_base(z, base);
	if (*((*printf)->str) == 'Q')
		ft_upper(str);
	if ((*printf)->sharp)
	{
		tmp = ft_strjoin("0", str);
		ft_strdel(&str);
		str = tmp;
	}
	ft_precision_n_width(printf, str, z);
	ft_strdel(&str);
	(*printf)->str++;
	(*printf)->i++;
}

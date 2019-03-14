/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 10:54:14 by aroi              #+#    #+#             */
/*   Updated: 2018/07/12 09:53:28 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			ft_print_width_c(t_printf **printf, char size)
{
	while ((*printf)->width - (int)size > 0)
	{
		write(1, " ", 1);
		(*printf)->num++;
		(*printf)->width--;
	}
}

static void			ft_wchar_precision_n_width(t_printf **printf, wchar_t c)
{
	int		precision;
	int		size;
	int		size2;

	if ((*printf)->zero)
	{
		(*printf)->precision = (*printf)->width;
		precision = (*printf)->precision;
		(*printf)->width = 0;
	}
	else
		precision = 0;
	size = (int)size_of(c);
	size2 = size;
	if (!(*printf)->minus)
		ft_print_width_c(printf, size);
	while ((*printf)->zero && precision-- - size > 0 &&
		++(*printf)->num)
		write(1, "0", 1);
	while (size-- > 0)
		(*printf)->num++;
	ft_putchar(c);
	if ((*printf)->minus)
		ft_print_width_c(printf, size2);
}

void				ft_char_precision_n_width(t_printf **print, char c)
{
	int		precision;
	int		size;
	int		size2;

	if ((*print)->zero && (*print)->width > 0)
	{
		(*print)->precision = (*print)->width;
		precision = (*print)->precision;
		(*print)->width = 0;
	}
	else
		precision = 0;
	size = (int)size_of(c);
	size2 = size;
	if (!(*print)->minus)
		ft_print_width_c(print, size);
	while ((*print)->zero && precision-- - size > 0 &&
		++(*print)->num)
		write(1, "0", 1);
	while (size-- > 0)
		(*print)->num++;
	ft_putchar(c);
	if ((*print)->minus)
		ft_print_width_c(print, size2);
}

void				ft_is_char(t_printf **printf, va_list apointer)
{
	char	c;
	wchar_t	wc;

	if (*((*printf)->str) == 'c' && (*printf)->cast != L)
	{
		(*printf)->conv = 'c';
		while ((*printf)->sigil-- > 0)
			c = (unsigned char)va_arg(apointer, int);
		ft_char_precision_n_width(printf, c);
	}
	else
	{
		(*printf)->conv = 'C';
		while ((*printf)->sigil-- > 0)
			wc = (wchar_t)va_arg(apointer, wint_t);
		ft_wchar_precision_n_width(printf, wc);
	}
	(*printf)->str += 1;
	(*printf)->i += 1;
}

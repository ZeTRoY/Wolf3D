/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:49:19 by aroi              #+#    #+#             */
/*   Updated: 2018/07/12 11:58:42 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_print_width_s(t_printf **printf, int size)
{
	if ((*printf)->zero)
		while ((*printf)->width - size > 0 &&
			(*printf)->width - (*printf)->precision > 0)
		{
			write(1, " ", 1);
			(*printf)->num++;
			(*printf)->width--;
		}
	else
		while ((*printf)->width - size > 0)
		{
			write(1, " ", 1);
			(*printf)->num++;
			(*printf)->width--;
		}
}

static int		ft_str_zero(t_printf **print, int *size, wchar_t *str)
{
	int		i;

	i = 0;
	if ((*print)->precision >= 0 && *size - (*print)->precision > 0)
	{
		*size = (*print)->precision;
		while (*size - size_of(str[i]) >= 0)
		{
			*size -= size_of(str[i++]);
		}
		*size = 0;
		while (i-- > 0)
			*size += size_of(str[i]);
	}
	if ((*print)->width == 0 || (*print)->precision == -1)
		(*print)->precision = *size;
	if ((*print)->zero)
	{
		if ((*print)->width)
			(*print)->precision = (*print)->width;
		(*print)->width = 0;
	}
	return ((*print)->precision);
}

static void		ft_uni_str_precision_n_width(t_printf **print, wchar_t *str)
{
	int			precision;
	int			size;

	size = size_of_uni_str(str);
	precision = ft_str_zero(print, &size, str);
	if (!(*print)->minus)
		ft_print_width_s(print, size);
	while ((*print)->zero &&
		precision - size > 0 && ++(*print)->num)
	{
		precision--;
		write(1, "0", 1);
	}
	while (*str && precision - size_of(*str) >= 0)
	{
		(*print)->num += size_of(*str);
		precision -= size_of(*str);
		ft_putchar(*str++);
	}
	if ((*print)->minus)
		ft_print_width_s(print, size);
}

static void		ft_str_precision_n_width(t_printf **print, char *str)
{
	int			precision;
	int			size;

	size = size_of_str(str);
	if (size - (*print)->precision > 0 && (*print)->precision >= 0)
		size = (*print)->precision;
	precision = ft_str_zero(print, &size, (wchar_t *)str);
	if (!(*print)->minus)
		ft_print_width_s(print, size);
	while ((*print)->zero &&
		precision - size > 0 && ++(*print)->num)
	{
		precision--;
		write(1, "0", 1);
	}
	(*print)->num += size;
	while (*str && size > 0 && precision > 0)
	{
		precision -= size_of(*str);
		ft_putchar(*str++);
	}
	if ((*print)->minus)
		ft_print_width_s(print, size);
}

void			ft_is_string(t_printf **printf, va_list apointer)
{
	char	*str;
	wchar_t	*str_u;

	if (*((*printf)->str) == 's' && (*printf)->cast != L)
	{
		(*printf)->conv = 's';
		while ((*printf)->sigil-- > 0)
			str = va_arg(apointer, char *);
		if (!str)
			str = "(null)";
		ft_str_precision_n_width(printf, str);
	}
	else
	{
		(*printf)->conv = 'S';
		while ((*printf)->sigil-- > 0)
			str_u = va_arg(apointer, wchar_t *);
		if (!str_u)
			ft_str_precision_n_width(printf, "(null)");
		else
			ft_uni_str_precision_n_width(printf, str_u);
	}
	(*printf)->str += 1;
	(*printf)->i += 1;
}

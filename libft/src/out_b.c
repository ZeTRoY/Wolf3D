/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 22:32:03 by aroi              #+#    #+#             */
/*   Updated: 2018/07/09 13:28:25 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			ft_minus(t_printf **printf, uintmax_t z, int qnt)
{
	int	precision;

	if ((*printf)->sharp)
	{
		if (!z)
			(*printf)->precision = -1;
		while ((*printf)->width - qnt > 0 &&
			(*printf)->width - (*printf)->precision > 0)
		{
			write(1, " ", 1);
			(*printf)->num++;
			(*printf)->width--;
		}
	}
	else
		ft_print_width_x(printf, qnt);
	precision = (*printf)->precision;
	return (precision);
}

static void			ft_print_bin_part(t_printf **printf, char **str)
{
	write(1, *str, 2);
	(*printf)->num += 2;
	if ((*printf)->zero)
		(*printf)->width -= 2;
	*str += 2;
}

static void			ft_b_precision_n_width(t_printf **printf, char *str,
						uintmax_t z)
{
	int		qnt;
	int		precision;

	if ((*printf)->precision > -1 &&
			(*printf)->precision - (*printf)->width > 0)
		qnt = ft_count_letters(str) - 2;
	else
		qnt = ft_count_letters(str);
	if ((*printf)->zero)
	{
		(*printf)->precision = (*printf)->width > 0 ? (*printf)->width : 1;
		(*printf)->width = 0;
	}
	precision = (*printf)->precision;
	if (!(*printf)->minus)
		precision = ft_minus(printf, z, qnt);
	if ((*printf)->sharp)
		ft_print_bin_part(printf, &str);
	while (precision - qnt > 0 && ++(*printf)->num && precision--)
		write(1, "0", 1);
	while ((z != 0 || (*printf)->precision != 0) && *str &&
			++(*printf)->num)
		write(1, str++, 1);
	if ((*printf)->minus)
		precision = ft_minus(printf, z, qnt);
}

static uintmax_t	bin_cast(t_printf **printf, va_list apointer)
{
	uintmax_t z;

	z = va_arg(apointer, uintmax_t);
	if ((*printf)->cast == LL)
		z = (unsigned long long)z;
	else if ((*printf)->cast == Z)
		z = (size_t)z;
	else if ((*printf)->cast == L || *((*printf)->str) == 'B')
		z = (unsigned long)z;
	else if ((*printf)->cast != J)
		z = (unsigned int)z;
	if (*((*printf)->str) == 'b')
	{
		if ((*printf)->cast == H)
			z = (unsigned short)z;
		else if ((*printf)->cast == HH)
			z = (unsigned char)z;
	}
	return (z);
}

void				ft_is_bin(t_printf **printf, va_list apointer)
{
	size_t		i;
	uintmax_t	z;
	char		*str;
	char		*tmp;

	i = 0;
	if (*((*printf)->str) == 'b')
		(*printf)->conv = 'b';
	else
		(*printf)->conv = 'B';
	while ((*printf)->sigil-- > 0)
		z = bin_cast(printf, apointer);
	str = ft_uitoa_base(z, 2);
	if ((*printf)->sharp)
	{
		tmp = ft_strjoin("0b", str);
		ft_strdel(&str);
		str = tmp;
	}
	ft_b_precision_n_width(printf, str, z);
	ft_strdel(&str);
	(*printf)->str++;
	(*printf)->i++;
}

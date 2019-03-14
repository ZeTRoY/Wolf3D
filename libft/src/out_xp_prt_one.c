/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_xp_prt_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:46:08 by aroi              #+#    #+#             */
/*   Updated: 2018/07/12 18:09:43 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static uintmax_t	ft_cast(t_printf **printf, va_list apointer)
{
	uintmax_t	z;

	z = va_arg(apointer, uintmax_t);
	if (*((*printf)->str) == 'p' || (*printf)->cast == L)
		z = (unsigned long)z;
	else if ((*printf)->cast == LL)
		z = (unsigned long long)z;
	else if ((*printf)->cast == Z || (*printf)->cast == T)
		z = (size_t)z;
	else if ((*printf)->cast != J)
		z = (unsigned int)z;
	if (*((*printf)->str) != 'p')
	{
		if ((*printf)->cast == H)
			z = (unsigned short)z;
		else if ((*printf)->cast == HH)
			z = (unsigned char)z;
	}
	return (z);
}

static void			zerox(t_printf **print, uintmax_t z)
{
	char		*tmp;
	char		*string;
	size_t		i;
	int			qnt;

	i = 0;
	tmp = ft_uitoa_base(z, 16);
	string = ft_strjoin("0x", tmp);
	ft_strdel(&tmp);
	while (*((*print)->str) >= 'A' && *((*print)->str) <= 'Z'
			&& string[++i])
		string[i] = ft_toupper(string[i]);
	qnt = ft_p_width(print, string, z);
	ft_p_precision(print, string, z, qnt);
	ft_strdel(&string);
}

static void			ft_x_precision_n_width(t_printf **printf,
						char *str, uintmax_t z)
{
	int		precision;
	int		qnt;

	if ((*printf)->zero && (*printf)->width && ((*printf)->precision == -1
		|| (*printf)->precision - (*printf)->width > 0))
	{
		(*printf)->precision = (*printf)->width;
		(*printf)->width = 0;
	}
	precision = (*printf)->precision;
	if ((*printf)->precision >= 0 && !z)
		qnt = 0;
	else
		qnt = ft_count_letters(str);
	if (!(*printf)->minus)
		ft_print_width_x(printf, qnt);
	while (precision-- - qnt > 0)
	{
		write(1, "0", 1);
		(*printf)->num++;
	}
	while (qnt > 0 && *str && ++(*printf)->num)
		write(1, str++, 1);
	if ((*printf)->minus)
		ft_print_width_x(printf, qnt);
}

void				ft_is_hexa(t_printf **print, va_list apointer)
{
	uintmax_t	z;
	size_t		i;
	char		*string;

	i = 0;
	(*print)->conv = *((*print)->str) == 'p' ? 'p' : 'x';
	while ((*print)->sigil-- > 0)
		z = ft_cast(print, apointer);
	if (*((*print)->str) != 'p' && !(*print)->sharp)
	{
		string = ft_uitoa_base(z, 16);
		while (*((*print)->str) == 'X' && string[i++])
			string[i - 1] = ft_toupper(string[i - 1]);
		ft_x_precision_n_width(print, string, z);
		ft_strdel(&string);
	}
	else
		zerox(print, z);
	(*print)->str++;
	(*print)->i++;
}

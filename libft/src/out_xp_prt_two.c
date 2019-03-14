/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_xp_prt_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:40:44 by aroi              #+#    #+#             */
/*   Updated: 2018/07/12 11:27:21 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_print_width_x(t_printf **printf, int qnt)
{
	while ((*printf)->width - qnt > 0 &&
		(*printf)->width - (*printf)->precision > 0)
	{
		write(1, " ", 1);
		(*printf)->num++;
		(*printf)->width--;
	}
}

static void		ft_print_width_xp(t_printf **printf, uintmax_t z, int qnt)
{
	if (!(*printf)->minus)
	{
		if ((*printf)->conv == 'p' || z != 0)
		{
			while ((*printf)->width - qnt > 0 &&
				(*printf)->width - (*printf)->precision > 2 &&
					++(*printf)->num)
			{
				write(1, " ", 1);
				(*printf)->width--;
			}
		}
		else
			ft_print_width_x(printf, qnt);
	}
}

static void		ft_write_after(t_printf **printf, uintmax_t z, int qnt)
{
	if ((*printf)->conv == 'p' || z != 0)
	{
		while ((*printf)->width - qnt > 0 &&
			(*printf)->width - (*printf)->precision > 2)
		{
			write(1, " ", 1);
			(*printf)->num++;
			(*printf)->width--;
		}
	}
	else
		ft_print_width_x(printf, qnt);
}

int				ft_p_width(t_printf **print, char *str, uintmax_t z)
{
	int qnt;

	if (((((*print)->zero &&
		(*print)->precision - ft_count_letters(str) + 2 > 0) || z == 0) &&
			(*print)->conv != 'p') || ((*print)->precision > -1 &&
				(*print)->precision - (*print)->width > 0))
		qnt = ft_count_letters(str) - 2;
	else
		qnt = ft_count_letters(str);
	if ((*print)->zero && (*print)->width && ((*print)->precision == -1
		|| (*print)->precision - (*print)->width > 0))
	{
		(*print)->precision = (*print)->width > 0 ? (*print)->width : 1;
		(*print)->width = 0;
	}
	ft_print_width_xp(print, z, qnt);
	return (qnt);
}

void			ft_p_precision(t_printf **print, char *str,
						uintmax_t z, int qnt)
{
	int		precision;

	precision = (*print)->precision;
	if (*((*print)->str) == 'p' || ((*print)->sharp && z))
	{
		write(1, str, 2);
		(*print)->num += 2;
		if ((*print)->zero)
			(*print)->width -= 2;
	}
	str += 2;
	if (z && (*print)->precision - ft_count_letters(str) > 0 && (*print)->width
		&& (*print)->precision > 0 && (*print)->width - (*print)->precision > 0)
		qnt -= 2;
	while (precision - qnt > 0 && ++(*print)->num)
	{
		write(1, "0", 1);
		precision--;
	}
	while ((z || (*print)->precision) && *str &&
			++(*print)->num)
		write(1, str++, 1);
	if ((*print)->minus)
		ft_write_after(print, z, qnt);
}

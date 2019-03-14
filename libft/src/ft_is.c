/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 10:00:49 by aroi              #+#    #+#             */
/*   Updated: 2018/07/09 12:12:43 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_is_n(t_printf **printf, va_list apointer, char c)
{
	if (c == 'n')
		ft_is_nbr_of_c(printf, apointer);
}

void			ft_what_is_love(t_printf **printf, va_list apointer)
{
	if (*((*printf)->str) == 'd' || *((*printf)->str) == 'i' ||
			*((*printf)->str) == 'D')
		ft_is_decimal(printf, apointer);
	else if (*((*printf)->str) == 'o' || *((*printf)->str) == 'O')
		ft_is_octo(printf, apointer);
	else if (*((*printf)->str) == 'u' || *((*printf)->str) == 'U')
		ft_is_unsigned(printf, apointer);
	else if (*((*printf)->str) == 'x'
			|| *((*printf)->str) == 'X' || *((*printf)->str) == 'p')
		ft_is_hexa(printf, apointer);
	else if (*((*printf)->str) == 'c' || *((*printf)->str) == 'C')
		ft_is_char(printf, apointer);
	else if (*((*printf)->str) == 's' || *((*printf)->str) == 'S')
		ft_is_string(printf, apointer);
	else if (*((*printf)->str) == 'b' || *((*printf)->str) == 'B')
		ft_is_bin(printf, apointer);
	else if (*((*printf)->str) == 'k')
		ft_is_date(printf, apointer);
	else if (*((*printf)->str) == 'q' || *((*printf)->str) == 'Q')
		ft_is_base(printf, apointer);
	else if (*((*printf)->str) == 'm')
		ft_is_bin_dec(printf, apointer);
	else if (*((*printf)->str) == 'y')
		ft_is_sqrt(printf, apointer);
	ft_is_n(printf, apointer, *((*printf)->str));
}

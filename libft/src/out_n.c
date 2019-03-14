/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:40:10 by aroi              #+#    #+#             */
/*   Updated: 2018/07/12 18:37:54 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_cast_jtl(t_printf **printf, va_list apointer)
{
	intmax_t *n;

	if ((*printf)->cast == J)
	{
		n = va_arg(apointer, intmax_t *);
		*n = (intmax_t)(*printf)->num;
	}
	else if ((*printf)->cast == T)
	{
		n = va_arg(apointer, ptrdiff_t *);
		*n = (ptrdiff_t)(*printf)->num;
	}
	else
	{
		n = va_arg(apointer, long *);
		*n = (long)(*printf)->num;
	}
}

static void		ft_cast_char_short(t_printf **printf, va_list apointer)
{
	char	*c;
	short	*s;

	if ((*printf)->cast == HH)
	{
		c = va_arg(apointer, char *);
		*c = (char)(*printf)->num;
	}
	else
	{
		s = va_arg(apointer, short *);
		*s = (short)(*printf)->num;
	}
}

void			ft_is_nbr_of_c(t_printf **printf, va_list apointer)
{
	int		*n;
	size_t	*z;

	if ((*printf)->cast == T || (*printf)->cast == J || (*printf)->cast == L)
		ft_cast_jtl(printf, apointer);
	else if ((*printf)->cast == Z)
	{
		z = va_arg(apointer, size_t *);
		*z = (size_t)(*printf)->num;
	}
	else if ((*printf)->cast == H || (*printf)->cast == HH)
		ft_cast_char_short(printf, apointer);
	else
	{
		n = va_arg(apointer, int *);
		*n = (*printf)->num;
	}
	(*printf)->str++;
	(*printf)->i++;
}

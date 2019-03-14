/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:59:58 by aroi              #+#    #+#             */
/*   Updated: 2018/07/12 19:01:46 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_printf			*new_printf(void)
{
	t_printf *printf;

	printf = (t_printf *)malloc(sizeof(t_printf));
	if (!printf)
		return (0);
	printf->sharp = 0;
	printf->zero = 0;
	printf->minus = 0;
	printf->plus = 0;
	printf->space = 0;
	printf->apostrophe = 0;
	printf->sigil = 1;
	printf->cast = 0;
	printf->conv = 0;
	printf->num = 0;
	printf->i = 0;
	printf->precision = -1;
	printf->width = 0;
	return (printf);
}

void				ft_printf_update(t_printf **printf)
{
	(*printf)->sharp = 0;
	(*printf)->zero = 0;
	(*printf)->minus = 0;
	(*printf)->plus = 0;
	(*printf)->space = 0;
	(*printf)->apostrophe = 0;
	(*printf)->cast = 0;
	(*printf)->width = 0;
	(*printf)->conv = 0;
	(*printf)->sigil = 1;
	(*printf)->precision = -1;
}

void				ft_del_printf(t_printf **printf)
{
	if (!*printf)
		return ;
	free(*printf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:18:48 by aroi              #+#    #+#             */
/*   Updated: 2018/07/12 10:10:33 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_what_is_it(t_printf **print, va_list apointer)
{
	while (is_flag((*print)->str) || is_width((*print)->str) ||
		is_precision((*print)->str) || is_cast((*print)->str))
	{
		if (is_sigil((*print)->str))
			ft_is_sigil(print);
		if (is_flag((*print)->str))
			ft_flag_activation(print);
		if (is_width((*print)->str))
			ft_width_activation(print, apointer);
		if (is_precision((*print)->str))
			ft_precision_activation(print, apointer);
		if (is_cast((*print)->str))
			ft_cast_activation(print);
	}
	if (is_conversion((*print)->str, (*print)->sigil))
		ft_what_is_love(print, apointer);
	if (!(*print)->conv && (*print)->str[0])
	{
		ft_char_precision_n_width(print, *((*print)->str));
		(*print)->str++;
		(*print)->i++;
	}
}

int				ft_printf(char *str, ...)
{
	t_printf	*printf;
	va_list		apointer;

	printf = new_printf();
	va_start(apointer, str);
	while (str[printf->i])
	{
		printf->str = str + printf->i;
		if (str[printf->i] == '{')
			ft_is_color(&printf);
		if (str[printf->i] != '%')
		{
			printf->num++;
			write(1, &str[printf->i++], 1);
		}
		else
		{
			ft_printf_update(&printf);
			printf->str = str + ++printf->i;
			ft_what_is_it(&printf, apointer);
		}
	}
	va_end(apointer);
	ft_del_printf(&printf);
	return (printf->num);
}

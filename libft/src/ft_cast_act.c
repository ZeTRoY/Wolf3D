/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_act.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:40:36 by aroi              #+#    #+#             */
/*   Updated: 2018/07/12 19:13:11 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_flag_activation(t_printf **printf)
{
	while (*((*printf)->str) == '#' || *((*printf)->str) == '0' ||
			*((*printf)->str) == '-' || *((*printf)->str) == '+' ||
			*((*printf)->str) == ' ' || *((*printf)->str) == '\'')
	{
		if ((*printf)->str[0] == '#')
			(*printf)->sharp = 1;
		else if ((*printf)->str[0] == '0' && !(*printf)->minus)
			(*printf)->zero = 1;
		else if ((*printf)->str[0] == '-')
		{
			(*printf)->zero = 0;
			(*printf)->minus = 1;
		}
		else if ((*printf)->str[0] == '+')
		{
			(*printf)->space = 0;
			(*printf)->plus = 1;
		}
		else if ((*printf)->str[0] == ' ' && !(*printf)->plus)
			(*printf)->space = 1;
		else if ((*printf)->str[0] == '\'')
			(*printf)->apostrophe = 1;
		(*printf)->str++;
		(*printf)->i++;
	}
}

void			ft_width_activation(t_printf **printf, va_list apointer)
{
	if (*((*printf)->str) == 42)
	{
		(*printf)->width = va_arg(apointer, int);
		(*printf)->i++;
		(*printf)->str++;
		if ((*printf)->width < 0)
		{
			(*printf)->minus = 1;
			(*printf)->zero = 0;
			(*printf)->width *= -1;
		}
	}
	else
	{
		(*printf)->width = ft_atoi((*printf)->str);
		while (ft_isdigit(*((*printf)->str)))
		{
			(*printf)->str++;
			(*printf)->i++;
		}
	}
}

void			ft_precision_activation(t_printf **printf, va_list apointer)
{
	(*printf)->str++;
	(*printf)->i++;
	if (*((*printf)->str) == 42)
	{
		(*printf)->precision = va_arg(apointer, int);
		(*printf)->i++;
		(*printf)->str++;
		if ((*printf)->precision < 0)
			(*printf)->precision = -1;
	}
	else
	{
		(*printf)->precision = ft_atoi((*printf)->str);
		while (ft_isdigit(*((*printf)->str)))
		{
			(*printf)->str++;
			(*printf)->i++;
		}
	}
}

static void		ft_cast(t_printf **printf)
{
	if ((*printf)->str[0] == 't' && T > (*printf)->cast)
		(*printf)->cast = T;
	else if ((*printf)->str[0] == 'z' && Z > (*printf)->cast)
		(*printf)->cast = Z;
	else if ((*printf)->str[0] == 'j' && J > (*printf)->cast)
		(*printf)->cast = J;
}

void			ft_cast_activation(t_printf **printf)
{
	while ((*printf)->str[0] == 'h' || (*printf)->str[0] == 'l' ||
			(*printf)->str[0] == 'j' || (*printf)->str[0] == 'z' ||
			(*printf)->str[0] == 't' || (*printf)->str[0] == 'L')
	{
		if ((*printf)->str[0] == 'L' && BL > (*printf)->cast)
			(*printf)->cast = BL;
		else if ((*printf)->str[0] == 't' || (*printf)->str[0] == 'z' ||
			(*printf)->str[0] == 'j')
			ft_cast(printf);
		else if ((*printf)->str[0] == 'l' && (*printf)->str[1] == 'l' &&
				LL > (*printf)->cast && (*printf)->str++ && (*printf)->i++)
			(*printf)->cast = LL;
		else if ((*printf)->str[0] == 'l' && L > (*printf)->cast)
			(*printf)->cast = L;
		else if ((*printf)->str[0] == 'h' && (*printf)->str[1] != 'h' &&
				H > (*printf)->cast)
			(*printf)->cast = H;
		else if (HH > (*printf)->cast && ++(*printf)->str && ++(*printf)->i)
			(*printf)->cast = HH;
		(*printf)->i++;
		(*printf)->str++;
	}
}

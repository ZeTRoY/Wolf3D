/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:29:24 by aroi              #+#    #+#             */
/*   Updated: 2018/07/12 18:06:10 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		is_flag(char *str)
{
	if (*str == '#' || *str == '0' || *str == '-' || *str == '+' ||
			*str == ' ' || *str == '\'')
		return (1);
	return (0);
}

int		is_width(char *str)
{
	if ((*str >= '1' && *str <= '9') || *str == 42)
		return (1);
	return (0);
}

int		is_precision(char *str)
{
	if (*str == '.')
		return (1);
	return (0);
}

int		is_cast(char *str)
{
	if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z'
		|| *str == 'L' || *str == 't')
		return (1);
	return (0);
}

int		is_conversion(char *str, int i)
{
	char c;

	c = ft_tolower(*str);
	if ((c == 's' || c == 'p' || c == 'd' || c == 'D' || c == 'i' || c == 'o' ||
		c == 'u' || c == 'x' || c == 'c' || c == 'n' || c == 'b' || c == 'k' ||
		c == 'q' || c == 'm' || c == 'y') && i)
		return (1);
	return (0);
}

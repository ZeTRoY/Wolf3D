/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 18:24:56 by aroi              #+#    #+#             */
/*   Updated: 2019/01/25 16:06:24 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	ft_what_color(char *str)
{
	if (ft_strstr(str, "black"))
		return (1);
	else if (ft_strstr(str, "red"))
		return (2);
	else if (ft_strstr(str, "orange"))
		return (3);
	else if (ft_strstr(str, "yellow"))
		return (4);
	else if (ft_strstr(str, "green"))
		return (5);
	else if (ft_strstr(str, "blue"))
		return (6);
	else if (ft_strstr(str, "purple"))
		return (7);
	else if (ft_strstr(str, "pink"))
		return (8);
	else if (ft_strstr(str, "eoc"))
		return (0);
	else
		return (-1);
}

static char	ft_print_color(char c)
{
	if (c > -1)
	{
		if (c == 1)
			ft_putstr("\033[1;38;2;0;0;0;48;2;255;255;255m");
		else if (c == 2)
			ft_putstr("\033[1;38;2;255;0;0m");
		else if (c == 3)
			ft_putstr("\033[1;38;2;255;125;0m");
		else if (c == 4)
			ft_putstr("\033[1;38;2;255;255;0m");
		else if (c == 5)
			ft_putstr("\033[1;38;2;0;175;0m");
		else if (c == 6)
			ft_putstr("\033[1;38;2;0;0;255;48;2;255;255;0m");
		else if (c == 7)
			ft_putstr("\033[1;38;2;140;0;255;48;2;115;255;0m");
		else if (c == 8)
			ft_putstr("\033[1;38;2;255;0;150m");
		else if (!c)
			ft_putstr("\033[0m");
		return (1);
	}
	return (0);
}

void		ft_is_color(t_printf **printf)
{
	char	n;
	int		i;
	char	*str;

	i = 0;
	n = 1;
	while ((*printf)->str[i] != '}')
		i++;
	str = (char *)malloc(i);
	str[i - 1] = '\0';
	while ((*printf)->str[--i] != '{')
		str[i - 1] = (*printf)->str[i];
	if (!ft_print_color(ft_what_color(str)))
		n = 0;
	if (n)
	{
		while (*((*printf)->str) != '}')
		{
			(*printf)->str++;
			(*printf)->i++;
		}
		(*printf)->str++;
		(*printf)->i++;
	}
	ft_strdel(&str);
}

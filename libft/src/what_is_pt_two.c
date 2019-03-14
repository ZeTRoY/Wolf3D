/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_pt_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 20:27:32 by aroi              #+#    #+#             */
/*   Updated: 2018/07/09 14:09:59 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_number(t_printf **printf, int qnt, char *str)
{
	if (*str == '-')
		str++;
	while (qnt-- > 0)
	{
		write(1, str++, 1);
		if ((*printf)->apostrophe && qnt > 0 &&
				qnt % 3 == 0 && ++(*printf)->num)
			write(1, ",", 1);
	}
}

int		is_sigil(char *str)
{
	if (!ft_isdigit(*str) && *str != '-')
		return (0);
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '$')
		return (1);
	return (0);
}

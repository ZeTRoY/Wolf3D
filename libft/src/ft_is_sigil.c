/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sigil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 20:31:12 by aroi              #+#    #+#             */
/*   Updated: 2018/07/12 19:00:39 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				ft_is_sigil(t_printf **printf)
{
	int		i;

	i = ft_atoi((*printf)->str);
	while (*((*printf)->str) != '$')
	{
		(*printf)->str++;
		(*printf)->i++;
	}
	if (!i)
		return ;
	if (i < 0)
		i *= -1;
	(*printf)->sigil = i;
	(*printf)->str++;
	(*printf)->i++;
}

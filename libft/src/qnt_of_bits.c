/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qnt_of_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:16:21 by aroi              #+#    #+#             */
/*   Updated: 2019/02/12 19:13:22 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			size_of_uni_str(wchar_t *str)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (str[i])
		size += size_of(str[i++]);
	return (size);
}

int			size_of_str(char *str)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (str[i])
		size += size_of(str[i++]);
	return (size);
}

char		size_of(wchar_t c)
{
	if (c <= 127 || MB_CUR_MAX != 4)
		return (1);
	if (c <= 2047)
		return (2);
	if (c <= 65535)
		return (3);
	return (4);
}

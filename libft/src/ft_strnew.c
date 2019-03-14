/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:55:55 by aroi              #+#    #+#             */
/*   Updated: 2018/03/24 17:04:44 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		while (i <= (int)size && (size + 1) > 0)
			str[i++] = '\0';
		return (str);
	}
	return (NULL);
}

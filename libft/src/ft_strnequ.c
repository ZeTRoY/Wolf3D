/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:15:09 by aroi              #+#    #+#             */
/*   Updated: 2018/03/27 20:20:18 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 && s2 && (int)n >= 0)
	{
		if (n == 0)
			return (1);
		while (i < n)
		{
			if (*(s1 + i) != *(s2 + i))
				return (0);
			i++;
		}
		if (*(s1 + i - 1) == *(s2 + i - 1))
			return (1);
	}
	else if (s1 == NULL && s2 == NULL)
		return (1);
	return (0);
}

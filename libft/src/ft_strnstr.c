/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:46:06 by aroi              #+#    #+#             */
/*   Updated: 2018/03/25 17:08:02 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char *)big;
	if (little[0] == '\0')
		return (str);
	while (big[i])
	{
		j = 0;
		while (big[i] == little[j] && big[i] && little[j] &&
				((int)len < 0 || i <= (int)len))
		{
			i++;
			j++;
		}
		if (little[j] == '\0' && (i <= (int)len || (int)len < 0))
			return (&str[i - j]);
		i -= j - 1;
	}
	return (0);
}

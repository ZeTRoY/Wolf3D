/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:11:44 by aroi              #+#    #+#             */
/*   Updated: 2018/03/26 21:16:29 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s)
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
		if (str)
		{
			while (*(s + i))
			{
				*(str + i) = f(i, *(s + i));
				i++;
			}
			*(str + i) = '\0';
			return (str);
		}
	}
	return (0);
}

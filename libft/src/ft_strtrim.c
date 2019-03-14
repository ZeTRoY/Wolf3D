/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:38:13 by aroi              #+#    #+#             */
/*   Updated: 2018/03/28 15:26:25 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_str(char const *s, int i, int j)
{
	int		k;
	char	*str;

	k = 0;
	str = (char *)malloc(sizeof(char) * (j - i + 2));
	if (str == 0)
		return (0);
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (s == 0)
		return (0);
	i = 0;
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j > 0)
		j--;
	if (j - i >= 0)
		return (copy_str(s, i, j));
	else
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (str == 0)
			return (0);
		str[0] = '\0';
		return (str);
	}
}

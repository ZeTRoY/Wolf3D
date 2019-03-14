/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 21:30:43 by aroi              #+#    #+#             */
/*   Updated: 2018/03/29 17:10:43 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	qnt_words(char const *s, char c)
{
	unsigned int	i;
	size_t			qnt;

	i = 0;
	qnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			qnt++;
		i++;
	}
	return (qnt);
}

static size_t	len_of_word(char const *s, char c, size_t *i)
{
	size_t j;
	size_t len;

	len = 0;
	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	j = *i;
	while (s[*i] != c && s[*i] != '\0')
	{
		len++;
		(*i)++;
	}
	*i = j;
	return (len);
}

static char		*str_alloc(char const *s, char c, size_t *i)
{
	char	*str;
	size_t	len;

	len = len_of_word(s, c, i);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
		return (str);
	return (0);
}

static char		*str_maker(char const *s, char c, size_t *i, char *str)
{
	size_t j;

	j = 0;
	if (!str)
		return (0);
	while (s[*i] != c && s[*i] != '\0')
		str[j++] = s[(*i)++];
	str[j] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	n;
	size_t	qnt;

	i = 0;
	n = -1;
	if (!s)
		return (0);
	qnt = qnt_words(s, c);
	str = (char **)malloc(sizeof(char *) * (qnt + 1));
	if (!str)
		return (0);
	while (++n < qnt)
	{
		str[n] = str_alloc(s, c, &i);
		if (!str)
		{
			ft_freearr((void **)str);
			return (0);
		}
		str[n] = str_maker(s, c, &i, str[n]);
	}
	str[n] = 0;
	return (str);
}

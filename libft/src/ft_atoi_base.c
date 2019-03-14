/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:42:59 by aroi              #+#    #+#             */
/*   Updated: 2018/07/26 13:40:53 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\f' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int			ft_base(const char *str, int base)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (ft_isdigit(str[i]) || ft_isalpha(str[i]))
	{
		if (ft_isdigit(str[i]))
			n = n * base + (int)str[i++] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			n = n * base + (int)str[i++] - 'A' + 10;
		else
			n = n * base + (int)str[i++] - 'a' + 10;
	}
	return (n);
}

int			ft_atoi_base(const char *str, int base)
{
	size_t		i;
	int			sign;

	i = 0;
	sign = 1;
	if (base == 10)
		return (ft_atoi(str));
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	return (sign * ft_base(str + i, base));
}

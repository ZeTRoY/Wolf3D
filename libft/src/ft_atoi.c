/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:50:41 by aroi              #+#    #+#             */
/*   Updated: 2018/07/14 04:20:23 by aroi             ###   ########.fr       */
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

int			ft_atoi(const char *str)
{
	size_t		i;
	long int	n;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit((int)str[i]))
	{
		if ((n > LONG || (n == LONG && str[i] - '0' > 7)) && sign == 1)
			return (-1);
		else if ((n > LONG || (n == LONG && str[i] - '0' > 8)) && sign == -1)
			return (0);
		n = n * 10 + (int)str[i++] - '0';
	}
	return (sign * (int)n);
}

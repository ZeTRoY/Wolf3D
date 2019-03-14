/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 10:34:16 by aroi              #+#    #+#             */
/*   Updated: 2018/07/14 04:23:41 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(intmax_t n, int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(n);
	while (str && str[i])
		ft_putchar_fd(str[i++], fd);
	ft_strdel(&str);
}

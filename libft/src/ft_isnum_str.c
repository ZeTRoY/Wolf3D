/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:33:57 by aroi              #+#    #+#             */
/*   Updated: 2019/02/02 18:45:40 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isnum_str(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

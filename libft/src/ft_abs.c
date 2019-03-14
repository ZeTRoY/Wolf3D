/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:15:34 by aroi              #+#    #+#             */
/*   Updated: 2019/03/07 11:41:13 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

double		ft_abs_double(double x)
{
	if (x < 0.0)
		return (-x);
	return (x);
}
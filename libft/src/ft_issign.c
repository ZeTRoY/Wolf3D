/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 13:01:49 by aroi              #+#    #+#             */
/*   Updated: 2018/07/29 13:17:58 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

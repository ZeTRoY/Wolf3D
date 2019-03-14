/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 12:42:43 by aroi              #+#    #+#             */
/*   Updated: 2018/07/09 10:31:58 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_date		*ft_new_date(void)
{
	t_date *date;

	if (!(date = (t_date *)malloc(sizeof(t_date))))
		return (0);
	date->year = 0;
	date->month = 1;
	date->day = 1;
	date->hour = 0;
	date->min = 0;
	date->sec = 0;
	date->n = 0;
	return (date);
}

void		ft_del_date(t_date **date)
{
	if (!*date)
		return ;
	free(*date);
}

void		print_date(t_printf **printf, int date, int specify)
{
	int i;

	i = ft_count_digits_base(date, 10);
	if (date == 0)
		i = 0;
	if (specify == YEAR)
		while (i < 4 && ++(*printf)->num && ++i)
			ft_putchar('0');
	else if (specify == MONTH)
		while (i < 2 && ++(*printf)->num && ++i)
			ft_putchar('0');
	else if (specify == DAY)
		while (i < 2 && ++(*printf)->num && ++i)
			ft_putchar('0');
	else if (specify == 2 * MONTH)
		while (i < 2 && ++(*printf)->num && ++i)
			ft_putchar('0');
	else
		while (i < 2 && ++(*printf)->num && ++i)
			ft_putchar('0');
	if (date)
		ft_putnbr(date);
	while (date && ++(*printf)->num)
		date /= 10;
}

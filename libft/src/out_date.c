/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_date.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 12:17:37 by aroi              #+#    #+#             */
/*   Updated: 2018/07/09 13:28:43 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	isvalid(t_date *date)
{
	if (ft_count_digits_base(date->year, 10) > 4 || date->year < 0)
		return (0);
	if (date->month < 1 || date->month > 12)
		return (0);
	if (date->day < 1 || date->day > 31)
		return (0);
	if (date->hour < 0 || date->day > 23)
		return (0);
	if (date->min < 0 || date->min > 59)
		return (0);
	if (date->day < 0 || date->day > 59)
		return (0);
	return (1);
}

static void	ft_print(t_printf **printf, t_date *date)
{
	if (date->n > 0 && isvalid(date))
	{
		print_date(printf, date->year, YEAR);
		ft_putchar('-');
		print_date(printf, date->month, MONTH);
		ft_putchar('-');
		print_date(printf, date->day, DAY);
	}
	if (date->n > 3 && isvalid(date))
	{
		ft_putchar(' ');
		print_date(printf, date->hour, 2 * MONTH);
		ft_putchar(':');
		print_date(printf, date->min, 2 * DAY);
		ft_putchar(':');
		print_date(printf, date->sec, 2 * DAY);
	}
	if (date->n == 0 && isvalid(date))
		write(1, "Standart time is: YYYY-MM-DD hh:mm:ss.", 38);
	else if (!isvalid(date))
	{
		write(1, "A year must be positive, month should be less then 13", 53);
		write(1, ", day less then 32,\nhours less then 25, minutes and ", 53);
		write(1, "seconds less then 60.", 21);
	}
}

static void	ft_print_date(t_date **date, char *tmp)
{
	if (!tmp || !*tmp)
		return ;
	if ((*date)->n == 0)
		(*date)->year = ft_atoi(tmp);
	else if ((*date)->n == 1)
		(*date)->month = ft_atoi(tmp);
	else if ((*date)->n == 2)
		(*date)->day = ft_atoi(tmp);
	else if ((*date)->n == 3)
		(*date)->hour = ft_atoi(tmp);
	else if ((*date)->n == 4)
		(*date)->min = ft_atoi(tmp);
	else if ((*date)->n == 5)
		(*date)->sec = ft_atoi(tmp);
	(*date)->n++;
}

static void	ft_find_n_write(t_printf **printf, t_date *date, char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		j = i;
		while (ft_isdigit(str[j]))
			j++;
		tmp = (char *)malloc(j - i + 1);
		j = 0;
		while (ft_isdigit(str[i]))
			tmp[j++] = str[i++];
		tmp[j] = '\0';
		ft_print_date(&date, tmp);
		ft_strdel(&tmp);
		if (str[i] && !ft_isdigit(str[i]))
			i++;
	}
	if (date->n > 3)
		(*printf)->num += 5;
	else if (date->n > 0)
		(*printf)->num += 2;
}

void		ft_is_date(t_printf **printf, va_list apointer)
{
	char	*str;
	t_date	*date;

	str = va_arg(apointer, char *);
	date = ft_new_date();
	ft_find_n_write(printf, date, str);
	ft_print(printf, date);
	ft_del_date(&date);
	(*printf)->str++;
	(*printf)->i++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:14:01 by aroi              #+#    #+#             */
/*   Updated: 2018/07/26 10:23:43 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define YEAR 1000
# define MONTH 12
# define DAY 30

# include <stdarg.h>
# include <stddef.h>
# include "libft.h"

enum				e_cast
{
	H = 1,
	HH = 2,
	L = 3,
	LL = 4,
	J = 5,
	T = 6,
	Z = 7,
	BL = 8
}					t_cast;

typedef struct		s_printf
{
	char			sharp;
	char			zero;
	char			minus;
	char			plus;
	char			space;
	char			apostrophe;
	char			cast;
	char			conv;
	int				sigil;
	int				width;
	int				precision;
	int				num;
	int				i;
	char			*str;
}					t_printf;

typedef struct		s_date
{
	int				year;
	int				month;
	int				day;
	int				hour;
	int				min;
	int				sec;
	int				n;
}					t_date;

int					ft_printf(char *str, ...);

t_printf			*new_printf(void);
void				ft_printf_update(t_printf **printf);
void				ft_del_printf(t_printf **printf);

t_date				*ft_new_date(void);
void				ft_del_date(t_date **date);
void				print_date(t_printf **printf, int date, int specify);

int					is_flag(char *str);
int					is_width(char *str);
int					is_precision(char *str);
int					is_cast(char *str);
int					is_conversion(char *str, int i);
void				ft_flag_activation(t_printf **printf);
void				ft_width_activation(t_printf **printf, va_list apointer);
void				ft_precision_activation(t_printf **printf,
						va_list apointer);
void				ft_cast_activation(t_printf **printf);
void				ft_what_is_love(t_printf **printf, va_list apointer);
void				ft_is_decimal(t_printf **printf, va_list apointer);
void				ft_is_unsigned(t_printf **printf, va_list apointer);
void				ft_is_char(t_printf **printf, va_list apointer);
void				ft_is_string(t_printf **printf, va_list apointer);
void				ft_is_bin_dec(t_printf **printf, va_list apointer);
void				ft_is_bin(t_printf **printf, va_list apointer);
void				ft_is_octo(t_printf **printf, va_list apointer);
void				ft_is_hexa(t_printf **printf, va_list apointer);
void				ft_is_base(t_printf **printf, va_list apointer);
void				ft_is_date(t_printf **printf, va_list apointer);
void				ft_print_width(t_printf **print, int qnt);
void				ft_char_precision_n_width(t_printf **printf, char c);
void				ft_p_precision(t_printf **printf, char *str,
						uintmax_t z, int qnt);
int					ft_p_width(t_printf **printf, char *str, uintmax_t z);
void				ft_print_width_x(t_printf **printf, int qnt);

int					is_sigil(char *str);
void				ft_is_sigil(t_printf **printf);
void				ft_print_number(t_printf **printf, int qnt, char *str);
void				ft_is_nbr_of_c(t_printf **printf, va_list apointer);

void				ft_is_color(t_printf **printf);
void				ft_is_sqrt(t_printf **printf, va_list apointer);
#endif

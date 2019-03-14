/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:39:32 by aroi              #+#    #+#             */
/*   Updated: 2019/03/13 14:36:45 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include "printf.h"

# define LONG 922337203685477580

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char	const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(intmax_t n);
void				ft_putchar(wchar_t c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(intmax_t n);
void				ft_putchar_fd(wchar_t c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(intmax_t n, int fd);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

size_t				ft_strlcpy(char *dst, char const *src, size_t size);
t_list				*ft_strsplittolist(char const *s, char c);
char				*ft_uitoa(uintmax_t n);
char				*ft_itoa_base(intmax_t n, int base);
char				*ft_uitoa_base(uintmax_t n, int base);

void				ft_freearr(void **arr);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_upper(char *str);
void				ft_lower(char *str);
int					ft_count_digits_base(intmax_t i, int base);
int					ft_count_udigits_base(uintmax_t n, int base);
int					ft_count_letters(char *str);
intmax_t			ft_pow(intmax_t n, int base);
char				size_of(wchar_t c);
int					size_of_str(char *str);
int					size_of_uni_str(wchar_t *str);
int					ft_sqrt(uintmax_t n);
int					ft_ishex(int c);
int					ft_isnum_str(char *str);
int					ft_ishexnumber(char *str);
int					ft_atoi_base(const char *str, int base);
void				ft_delarr(void **arr, int y);
int					ft_issign(char c);
void				ft_capitalize(char *str);
void				ft_quicksort_chars(char **arr, int start, int end);
void				ft_skip_whitespaces(const char *str, int *i);
int					ft_abs(int x);
double				ft_abs_double(double x);
int					ft_is_whitespace(char c);

#endif

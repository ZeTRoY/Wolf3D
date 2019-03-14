/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:08:18 by aroi              #+#    #+#             */
/*   Updated: 2018/07/26 10:15:58 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static t_line	*ft_newlist(char *str, int fd)
{
	t_line *list;

	list = (t_line *)malloc(sizeof(t_line));
	if (!list)
		return (0);
	list->content = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!list->content)
	{
		free(list);
		return (0);
	}
	list->fd = fd;
	ft_strcpy(list->content, str);
	list->next = 0;
	return (list);
}

static t_line	*ft_add_and_find_elem(int fd, t_line **list)
{
	char	*str;
	t_line	*tmp;

	if (!*list)
	{
		str = ft_strdup("");
		*list = ft_newlist(str, fd);
		ft_strdel(&str);
		return (*list);
	}
	tmp = *list;
	while (tmp->next)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->fd == fd)
		return (tmp);
	str = ft_strdup("");
	tmp->next = ft_newlist(str, fd);
	ft_strdel(&str);
	return (tmp->next);
}

static void		ft_del_and_add_line(char **line, char **cont)
{
	char *str;

	*line = ft_strsub(*cont, 0, ft_strchr(*cont, '\n') - *cont);
	str = *cont;
	*cont = ft_strsub(*cont, ft_strchr(*cont, '\n') - *cont + 1,
			ft_strlen(*cont) - (ft_strchr(*cont, '\n') - *cont) - 1);
	ft_strdel(&str);
}

int				ft_compare(char **line, char *buff, char **cont)
{
	if (!ft_strcmp(*cont, "") && !ft_strcmp(buff, ""))
		return (0);
	else if (!ft_strcmp(buff, ""))
	{
		*line = ft_strjoin(*cont, buff);
		ft_strclr(*cont);
		return (1);
	}
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	int				res;
	char			*str;
	char			buff[BUFF_SIZE + 1];
	static t_line	*list;
	t_line			*tmp;

	if (fd < 0 || BUFF_SIZE < 0 || read(fd, buff, 0) == -1)
		return (-1);
	tmp = ft_add_and_find_elem(fd, &list);
	while (!ft_strchr(tmp->content, '\n'))
	{
		ft_bzero((char *)buff, BUFF_SIZE + 1);
		read(fd, (char *)buff, BUFF_SIZE);
		if ((res = ft_compare(line, (char *)buff, &tmp->content)) >= 0)
			return (res);
		str = tmp->content;
		tmp->content = ft_strjoin(tmp->content, (char *)buff);
		ft_strdel(&str);
	}
	ft_del_and_add_line(line, (char **)&tmp->content);
	return (1);
}

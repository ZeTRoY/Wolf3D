/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:38:46 by aroi              #+#    #+#             */
/*   Updated: 2018/07/26 21:11:24 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000
# include <unistd.h>
# include <stdlib.h>

int					get_next_line(int fd, char **line);

typedef struct		s_line
{
	struct s_line	*next;
	int				fd;
	char			*content;
}					t_line;

#endif

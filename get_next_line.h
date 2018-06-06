/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:50:33 by gzagura           #+#    #+#             */
/*   Updated: 2018/03/24 20:52:22 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 10

#include "./libft/libft.h"

int		get_next_line(const int fd, char **line);

typedef struct			s_getlist
{
	int					num_fd;
	char				*content;
	struct s_getlist	*next;
}						t_getlist;
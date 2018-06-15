/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:45:58 by gzagura           #+#    #+#             */
/*   Updated: 2018/03/24 20:46:00 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

t_getlist	*ft_newlist(int fd)
{
	t_getlist	*new;

	new = (t_getlist*)malloc(sizeof(t_getlist));
	new->next = NULL;
	new->content = ft_strnew(BUFF_SIZE);
	new->num_fd = fd;
	return (new);
}

t_getlist	*ft_worklist(t_getlist *head, int fd)
{
	if (head == NULL)
	{
		head = ft_newlist(fd);
		return (head);
	}
	while (head != NULL)
	{
		if(head->num_fd == fd)
			return (head);
		else if (head->next)
			head = head->next;
		else
			break ;
	}
	head->next = ft_newlist(fd);
	return (head->next);
}

int		ft_crazy(char *buffe, int fd, char **line, int bytes)
{
	static t_getlist *tmp = NULL;
	t_getlist *head;
	char *suka;

	*line = NULL;
	if (!tmp)
	{
		tmp = ft_worklist(tmp, fd);
		head = tmp;
	}
	else
		head = ft_worklist(tmp, fd);
	*line = ft_strjoin(head->content, buffe);
	free(head->content);
	head->content = ft_strdup(*line);
	free(*line);
	if (ft_strchr(head->content, '\n'))
	{
		*line = ft_strsub(head->content, 0, (int)(ft_strchr(head->content, '\n') - head->content));
		suka = ft_strdup(ft_strchr(head->content, '\n') + 1);
		free(head->content);
		head->content = ft_strdup(suka);
		free(suka);
		return (1);
	}
	if (head->content[0] != '\0' && bytes < BUFF_SIZE)
	{
		*line = ft_strdup(head->content);
		ft_bzero(head->content, ft_strlen(head->content));
		return (1);
	}
	if (head->content[0] != '\0')
		return (-1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int		bytes;
    int     re;
	char	buffe[BUFF_SIZE + 1];

	buffe[BUFF_SIZE] = '\0';
	if (!line || fd < 0 || read(fd, 0, 0) == -1)
		return (-1);
	while ((bytes = read(fd, buffe, BUFF_SIZE)) > -2)
	{
		if (bytes == -1)
			return (-1);
		if (bytes < BUFF_SIZE)
			ft_bzero((void **) (buffe + bytes), BUFF_SIZE - bytes);
		while ((re = ft_crazy(buffe, fd, line, bytes)) > -2)
		{
			if (re == -1)
				break;
			return (re);
		}
	}
	return (0);
}

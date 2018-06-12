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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		main(int argc, char const *argv[])
{
	int fd1;
	int fd2;
	char *line;

	fd1 = open("test", O_RDONLY);
	fd2 = open("text", O_RDONLY);
	get_next_line(fd1, &line);
	free(line);
	printf("after gnl = %s\n", line);
	get_next_line(fd2, &line);
	free(line);
	printf("after gnl = %s\n", line);
	get_next_line(fd1, &line);
	printf("after gnl = %s\n", line);
	get_next_line(fd2, &line);
	free(line);
	printf("after gnl = %s\n", line);

	return (0);
	
}

t_getlist	*ft_newlist(int fd)
{
	t_getlist	*new;

	//printf("\n\n\nprivet\n");
	new = (t_getlist*)malloc(sizeof(t_getlist));
	new->next = NULL;
	new->content = (char*)malloc(sizeof(1));
	ft_bzero(new->content, 2);
	new->num_fd = fd;
	//printf("FD =%d\n", head->num_fd);
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
	//printf("11111111\n");
	head->next = ft_newlist(fd);
	return (head);
}

int		ft_crazy(char *buffe, int fd, char **line)
{
	static t_getlist *tmp = NULL;
	t_getlist *head;
	int i = -1;
	char	*suka;

	*line = NULL;
	if (!tmp)
	{
		tmp = ft_worklist(tmp, fd);
		head = tmp;
		//printf("11111\n");
	}
	else
	{
		head = ft_worklist(tmp, fd);
	}
	suka = ft_strjoin(head->content, buffe);
	free(head->content);
	head->content = ft_strdup(suka);
	//printf("head->content =%s\n",head->content );
	while (head->content[++i] != '\0')
	{
		
		if(head->content[i] == '\n')
		{
			*line = ft_strsub(head->content, 0, i);
			suka = ft_strdup(head->content + i + 1);
			free(head->content);
			head->content = ft_strdup(suka);
			return (1);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int		bytes = 1;
	char	buffe[BUFF_SIZE + 1];

	if (!line)
		return (-1);
	while (bytes > 0)
	{
		bytes = read(fd, buffe, BUFF_SIZE);
		if (bytes < 0)
			return(-1);
		if (ft_crazy(buffe, fd, line) == 1)
		{
			return (1);
		}
	}
	return (0);
}


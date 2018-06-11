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
	char *line;

	fd1 = open("text", O_RDONLY);
	get_next_line(fd1, &line);
	printf("after gnl = %s\n", line);
	get_next_line(fd1, &line);
	printf("after gnl = %s\n", line);
	return 0;
}
char	*ft_strjoinfree(char *s1, char *s2)
{
	char *string;

	string = NULL;
	string = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
											ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	ft_strcpy(string, s1);
	ft_strcpy(string + ft_strlen(s1), s2);
	return (string);
}

t_getlist	*ft_newlist(t_getlist *head, int fd)
{
	head = (t_getlist*)malloc(sizeof(t_getlist));
	head->next = NULL;
	head->content = (char*)malloc(sizeof(1));
	ft_bzero(head->content, 2);
	head->num_fd = fd;
	return (head);
}
t_getlist	*ft_worklist(t_getlist *head, int fd)
{
	if (head == NULL)
	{
		head = ft_newlist(head, fd);
		return (head);
	}
	while (head)
	{
		if(head->num_fd == fd)
			return (head);
		head = head->next;
	}
	return (head);
}

int		ft_crazy(char *buffe, int fd, char **line)
{
	static t_getlist *head = NULL;
	int i = -1;

	*line = NULL;
	head = ft_worklist(head, fd);
	head->content = ft_strjoinfree(head->content, buffe);
	printf("-------FULL--------\n");
	printf("%s\n",head->content);
	printf("---------------\n");
	while (head->content[++i] != '\0')
	{
		
		if(head->content[i] == '\n')
		{
			*line = ft_strsub(head->content, 0, i);
			printf("len = %d\n", (int)ft_strlen(head->content));
			printf("head->content = %s\n", head->content + i + 1);
			head->content = ft_strsub(head->content + i + 1, 0, ft_strlen(head->content + i + 1));
			printf("CCContent = %s\n\n",head->content);
			return (1);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int		bytes = 1;
	char	buffe[BUFF_SIZE + 1];

	while (bytes > 0)
	{
		bytes = read(fd, buffe, BUFF_SIZE);
		if (ft_crazy(buffe, fd, line) == 1)
		{
			printf("line =  %s\n", *line);
			return (0);
		}
	}
	return (0);
}


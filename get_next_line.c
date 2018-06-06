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
	int fd;
	//printf("LOX\n");
	fd = open("text.txt", O_RDONLY);
	get_next_line(fd,NULL);
	return 0;
}
void	ft_newlist(t_getlist *head, int fd)
{
	head = (t_getlist*)malloc(sizeof(t_getlist));
	head->next = NULL;
	head->content = ft_strnew(BUFF_SIZE);
	head->num_fd = fd;
}
t_getlist	*ft_worklist(t_getlist *head, int fd)
{
	if (head == NULL)
			ft_newlist(head, fd);
	while (head)
	{
		if (head == NULL)
			ft_newlist(head, fd);
		else if(head->num_fd == fd)
			return (head);
		head = head->next;
	}
	return (head);
}

int		ft_crazy(char *buffe, int fd)
{
	t_getlist *head;
	int i = -1;

	if (!head)
		ft_worklist(head, fd);
	head->content = ft_strjoin(head->content, buffe);
	while (head->content[++i] != '\0')
	{
		if(head->content[i] == '\n')
		{
			printf("CRAZY: %s\n",head->content);
			return (0);
		}
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int		bytes = 1;
	char	buffe[BUFF_SIZE + 1];

	while (ft_crazy(buffe, fd) == 1 && bytes > 0)
	{
		bytes = read(fd, buffe, BUFF_SIZE);
		ft_crazy(buffe, fd);
	}
	return (0);
}

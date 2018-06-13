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

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl7_1.txt";
	fd = open(filename, O_RDONLY);
	line = NULL;
	ret = 0;
	
	char	*lolo;

	lolo = "taras molodec\ngleb toje molodec";
	printf("%s\n",ft_strchr(lolo, '\n'));

	// count_lines = 0;
	// while ((ret = get_next_line(fd, &line)) > 0)
	// {
	// 	count_lines++;
	// 	printf("%s\n",line);
	// }
	// printf("count_lines = %d\n", count_lines);
	return (0);
}

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

int		ft_crazy(char *buffe, int fd, char **line)
{
	static t_getlist *tmp = NULL;
	t_getlist *head;
	int i = -1;
	//char	*suka;

	// *line = NULL;
	if (!tmp)
	{
		tmp = ft_worklist(tmp, fd);
		head = tmp;
	}
	else
	{
		head = ft_worklist(tmp, fd);
	}
	*line = ft_strjoin(head->content, buffe);
	free(head->content);
	head->content = ft_strdup(*line);
	//printf("%s\n",*line);
	//free(*line);
	while (head->content[++i] != '\0')
	{
		if(head->content[i] == '\n')
		{
			// printf("11\n");
			// printf("head->content = %s\nsuka = %s\nhead->content[i] = %c\n", head->content, suka, head->content[i]);
			*line = ft_strsub(head->content, 0, i);
			//printf("line = %s\n", *line);
			head->content = ft_strdup(head->content + i + 1);

			
			// free(head->content);
			// head->content = ft_strdup(suka);
			
			// free(suka);
			return (1);
		}
	}
	
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int		bytes = 1;
	char	buffe[BUFF_SIZE + 1];

	buffe[BUFF_SIZE] = '\0';

	if (!line)
		return (-1);
	while ((bytes = read(fd, buffe, BUFF_SIZE)))
	{
		
		if (bytes < 0)
			return(-1);
		if (ft_crazy(buffe, fd, line) == 1)
		{
			return (1);
		}
	}
	return (0);
}


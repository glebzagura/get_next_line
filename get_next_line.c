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

int		ft_crazy(char **suka)
{
	t_getlist *head;

	head = (t_getlist*)malloc(sizeof(t_getlist));
	head->next = NULL;

}

int		get_next_line(const int fd, char **line)
{
	char	buffe[BUFF_SIZE + 1];

	while (ft_crazy(buffe) == 1)
	{
		read(fd, buffe, BUFF_SIZE) > 0
		if (!head->content)
		{
			printf("%s\n", ft_strjoin(head->content, buffe)); 
		}
		head->content = (char*)malloc(sizeof(BUFF_SIZE + 1));
		head->content = buffe;
	}
	printf("SUKA %zu\n", ft_strlen(head->content));
	printf("%s\n", head->content);
	return (0);
}

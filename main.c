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
	
	//char	*lolo;

	//lolo = "taras molodec\ngleb toje molodec";
	//printf("%s\n",ft_strchr(lolo, '\n'));

	count_lines = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		count_lines++;
		printf("%s\n",line);
	}
	printf("count_lines = %d\n", count_lines);
	return (0);
}
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
	
	count_lines = 0;
	get_next_line(fd, &line);
	printf("%s\n",line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n",line);
	free(line);
	get_next_line(fd, &line);
	printf("%s\n",line);
	free(line);
	return (0);
}
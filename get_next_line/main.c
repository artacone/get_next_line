# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"

int		main()
{
	char	*line;
	int		fd;
	int		i;

#if 1
	fd = open("test.txt", O_RDONLY);

	while((i = get_next_line(fd, &line)) > 0)
	{
		printf("[i:%d %s\n", i, line);
		free (line);
	}
	printf("[i:%d %s\n", i, line);
	free(line);
#else
	fd = open("test.txt", O_RDONLY);

	i = get_next_line(fd, &line);
	printf("[i:%d %s\n", i, line);
	free (line);
	close(fd);

	fd = open("test.txt", O_RDONLY);

	i = get_next_line(fd, &line);
	printf("[i:%d %s\n", i, line);
	free (line);
#endif
	return (0);
}

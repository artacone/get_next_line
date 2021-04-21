# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line_bonus.h"

int		main()
{
	char	*line = NULL;
	int		ret;

	int fd1 = open("./test/bonus1.txt", O_RDONLY);
	int fd2 = open("./test/bonus2.txt", O_RDONLY);
	int fd3 = open("./test/bonus3.txt", O_RDONLY);
	int fd4 = open("./test/bonus4.txt", O_RDONLY);
	int fd5 = open("./test/bonus5.txt", O_RDONLY);

	for (int i = 0; i < 10; i++)
	{
		ret = get_next_line(fd1, &line);
		printf("file1: %d\t%s\n", ret, line);
		if (line) free(line);
		ret = get_next_line(fd2, &line);
		printf("file2: %d\t%s\n", ret, line);
		if (line) free(line);
		ret = get_next_line(fd3, &line);
		printf("file3: %d\t%s\n", ret, line);
		if (line) free(line);
		ret = get_next_line(fd4, &line);
		printf("file4: %d\t%s\n", ret, line);
		if (line) free(line);
		ret = get_next_line(fd5, &line);
		printf("file5: %d\t%s\n", ret, line);
		if (line) free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	return (0);
}

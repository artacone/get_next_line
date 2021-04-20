#include "get_next_line.h"

/*
 * TODO * No rem reallocation (allocate and free once and use smth like strcpy)
 *		* Protect read()
 * 		* Norm
 * 		* Bonus (multiple fds)
 */
static char	*trim_line(char **buf, char **line)
{
	char	*ptr_endl;
	char	*to_free;

	ptr_endl = NULL;
	if (*buf != NULL)
	{
		to_free = *line;
		if ((ptr_endl = ft_strchr(*buf, '\n')) != NULL)
		{
			*ptr_endl = '\0';
			*line = ft_strjoin(*line, *buf);
			free(*buf);
			*buf = ft_strdup(++ptr_endl); // FIXME replace with smth like strcpy()
		}
		else
		{
			*line = ft_strjoin(*line, *buf);
			free(*buf);
			*buf = NULL;
		}
		free(to_free);
	}
	return (ptr_endl);
}

int	get_next_line(int fd, char **line)
{
	char		buf_read[BUFFER_SIZE + 1];
	ssize_t		n_read;
	char 		*ptr_endl;
	static char	*buf;

	if (BUFFER_SIZE < 1 || line == NULL || read(fd, buf_read, 0) == -1)
		return (-1);
	*line = ft_strdup("");
	ptr_endl = trim_line(&buf, line);
	while ((ptr_endl == NULL) && (n_read = read(fd, buf_read, BUFFER_SIZE))) // FIXME protect read
	{
		buf_read[n_read] = '\0';
		buf = ft_strdup(buf_read);
		ptr_endl = trim_line(&buf, line);
	}
	if (ptr_endl)
		return (1);
	else
		return (0);
}

#include "get_next_line.h"

/*
 * TODO *
 *		* Protect read()
 * 		* Norm
 * 		* Bonus (multiple fds)
 */
static char	*trim_line(char **buf, char **line)
{
	char	*ptr_endl;
	char	*to_free;

	ptr_endl = NULL;
	if (**buf != '\0')
	{
		to_free = *line;
		if ((ptr_endl = ft_strchr(*buf, '\n')) != NULL)
		{
			*ptr_endl = '\0';
			*line = ft_strjoin(*line, *buf);
			ft_strlcpy(*buf, ++ptr_endl, BUFFER_SIZE);
		}
		else
		{
			*line = ft_strjoin(*line, *buf);
			ft_bzero(*buf, BUFFER_SIZE);
		}
		free(to_free);
	}
	return (ptr_endl);
}

int	get_next_line(int fd, char **line)
{
	char 		*ptr_endl;
	static char	*buf;

	if (buf == NULL)
	{
		buf = (char *) calloc(BUFFER_SIZE + 1, 1);
	}
	if (BUFFER_SIZE < 1 || line == NULL || buf == NULL || read(fd, 0, 0) == -1)
		return (-1); // buf leak
	*line = ft_strdup("");
	ptr_endl = trim_line(&buf, line);
	while ((ptr_endl == NULL) && read(fd, buf, BUFFER_SIZE)) // FIXME protect read
	{
		ptr_endl = trim_line(&buf, line);
	}
	if (ptr_endl)
		return (1);
	else
		return (0);
}

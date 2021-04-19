#include "get_next_line.h"

/*
 * TODO * No rem reallocation (allocate and free once and use smth like strcpy)
 *		* Protect read()
 * 		* Norm
 * 		* Bonus (multiple fds)
 */
static char	*check_rem(char **rem, char **line) // Should it free line in advance?
{
	char	*p_endl;
	char	*to_free;

	p_endl = NULL;
	*line = ft_strdup(""); // FIXME (escape free() error)
	if (*rem != NULL)
	{
		to_free = *line;
		if ((p_endl = ft_strchr(*rem, '\n')) != NULL)
		{
			*p_endl = '\0';
			*line = ft_strdup(*rem);
			free(*rem);
			*rem = ft_strdup(++p_endl); // FIXME replace with smth like strcpy()
		}
		else
		{
			*line = ft_strdup(*rem);
			free(*rem);
			*rem = NULL;
		}
		free(to_free);
	}
	return (p_endl);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		n_read;
	char 		*ptr_endl;
	char 		*to_free;
	static char	*rem;

	if (BUFFER_SIZE < 1 || line == NULL || read(fd, buf, 0) == -1)
		return (-1);
	ptr_endl = check_rem(&rem, line);
	while ((ptr_endl == NULL) && (n_read = read(fd, buf, BUFFER_SIZE))) // FIXME protect read
	{
		buf[n_read] = '\0';
		if ((ptr_endl = ft_strchr(buf, '\n')))
		{
			*ptr_endl = '\0';
			rem = ft_strdup(++ptr_endl); // Should it really allocate each time?
		}
		to_free = *line;
		if ((*line = ft_strjoin(*line, buf)) == NULL)
		{
			free(to_free);
			if (ptr_endl)
				free(rem);
			return (-1); // Leak possibility
		}
		free(to_free); // FIXME free(rem)
	}
	if (ptr_endl)
		return (1);
	else
		return (0);
}

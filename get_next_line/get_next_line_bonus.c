#include "get_next_line_bonus.h"

/*
 * TODO *
 *		* Protect read()
 * 		* Norm
 * 		* LEAK with buf
 */
static char	*trim_line(char **buf, char **line)
{
	char	*ptr_endl;
	char	*to_free;

	ptr_endl = NULL;
	if (**buf != '\0')
	{
		to_free = *line;
		ptr_endl = ft_strchr(*buf, '\n');
		if (ptr_endl != NULL)
		{
			*ptr_endl++ = '\0';
			*line = ft_strjoin(*line, *buf);
			ft_strlcpy(*buf, ptr_endl, BUFFER_SIZE);
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

static int	get_next_line_internal(int fd, char **line, char *buf)
{
	char	*ptr_endl;

	*line = ft_strjoin("", "");
	if (line == NULL)
		return (-1);
	ptr_endl = trim_line(&buf, line);
	if (line == NULL)
		return (-1);
	while (ptr_endl == NULL && read(fd, buf, BUFFER_SIZE)) // FIXME protect read
	{
		ptr_endl = trim_line(&buf, line); // leak
		if (line == NULL)
			return (-1);
	}
	if (ptr_endl) // '\n' was found
		return (1);
	else
		return (0);
}

t_buf_list	*create_new_buf_node(const int fd)
{
	t_buf_list *new;

	new = (t_buf_list *)malloc(sizeof(t_buf_list));
	if (new)
	{
		new->fd = fd;
		new->buf = (char *)calloc(BUFFER_SIZE + 1, 1);
		if (new->buf == NULL)
		{
			free(new);
			return (NULL);
		}
		new->next = NULL;
	}
	return (new);
}

int	get_next_line(int fd, char **line)
{
	static t_buf_list	*head_buf_list;
	t_buf_list			*node_buf_list;
	int					ret;

	if (BUFFER_SIZE < 1 || line == NULL || read(fd, 0, 0) == -1)
	{
		//clear_list_buf(&head_buf);
		return (-1);
	}
	if (head_buf_list == NULL)
	{
		head_buf_list = create_new_buf_node(fd);
		if (head_buf_list == NULL)
			return (-1);
	}
	node_buf_list = head_buf_list;
	while (node_buf_list->fd != fd)
	{
		if (node_buf_list->next == NULL)
		{
			node_buf_list->next = create_new_buf_node(fd);
			if (node_buf_list->next == NULL)
				return (-1); // We don't clear all other fds
		}
		node_buf_list = node_buf_list->next;
	}
	ret = get_next_line_internal(fd, line, node_buf_list->buf); // FIXME leak on end EOF
	if (ret == -1 || ret == 0)
		//delete_node();
	return (ret);
}

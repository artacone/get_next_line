#include "get_next_line_bonus.h"

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
			**buf = '\0';
		}
		free(to_free);
	}
	return (ptr_endl);
}

static int	get_next_line_internal(int fd, char **line, char *buf)
{
	char	*ptr_endl;
	ssize_t	n_read;

	*line = ft_str_calloc(1);
	if (*line == NULL)
		return (-1);
	ptr_endl = trim_line(&buf, line);
	while (ptr_endl == NULL)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (*line == NULL || n_read == -1)
			return (-1);
		buf[n_read] = '\0';
		if (n_read == 0)
			break ;
		ptr_endl = trim_line(&buf, line);
	}
	if (ptr_endl)
		return (1);
	else
		return (0);
}

static void	remove_fd_from_list(t_buf_list **head, int fd)
{
	t_buf_list	*node;
	t_buf_list	*prev;

	node = *head;
	prev = NULL;
	if (node != NULL && node->fd == fd)
	{
		*head = node->next;
		free(node->buf);
		free(node);
		return ;
	}
	while (node != NULL && node->fd != fd)
	{
		prev = node;
		node = node->next;
	}
	if (node == NULL)
		return ;
	prev->next = node->next;
	free(node->buf);
	free(node);
}

static int	init_handler(int fd, char **line, t_buf_list **head)
{
	if (BUFFER_SIZE < 1 || line == NULL || read(fd, 0, 0) == -1)
	{
		remove_fd_from_list(head, fd);
		return (-1);
	}
	if (*head == NULL)
	{
		*head = create_new_buf_node(fd);
		if (*head == NULL)
			return (-1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_buf_list	*head_buf_list;
	t_buf_list			*node_buf_list;
	int					ret;

	if (init_handler(fd, line, &head_buf_list) == -1)
		return (-1);
	node_buf_list = head_buf_list;
	while (node_buf_list->fd != fd)
	{
		if (node_buf_list->next == NULL)
		{
			node_buf_list->next = create_new_buf_node(fd);
			if (node_buf_list->next == NULL)
				return (-1);
		}
		node_buf_list = node_buf_list->next;
	}
	ret = get_next_line_internal(fd, line, node_buf_list->buf);
	if (ret == -1 || ret == 0)
		remove_fd_from_list(&head_buf_list, fd);
	return (ret);
}

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = c;
	while (*s)
	{
		if (*s++ == ch)
		{
			return ((char *)s - 1);
		}
	}
	if (ch == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*resi;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	res = (char *)malloc(s1_len + s2_len + 1);
	if (res == NULL)
		return (NULL);
	resi = res;
	while (*s1)
		*resi++ = *s1++;
	while (*s2)
		*resi++ = *s2++;
	*resi = '\0';
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*s;
	size_t		n_left;

	s = src;
	n_left = size;
	if (n_left != 0)
	{
		while (--n_left != 0)
		{
			*dst++ = *s;
			if (*s++ == '\0')
				break ;
		}
	}
	if (n_left == 0)
	{
		if (size != 0)
			*dst = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}

char	*ft_str_calloc(size_t n_bytes)
{
	void			*str;
	unsigned char	*str_i;

	str = malloc(n_bytes);
	if (str != NULL)
	{
		str_i = str;
		while (n_bytes-- != 0)
		{
			*str_i++ = '\0';
		}
	}
	return (str);
}

t_buf_list	*create_new_buf_node(const int fd)
{
	t_buf_list	*new;

	new = (t_buf_list *)malloc(sizeof(t_buf_list));
	if (new)
	{
		new->fd = fd;
		new->buf = ft_str_calloc(BUFFER_SIZE + 1);
		if (new->buf == NULL)
		{
			free(new);
			return (NULL);
		}
		new->next = NULL;
	}
	return (new);
}

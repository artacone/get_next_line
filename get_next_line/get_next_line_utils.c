#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*str)
	{
		str++;
	}
	return (str - s);
}

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

	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == NULL)
	{
		return (NULL);
	}
	resi = res;
	while (*s1)
	{
		*resi++ = *s1++;
	}
	while (*s2)
	{
		*resi++ = *s2++;
	}
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

void	*ft_calloc(size_t n_bytes)
{
	void			*ptr;
	unsigned char	*ptr_i;

	ptr = malloc(n_bytes);
	if (ptr != NULL)
	{
		ptr_i = ptr;
		while (n_bytes-- != 0)
		{
			*ptr_i++ = '\0';
		}
	}
	return (ptr);
}

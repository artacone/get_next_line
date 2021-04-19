#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char  *str;

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

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s) + 1;
	dup = (char *)malloc(size);
	if (dup == NULL)
	{
		return (NULL);
	}
	ft_memcpy(dup, s, size);
	return (dup);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long long			*wd;
	const unsigned long long	*ws;
	unsigned char				*cd;
	const unsigned char			*cs;

	wd = dest;
	ws = src;
	while (n >= sizeof(*wd))
	{
		*wd++ = *ws++;
		n -= sizeof(*wd);
	}
	cs = (const unsigned char *)ws;
	cd = (unsigned char *)wd;
	while (n > 0)
	{
		*cd++ = *cs++;
		n--;
	}
	return (dest);
}
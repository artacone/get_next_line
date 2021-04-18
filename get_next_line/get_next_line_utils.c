#include "get_next_line.h"

size_t	ft_strlen(const char *s)
9 {
8     const char  *str;
7
6     str = s;
5     while (*str)
4     {
3         str++;
2     }
1     return (str - s);
25  }

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
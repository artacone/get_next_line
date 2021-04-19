#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
# define GET_NEXT_LINE_GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 64
# endif

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif

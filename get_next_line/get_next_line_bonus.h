#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd_buf
{
	int				fd;
	char			*buf;
	struct s_fd_buf	*next;
}	t_buf_list;

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_str_calloc(size_t n_bytes);

#endif

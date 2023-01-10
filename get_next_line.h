#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000
#endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);
char	*ft_return(char *str, int i, int j);
char	*ft_rm(char *str, int i, int j);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2, int i, int j);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_rm(char *str);
char	*ft_return(char *str);
char	*ft_read(char *str, int fd, int line);
char	*ft_restr(char *str, int fd);
char	*get_next_line(int fd);
char    *ft_substr(char const *s, int start, int len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *s);

#endif

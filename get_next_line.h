#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100000

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char            *get_next_line(int fd);
int             ft_how_many_lines(char *s);
char            *ft_rendu(char *s);
char            *ft_reallocate_properly(char *s, long long count, unsigned int line);
void            *ft_memmove(void *dst, const void *src, int len);
unsigned int    ft_strlen(const char *s);
char            *ft_substr(char const *s, unsigned int start, size_t len);

#endif
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void    *ft_memmove(void *dst, const void *src, int len)
{
    unsigned char	*dest;
    unsigned char	*srcc;
   	int				i;

    dest = (unsigned char *)dst;
    srcc = (unsigned char *)src;
    i = 0;
    if (!dest && !srcc)
        return (0);
    while (i < len && dst < src)
    {
        dest[i] = srcc[i];
        i++;
    }
    while (len-- && (!(dst < src)))
        dest[len] = srcc[len];
    return (dst);
}

unsigned int    ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t    i;
    size_t    sub_len;
    char    *substr;

    i = 0;
    if (!s)
        return (0);
    sub_len = start;
    if (len > ft_strlen(s))
        len = ft_strlen(s) - start;
    if (start > ft_strlen(s))
        len = 0;
    substr = (char *)malloc(sizeof(char) * (len + 1));
    if (!substr || !s)
        return (0);
    while (start < sub_len + len)
        substr[i++] = s[start++];
    substr[i] = '\0';
    return (substr);
}

char    *ft_rendu(char *s)
{    
    static char *rendu;
    int i;

    i = 0;
    if (rendu)
        free(rendu);
    while (s[i] && s[i] != '\n')
        i++;
	if (s[i] == '\n')
		i++;
    rendu = ft_substr((char const *)s, 0, (size_t)i);
    return (rendu);
}

char    *ft_reallocate_properly(char *s, long long count, unsigned int line)
{
    static char    *rendu;
    unsigned int i;
    unsigned int current_line;

    i = 0;
    current_line = 0;
    if (rendu)
      free(rendu);
    if (s && count)
    {
        while (s[i] && current_line != line)
        {    
            while (i != line && s[i] != '\n')
                i++;
            if (s[i++] == '\n')
                current_line++;
        }
        rendu = (char *)malloc(sizeof(char) * (count - i + 1));
        ft_memmove((void *)rendu, (const void *)s + i, count - i + 1);
        return (ft_rendu(rendu));
    }
    return (0);
}

int ft_how_many_lines(char *s)
{
	int i;
	int line_count;
	
	i = 0;
	line_count = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			line_count++;
		i++;
	}
	return (line_count-1);
}

char *get_next_line(int fd)
{
	static int line;
	int size = 789897;
	static int count;
	static char *s;
	char *rendu;
	char *tmp;
	
	if(s == 0 || !count)
	{
		tmp = malloc(sizeof(char)*size);
		count = read(fd, tmp, size);
		s = malloc(sizeof(char)*(count+1));
		ft_memmove(s, tmp, count);
		s[count + 1] = '\0';
		free(tmp);
	}
	if (line > ft_how_many_lines(s))
		return (0);
	rendu = ft_reallocate_properly(s, count, line);
	line++;
	return(rendu);
}


int main()
{
	int fd = open("txt.txt", O_RDWR);

  	for (int i=0; i<45; i++)
		printf("%s", get_next_line(fd));	
	return (0);  
}

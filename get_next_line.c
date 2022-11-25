#include "get_next_line.h"

char *get_next_line(int fd)
{
	static int line;
	static int count;
	static char *s;
	char *rendu;
	char *tmp;
	
	if(s == 0 || !count)
	{
		tmp = malloc(sizeof(char)*BUFFER_SIZE);
		count = read(fd, tmp, BUFFER_SIZE);
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

int main()
{
	int fd = open("txt.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
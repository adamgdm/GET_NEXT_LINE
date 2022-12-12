#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*str;
	static char *print;
	static int	line;
	int count;
	
	if (line == 0 && fd != -1)
		str = malloc(sizeof(char) * BUFFER_SIZE);
	if (!str && fd != -1)
		return (0);
	if (line == 0 && fd != -1)
		count = read(fd, str, BUFFER_SIZE);
	if (fd == -1)
		return (0);
	line++;
	str = ft_read(str, fd, line);
	if (print)
		free(print);
	print = ft_return(str);
	str = ft_rm(str);
	return (print);
}

char	*ft_restr(char *str, int fd)
{
	char *s;
	char *tmp;
	int count;

	s = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (!s)
		return (0);	
	count = read(fd, s, BUFFER_SIZE);
	if (count == -1)
	{
		if (s)
			free(s);
		return (0);
	}
	if (count == 0)
		return (str);
	s[BUFFER_SIZE] = '\0';
	tmp = str;
	str = ft_strjoin(str, s);
	if (!str)
		return (0);
	if (s)
		free(s);
	if (tmp)
		free(tmp);
	return (str);
}

char	*ft_read(char *str, int fd, int line)
{
	int			i;
	int			count;
	static int	current;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			current++;
		if (str[i + 1] == 0)
		{
			count = ft_strlen(str);
			str = ft_restr(str, fd);
			if (!str)
				return (0);
			if (count == ft_strlen(str))
				return (str);
		}
		if (current == line)
			return (str);
		i++;
	}
	return (0);
}

char	*ft_return(char *str)
{
	int i;
	char *s;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{	
		if (str[i] == '\n')
			break ;
		i++;
	}
	s = ft_substr(str, 0, i);
	return (s);
}

char	*ft_rm(char *str)
{
	int i;
	int j;
	char *s;
	
	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[j])
		j++;	
	while (str[i])
	{	
		if (str[i] == '\n')
			break ;
		i++;
	}
	s = ft_substr(str, i + 1, j);
	return (s);
}

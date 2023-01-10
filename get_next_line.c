#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*print;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	print = ft_return(str, 0, 0);
	str = ft_rm(str, 0, 0);
	return (print);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	char	*tmp;
	int		i;

	i = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free (str);
			free (buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		tmp = str;
		str = ft_strjoin(str, buffer, 0, 0);
		free (tmp);
	}
	free (buffer);
	return (str);
}

char	*ft_return(char *str, int i, int j)
{
	char	*print;

	if (str[0] == '\0')
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[i] != '\n')
		print = malloc(sizeof(char) * (i + 1));
	else
		print = malloc(sizeof(char) * (i + 2));
	if (!print)
		return (NULL);
	while (j <= i && str[j])
	{
		print[j] = str[j];
		j++;
	}
	print[j] = '\0';
	return (print);
}

char	*ft_rm(char *str, int i, int j)
{
	char 	*rest;
	
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	i++;
	rest = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest)
	{
		free (str);
		return (NULL);
	}
	while (str[i])
	{
		rest[j] = str[i];
		j++;
		i++;
	}
	rest[j] = '\0';
	free (str);
	return (rest);
}
/*
int main()
{
	int fd = open("txt.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));


}[33~**/

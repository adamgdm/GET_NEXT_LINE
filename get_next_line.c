#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

typedef struct t_lens 
{
	int len_s1;
	int len_s2;
	int total;
}	t_len;

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		lsrc;
	char	*str;

	str = (char *)s;
	if (!str)
		return (0);
	i = 0;
	lsrc = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return (str + lsrc);
	while (i <= lsrc && str[i])
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	if (!c)
		return (str + i);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sub_len;
	char	*substr;

	i = 0;
	if (!s)
		return (0);
	sub_len = start;
	substr = calloc(sizeof(char), (len + 1));
	if (!substr || !s)
		return (0);
	while (start < sub_len + len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char	*new;
	t_len		x;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	i = 0;
	j = ft_strlen(s1);
	x.len_s1 = ft_strlen(s1);
	x.len_s2 = ft_strlen(s2);
	new = malloc((x.len_s1 + x.len_s2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < x.len_s1)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < x.len_s2)
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}
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

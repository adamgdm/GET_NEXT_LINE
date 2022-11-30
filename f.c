#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		total;
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	k = ft_strlen(s1);
	total = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * total + 1);
	if (!str)
		return (0);
	while (i < total)
	{
		while (i < k)
			str[i++] = s1[j++];
		j = 0;
		while (i < total)
			str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

char	*ft_check(char *s, int fd, int size, int line)
{
	int i;
	char *s2;
	int current_line;

	i = 0;
	current_line = 0; 
	while (s[i])
	{
		while (s[i] != '\n' && s[i + 1] != '\0')
			i++;
		if (s[i] == '\n' && current_line == line)	
			return (s);
		if (s[i] == '\n')
		{	
			current_line++;
			i++;
		}
		else
		{
			s2 = malloc(sizeof(char) * (size + 1));
			read(fd, s2, size);
			s2[size + 1] = '\0';
			s = ft_strjoin(s, s2);
			free(s2);
			i = 0;
		}	
	}
	return (s);
}

int main()
{
	int fd = open("txt.txt", O_RDONLY);

	char *s = malloc (sizeof(char) * (11));

	read(fd, s, 10);

	printf("%s", ft_check(s, fd, 10, 2));

}

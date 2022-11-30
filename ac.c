#include "a.h"

char *mallocatethefouttas1(char *s1, int size);

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

char *do_ya_thong(int fd)
{
	int i;
	int size;
	int count;	
	char *s1;
	char *s2;
	
	printf("FUNCTION START : DO YA THANG\n");
	i = 0;
	size += BUFFER_SIZE;
	s1 = malloc(sizeof(char) * (size + 1));
	count = read(fd, s1, size);
	printf("count : %d", count);
	s1[size + 1] = '\0';
	printf("	SIZE == %d\n", size);
	printf("	S1 == %s\n", s1);
	while(s1[i])
	{
		while ((s1[i] != '\n') && (s1[i + 1] != '\0') && (i < size))
		{
			i++;
		}
		if (s1[i] == '\n' || s1[i + 1] == '\0')
		{
			return (mallocatethefouttas1(s1, i));
		}
		else
		{
			s2 = mallocatethefouttas1(s1, i + BUFFER_SIZE);
			size += BUFFER_SIZE;
			printf("	SIZE == %d\n", size);
			printf("	S2 == %s\n", s2);
			free(s1);
			s1 = malloc(sizeof(char) * (size + 1));
			count = read(fd, s1, size);
			s1[size + 1] = '\0';
			s1 = ft_strjoin(s2, s1);
			printf("	S1 == %s\n", s1);
			free(s2);
		}
	}
	free (s1);
	return (0);
}

char *mallocatethefouttas1(char *s1, int size)
{
	int index;
	char *s2;

	s2 = malloc(sizeof(char) * (size + 1));
	while (s1[index])
	{
		s2[index] = s1[index];
		index++;
	}
	s2[index] = '\0';
}

int main()
{
	int fd = open("txt.txt", O_RDONLY);

	printf("%s", do_ya_thong(fd));
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
char	*ft_do_ya_thong(int fd, int size, int n)
{
	char *s;
	int i;
	int zise = size;
	int m;
	char *mok;
	int j = 1;

	i = 0;
	s = malloc(sizeof(char) * (size + 1));
	mok = s;
	m = read(fd, s, size);
	s[size + 1] = '\0';
	n = m;
	printf("CURRENT LINE IS : %s\n", s);
	printf("CURRENT SIZE IS : %d\n", size);
	while (m >= n)
	{
		while (s[i])
		{
			if (s[i] == '\n' || s[i + 1] == '\0')
				return (s);
			i++;
		}
		i = 0;
		size += zise;
		free(s);
		s = malloc(sizeof(char) * (size + 1) * j);
		s[(size + 1) * j] = '\0';
		m = read(fd, mok, (size);
		printf("CURRENT LINE IS : %s\n", s);
		printf("CURRENT SIZE IS : %d\n", size);
		j++;
	}
	free(s);
	return (0);
}
int main()
{
	static char *s;
	int n;
	int size = 10;
	int fd = open("txt.txt", O_RDONLY);
	
	printf("FINAL RESULT :%s\n", ft_do_ya_thong(fd, size, 0));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:18:34 by agoujdam          #+#    #+#             */
/*   Updated: 2022/11/29 21:44:20 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{	
	static int	line;
	static int	count;
	static char	*s;
	char		*rendu;
	static int	size;
	
	size = BUFFER_SIZE;
	if (fd <= -1)
		return (0);
	if (s == 0 || !count)
	{
		s = malloc(sizeof(char) * (size + 1));
		count = read(fd, s, size);
		s[size + 1] = '\0';
		s = ft_check(s, fd, size, line);
	}
	if (!s || line > ft_how_many_lines(s))
		return (0);

	rendu = ft_reallocate_properly(s, ft_strlen(s), line);
	line++;
	return (rendu);
}

char	*ft_check(char *s, int fd, int size, int line)
{
	int i;
	int count;
	int current_line;
	char *s2;

	i = 0;
	current_line = 0;
	while (s[i])
	{
		while(s[i + 1] != '\0')
			i++;
		if (s[i] == '\n')
		{	
			if (current_line == line)
				return (s);
			current_line++;
		}
		else
		{
			s2 = malloc(sizeof(char) * (size + 1));
			count = read(fd, s2, size);
			if (count == -1)
				return (s);
			s2[size + 1] = '\0';
			s = ft_strjoin(s, s2);
			free (s2);
			i = 0;
		}
	}
	return (s);
}

int	ft_how_many_lines(char *s)
{
	int	i;
	int	line_count;

	i = 0;
	line_count = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			line_count++;
		i++;
	}
	return (line_count - 1);
}

char	*ft_rendu(char *s)
{
	static char	*rendu;
	int			i;

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

char	*ft_reallocate_properly(char *s, long long count, unsigned int line)
{
	static char		*rendu;
	unsigned int	i;
	unsigned int	current_line;

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

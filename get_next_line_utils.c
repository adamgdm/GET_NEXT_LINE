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

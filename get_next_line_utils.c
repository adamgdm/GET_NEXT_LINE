#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	str = (char *)malloc(sizeof(char) * (total + 1));
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

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	int		sub_len;
	char	*substr;

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

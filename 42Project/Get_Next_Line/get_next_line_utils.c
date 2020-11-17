#include "get_next_line.h"

int			ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!(res = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char		*ft_strdup(const char *str)
{
	char	*new_str;
	int		len;

	len = ft_strlen(str);
	if (!(new_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new_str[len] = 0;
	while (len--)
		*new_str++ = *str++;
	return (new_str);
}


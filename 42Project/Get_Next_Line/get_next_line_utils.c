#include "get_next_line.h"


int			ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char		*ft_join(char *s1, char *s2)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	i = 0;
	if (!s1)
	{
		if (!(s1 = (char *)malloc(1)))
			return (NULL);
		*s1 = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char*)malloc(len + 1)))
		return (NULL);
	res[len] = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	return (res);
}

char		*ft_strdup(char *str)
{
	char	*new_str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (!(new_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new_str[len] = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}

char		*ft_strchr(char *s, unsigned char c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return (s);
	return (NULL);
}

char		*ft_strlendup(char *str, int len)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (!(new_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new_str[len] = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}
#include "get_next_line.h"

int				get_next_line(int fd, char **line);

int			ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
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

char			*ft_strchr(char *s, unsigned char c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return (s);
	return (NULL);
}

char			*ft_strlendup(char *str, int len)
{
	char		*new_str;
	int			i;

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

int				split_line(char **line_on_fd, char **line, int fd, int rlen)
{
	char		*tmp;
	int			i;

	i = 0;
	while (line_on_fd[fd][i] && line_on_fd[fd][i] != '\n')
		i++;
	if (line_on_fd[fd][i] == '\n')
	{
		*line = ft_strlendup(line_on_fd[fd], i); // on copy la premiere ligne de line_of_fd
		tmp = ft_strdup(line_on_fd[fd] + i + 1); // on garde le debut de la ligne suivante
		free(line_on_fd[fd]); // on free line_of_fd
		line_on_fd[fd] = tmp; // on stock le debut de la ligne suivante de line_of_fd
		if (line_on_fd[fd][0] == '\0')
		{
			free(line_on_fd[fd]);
			line_on_fd[fd] = NULL;
		}
	}
	else if (line_on_fd[fd][i] == '\0')
	{
		if (rlen == BUFFER_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(line_on_fd[fd]);
		free(line_on_fd[fd]);
		line_on_fd[fd] = NULL;
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*line_on_fd[MAX_FD];
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	int			rlen;

	if (fd < 0 || !line)
		return (-1);
	while ((rlen = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rlen] = 0;
		if (!line_on_fd[fd])
		{
			line_on_fd[fd] = malloc(1);
			*line_on_fd[fd] = '\0';
		}
		tmp = ft_strjoin(line_on_fd[fd], buffer);
		free(line_on_fd[fd]);
		line_on_fd[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (rlen == -1)
		return (-1);
	else if (!rlen && (!line_on_fd[fd] || line_on_fd[fd][0] == '\0'))
		return (0);
	return (split_line(line_on_fd, line, fd, rlen));
}

int				main(int ac, char **av)
{
	char		*line;
	int 		fd1;
	int			fd2;
	int			fd3;

	(void)ac;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);

	if (get_next_line(fd1, &line) > 0)
		printf("%s\n", line);
	if (get_next_line(fd3, &line) > 0)
		printf("%s\n", line);
	if (get_next_line(fd2, &line) > 0)
		printf("%s\n", line);
	if (get_next_line(fd1, &line) > 0)
		printf("%s\n", line);
	if (get_next_line(fd3, &line) > 0)
		printf("%s\n", line);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
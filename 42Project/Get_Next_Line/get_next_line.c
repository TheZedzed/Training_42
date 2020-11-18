#include "get_next_line.h"

int				split_line(char **line_on_fd, char **line, int fd)
{
	char		*save;
	int			i;

	i = 0;
	while (line_on_fd[fd][i] && line_on_fd[fd][i] != '\n')
		i++;
	if (line_on_fd[fd][i] == '\n') // si y'a une ligne
	{
		*line = ft_strlendup(line_on_fd[fd], i); // on retourne la premiere ligne lue dans line
		save = ft_strdup(line_on_fd[fd] + i + 1); // on garde le debut de la ligne suivante
		free(line_on_fd[fd]); // on free string de line_of_fd
		line_on_fd[fd] = save; // on stock le debut de la ligne suivante dans line_of_fd
		if (line_on_fd[fd][0] == 0) // si ctrl+d --> "0\n"
		{
			free(line_on_fd[fd]);
			line_on_fd[fd] = NULL;
		}
	}
	else if (line_on_fd[fd][i] == '\0') // si derniere ligne
	{
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
	char		*save;
	int			rlen;

	if (fd < 0 || !line)
		return (-1);
	while ((rlen = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rlen] = 0; //pour pouvoir travailler sur un string fermé
		save = ft_join(line_on_fd[fd], buffer); // tmp : realloc du string de line_of_fd + string buffer
		free(line_on_fd[fd]); // on supprime le mi-string de line_of_fd
		line_on_fd[fd] = save; // string realloué dans line_of_fd
		if (ft_strchr(buffer, '\n')) // si une ligne a été lue on sort
			break ;
	}
	if (rlen == -1)
		return (-1);
	else if (!rlen && !line_on_fd[fd]) // si fin du fichier et derniere ligne déja affichée
		return (0);
	return (split_line(line_on_fd, line, fd)); // on split la ligne lue
}

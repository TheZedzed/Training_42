#include "get_next_line.h"

int				main(int ac, char **av)
{
	char		*line;
	int 		fd1;
	int			fd2;
	int			fd3;

	if (ac == 1)
	{
		while (get_next_line(0, &line) > 0)
		{
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
			free(line);
		}
		return (0);
	}
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);

	while (get_next_line(fd1, &line) > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	if (get_next_line(fd3, &line) > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	if (get_next_line(fd2, &line) > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	if (get_next_line(fd3, &line) > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	if (get_next_line(fd1, &line) > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 1 //dynamique
# define MAX_FD 256 //ulimite -n

int		split_line(char **line_on_fd, char **line, int fd);
int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
char	*ft_strlendup(char *str, int len);
char	*ft_strchr(char *s, unsigned char c);
char	*ft_strdup(char *str);
char	*ft_join(char *s1, char *s2);

#endif
#include "libft.h"
#include <stdlib.h>

int	empty_test(void)
{
	if (atoi("") == ft_atoi(""))
		return (0);
	return (-1);
}

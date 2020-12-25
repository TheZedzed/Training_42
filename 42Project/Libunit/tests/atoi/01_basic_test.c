#include "libft.h"
#include <stdlib.h>

int	basic_test(void)
{
	if (atoi("    12") == ft_atoi("    12"))
		return (0);
	return (-1);
}
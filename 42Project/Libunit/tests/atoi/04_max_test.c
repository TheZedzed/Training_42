#include "libft.h"
#include <stdlib.h>

int	max_test(void)
{
	if (atoi("2147483647") == ft_atoi("2147483647"))
		return (0);
	return (-1);
}

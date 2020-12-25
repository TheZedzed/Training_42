#include "libft.h"
#include <stdlib.h>

int	null_test(void)
{
	if (atoi(NULL) == ft_atoi(NULL))
		return (0);
	return (-1);
}

#include "libft.h"
#include <stdlib.h>

int	min_test(void)
{
	if (atoi("-2147483648") == ft_atoi("-2147483648"))
		return (0);
	return (-1);
}

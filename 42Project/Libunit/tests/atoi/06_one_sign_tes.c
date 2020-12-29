#include "libft.h"
#include <stdlib.h>

int	one_sign_test(void)
{
	if (atoi("-214") == ft_atoi("-214"))
		return (0);
	return (-1);
}

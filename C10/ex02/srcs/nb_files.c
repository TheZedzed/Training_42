/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:59:35 by alex              #+#    #+#             */
/*   Updated: 2020/07/14 23:59:46 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

/*
** Checks the number of filename
*/
int	nb_file(char **argv)
{
	int	count;

	count = 0;
	++argv;
	while (*argv)
	{
		if (!ft_strncmp(*argv, "-c", 2))
		{
			if (ft_strlen(*argv) > 2)
				argv++;
			else
				argv += 2;
		}
		else
		{
			argv++;
			count++;
		}
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 00:01:49 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 15:55:28 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

/*
** Sets a new array of pointer which contains:
** --- as first pointer: allocated memory --> itoa(number of files)
** --- then: pointer to these files
*/

char	**set_command(char **argv, int(*f)(char **), char*(*g)(int))
{
	int	count;
	char	**cur;
	char	**tab;

	count = (*f)(argv);
	if (!(tab = (char **) malloc(sizeof(*tab) * (count + 2))))
		return (NULL);
	cur = tab;
	if (!(tab[0] = (*g)(count)))
		return (NULL);
	++argv;
	++cur;
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
			*cur++ = *argv++;
	}
	*cur = 0;
	return (tab);
}

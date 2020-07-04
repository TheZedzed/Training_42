/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_stdout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:20:14 by alex              #+#    #+#             */
/*   Updated: 2020/07/04 18:20:35 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_cat_stdout(int file)
{
	char	buffer[29696];
	int	bytes;

	while ((bytes = read(file, &buffer, 29695)))
	{
		write(1, &buffer, bytes);
	}
	close(file);
}

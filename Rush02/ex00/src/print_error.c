/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:20:21 by msahli            #+#    #+#             */
/*   Updated: 2020/10/25 17:25:03 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/main.h"

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	print_dict_err(void)
{
	write(1, "Dict Error\n", 11);
	return (0);
}

int	print_alloc_err(void)
{
	write(1, "Fail to allocate\n", 17);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_chk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:13:47 by msahli            #+#    #+#             */
/*   Updated: 2020/10/25 17:25:03 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include "../include/exception_chk.h"
#include "../include/ft_func.h"

char		*exception_chk(int argc, char *argv[])
{
	char	*dict_name;

	dict_name = NULL;
	if (argc != 2 && argc != 3)
		return (0);
	if (!is_number(argv[argc - 1]))
		return (0);
	if (str_cmp(argv[argc - 1], "") == 0)
		return (0);
	if (argc == 2)
		dict_name = "numbers.dict.txt";
	else
		dict_name = argv[1];
	return (dict_name);
}

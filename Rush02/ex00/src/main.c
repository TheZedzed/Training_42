/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:13:54 by msahli            #+#    #+#             */
/*   Updated: 2020/10/25 17:56:44 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include "../include/exception_chk.h"
#include "../include/read_dict.h"
#include "../include/split_dict.h"
#include "../include/print_error.h"
#include "../include/split_num.h"
#include "../include/invert_to_word.h"
#include "../include/ft_free.h"

int			main(int argc, char *argv[])
{
	char	*dict_name;

	dict_name = exception_chk(argc, argv);
	if (dict_name == 0)
		return (print_error());
	if (split_num(argc, argv))
		return (print_alloc_err());
	if (read_dict(dict_name))
		return (print_dict_err());
	invert_to_word();
	ft_free();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_to_word_sub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:44:15 by msahli            #+#    #+#             */
/*   Updated: 2020/10/25 17:04:15 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include "../include/ft_func.h"

void	print_word(void)
{
	g_result[str_len(g_result)] = '\n';
	write(1, g_result, str_len(g_result));
	free(g_result);
}

int		zero_row(int index)
{
	if (g_num[index][0] == '0' && g_num[index][1] == '0')
	{
		if (g_num[index][2] == '0')
		{
			return (1);
		}
	}
	return (0);
}

int		match_word(char *cmp_str)
{
	int i;

	i = 0;
	while (i < g_max_dict)
	{
		if (str_cmp(g_dict[i].key, cmp_str) == 0)
		{
			str_cat(g_result, g_dict[i].value);
			return (1);
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:14:00 by msahli            #+#    #+#             */
/*   Updated: 2020/10/25 17:25:03 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int			split_line(int index, char *str)
{
	int		i;

	i = 0;
	while (*str >= '0' && *str <= '9')
		g_dict[index].key[i++] = *(str++);
	g_dict[index].key[i] = '\0';
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*(str++) != ':')
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	i = 0;
	while (*str >= 32 && *str <= 126)
		g_dict[index].value[i++] = *(str++);
	g_dict[index].value[i] = '\0';
	if (*str != '\0')
		return (0);
	return (1);
}

int			split_dict(char *buf)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (*buf)
	{
		if (*buf == '\n')
		{
			g_dict[row].str[col] = '\0';
			if (split_line(row, g_dict[row].str) == 0)
				return (0);
			row++;
			col = 0;
		}
		else
			g_dict[row].str[col++] = *buf;
		buf++;
	}
	if (col != 0)
		g_dict[row].str[col] = '\0';
	return (1);
}

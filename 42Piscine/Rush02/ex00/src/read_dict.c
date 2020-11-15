/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:13:58 by msahli            #+#    #+#             */
/*   Updated: 2020/10/25 17:25:03 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include "../include/split_dict.h"

int		open_dict(char *dict_name, char *buf)
{
	int		fd;

	fd = open(dict_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	read(fd, buf, BUF_SIZE);
	return (fd);
}

int		allocate_dict(int max_row)
{
	int		i;

	i = 0;
	g_dict = malloc(sizeof(t_dict) * max_row + 1);
	if (g_dict == NULL)
		return (1);
	while (i < (max_row + 1))
	{
		g_dict[i].str = (char *)malloc(sizeof(char) * g_size);
		g_dict[i].key = (char *)malloc(sizeof(char) * g_size);
		g_dict[i].value = (char *)malloc(sizeof(char) * g_size);
		if (g_dict[i].str == NULL || g_dict[i].key == NULL ||\
				g_dict[i].value == NULL)
			return (1);
		i++;
	}
	g_max_dict = max_row;
	return (0);
}

int		read_dict(char *dict_name)
{
	int		fd;
	int		max_row;
	int		i;
	char	buf[BUF_SIZE];

	fd = open_dict(dict_name, buf);
	g_size = 0;
	i = 0;
	max_row = 0;
	if (fd == -1)
		return (1);
	while (*(buf + g_size))
		g_size++;
	close(fd);
	while (*(buf + i))
	{
		if (*(buf + i) == '\n')
			max_row++;
		i++;
	}
	if (allocate_dict(max_row))
		return (1);
	if (split_dict(buf) == 0)
		return (1);
	return (0);
}

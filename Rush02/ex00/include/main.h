/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:14:12 by msahli            #+#    #+#             */
/*   Updated: 2020/10/25 18:08:27 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_Hno

# define BUF_SIZE 2048

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_dict
{
	char		*str;
	char		*key;
	char		*value;
}				t_dict;

t_dict			*g_dict;
char			**g_num;
char			*g_result;
int				g_size;
int				g_max_num;
int				g_max_dict;

#endif

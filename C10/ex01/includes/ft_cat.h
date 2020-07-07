/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:18:06 by alex              #+#    #+#             */
/*   Updated: 2020/07/07 13:48:22 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
#define FT_CAT_H

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <stdio.h>

void	ft_putstr(char *str);
void	ft_cat_stdin(void);
void	ft_cat_stdout(int file);
int	ft_strcmp(const char *s1, const char *s2);

#endif

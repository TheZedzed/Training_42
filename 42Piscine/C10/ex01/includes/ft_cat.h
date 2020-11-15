/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 16:26:44 by alex              #+#    #+#             */
/*   Updated: 2020/07/11 16:30:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_CAT_H
#define	FT_CAT_H

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>

void	ft_puterror(const char *file, int error);
void	ft_putstr(const char *s);
int	ft_strcmp(const char *s1, const char *s2);
int	cat_stream(int fd);
#endif

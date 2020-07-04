/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:18:06 by alex              #+#    #+#             */
/*   Updated: 2020/07/01 22:19:06 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
#define FT_CAT_H

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_cat(const char *filename);

#endif

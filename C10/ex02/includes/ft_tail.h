/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:11:12 by alex              #+#    #+#             */
/*   Updated: 2020/07/04 22:25:48 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_TAIL_H
#define	FT_TAIL_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <libgen.h>

void	ft_tail_stdin(void);
void	ft_putstr(char *str);
void	ft_tail_stdout(int file);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:11:12 by alex              #+#    #+#             */
/*   Updated: 2020/07/05 17:52:45 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_TAIL_H
#define	FT_TAIL_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <libgen.h>

int	ft_isdigit(int c);
int	ft_isspace(int c);
int	ft_isoperator(int c);
int	ft_atoi(const char *str);
int	ft_str_isdigit(const char *str);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_error_arg(int argc, char **argv);
void	ft_putstr(char *str);
void	ft_tail_stdin(void);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif

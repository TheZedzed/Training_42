/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:11:12 by alex              #+#    #+#             */
/*   Updated: 2020/07/15 15:55:07 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_TAIL_H
#define	FT_TAIL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int	ft_strlen(char *s);
int	tail_stream(int fd, int num);
int	nb_file(char **argv);
int	check_num(char *str);
int	check_option(int ac, char **av);
int	ft_strncmp(char *s1, char *s2, size_t n);
void	ft_putstr(char *s);
void	opt_error(char *argv);
void	head_arg(char *filename, int index, char *argc);
void	put_error(char *filename, int error);
char	*simple_itoa(int nb);
char	**set_command(char **argv, int(*f)(char **), char *(*g)(int));
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:47:24 by alex              #+#    #+#             */
/*   Updated: 2020/06/15 23:47:42 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LIB_H
#define	FT_LIB_H

#include <unistd.h>
#include <stdlib.h>

/*
** String func
*/

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strncat(char *dest, char *src, unsigned int n);
int		ft_strlen(char *str);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strcat(char *dest, char *src);
char		*ft_strstr(char *str, char *to_find);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);

/*
** Sort func
*/

int		ft_partition(int *tab, int begin, int end);
void		ft_swap(int *a, int *b);
void		ft_quicksort(int *tab, int low, int high);
void		ft_sort_params(int ac, char **av);

/*
** Bool func
*/

int		ft_isope(char c);
int		ft_islow(char c);
int		ft_isup(char c);
int		ft_isalpha(char c);
int		ft_isnum(char c);
int		ft_isspace(char c);
int		ft_issep(char c, char *charset);
int		ft_str_is_printable(char *str);
int		ft_is_inbase(char c, char *base);
int		ft_is_wrong_base(char *base);

/*
** Convert func
*/

int		ft_atoi(char *str);
int		ft_atoi_base(char *str, char *base);
int		ft_nbrlen(int nb, char *base);
void		ft_nb_to_base(int nb, int end_index, char *nbr, char *base);
char		*ft_convert_base(char *nbr, char *base_from, char *base_to);

/*
** Maths func
*/

int		ft_factorial(int nb);
int		ft_power(int nb, int power);
int		ft_sqrt(int nb);
int		ft_is_prime(int nb);
int		ft_find_next_prime(int nb);

/*
** Mem func
*/

char		*ft_strdup(const char *str);

#endif

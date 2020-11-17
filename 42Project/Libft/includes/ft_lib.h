/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 00:02:12 by alex              #+#    #+#             */
/*   Updated: 2020/07/08 17:14:18 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
#define FT_LIB_H

#include <unistd.h>
#include <stdlib.h>

#define	ABS(n)	(n < 0 ? -n : n)

int	ft_isblank(int c);
int	ft_iscntrl(int c);
int	ft_isalpha(int c);
int	ft_isalnum(int c);
int	ft_isgraph(int c);
int	ft_islower(int c);
int	ft_isupper(int c);
int	ft_isspace(int c);
int	ft_isxdigit(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_isdigit(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);
int	ft_atoi(const char *str);
int	ft_str_is_alpha(const char *s);
int	ft_str_is_numeric(const char *s);
int	ft_str_is_lowercase(const char *s);
int	ft_str_is_printable(const  char *s);
int	ft_str_is_uppercase(const char *s);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_strcasecmp(const char *s1, const char *s2);
int	ft_strequ(const char *s1, const char *s2);
int	ft_strnequ(const char *s1, const char *s2, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
int	ft_strncmp(char *s1, char *s2, size_t n);

void	ft_putchar(char c);
void	ft_putstr(const char *s);
void	ft_reverse(char *s, size_t len);
void	ft_memdel(void	**ptr);
void	ft_putendl(const char *s);
void	ft_putnbr(int n);
void	ft_strclr(char *s);
void	ft_strdel(char **ptr);
void	ft_bzero(void *s, size_t n);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_itoa_base(int nb, int base);
char	*ft_strcapitalize(char *s);
char	*ft_str_lowcase(char *s);
char	*ft_strcasestr(const char *haystack, const char *needle);
char	*ft_strnew(size_t size);
char	*ft_strlowcase(char *s);
char	*ft_strupcase(char *s);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strmap(const char *s, char (*f)(char));

void	*ft_memalloc(size_t size);
void	*ft_memset(void *ptr, int c, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

size_t	ft_strlen(const char *s);
size_t	ft_strnlen(const char *s, size_t maxlen);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlcat(char *dest, char *src, size_t size)

typedef enum	e_bool
{
	FALSE = 0,
	TRUE = !FALSE
}		t_bool;

#endif

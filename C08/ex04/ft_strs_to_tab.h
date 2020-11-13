/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 03:57:29 by alex              #+#    #+#             */
/*   Updated: 2020/05/21 04:00:20 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRS_TO_TAB_H
# define FT_STRS_TO_TAB_H
typedef struct		s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}					t_stock_str;
int					ft_strlen(char *str);
char				*ft_strdup(char *str);
char				*ft_strcpy(char *dest, char *src);
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

#endif

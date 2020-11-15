/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 13:38:03 by alex              #+#    #+#             */
/*   Updated: 2020/03/27 03:05:58 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strlowcase(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		if (*ptr >= 65 && *ptr <= 90)
			*ptr += 32;
		ptr++;
	}
	return (str);
}

int	is_alpha(char c)
{
	return ((c >= 97 && c <= 122) || (c >= 65 && c <= 90));
}

int	is_num(char c)
{
	return (c >= 48 && c <= 57);
}

char		*ft_strcapitalize(char *str)
{
	char	*ptr;

	ptr = str;
	ft_strlowcase(str);
	while (*ptr)
	{
		if (is_alpha(*ptr) && !(is_num(*(ptr - 1)) || is_alpha(*(ptr - 1))))
			*ptr -= 32;
		ptr++;
	}
	return (str);
}

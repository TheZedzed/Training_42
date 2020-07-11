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

char	*ft_strlowcase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')); 
}

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[++i])
	{
		while (!is_alpha(str[i]))
			i++;
		if (!(is_num(str[i - 1]) || is_alpha(str[i - 1])))
			str[i] -= 32;
	}
	return (str);
}

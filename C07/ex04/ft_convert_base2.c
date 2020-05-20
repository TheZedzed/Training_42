/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 16:55:56 by alex              #+#    #+#             */
/*   Updated: 2020/05/16 16:56:02 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	is_operator(char c)
{
	return (c == 43 || c == 45);
}

int	ft_strlen(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

int	is_inbase(char c, char *base_from)
{
	int	index;

	index = 0;
	while (base_from[index] && c != base_from[index])
		index++;
	if (base_from[index] == '\0')
		return (-1);
	else
		return (index);
}

int	invalid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (1);
	while (base[i] && !is_operator(base[i]) && !is_space(base[i]))
	{
		j = i + 1;
		while (base[j] && base[j] != base[i])
			j++;
		if (base[j] != '\0')
			return (1);
		i++;
	}
	if (base[i] == '\0')
		return (0);
	return (1);
}

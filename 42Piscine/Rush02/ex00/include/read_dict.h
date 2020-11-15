/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:14:09 by msahli            #+#    #+#             */
/*   Updated: 2020/10/25 17:25:03 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef read_dict_H
# define READ_DICT_H

int		open_dict(char *dict_name, char *buf);
int		allocate_dict(int max_row);
int		read_dict(char *dict_name);

#endif

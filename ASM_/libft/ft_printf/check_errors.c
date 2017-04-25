/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:18:27 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 16:19:13 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_errors(const char *s, int *i, int num_check)
{
	if (num_check == 1)
		if (!(ft_is_flag(s[*i + 1])) && !(ft_is_type(s[*i + 1])) &&
			!(ft_is_length(s[*i + 1])) && !(ft_isdigit(s[*i + 1])) &&
			s[*i + 1] != '.' && s[*i + 1] != '*')
			return (-1);
	if (num_check == 2)
		if (!(ft_is_type(s[*i])) && !(ft_is_length(s[*i])) &&
			!(ft_isdigit(s[*i])) && s[*i] != '*' && s[*i] != '.')
			return (-1);
	if (num_check == 3)
		if (!(ft_is_type(s[*i])) && !(ft_is_length(s[*i])) &&
			!(ft_isdigit(s[*i])) && s[*i] != '.')
			return (-1);
	if (num_check == 4)
		if (!ft_is_type(s[*i]) && !ft_is_length(s[*i]))
			return (-1);
	if (num_check == 5)
		if (!ft_is_type(s[*i]))
			return (-1);
	return (0);
}

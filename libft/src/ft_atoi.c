/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:02:35 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 15:29:49 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int negative;
	int output;

	output = 0;
	negative = 0;
	while (*str == '\t' || *str == '\v' || *str == '\r' || *str == '\f' ||
			*str == '\n' || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		negative = 1;
		str++;
	}
	while (*str > 47 && *str < 58 && *str)
	{
		output = output * 10 + (*str - '0');
		str++;
	}
	if (negative)
		output = -output;
	return (output);
}

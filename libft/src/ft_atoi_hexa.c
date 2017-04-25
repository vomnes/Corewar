/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:47:04 by atrudel           #+#    #+#             */
/*   Updated: 2016/12/10 15:15:26 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		conversion(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else
		return (-1);
}

int		ft_atoi_hexa(const char *str)
{
	int output;

	output = 0;
	str = ft_strstr(str, "0x");
	if (str)
	{
		str += 2;
		while (conversion(*str) != -1)
		{
			output = output * 16 + conversion(*str);
			str++;
		}
	}
	return (output);
}

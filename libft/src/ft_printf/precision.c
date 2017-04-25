/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:47:02 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 11:59:05 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*handle_precision_numeric(t_conversion *conversion, char *output)
{
	int		i;
	int		negative;

	if (output && *output == '-')
	{
		output = ft_strchop_before(output, 1);
		negative = 1;
	}
	else
		negative = 0;
	if (output)
	{
		i = ft_strlen(output);
		if (i == 1 && *output == '0' && conversion->period &&
			conversion->precision == 0)
			output = ft_strchop_before(output, 1);
	}
	while (output && i < conversion->precision)
	{
		output = ft_strappend_char_before(output, '0');
		i++;
	}
	if (output && negative)
		output = ft_strappend_char_before(output, '-');
	return (output);
}

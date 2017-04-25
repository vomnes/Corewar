/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:47:10 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 14:24:27 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*handle_sharp_o(t_conversion *conversion, char *output)
{
	if (output && conversion->flag_sharp && *output != '0')
		output = ft_strappend_char_before(output, '0');
	return (output);
}

char	*handle_sharp_x(t_conversion *conversion, char *output)
{
	if (output && conversion->flag_sharp)
	{
		output = ft_strappend_char_before(output, conversion->specifier);
		if (output)
			output = ft_strappend_char_before(output, '0');
	}
	return (output);
}

char	*handle_sharp_b(t_conversion *conversion, char *output)
{
	char	*new_output;
	int		i;
	int		j;

	if (output && conversion->flag_sharp)
	{
		new_output = ft_strnew(0);
		i = ft_strlen(output) - 1;
		j = 0;
		while (new_output && i >= 0)
		{
			new_output = ft_strappend_char_before(new_output, output[i]);
			j++;
			if (j % 8 == 0 && i != 0)
				new_output = ft_strappend_char_before(new_output, ' ');
			i--;
		}
		while (new_output && j++ % 8 != 0)
			new_output = ft_strappend_char_before(new_output, '0');
		ft_strdel(&output);
		return (new_output);
	}
	return (output);
}

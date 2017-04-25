/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:45:15 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 11:36:36 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_stringl	*convert_percent(t_conversion *conversion, va_list args)
{
	char	*output;

	(void)args;
	if ((output = ft_strnew(1)))
		*output = '%';
	output = handle_zero(conversion, output);
	output = handle_width(conversion, output);
	return (str_to_stringl(output));
}

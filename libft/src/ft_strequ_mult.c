/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:07:34 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/03 20:07:59 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_strequ_mult(const char *s1, int nb, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	if (nb < 1)
		return (-1);
	va_start(args, nb);
	while (nb > 0)
	{
		if (ft_strequ(s1, va_arg(args, const char *)))
		{
			ret = 1;
			break ;
		}
		nb--;
	}
	va_end(args);
	return (ret);
}

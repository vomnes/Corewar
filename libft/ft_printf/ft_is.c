/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:07:37 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 15:08:16 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_type(int c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%' ||
			c == 'b' || c == 'k' || c == 'Z');
}

int		ft_is_type_less_pct(int c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C');
}

int		ft_is_flag(int c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
}

int		ft_is_signed(int c)
{
	return (c == 'D' || c == 'd' || c == 'i');
}

int		ft_is_length(int c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z');
}

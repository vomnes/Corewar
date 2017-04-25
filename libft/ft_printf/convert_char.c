/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:34:26 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 15:11:19 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(int value, int *k, t_args *elem)
{
	int		i;
	char	space;

	i = 0;
	space = (elem[*k].pre_zero == 0) ? ' ' : '0';
	if (elem[*k].ok_precision == 1)
		elem[*k].ok_precision = 0;
	if (elem[*k].end_space == 0 && elem[*k].ok_width == 1)
		while (i++ < elem[*k].width - 1)
			ft_putchar_len(space, &elem[*k].arg_len);
	ft_putchar(value);
	elem[*k].arg_len++;
	i = 0;
	if (elem[*k].end_space == 1 && elem[*k].ok_width == 1)
		while (i++ < elem[*k].width - 1)
			ft_putchar_len(' ', &elem[*k].arg_len);
	return (elem[*k].arg_len);
}

int		ft_print_wchar(wchar_t value, int *k, t_args *elem)
{
	int		i;
	char	space;

	i = 0;
	space = (elem[*k].pre_zero == 0) ? ' ' : '0';
	if ((int)value < 0 || (((int)value > 0xD7FF && (int)value < 0xE000))
		|| ((int)value > 0x10FFFF))
		return (-1);
	if (elem[*k].ok_precision == 1)
		elem[*k].ok_precision = 0;
	if (elem[*k].end_space == 0 && elem[*k].ok_width == 1)
		while (i++ < elem[*k].width - (int)ft_sizewchar(value))
			ft_putchar_len(space, &elem[*k].arg_len);
	if (value == 0)
		ft_putchar_len(0, &elem[*k].arg_len);
	else
	{
		ft_putwchar_all(value);
		elem[*k].arg_len += (int)ft_sizewchar(value);
	}
	i = 0;
	if (elem[*k].end_space == 1 && elem[*k].ok_width == 1)
		while (i++ < elem[*k].width - (int)ft_sizewchar(value))
			ft_putchar_len(' ', &elem[*k].arg_len);
	return (elem[*k].arg_len);
}

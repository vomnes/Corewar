/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:36:09 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 15:55:58 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_hex_basic_one(const char *value, t_args *elem, int *k)
{
	int i;

	i = 0;
	if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1 &&
		elem[*k].end_space == 0 && elem[*k].pre_zero == 0)
	{
		if (elem[*k].pre_hash == 0 || value[0] == '0')
			while (i++ < elem[*k].width - elem[*k].size)
				ft_putchar_len(' ', &elem[*k].arg_len);
		else
			while (i++ < elem[*k].width - ((int)ft_strlen(value) + 2))
				ft_putchar_len(' ', &elem[*k].arg_len);
	}
	if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 0 &&
		elem[*k].pre_zero == 0 && elem[*k].pre_hash == 0)
		while (i++ < elem[*k].precision - elem[*k].size)
			ft_putchar_len('0', &elem[*k].arg_len);
}

static void	ft_hex_basic_two_bis(const char *value, t_args *elem, int *k)
{
	int i;

	i = 0;
	if (elem[*k].width <= elem[*k].precision)
		while (i++ < elem[*k].precision - (int)ft_strlen(value))
			ft_putchar_len('0', &elem[*k].arg_len);
	else if (elem[*k].precision <= (int)ft_strlen(value) && !elem[*k].end_space)
		while (i++ < elem[*k].width - elem[*k].precision -
		((int)ft_strlen(value) - elem[*k].precision))
			ft_putchar_len(' ', &elem[*k].arg_len);
	else
	{
		if (elem[*k].end_space == 0)
			while (i++ < elem[*k].width - elem[*k].precision)
				ft_putchar_len(' ', &elem[*k].arg_len);
		i = 0;
		while (i++ < elem[*k].precision - (int)ft_strlen(value))
			ft_putchar_len('0', &elem[*k].arg_len);
	}
}

void		ft_hex_basic_two(const char *value, t_args *elem, int *k)
{
	int i;

	i = 0;
	if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 &&
		elem[*k].pre_zero == 0 && elem[*k].pre_hash == 0)
		ft_hex_basic_two_bis(value, elem, k);
	else if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 &&
		elem[*k].pre_zero == 1)
	{
		if (elem[*k].precision <= (int)ft_strlen(value))
			while (i++ < elem[*k].width - (int)ft_strlen(value) -
			((elem[*k].pre_hash == 1 && value[0] != '0') ? 2 : 0))
				ft_putchar_len(' ', &elem[*k].arg_len);
		else
			while (i++ < elem[*k].width - elem[*k].precision -
			((elem[*k].pre_hash == 1 && value[0] != '0') ? 2 : 0))
				ft_putchar_len(' ', &elem[*k].arg_len);
	}
	if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 &&
	elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1 && elem[*k].end_space == 1)
		if ((elem[*k].precision < elem[*k].width) && (elem[*k].precision > 1)
			&& value[0] == '0')
			ft_putchar_len('0', &elem[*k].arg_len);
}

void		ft_hex_hash(const char *value, t_args *elem, int *k)
{
	int i;

	i = 0;
	if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 &&
	elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1 && elem[*k].end_space == 0)
	{
		if (elem[*k].precision < (int)ft_strlen(value))
			while (i++ < elem[*k].width - (int)ft_strlen(value) -
			((value[0] != '0') ? 2 : 0))
				ft_putchar_len(' ', &elem[*k].arg_len);
		else
		{
			while (i++ < elem[*k].width - elem[*k].precision -
			((value[0] != '0') ? 2 : 1))
				ft_putchar_len(' ', &elem[*k].arg_len);
			if (elem[*k].width >= elem[*k].precision && value[0] == '0')
				ft_putchar_len(' ', &elem[*k].arg_len);
			if (value[0] == '0')
				ft_putchar_len('0', &elem[*k].arg_len);
		}
	}
}

void		ft_hex_zero_one(const char *value, t_args *elem, int *k)
{
	int i;

	i = 0;
	if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 0 &&
		elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1)
		while (i++ < elem[*k].precision - (int)ft_strlen(value))
			ft_putchar_len('0', &elem[*k].arg_len);
	if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1 &&
		elem[*k].pre_zero == 0 && elem[*k].pre_hash == 1)
	{
		if (elem[*k].width <= elem[*k].precision)
			while (i++ < elem[*k].precision - elem[*k].size -
			(int)ft_strlen(value) +
			(elem[*k].end_space == 1 && value[0] == '0' ? 1 : 0))
				ft_putchar_len('0', &elem[*k].arg_len);
		else
		{
			while (i++ < elem[*k].precision - (int)ft_strlen(value) -
			(value[0] == '0' ? 1 : 0))
				ft_putchar_len('0', &elem[*k].arg_len);
		}
	}
}

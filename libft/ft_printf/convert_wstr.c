/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:35:39 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 16:54:00 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wstr_pre_bis(const wchar_t *val, int *len, int *k, t_args *elem)
{
	int		i;
	char	space;

	i = 0;
	space = (elem[*k].pre_zero == 0) ? ' ' : '0';
	if (val != NULL && elem[*k].precision < (int)ft_sizewchar(val[0]))
		while (i++ < elem[*k].width - elem[*k].precision + elem[*k].precision)
			ft_putchar_len(space, &elem[*k].arg_len);
	else if (elem[*k].precision <= *len)
		while (i++ < elem[*k].width - elem[*k].precision +
		(*len - elem[*k].precision))
			ft_putchar_len(space, &elem[*k].arg_len);
	else
		while (i++ < elem[*k].width - *len)
			ft_putchar_len(space, &elem[*k].arg_len);
}

static void	ft_wstr_pre(const wchar_t *value, int *len, int *k, t_args *elem)
{
	int		i;
	char	space;

	i = 0;
	space = (elem[*k].pre_zero == 0) ? ' ' : '0';
	if (elem[*k].end_space == 0)
	{
		if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
			ft_wstr_pre_bis(value, len, k, elem);
		else if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
			while (i++ < elem[*k].width - *len)
				ft_putchar_len(space, &elem[*k].arg_len);
	}
}

static void	ft_wstr_end_space(int *len, int *k, t_args *elem)
{
	int i;

	i = 0;
	if (elem[*k].end_space == 1)
	{
		if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
		{
			if (elem[*k].precision < *len)
				while (i++ < elem[*k].width - elem[*k].precision)
					ft_putchar_len(' ', &elem[*k].arg_len);
			else
				while (i++ < elem[*k].width - *len)
					ft_putchar_len(' ', &elem[*k].arg_len);
		}
		else if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
			while (i++ < elem[*k].width - *len)
				ft_putchar_len(' ', &elem[*k].arg_len);
	}
}

static void	ft_wstr_print(const wchar_t *value, int *len, int *k, t_args *elem)
{
	if (value != NULL)
	{
		if (elem[*k].ok_precision == 1)
			ft_putwstr_size(value, elem[*k].precision);
		else
			ft_putwstr(value);
		elem[*k].arg_len += *len;
	}
	else
	{
		if (elem[*k].ok_precision == 1)
		{
			write(1, "(null)", *len);
			elem[*k].arg_len += elem[*k].precision;
		}
		else
		{
			ft_putstr("(null)");
			elem[*k].arg_len += 6;
		}
	}
}

int			ft_print_wstr(const wchar_t *value, int *k, t_args *elem)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (value == NULL)
	{
		if (elem[*k].ok_precision == 1 && elem[*k].precision < 6)
			len = elem[*k].precision;
		else
			len = 6;
	}
	else
	{
		while (value[i] != L'\0')
			len += (int)ft_sizewchar(value[i++]);
		if (elem[*k].ok_precision == 1 && elem[*k].precision < len)
			len = (int)ft_wstrnlen(value, elem[*k].precision);
	}
	ft_wstr_pre(value, &len, k, elem);
	ft_wstr_print(value, &len, k, elem);
	ft_wstr_end_space(&len, k, elem);
	return (elem[*k].arg_len);
}

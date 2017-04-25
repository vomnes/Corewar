/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:35:12 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 15:38:11 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_string_pre(int *len, int *k, t_args *elem)
{
	int		i;
	char	space;

	i = 0;
	space = (elem[*k].pre_zero == 0) ? ' ' : '0';
	if (elem[*k].end_space == 0)
	{
		if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
		{
			if (elem[*k].precision < *len)
				while (i++ < elem[*k].width - elem[*k].precision)
					ft_putchar_len(space, &elem[*k].arg_len);
			else
				while (i++ < elem[*k].width - *len)
					ft_putchar_len(space, &elem[*k].arg_len);
		}
		else if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
			while (i++ < elem[*k].width - *len)
				ft_putchar_len(space, &elem[*k].arg_len);
	}
}

static void	ft_string_end_space(int *len, int *k, t_args *elem)
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

static int	ft_write_len(char *value, int *k, t_args *elem, int len)
{
	if (elem[*k].ok_precision == 1 && elem[*k].precision < len)
	{
		write(1, value, elem[*k].precision);
		return (elem[*k].precision);
	}
	else
	{
		ft_putstr(value);
		return (len);
	}
}

int			ft_print_string(char *value, int *k, t_args *elem)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (value == NULL)
		len = 6;
	else
		len = (int)ft_strlen(value);
	ft_string_pre(&len, k, elem);
	if (value != NULL)
		elem[*k].arg_len += ft_write_len(value, k, elem, (int)ft_strlen(value));
	else
		elem[*k].arg_len += ft_write_len("(null)", k, elem, 6);
	ft_string_end_space(&len, k, elem);
	return (elem[*k].arg_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_date.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:14:57 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 15:15:21 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_date_one(int *date, int *v, t_args *elem)
{
	if (elem[*v].pre_hash && !elem[*v].pre_sign && !elem[*v].pre_blank &&
	!elem[*v].end_space)
		ft_put_h(date, '#', elem, v);
	else if (elem[*v].pre_hash && elem[*v].pre_sign && !elem[*v].pre_blank &&
	!elem[*v].end_space)
	{
		ft_put_h(date, '#', elem, v);
		ft_put_h(date, '+', elem, v);
	}
	else if (!elem[*v].pre_hash && !elem[*v].pre_sign && !elem[*v].pre_blank &&
	elem[*v].end_space)
		ft_put_d(date, '-', elem, v);
}

void	ft_date_two(int *date, int *v, t_args *elem)
{
	if (!elem[*v].pre_hash && !elem[*v].pre_sign && elem[*v].pre_blank &&
		elem[*v].end_space)
	{
		ft_put_d(date, '-', elem, v);
		ft_putchar_len(' ', &elem[*v].arg_len);
		ft_put_d(date, ' ', elem, v);
	}
	else if (!elem[*v].pre_hash && !elem[*v].pre_sign && elem[*v].pre_blank &&
			!elem[*v].end_space)
	{
		ft_put_d(date, ' ', elem, v);
		ft_putchar_len(' ', &elem[*v].arg_len);
		ft_put_d(date, '-', elem, v);
	}
	else if (elem[*v].pre_hash && !elem[*v].pre_sign && elem[*v].pre_blank &&
			elem[*v].end_space)
	{
		ft_put_d(date, ' ', elem, v);
		ft_putchar_len(' ', &elem[*v].arg_len);
		ft_put_d(date, '-', elem, v);
		ft_putchar_len(' ', &elem[*v].arg_len);
		ft_put_h(date, '#', elem, v);
	}
}

void	ft_print_date(int *date, int *v, t_args *elem)
{
	ft_date_one(date, v, elem);
	ft_date_two(date, v, elem);
	if (!elem[*v].pre_hash && !elem[*v].pre_sign && !elem[*v].pre_blank &&
		!elem[*v].end_space)
	{
		ft_put_d(date, ' ', elem, v);
		ft_putchar_len(' ', &elem[*v].arg_len);
		ft_put_d(date, '-', elem, v);
		ft_putchar_len(' ', &elem[*v].arg_len);
		ft_put_h(date, '#', elem, v);
		ft_put_h(date, '+', elem, v);
	}
}

int		ft_put_date(const char *format, int *v, t_args *elem)
{
	int date[6];
	int i;
	int k;

	i = 0;
	while (i < 6)
		date[i++] = 0;
	i = -1;
	k = 0;
	while (format[++i] != '\0')
	{
		if (!ft_isdigit(format[i]) && format[i] != 'T' && format[i] != ':'
			&& format[i] != '-')
			return (-1);
		if (ft_isdigit(format[i]) == 1)
			date[k] = date[k] * 10 + (format[i] - '0');
		if (format[i] == '-' && k < 3)
			k++;
		else if (format[i] == 'T' && k == 2)
			k++;
		else if (format[i] == ':')
			k++;
	}
	ft_print_date(date, v, elem);
	return (elem[*v].arg_len);
}

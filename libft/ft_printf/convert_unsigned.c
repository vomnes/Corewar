/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:35:21 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 15:42:35 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_u_width_precision(char const *value, int *k, t_args *elem)
{
	int i;

	i = 0;
	if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
	{
		if (elem[*k].width <= elem[*k].precision)
			while (i++ < elem[*k].precision - (int)ft_strlen(value))
				ft_putchar_len('0', &elem[*k].arg_len);
		else
		{
			if ((elem[*k].precision <= (int)ft_strlen(value)) &&
			elem[*k].end_space == 0)
				while (i++ < elem[*k].width - (int)ft_strlen(value))
					ft_putchar_len(' ', &elem[*k].arg_len);
			else if ((elem[*k].precision > (int)ft_strlen(value)) &&
			elem[*k].end_space == 0)
				while (i++ < elem[*k].width - elem[*k].precision)
					ft_putchar_len(' ', &elem[*k].arg_len);
			i = 0;
			while (i++ < elem[*k].precision - (int)ft_strlen(value))
				ft_putchar_len('0', &elem[*k].arg_len);
		}
	}
}

static void	ft_u_end_space(char const *value, int *k, t_args *elem)
{
	int i;

	i = 0;
	if (elem[*k].end_space == 1)
	{
		if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 1)
		{
			if (elem[*k].precision <= (int)ft_strlen(value))
				while (i++ < elem[*k].width - (int)ft_strlen(value))
					ft_putchar_len(' ', &elem[*k].arg_len);
			else if (elem[*k].width > elem[*k].precision)
				while (i++ < elem[*k].width - elem[*k].precision)
					ft_putchar_len(' ', &elem[*k].arg_len);
		}
		else if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
			while (i++ < elem[*k].width - (int)ft_strlen(value))
				ft_putchar_len(' ', &elem[*k].arg_len);
	}
}

static void	ft_manage_unsigned(const char *value, t_args *elem, int *k)
{
	int i;

	i = 0;
	ft_u_width_precision(value, k, elem);
	if (elem[*k].ok_precision == 0 && elem[*k].ok_width == 1)
		if ((elem[*k].precision <= (int)ft_strlen(value)) &&
		elem[*k].end_space == 0)
			while (i++ < elem[*k].width - (int)ft_strlen(value))
				ft_putchar_len((elem[*k].pre_zero == 0) ? ' ' : '0',
				&elem[*k].arg_len);
	if (elem[*k].ok_precision == 1 && elem[*k].ok_width == 0)
		if (elem[*k].precision > (int)ft_strlen(value))
			while (i++ < elem[*k].precision - (int)ft_strlen(value))
				ft_putchar_len('0', &elem[*k].arg_len);
	if (elem[*k].ok_precision == 1 && elem[*k].precision == 0 &&
	value[0] == '0')
	{
		if (elem[*k].ok_width == 1)
			ft_putchar_len(' ', &elem[*k].arg_len);
		else
			;
	}
	else
		ft_putstr_len(value, &elem[*k].arg_len);
	ft_u_end_space(value, k, elem);
}

int			ft_itoa_unsigned(unsigned long long int nb, int *k, t_args *elem)
{
	int			len;
	char		str[100];

	ft_bzero(str, 100);
	len = ft_count_ho(nb, 10);
	if (len > 100)
		return (-1);
	len--;
	if (nb == 0)
		str[len] = '0';
	while (nb)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	ft_manage_unsigned(str, elem, k);
	return (elem[*k].arg_len);
}

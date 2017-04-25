/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:34:52 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 15:29:16 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ptr_start_space(const char *value, t_args *elem, int *k)
{
	int	i;
	int	prefix_len;

	i = 0;
	prefix_len = (elem[*k].ok_precision == 1 && elem[*k].precision == 0 &&
	value[0] == '0') ? 1 : 2;
	if (elem[*k].ok_width && elem[*k].ok_precision && !elem[*k].end_space)
	{
		if (elem[*k].precision >= (int)ft_strlen(value))
			while (i++ < elem[*k].width - elem[*k].precision - prefix_len)
				ft_putchar_len(' ', &elem[*k].arg_len);
		else
			while (i++ < elem[*k].width - (int)ft_strlen(value) - prefix_len)
				ft_putchar_len(' ', &elem[*k].arg_len);
	}
	else if (elem[*k].ok_width == 1 && elem[*k].ok_precision == 0)
	{
		if (elem[*k].ok_width == 1 && elem[*k].end_space == 0 &&
			elem[*k].pre_zero == 0)
			if (elem[*k].width >= (int)ft_strlen(value) - prefix_len)
				while (i++ < elem[*k].width - (int)ft_strlen(value)
				- prefix_len)
					ft_putchar_len(' ', &elem[*k].arg_len);
	}
}

static void	ft_ptr_zeroes(const char *value, t_args *elem, int *k)
{
	int i;
	int prefix_len;

	i = 0;
	prefix_len = (elem[*k].ok_precision == 1 && elem[*k].precision == 0 &&
				value[0] == '0') ? 1 : 2;
	if (elem[*k].ok_width == 1 && elem[*k].ok_precision == 1)
		while (i++ < elem[*k].precision - (int)ft_strlen(value))
			ft_putchar_len('0', &elem[*k].arg_len);
	else if (elem[*k].ok_width == 1 && elem[*k].ok_precision == 0)
	{
		if (elem[*k].pre_zero == 1)
			if (elem[*k].width >= (int)ft_strlen(value) + prefix_len)
				while (i++ < elem[*k].width - ((int)ft_strlen(value) +
				prefix_len))
					ft_putchar_len('0', &elem[*k].arg_len);
	}
	else if (elem[*k].ok_width == 0 && elem[*k].ok_precision == 1)
		while (i++ < elem[*k].precision - (int)ft_strlen(value))
			ft_putchar_len('0', &elem[*k].arg_len);
}

static void	ft_ptr_end_space(const char *value, t_args *elem, int *k)
{
	int i;
	int prefix_len;

	i = 0;
	prefix_len = (elem[*k].ok_precision == 1 && elem[*k].precision == 0 &&
				value[0] == '0') ? 1 : 2;
	if (elem[*k].ok_width == 1 && elem[*k].ok_precision == 1 &&
		elem[*k].end_space)
	{
		if (elem[*k].precision >= (int)ft_strlen(value))
			while (i++ < elem[*k].width - elem[*k].precision - prefix_len)
				ft_putchar_len(' ', &elem[*k].arg_len);
		else
			while (i++ < elem[*k].width - (int)ft_strlen(value) - prefix_len)
				ft_putchar_len(' ', &elem[*k].arg_len);
	}
	else if (elem[*k].ok_width == 1 && elem[*k].ok_precision == 0 &&
			elem[*k].end_space == 1)
	{
		if (elem[*k].width >= (int)ft_strlen(value) - prefix_len)
			while (i++ < elem[*k].width - (int)ft_strlen(value) - prefix_len)
				ft_putchar_len(' ', &elem[*k].arg_len);
	}
}

static void	ft_manage_ptr(const char *value, t_args *elem, int *k)
{
	ft_ptr_start_space(value, elem, k);
	ft_putstr("0x");
	elem[*k].arg_len += 2;
	ft_ptr_zeroes(value, elem, k);
	if (elem[*k].ok_precision == 1 && elem[*k].precision == 0 &&
	value[0] == '0')
		;
	else
	{
		ft_putstr(value);
		elem[*k].arg_len += (int)ft_strlen(value);
	}
	ft_ptr_end_space(value, elem, k);
}

int			ft_itoa_ptr(unsigned long long int nb, int *k, t_args *elem)
{
	int			len;
	char		str[100];

	ft_bzero(str, 100);
	len = ft_count_ho(nb, 16);
	if (len > 100)
		return (-1);
	len--;
	if (nb == 0)
		str[len] = '0';
	while (nb)
	{
		if (nb % 16 <= 9)
			str[len--] = (nb % 16) + '0';
		else
			str[len--] = (nb % 16) + 'a' - 10;
		nb /= 16;
	}
	ft_manage_ptr(str, elem, k);
	return (elem[*k].arg_len);
}

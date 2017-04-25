/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:34:41 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 15:21:28 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_adapt_octal(const char *value, t_args *elem, int *k)
{
	if (elem[*k].type == 'o' || elem[*k].type == 'O')
	{
		elem[*k].size = ft_strlen(value);
		if (elem[*k].pre_sign == 1)
			elem[*k].pre_sign = 0;
		if (elem[*k].pre_blank == 1)
			elem[*k].pre_blank = 0;
		if (elem[*k].pre_hash == 1 && value[0] != '0')
			elem[*k].size -= 2;
	}
	return (0);
}

int		ft_manage_o(const char *value, t_args *elem, const char *prefix, int *k)
{
	ft_adapt_octal(value, elem, k);
	ft_octal_basic_one(value, elem, k);
	ft_octal_basic_two(value, elem, k);
	ft_octal_hash(value, elem, k);
	if (elem[*k].pre_hash == 1 && value[0] != '0')
		ft_putstr_len(prefix, &elem[*k].arg_len);
	ft_octal_zero_one(value, elem, k);
	ft_octal_zero_two(value, elem, k);
	if (elem[*k].ok_precision == 1 && elem[*k].precision == 0
		&& value[0] == '0')
	{
		if (elem[*k].pre_hash == 1 && elem[*k].ok_width == 0)
			ft_putchar_len('0', &elem[*k].arg_len);
		else if (elem[*k].ok_width == 0)
			;
		else if (elem[*k].ok_width == 1 && elem[*k].pre_hash == 1)
			ft_putchar_len('0', &elem[*k].arg_len);
		else if (elem[*k].ok_width == 1)
			ft_putchar_len(' ', &elem[*k].arg_len);
	}
	else
		ft_putstr_len(value, &elem[*k].arg_len);
	ft_octal_end_space(value, elem, k);
	return (0);
}

size_t	ft_count_ho(unsigned long long int nb, int base)
{
	size_t count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		count++;
	}
	return (count);
}

int		ft_itoa_octal(unsigned long long int nb, t_args *elem, int *k)
{
	int						len;
	char					str[100];
	unsigned long long int	tmp_nb;

	tmp_nb = nb;
	ft_bzero(str, 100);
	len = ft_count_ho(nb, 8);
	if (len > 100)
		return (-1);
	str[len + 1] = '\0';
	if (nb == 0)
		str[len] = '0';
	while (len--)
	{
		str[len] = (nb % 8) + '0';
		nb /= 8;
	}
	if (tmp_nb == 0)
	{
		ft_bzero(str, 100);
		str[0] = '0';
	}
	ft_manage_o(str, elem, "0", k);
	return (elem[*k].arg_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_date.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:15:06 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 15:50:13 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_month(const char *value, int month, int checker)
{
	if (month == checker)
		ft_putstr(value);
}

static void	ft_put_month(int month)
{
	ft_month("Jan", month, 1);
	ft_month("Feb", month, 2);
	ft_month("Mar", month, 3);
	ft_month("Apr", month, 4);
	ft_month("May", month, 5);
	ft_month("Jun", month, 6);
	ft_month("Jul", month, 7);
	ft_month("Aug", month, 8);
	ft_month("Sep", month, 9);
	ft_month("Oct", month, 10);
	ft_month("Nov", month, 11);
	ft_month("Dec", month, 12);
}

static void	ft_put_day_hour(int value, char space)
{
	if (value < 10)
	{
		ft_putchar(space);
		ft_putnbr(value);
	}
	else
		ft_putnbr(value);
}

void		ft_put_h(int *date, char x, t_args *elem, int *v)
{
	if (x == '#')
	{
		ft_put_day_hour(date[3], '0');
		ft_putchar_len(':', &elem[*v].arg_len);
		ft_put_day_hour(date[4], '0');
		elem[*v].arg_len += 4;
	}
	else if (x == '+')
	{
		ft_putchar_len('.', &elem[*v].arg_len);
		ft_put_day_hour(date[5], '0');
		elem[*v].arg_len += 2;
	}
}

void		ft_put_d(int *date, char x, t_args *elem, int *v)
{
	if (x == '-')
	{
		if (date[1] > 0 && (date[1] >= 1 && date[1] <= 12))
			ft_put_month(date[1]);
		else
			ft_putstr("   ");
		ft_putchar_len(' ', &elem[*v].arg_len);
		if (date[2] <= 31)
			ft_put_day_hour(date[2], (elem[*v].pre_zero ? '0' : ' '));
		else
			ft_putstr("  ");
		elem[*v].arg_len += 5;
	}
	else if (x == ' ')
	{
		if (date[0] > 0 && (date[0] < 1000 || date[0] > 9999))
			ft_putstr("0000");
		else
			ft_putnbr(date[0]);
		elem[*v].arg_len += 4;
	}
}

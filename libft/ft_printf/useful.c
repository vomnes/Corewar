/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:36:53 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 16:26:03 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(t_args *elem, int *k)
{
	elem[*k].start = 0;
	elem[*k].ok_start = 0;
	elem[*k].end = 0;
	elem[*k].new_start = 0;
	elem[*k].nb_arg = 0;
	elem[*k].pre_hash = 0;
	elem[*k].pre_zero = 0;
	elem[*k].end_space = 0;
	elem[*k].pre_sign = 0;
	elem[*k].pre_blank = 0;
	elem[*k].ok_width = 0;
	elem[*k].width = 0;
	elem[*k].wildcard_width = 0;
	elem[*k].ok_precision = 0;
	elem[*k].precision = 0;
	elem[*k].wildcard_precision = 0;
	elem[*k].type = 0;
	elem[*k].size = 0;
	elem[*k].i_nb = 0;
	elem[*k].neg = 0;
	elem[*k].arg_len = 0;
}

void	ft_putchar_len(char c, int *up)
{
	write(1, &c, 1);
	(*up)++;
}

void	ft_putstr_len(const char *value, int *up)
{
	ft_putstr(value);
	*up += (int)ft_strlen(value);
}

int		ft_nb_pct(const char *s)
{
	int i;
	int count;
	int is_arg;

	i = 0;
	count = 0;
	is_arg = 0;
	while (s[i] != '\0')
	{
		if (is_arg == 1 && ft_is_type(s[i]))
			is_arg = 0;
		else if (s[i] == '%')
		{
			is_arg = 1;
			count++;
		}
		i++;
	}
	return (count);
}

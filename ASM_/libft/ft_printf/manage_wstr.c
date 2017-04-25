/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 14:48:11 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 14:49:40 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwstr_size(const wchar_t *wc, size_t n)
{
	size_t i;

	i = 0;
	while (*wc && i < n)
	{
		if (*wc <= 0x7F)
			i++;
		else if (*wc <= 0x7FF)
			i += 2;
		else if (*wc <= 0xFFFF)
			i += 3;
		else if (*wc <= 0x10FFFF)
			i += 4;
		if (i <= n)
			ft_putwchar_all(*wc++);
	}
}

int		ft_wstrnlen(const wchar_t *wc, size_t n)
{
	size_t i;
	size_t add;

	i = 0;
	add = 0;
	while (*wc && i < n)
	{
		add = 0;
		if (*wc <= 0x7F)
			add = 1;
		else if (*wc <= 0x7FF)
			add = 2;
		else if (*wc <= 0xFFFF)
			add = 3;
		else if (*wc <= 0x10FFFF)
			add = 4;
		if (i + add <= n)
			i += add;
		else
			return (i);
	}
	return (i);
}

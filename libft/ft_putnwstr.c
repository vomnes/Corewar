/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:40:50 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/17 15:44:29 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnwstr(const wchar_t *wc, size_t n)
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
			ft_putwchar(*wc++);
	}
}

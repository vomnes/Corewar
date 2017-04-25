/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:46:14 by vomnes            #+#    #+#             */
/*   Updated: 2016/12/19 10:25:01 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wint_t	ft_putwchar(wchar_t wc)
{
	char tab[5];

	ft_bzero(tab, 5);
	if ((int)wc >= 0 && (int)wc <= 0x7F)
		tab[0] = (int)wc;
	else if ((int)wc <= 0x7FF)
	{
		tab[0] = ((int)wc >> 6) + 0xC0;
		tab[1] = ((int)wc & 0x3F) + 0x80;
	}
	else if ((int)wc <= 0xFFFF)
	{
		tab[0] = ((int)wc >> 12) + 0xE0;
		tab[1] = (((int)wc >> 6) & 0x3F) + 0x80;
		tab[2] = ((int)wc & 0x3F) + 0x80;
	}
	else if ((int)wc <= 0x10FFFF)
	{
		tab[0] = ((int)wc >> 18) + 0xF0;
		tab[1] = (((int)wc >> 12) & 0x3F) + 0x80;
		tab[2] = (((int)wc >> 6) & 0x3F) + 0x80;
		tab[3] = ((int)wc & 0x3F) + 0x80;
	}
	write(1, &tab, ft_strlen(tab));
	return (0);
}

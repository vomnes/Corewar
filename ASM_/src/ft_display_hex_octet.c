/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hex_octet.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:11:54 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/10 16:30:01 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_count_ho(unsigned long long int nb, int base)
{
	int count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= base;
		count++;
	}
	return (count);
}

static void     ft_print_char(char str[100], int i, int len)
{
    int less;
    int count;

    count = 0;
    less = 0;
    if (len % 2 != 0 && len != 5)
        less = 1;
    while (str[i])
    {
        count++;
        ft_putchar(str[i]);
        i++;
        if (count % 2 - less == 0 && str[i])
            ft_putstr(" 0x");
    }
}

static void     ft_print_zeroes_hex(char str[100], int nb_octet)
{
    int i;
    int less;
    int len;

    len = ft_strlen(str);
    i = len - nb_octet * 2;
    less = 1;
    if (len % 2 != 0)
        less = 0;
    while (i < 0)
    {
        ft_putchar('0');
        if (-i % 2 - less == 0 && nb_octet > 1)
        {
            if (i >= -1 && *str == '\0')
                ;
            else
                ft_putstr(" 0x");
        }
        i++;
    }
    ft_print_char(str, i, len);
}

/*
** ft_display_hex_octet : Write on the standard output an unsigned long long int
** according to the model of hexdump. The function takes in parameter a number
** and the number of octet(s) to print.
** e.g  ft_display_hex_octet(42, 4); -> 0x00 0x00 0x00 0x2a
*/

void		ft_display_hex_octet(unsigned long long int nb, int nb_octet)
{
	int		len;
	char	str[100];

	ft_bzero(str, 100);
	len = ft_count_ho(nb, 16);
	if (len > 100)
		;
	len--;
	ft_putstr("0x");
	while (nb != 0)
	{
		if (nb % 16 <= 9)
			str[len--] = (nb % 16) + '0';
		else
			str[len--] = (nb % 16) + 'a' - 10;
		nb /= 16;
	}
    ft_print_zeroes_hex(str, nb_octet);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:17:58 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/30 17:31:47 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hex_to_dec(char *hex)
{
	int		hex_len;
	int		nb;
	int		i;
	char	c;

	hex_len = ft_strlen(hex);
	nb = 0;
	i = 0;
	while (i < hex_len)
	{
		c = hex[i];
		if (ft_isdigit(hex[i]))
			c -= '0';
		else if (c >= 'A' && c <= 'F')
			c -= 'A' - 10;
		else if (c >= 'a' && c <= 'f')
			c -= 'a' - 10;
		nb += c * ft_pow(16, ((hex_len - i) - 1));
		i++;
	}
	return (nb);
}

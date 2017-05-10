/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_byte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:46:42 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/10 17:06:16 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** ft_write_byte : Write an unsigned int in a file descriptor on n octet(s).
*/

void	ft_write_byte(int fd, unsigned int value, char nb_octet)
{
	int		byte_offset;
	char	octet;

	octet = 0;
	byte_offset = 8 * (nb_octet - 1);
	while (byte_offset >= 0)
	{
		octet = (value >> byte_offset) & 0xFF;
		write(fd, &octet, 1);
		byte_offset -= 8;
	}
}

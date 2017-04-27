/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:22:41 by vomnes            #+#    #+#             */
/*   Updated: 2017/04/26 17:23:10 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void ft_write_str(int fd, char *str, int len)
{
	int index;
	int word_len;
	char zero;

	index = 0;
	word_len = ft_strlen(str);
	zero = 0;
	while (index < len)
	{
		if (index < word_len)
			write(fd, &(str[index]), 1);
		else
			write(fd, &zero, 1);
		index++;
	}
}

static void ft_write_nb(int fd, unsigned int value, char nb_octet)
{
	char octet;

    if (nb_octet == 4)
    {
        octet = (value >> 24) & 0xFF;
    	write(fd, &octet, 1);
    	octet = (value >> 16) & 0xFF;
    	write(fd, &octet, 1);
    	octet = (value >> 8) & 0xFF;
    	write(fd, &octet, 1);
    	octet = value & 0xFF;
    	write(fd, &octet, 1);
    }
    else if (nb_octet == 2)
    {
        octet = (value >> 8) & 0xFF;
        write(fd, &octet, 1);
        octet = value & 0xFF;
        write(fd, &octet, 1);
    }
}

void write_header(int fd, header_t header)
{
	ft_write_nb(fd, header.magic, 4);
	ft_write_str(fd, header.prog_name, PROG_NAME_LENGTH + 4);
	ft_write_nb(fd, header.prog_size, 4);
	ft_write_str(fd, header.comment, COMMENT_LENGTH + 4);
}

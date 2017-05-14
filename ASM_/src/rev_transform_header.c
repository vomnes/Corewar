/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_transform_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:38:33 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/14 15:16:21 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse.h"

static unsigned int	rev_n_bytes_to_uint(unsigned char *ptr, size_t n)
{
	unsigned int	value;

	value = 0;
	if (n > 4)
		ft_dprintf(2, "Error: trying to store %lu bytes in an int\n", n);
	while (n > 0)
	{
		value = (value << 8) | (unsigned int)(*ptr);
		ptr++;
		n--;
	}
	return (value);
}

static void			rev_check_exec_magic(unsigned char *buf)
{
	unsigned int	nb;

	nb = rev_n_bytes_to_uint(buf, 4);
	if (nb != COREWAR_EXEC_MAGIC)
	{
		ft_putendl_fd("Error: Not a valid file", 2);
		exit(-1);
	}
}

unsigned int		rev_parse_header(size_t size, unsigned char buf[size])
{
	size_t			i;
	size_t			j;
	unsigned int	size_prog;

	i = 0;
	j = 0;
	rev_check_exec_magic(buf);
	i += 4;
	ft_printf("%s \"", NAME_CMD_STRING);
	while (i < size && buf[i])
		ft_putchar(buf[i++]);
	while (i < PROG_NAME_LENGTH)
		i++;
	ft_printf("\"\n%s \"", COMMENT_CMD_STRING);
	size_prog = rev_n_bytes_to_uint(&buf[i + 8], 4);
	i += 12;
	while (i < size && buf[i])
		ft_putchar(buf[i++]);
	ft_putstr("\"\n\n");
	return (size_prog);
}

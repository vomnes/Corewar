/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:22:41 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/19 10:47:27 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_write_str(int fd, char *str, int len)
{
	int		index;
	int		word_len;
	char	zero;

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

/*
** write_header : Write the header (Magic number, name, program size, comment)
** in a file descriptor.
*/

void		write_header(int fd, t_header header)
{
	ft_write_byte(fd, COREWAR_EXEC_MAGIC, 4);
	ft_write_str(fd, header.prog_name, PROG_NAME_LENGTH + 4);
	ft_write_byte(fd, header.prog_size, 4);
	ft_write_str(fd, header.comment, COMMENT_LENGTH + 4);
}

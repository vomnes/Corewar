/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:34:38 by vomnes            #+#    #+#             */
/*   Updated: 2017/04/26 15:43:58 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void binary_header(header_t *header, int fd)
{
	header->magic = COREWAR_EXEC_MAGIC;
	ft_strcat(header->prog_name, "zork");
	header->prog_size = 0;
	ft_strcat(header->comment, "just a basic living prog");
	write_header(fd, *header);
}

int main(int argc, char **argv)
{
	t_data data;
	int fd;

	if (open_input(argc, argv, &data.input) == -1)
		return (-1);
	if ((fd = create_binary_file(data.input)) == -1)
		return (-1);
	binary_header(&data.header, fd);
	return (0);
}


// ft_write_nb(fd, 0x0b680100);
// ft_write_nb(fd, 0x0f000106);
// ft_write_nb(fd, 0x64010000);
// ft_write_nb(fd, 0x00000101);
// ft_write_nb(fd, 0x01);
// 42
// Just a basic Winner Program

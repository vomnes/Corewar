/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_binary_code.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:56:22 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/08 18:08:18 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void binary_header(header_t *header, int fd)
{
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 0;
	write_header(fd, *header);
}

int generate_binary_code(t_data *data)
{
	if (create_param_byte(&data->parsing.lst) == -1)
		return (-1);
	if (get_prog_data(&data->parsing.lst, &data->header) == -1)
		return (-1);
	binary_header(&data->header, data->binary_file.fd);
	return (0);
}

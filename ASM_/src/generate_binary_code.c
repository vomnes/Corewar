/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_binary_code.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:56:22 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/10 12:02:42 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	generate_binary_code(t_data *data)
{
	if (create_param_byte(&data->parsing.lst) == -1)
		return (-1);
	if (get_prog_data(&data->parsing.lst, &data->header) == -1)
		return (-1);
	if (set_label_value(&data->parsing.lst) == -1)
		return (-1);
	details_compilation(data->parsing.lst, data->header);
	write_header(data->binary_file.fd, data->header);
	if (write_binary(&data->parsing.lst, &data->binary_file) == -1)
		return (-1);
	return (0);
}

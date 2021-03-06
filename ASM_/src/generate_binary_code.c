/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_binary_code.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:56:22 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/10 15:43:56 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	generate_binary_code(t_data *data)
{
	write_header(data->binary_file.fd, data->header);
	if (write_binary(&data->parsing.lst, &data->binary_file) == -1)
		return (-1);
	return (0);
}

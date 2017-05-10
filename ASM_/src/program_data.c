/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:06:33 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/10 15:40:18 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	program_data(t_data *data)
{
	if (create_param_byte(&data->parsing.lst) == -1)
		return (-1);
	if (get_prog_data(&data->parsing.lst, &data->header) == -1)
		return (-1);
	if (set_label_value(&data->parsing.lst) == -1)
		return (-1);
	return (0);
}

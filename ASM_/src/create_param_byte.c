/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_param_byte.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:03:12 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/09 18:17:53 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_each_arg(t_instructions *lst)
{
	t_args	*current;
	int		byte_offset;

	current = lst->arg;
	byte_offset = 6;
	while (current != NULL)
	{
		lst->param_byte = (current->type << byte_offset) | lst->param_byte;
		current = current->next;
		byte_offset -= 2;
	}
}

int			create_param_byte(t_instructions **lst)
{
	t_instructions *current;

	current = *lst;
	while (current != NULL)
	{
		if (g_op_tab[current->opcode].param_byte == 1)
			check_each_arg(current);
		current = current->next;
	}
	return (0);
}

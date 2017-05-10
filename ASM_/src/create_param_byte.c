/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_param_byte.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:03:12 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/10 16:38:16 by vomnes           ###   ########.fr       */
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

/*
** create_param_byte : Build and put in the elements param_byte of the linked
** list t_instructions the binary value create with the type of each argument.
**  Example :
** 		>> r2  --> 0b01 |
**		>> 23  --> 0b11 |--> Binary value --> 0b01111000 --> 0x78
**		>> %34 --> 0b10 |
**
*/

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

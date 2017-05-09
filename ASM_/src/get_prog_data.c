/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prog_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:41:31 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/09 18:29:12 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_each_arg(t_instructions **lst, header_t *header)
{
	t_args	*current;

	current = (*lst)->arg;
	header->prog_size += 1;
	if (g_op_tab[(*lst)->opcode].param_byte == 1)
		header->prog_size += 1;
	while (current != NULL)
	{
		if (current->type == REG_CODE)
			header->prog_size += REG_OCTET;
		else if (current->type == DIR_CODE &&
		(g_op_tab[(*lst)->opcode].has_index == 1))
			header->prog_size += DIR_OCTET_INDEX;
		else if (current->type == DIR_CODE)
			header->prog_size += DIR_OCTET;
		else if (current->type == IND_CODE)
			header->prog_size += IND_OCTET;
		current = current->next;
	}
}

int			get_prog_data(t_instructions **lst, header_t *header)
{
	t_instructions	*current;
	unsigned int	prog_size;

	current = *lst;
	header->prog_size = 0;
	prog_size = 0;
	while (current != NULL)
	{
		current->index_octet = header->prog_size;
		if (current->opcode > 0)
			check_each_arg(&current, header);
		current = current->next;
	}
	return (0);
}

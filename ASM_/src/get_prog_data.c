/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prog_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:41:31 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/08 19:14:10 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void check_each_arg(t_instructions **lst, unsigned int *prog_size)
{
	t_args  *current;

	current = (*lst)->arg;
    if (g_op_tab[(*lst)->opcode].param_byte == 1)
        (*prog_size) += 1;
	while(current != NULL)
	{
        if (current->type == REG_CODE)
            (*prog_size) += T_REG;
        else if (current->type == DIR_CODE)
            (*prog_size) += T_DIR;
        else if (current->type == IND_CODE)
            (*prog_size) += T_IND;
		current = current->next;
	}
}

// else if (current->type == DIR_CODE && g_op_tab[(*lst)->opcode].has_index == 1)
    // header->prog_size += T_DIR;

    // if ((*lst)->label_name != NULL)
    //     (*lst)->index_octet = prog_size;
/*
** get_prog_data -> Length program and position labels
*/

int get_prog_data(t_instructions **lst, header_t *header)
{
    t_instructions *current;
    unsigned int prog_size;

    current = *lst;
    header->prog_size = 0;
    prog_size = 0;
    while(current != NULL)
    {
        if (current->line_label != NULL || current->line_opcode != NULL)
            prog_size += 1;
        check_each_arg(&current, &prog_size);
        ft_printf("%d |-> octet = %x\n", current->num_line, current->index_octet);
        current = current->next;
    }
    ft_printf("prog_size = %#x | %d |>> %d\n", prog_size, prog_size, 0x2f);
    return (0);
}

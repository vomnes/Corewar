/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:19:06 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/10 16:45:17 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void				init_link(t_instructions **instruction)
{
	(*instruction)->num_line = 0;
	(*instruction)->is_label = 0;
	(*instruction)->line_label = NULL;
	(*instruction)->label_name = NULL;
	(*instruction)->line_opcode = NULL;
	(*instruction)->opcode = -1;
	(*instruction)->arg = NULL;
	(*instruction)->line_args = NULL;
	(*instruction)->param_byte = 0;
	(*instruction)->index_octet = 0;
}

static t_instructions	*instruction_add_elem(t_parsing *collect)
{
	t_instructions *new_instruction;

	new_instruction = NULL;
	if (!(new_instruction = (t_instructions*)malloc(sizeof(t_instructions))))
		return (NULL);
	init_link(&new_instruction);
	new_instruction->num_line = collect->line_nb;
	if (collect->line_label != NULL)
	{
		if (!(new_instruction->line_label = ft_strdup(collect->line_label)))
			return (NULL);
		new_instruction->is_label = 1;
		if (!(new_instruction->label_name = ft_strdup(collect->label_name)))
			return (NULL);
	}
	if (collect->line_opcode != NULL && *collect->line_opcode != '\0')
		if (!(new_instruction->line_opcode = ft_strdup(collect->line_opcode)))
			return (NULL);
	return (new_instruction);
}

/*
** add_new_instruction : Add at the end of the linked list t_instructions
** an instruction (line) with the line, the line label, the label and
** the line_opcode content.
*/

int						add_new_instruction(t_instructions **lst_head, \
t_parsing *collect)
{
	t_instructions	*new_node;

	new_node = *lst_head;
	if (*lst_head == NULL)
	{
		if (!(*lst_head = instruction_add_elem(collect)))
			return (-1);
		(*lst_head)->next = NULL;
	}
	else
	{
		while (new_node->next != NULL)
			new_node = new_node->next;
		if (!(new_node->next = instruction_add_elem(collect)))
			return (-1);
		new_node->next->next = NULL;
	}
	return (1);
}

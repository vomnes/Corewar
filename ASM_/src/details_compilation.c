/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_compilation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 09:09:16 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/12 11:18:25 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static const char	*get_type(int type)
{
	if (type == REG_CODE)
		return ("Register");
	else if (type == DIR_CODE)
		return ("Direct");
	else if (type == IND_CODE)
		return ("Indirect");
	return ("");
}

static void			display_arg_value(int type, int value, int has_index)
{
	if (type == REG_CODE)
		ft_display_hex_octet(value, REG_OCTET);
	else if (type == DIR_CODE && has_index == 1)
		ft_display_hex_octet(value, DIR_OCTET_INDEX);
	else if (type == DIR_CODE)
		ft_display_hex_octet(value, DIR_OCTET);
	else if (type == IND_CODE)
		ft_display_hex_octet(value, IND_OCTET);
}

static void			check_each_arg(t_instructions *lst)
{
	t_args	*current;

	current = lst->arg;
	ft_printf("%s%-5s%s ⇨  [%#.2x] ", GOLD, g_op_tab[lst->opcode].name, \
	DEF, lst->opcode);
	if (g_op_tab[lst->opcode].param_byte == 1)
		ft_printf("0b%.8b - %#2x", lst->param_byte, lst->param_byte);
	else
		ft_printf("%10s ", " ");
	while (current != NULL)
	{
		ft_printf("\n%32s %s ➜ %s  %s%-8s%s → [%-8s - 0b%.2b - ", " ", \
		B_GREEN, DEF, B_RED, current->content, DEF, \
		get_type(current->type), current->type);
		display_arg_value(current->type, current->value, \
		g_op_tab[lst->opcode].has_index);
		ft_putchar(']');
		current = current->next;
	}
	ft_putchar('\n');
}

/*
** details_compilation : Print on the standard output the details of the
** compilation.
*/

void				details_compilation(t_instructions *lst, header_t header)
{
	t_instructions *current;

	current = lst;
	ft_printf("Details binary compilation\n");
	ft_printf("Program size : %d bytes - %#x\n", header.prog_size, \
	header.prog_size);
	ft_printf("Champion's comment : \"%s\"\n", header.comment);
	ft_printf("Champion's name : \"%s\"\n", header.prog_name);
	ft_printf("Magic number : %#x\n\n", COREWAR_EXEC_MAGIC);
	while (current != NULL)
	{
		if (current->label_name != NULL)
			ft_printf(":%s\n", current->label_name);
		if (current->opcode > 0)
			check_each_arg(current);
		current = current->next;
	}
}

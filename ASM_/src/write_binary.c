/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:35:14 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/10 15:54:48 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_each_arg(t_instructions **lst, int fd)
{
	t_args	*current;

	current = (*lst)->arg;
	ft_write_byte(fd, (*lst)->opcode, 1);
	if (g_op_tab[(*lst)->opcode].param_byte == 1)
		ft_write_byte(fd, (*lst)->param_byte, 1);
	while (current != NULL)
	{
		if (current->type == REG_CODE)
			ft_write_byte(fd, current->value, REG_OCTET);
		else if (current->type == DIR_CODE &&
		(g_op_tab[(*lst)->opcode].has_index == 1))
			ft_write_byte(fd, current->value, DIR_OCTET_INDEX);
		else if (current->type == DIR_CODE)
			ft_write_byte(fd, current->value, DIR_OCTET);
		else if (current->type == IND_CODE)
			ft_write_byte(fd, current->value, IND_OCTET);
		current = current->next;
	}
}

/*
** write_binary : Run linked list with the input data in order to write this
** data in the memory output file .cor.
*/

int			write_binary(t_instructions **lst, t_output *binary_file)
{
	t_instructions *current;

	current = *lst;
	while (current != NULL)
	{
		if (current->opcode > 0)
			check_each_arg(&current, binary_file->fd);
		current = current->next;
	}
	return (0);
}

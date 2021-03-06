/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opcode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:23:26 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/11 10:43:50 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	undefined_opcode(t_instructions *current, char **opcode_name)
{
	if (current->opcode == -10)
	{
		if (*opcode_name != NULL && *opcode_name[0] != '\0')
			ft_dprintf(2, "Unknown instruction : '%s' - Line %d\n", \
			*opcode_name, current->num_line);
		else
			ft_dprintf(2, "Undefined instruction syntax - Line %d\n", \
			current->num_line);
		ft_strdel(&(*opcode_name));
		return (-1);
	}
	return (0);
}

/*
** parse_opcode : Parse each line_opcode to check the validity of the opcode
** and stock the opcode in t_instructions.
*/

int			parse_opcode(t_instructions **lst)
{
	t_instructions	*current;
	char			*opcode_name;

	current = *lst;
	opcode_name = NULL;
	while (current != NULL)
	{
		if (current->line_opcode != NULL)
		{
			if ((current->opcode = get_opcode(current->line_opcode, \
			&opcode_name)) == -1)
			{
				ft_strdel(&opcode_name);
				return (-1);
			}
			if (undefined_opcode(current, &opcode_name) == -1)
				return (-1);
			if (!(current->line_args = ft_strtrim(current->line_opcode + \
			ft_strlen(opcode_name))))
				return (-1);
			ft_strdel(&opcode_name);
		}
		current = current->next;
	}
	return (0);
}

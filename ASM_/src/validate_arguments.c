/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 19:25:35 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/08 11:20:46 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


static int print_arg_error(t_args *current, int opcode, int num_line, \
int num_arg)
{
	if (current->type == REG_CODE)
		ft_printf("Invalid parameter %d type %s for INSTRUCTION '%s' \
- Line %d\n", num_arg + 1, "REGISTER", g_op_tab[opcode].name, num_line);
	else if (current->type == IND_CODE)
		ft_printf("Invalid parameter %d type %s for INSTRUCTION '%s' \
- Line %d\n", num_arg + 1, "INDIRECT", g_op_tab[opcode].name, num_line);
	else if (current->type == DIR_CODE)
		ft_printf("Invalid parameter %d type %s for INSTRUCTION '%s' \
- Line %d\n", num_arg + 1, "DIRECT", g_op_tab[opcode].name, num_line);
	return (-1);
}

static int check_each_arg(t_instructions *lst, int opcode, int num_line)
{
	t_args  *current;
    int     num_arg;
    int code;

    num_arg = 0;
	current = lst->arg;
    code = 0;
	while(current != NULL)
	{
        if ((code = (g_op_tab[opcode].arg_types[num_arg] & \
			current->t_arg)) == 0)
            return (print_arg_error(current, opcode, num_line, num_arg));
		current = current->next;
        num_arg++;
	}
    return (0);
}

int validate_arguments(t_instructions **lst)
{
    t_instructions *current;

	current = *lst;
	while(current != NULL)
	{
        if (current->line_args)
        {
            if (check_each_arg(current, current->opcode, \
				current->num_line) == -1)
                return (-1);
        }
		current = current->next;
	}
    return (0);
}

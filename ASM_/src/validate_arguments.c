/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 19:25:35 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/07 21:36:22 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
        if ((code = (g_op_tab[opcode].arg_types[num_arg] & current->t_arg)) == 0)
        {
            if (current->type == REG)
                ft_printf("Invalid parameter %d type %s for INSTRUCTION '%s' - Line %d\n", num_arg + 1, "REGISTER", g_op_tab[opcode].name, num_line);
            else if (current->type == IND)
                ft_printf("Invalid parameter %d type %s for INSTRUCTION '%s' - Line %d\n", num_arg + 1, "INDIRECT", g_op_tab[opcode].name, num_line);
            else if (current->type == DIR)
                ft_printf("Invalid parameter %d type %s for INSTRUCTION '%s' - Line %d\n", num_arg + 1, "DIRECT", g_op_tab[opcode].name, num_line);
            return (-1);
        }
		current = current->next;
        num_arg++;
	}
    return (0);
}

// if (current->type == REG)
//     ft_printf("          Type = %.2b | %s | %d\n", current->type, "REG", current->t_arg);
// else if (current->type == IND)
//     ft_printf("          Type = %.2b | %s | %d\n", current->type, "INDIRECT", current->t_arg);
// else if (current->type == DIR)
//     ft_printf("          Type = %.2b | %s | %d\n", current->type, "DIRECT", current->t_arg);

int validate_arguments(t_instructions **lst)
{
    t_instructions *current;

	current = *lst;
	while(current != NULL)
	{
        if (current->line_args)
        {
            ft_printf(B_GREEN"[%02d] >> %s\n"DEF, current->num_line, g_op_tab[current->opcode].name);
            if (check_each_arg(current, current->opcode, current->num_line) == -1)
                return (-1);
        }
		current = current->next;
	}
    return (0);
}

/*strtrim */

// if (type != DIR)
//     return (-1);
// 1  -> DIR
// 2  -> T_DIR | T_IND        , T_REG
// 3  -> T_REG                , T_IND | T_REG
// add : 4  -> T_REG                , T_REG                , T_REG
// 5  -> T_REG                , T_REG                , T_REG
// and : 6  -> T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG
// 7  -> T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG
// 8  -> T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG
// 9  -> T_DIR
// 10 -> T_REG | T_DIR | T_IND, T_DIR | T_REG        , T_REG
// 11 -> T_REG                , T_REG | T_DIR | T_IND, T_DIR | T_REG
// 12 -> T_DIR
// 13 -> T_DIR | T_IND        , T_REG
// 14 -> T_REG | T_DIR | T_IND, T_DIR | T_REG        , T_REG
// 15 -> T_DIR
// 16 -> T_REG

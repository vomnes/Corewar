/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:36:54 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/05 20:01:04 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int check_nb_args(char **tab, int opcode, char num_line)
{
    int nb_args;

    nb_args = 0;
    while (tab[nb_args] != NULL)
        nb_args++;
    if (nb_args != g_op_tab[opcode].nb_args)
    {
        ft_printf("Invalid parameter number for the instruction '%s' - Need only %d argument(s) - Line %d\n",\
        g_op_tab[opcode].name, g_op_tab[opcode].nb_args, num_line);
        return (-1);
    }
    return (0);
}

int push_arg_on(t_args **lst, char **tab)
{
    int index;

    index = 0;
    while (tab[index] != NULL)
    {
        if (add_arg(&(*lst), tab[index]) == -1)
            return (-1);
        index++;
    }
    return (0);
}

void print(t_args *lst)
{
	t_args *current;

	current = lst;
	while(current != NULL)
	{
		ft_printf(B_GREEN"---> arg = %s\n"DEF, current->content);
		current = current->next;
	}
}

int parse_args(t_instructions **lst)
{
	t_instructions *current;
    char **arg_tab;

	current = *lst;
	while(current != NULL)
	{
        if (current->line_args)
        {
            ft_printf("a[%02d] >> %s\n", current->num_line, current->line_args);
            if (!(arg_tab = ft_strsplit(current->line_args, SEPARATOR_CHAR)))
                return (-1);
            if (check_nb_args(arg_tab, current->opcode, current->num_line)\
                == -1)
                return (-1);
            if (push_arg_on(&(current->arg), arg_tab) == -1)
                return (-1);
            ft_strtab_free(arg_tab);
            print(current->arg);
        }
		current = current->next;
	}
    return (0);
}

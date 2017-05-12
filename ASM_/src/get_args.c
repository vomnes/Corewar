/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 12:04:27 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/12 15:00:46 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_nb_args(char **tab, int opcode, char num_line)
{
	int nb_args;

	nb_args = 0;
	while (tab[nb_args] != NULL)
		nb_args++;
	if (nb_args != g_op_tab[opcode].nb_args)
	{
		ft_dprintf(2, "Invalid parameter number for the instruction '%s' - \
expected %d, have %d - Line %d\n",\
		g_op_tab[opcode].name, g_op_tab[opcode].nb_args, nb_args, num_line);
		ft_strtab_free(tab);
		return (-1);
	}
	return (0);
}

static int	push_arg_on(t_args **lst, char **tab)
{
	int index;

	index = 0;
	while (tab[index] != NULL)
	{
		if (add_arg(&(*lst), tab[index]) == -1)
		{
			ft_strtab_free(tab);
			return (-1);
		}
		index++;
	}
	return (0);
}

/*
** get_args : Check and add the argument(s) of the line_args (t_instructions)
** in the linked list t_arg (t_instructions) for each instruction.
*/

int			get_args(t_instructions **lst)
{
	t_instructions	*current;
	char			**arg_tab;

	current = *lst;
	while (current != NULL)
	{
		if (current->line_args)
		{
			if (!(arg_tab = ft_strsplit(current->line_args, SEPARATOR_CHAR)))
				return (-1);
			if (check_nb_args(arg_tab, current->opcode, current->num_line)\
			== -1)
				return (-1);
			if (push_arg_on(&(current->arg), arg_tab) == -1)
				return (-1);
			ft_strtab_free(arg_tab);
		}
		current = current->next;
	}
	return (0);
}

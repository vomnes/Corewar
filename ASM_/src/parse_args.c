/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:36:54 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/12 14:53:40 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_isindirect(int c)
{
	return ((c >= '0' && c <= '9') || c == '-' || c == LABEL_CHAR);
}

static int	arg_reg_parse(t_args *current, char num_arg, int num_line)
{
	char *content;

	content = (current->type < 3) ? current->content + 1 : current->content;
	if (current->type == REG_CODE)
	{
		if (ft_isnumber_syntax(content, 0) == -1 || *content == '\0')
		{
			ft_dprintf(2, "Invalid number for register type [arg %d]  - \
Line %d\n", num_arg, num_line);
			return (-1);
		}
		current->value = ft_lltoi(content);
		if (current->value > REG_NUMBER || \
		ft_strlen(content) > ft_intlen(REG_NUMBER))
		{
			ft_dprintf(2, "Only %d register(s) available [arg %d] - Line %d\n",\
			REG_NUMBER, num_arg, num_line);
			return (-1);
		}
	}
	return (0);
}

static int	arg_type(t_args *current, char num_arg, int num_line)
{
	if (*current->content == 'r')
	{
		current->type = REG_CODE;
		current->t_arg = T_REG;
	}
	else if (*current->content == DIRECT_CHAR)
	{
		current->type = DIR_CODE;
		current->t_arg = T_DIR;
	}
	else if (ft_isindirect(*current->content) == 1)
	{
		current->type = IND_CODE;
		current->t_arg = T_IND;
	}
	else
	{
		ft_dprintf(2, "Invalid syntax [arg %d] - Line %d\n", num_arg, num_line);
		return (-1);
	}
	return (0);
}

static int	check_each_arg(t_instructions *lst, t_instructions *check_label)
{
	t_args	*current;
	char	num_arg;
	char	*tmp_content;

	current = lst->arg;
	num_arg = 0;
	while (current != NULL)
	{
		num_arg++;
		tmp_content = current->content;
		ft_strdel(&current->content);
		if (!(current->content = ft_strtrim(tmp_content)))
			return (-1);
		if (arg_type(current, num_arg, lst->num_line) == -1)
			return (-1);
		if (arg_reg_parse(current, num_arg, lst->num_line) == -1)
			return (-1);
		if (arg_dir_ind_parse(current, num_arg, lst->num_line, \
		check_label) == -1)
			return (-1);
		current = current->next;
	}
	return (0);
}

/*
** parse_args : Check the validity of each argument (t_args) and set the
** argument type (0b01 - 0b10 - 0b11) for each instruction (t_instructions).
*/

int			parse_args(t_instructions **lst)
{
	t_instructions *current;
	t_instructions *check_label;

	current = *lst;
	check_label = *lst;
	while (current != NULL)
	{
		if (current->line_args)
		{
			if (check_each_arg(current, check_label) == -1)
				return (-1);
		}
		current = current->next;
	}
	return (0);
}

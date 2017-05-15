/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_dir_ind_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 19:02:58 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/15 19:51:38 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define ARG_NULL "Syntax error - argument %d (null) - Line %d\n"
#define UNDEFINED_LABEL "Undefined label [arg %d] - Line %d\n"
#define UNDEFINED_SYNTAX "Undefined syntax [arg %d] - Line %d\n"

static int	empty_arg(char *content, int num_arg, int num_line)
{
	if (*content == '\0')
	{
		ft_dprintf(2, ARG_NULL, num_arg, num_line);
		return (-1);
	}
	return (0);
}

static int ft_isstr_expression_char(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '+' && str[i] != '-'
		&& str[i] != '*' && str[i] != '/' && str[i] != '%'
		&& !ft_isdigit(str[i]))
            return (-1);
        i++;
    }
    return (1);
}

/*
** arg_dir_ind_parse : Check if arguments Direct and Indirect are correct.
*/

int			arg_dir_ind_parse(t_args *current, char num_arg, int num_line, \
t_instructions *check_label)
{
	char *content;

	content = (current->type < 3) ? current->content + 1 : current->content;
	if (current->type == DIR_CODE || current->type == IND_CODE)
	{
		if (empty_arg(content, num_arg, num_line) == -1)
			return (-1);
		if (*content == LABEL_CHAR)
		{
			if (ft_charindex(content, ' ') != -1)
			{
				if (eval_expr(current, num_arg, num_line, 1, check_label))
					return (-1);
			}
			else
			{
				if (label_exist(check_label, content + 1) == 0)
				{
					ft_dprintf(2, UNDEFINED_LABEL, num_arg, num_line);
					return (-1);
				}
				current->label = content + 1;
			}
		}
		else if (ft_isnumber_syntax(content, 1) == 1)
			current->value = ft_lltoi(content);
		else if (ft_isstr_expression_char(content) == 1)
			return (eval_expr(current, num_arg, num_line, 0, check_label));
		else
		{
			ft_dprintf(2, UNDEFINED_SYNTAX, num_arg, num_line);
			return (-1);
		}
	}
	return (0);
}

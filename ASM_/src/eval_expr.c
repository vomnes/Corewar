/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:22:24 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/15 19:48:01 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int 		eval_expr(t_args *current, char num_arg, int num_line, char flag_type, \
t_instructions *check_label)
{
	char **expression_tab;

    char *content;
	content = (current->type < 3) ? current->content + 1 : current->content;
    if (flag_type == 1)
        content = content + 1;
	if (!(expression_tab = ft_strsplit(content, ' ')))
		return (-1);
    if (ft_strtab_len(expression_tab) != 3)
    {
ft_dprintf(2, "Unauthorised expression : [arg %d] - Line %d\n\
-> Maximum operation (+,-,*,/,%%) between a label/number and a number\n   \
Example: %%100 + 25\n", \
num_arg, num_line);
    		return (-1);
	}
    if (flag_type == 1)
    {
        if (label_exist(check_label, expression_tab[0]) == 0)
        {
            ft_dprintf(2, "Undefined label [arg %d] - Line %d\n", num_arg, num_line);
            return (-1);
        }
        char *tmp;
        tmp = content;
        tmp[ft_charindex(content, ' ')] = '\0';
        current->label = tmp;
    }
    else
    {
        if (ft_isnumber_syntax(expression_tab[0], 1) != 1)
        {
            ft_dprintf(2, "The first value in expression is not a number/label - \
    [arg %d] - Line %d\n", num_arg, num_line);
            return (-1);
        }
    }
	if (ft_strlen(expression_tab[1]) != 1 ||
	(*expression_tab[1] != '+' && *expression_tab[1] != '-' &&
	*expression_tab[1] != '*' && *expression_tab[1] != '/' &&
	*expression_tab[1] != '%'))
	{
		ft_dprintf(2, "Unauthorised operator in expression - \
[arg %d] - Line %d - Authorised operator are +, -, * and /\n",\
		num_arg, num_line);
		return (-1);
	}
	if (ft_isnumber_syntax(expression_tab[2], 1) != 1)
	{
		ft_dprintf(2, "The second value in expression is not a number\
- [arg %d] - Line %d\n", num_arg, num_line);
		return (-1);
	}
    if (flag_type != 1)
	   current->value = ft_lltoi(expression_tab[0]);
	current->op = *expression_tab[1];
	current->value_2 = ft_lltoi(expression_tab[2]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:22:24 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/16 12:36:50 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_len_tab(char **expression_tab, char num_arg, int num_line)
{
	if (ft_strtab_len(expression_tab) != 3)
	{
		ft_dprintf(2, "Unauthorised expression : [arg %d] - Line %d\n\
-> Maximum operation (+,-,*,/,%%) between a label/number and a number\n   \
Example: %%100 + 25\n", \
num_arg, num_line);
		return (-1);
	}
	return (0);
}

static int	error_part_two(char **expression_tab, char num_arg, \
int num_line)
{
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
	return (0);
}

static void	put_value(t_args *current, char **expression_tab, char flag_type)
{
	if (flag_type != 1)
		current->value = ft_lltoi(expression_tab[0]);
	current->op = *expression_tab[1];
	current->value_2 = ft_lltoi(expression_tab[2]);
}

int			eval_expr_label(t_args *current, char num_arg, int num_line, \
t_instructions *check_label)
{
	char	**expression_tab;
	char	*content;
	char	*label;

	label = NULL;
	content = (current->type < 3) ? current->content + 2 : current->content + 1;
	if (!(expression_tab = ft_strsplit(content, ' ')))
		return (-1);
	if (check_len_tab(expression_tab, num_arg, num_line) == -1)
		return (-1);
	if (label_exist(check_label, expression_tab[0]) == 0)
	{
		ft_dprintf(2, "Undefined label [arg %d] - Line %d\n", \
		num_arg, num_line);
		return (-1);
	}
	label = content;
	label[ft_charindex(content, ' ')] = '\0';
	current->label = label;
	if (error_part_two(expression_tab, num_arg, num_line) == -1)
		return (-1);
	put_value(current, expression_tab, 1);
	return (0);
}

int			eval_expr(t_args *current, char num_arg, int num_line)
{
	char	**expression_tab;
	char	*content;

	content = (current->type < 3) ? current->content + 1 : current->content;
	if (!(expression_tab = ft_strsplit(content, ' ')))
		return (-1);
	if (check_len_tab(expression_tab, num_arg, num_line) == -1)
		return (-1);
	if (ft_isnumber_syntax(expression_tab[0], 1) != 1)
	{
		ft_dprintf(2, "The first value in expression is not a number/label - \
	[arg %d] - Line %d\n", num_arg, num_line);
		return (-1);
	}
	if (error_part_two(expression_tab, num_arg, num_line) == -1)
		return (-1);
	put_value(current, expression_tab, 0);
	return (0);
}

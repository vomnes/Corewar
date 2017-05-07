/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:36:54 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/07 12:49:42 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define REG 0b01
#define DIR 0b10
#define IND 0b11

int		ft_isindirect(int c)
{
	return ((c >= '0' && c <= '9') || c == '-' || c == ':');
}

void print(t_args *lst)
{
	t_args *current;

	current = lst;
	while(current != NULL)
	{
		ft_printf(B_GREEN"---> arg = %s\n"DEF, current->content);
        ft_printf("          Type = %d\n", current->type);
        ft_printf("          Value = %d >> [%x]\n", current->value, current->value);
        ft_printf("          Label = %s\n", current->label);
		current = current->next;
	}
}

int arg_reg_parse()
{
    if (type == REG)
    {
        
    }
    return (0);
}
// int arg_dir_parse()
// {
//
// }
// int arg_ind_parse()
// {
//
// }

int check_each_arg(t_args *lst, int num_line, t_instructions *check_label)
{
	t_args *current;
    char *content;
    char num_arg;

	current = lst;
    content = NULL;
    num_arg = 0;
	while(current != NULL)
	{
        num_arg++;
        if (*current->content == 'r')
            current->type = REG;
        else if (*current->content == DIRECT_CHAR)
            current->type = DIR;
        else if (ft_isnumeric(*current->content) == 1)
            current->type = IND;
        else
        {
            ft_printf("Invalid syntax for argument number %d  - Line %d\n",\
            num_arg, num_line);
            return (-1);
        }
        if (current->type < 3)
            content = current->content + 1;
        else
            content = current->content;
        ft_printf(B_GREEN"---> arg = %s\n"DEF, current->content);
        ft_printf("          Type = %d\n", current->type);
        ft_printf("          Content = %s\n"DEF, content);
		current = current->next;
	}
    return (0);
}

int parse_args(t_instructions **lst)
{
	t_instructions *current;
    t_instructions *check_label;

	current = *lst;
	while(current != NULL)
	{
        if (current->line_args)
        {
            ft_printf(B_BLUE"[%02d] >> %s\n"DEF, current->num_line, current->line_args);
            if (check_each_arg(current->arg, current->num_line, check_label) == -1)
                return (-1);
            // print(current->arg);
        }
		current = current->next;
	}
    return (0);
}

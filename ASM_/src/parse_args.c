/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:36:54 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/07 14:56:17 by vomnes           ###   ########.fr       */
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

int arg_type(t_args *current, char num_arg, int num_line)
{
    if (*current->content == 'r')
        current->type = REG;
    else if (*current->content == DIRECT_CHAR)
        current->type = DIR;
    else if (ft_isindirect(*current->content) == 1)
        current->type = IND;
    else
    {
        ft_printf("Invalid syntax for argument number %d - Line %d\n",\
        num_arg, num_line);
        return (-1);
    }
    return (0);
}

size_t	ft_intlen(int nbr)
{
	size_t length;

	length = 0;
	if (nbr <= 0)
		length++;
	while (nbr)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length);
}

int arg_reg_parse(t_args *current, char num_arg, int num_line)
{
    char *content;

    content = (current->type < 3) ? current->content + 1 : current->content;
    if (current->type == REG)
    {
        if (ft_isnumber_syntax(content, 0) == -1)
        {
            ft_printf("Invalid number for register type [arg %d]  - Line %d\n",\
            num_arg, num_line);
            return (-1);
        }
        current->value = ft_atoi(content);
        if (current->value > REG_NUMBER || ft_strlen(content) > ft_intlen(REG_NUMBER))
        {
            ft_printf("Only %d register(s) available [arg %d] - Line %d\n",\
            REG_NUMBER, num_arg, num_line);
            return (-1);
        }
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

int check_each_arg(t_instructions *lst)
{
	t_args *current;
    char num_arg;

	current = lst->arg;
    num_arg = 0;
	while(current != NULL)
	{
        num_arg++;
        if (arg_type(current, num_arg, lst->num_line) == -1)
            return (-1);
        if (arg_reg_parse(current, num_arg, lst->num_line) == -1)
            return (-1);
        ft_printf(B_GREEN"---> arg = %s\n"DEF, current->content);
        ft_printf("          Type = %d\n", current->type);
        ft_printf("          Value = %#.2x\n", current->value);
		current = current->next;
	}
    return (0);
}

int parse_args(t_instructions **lst)
{
	t_instructions *current;
    t_instructions *check_label;

	current = *lst;
    check_label = *lst;
	while(current != NULL)
	{
        if (current->line_args)
        {
            ft_printf(B_BLUE"[%02d] >> %s\n"DEF, current->num_line, current->line_args);
            if (check_each_arg(current) == -1)
                return (-1);
            // print(current->arg);
        }
		current = current->next;
	}
    return (0);
}

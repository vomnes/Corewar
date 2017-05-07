/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_dir_ind_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 19:02:58 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/07 21:38:21 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int ft_label_exist(t_instructions *lst, char *label_to_check)
{
    t_instructions *tmp;

    tmp = lst;
    while (tmp != NULL)
    {
        if (tmp->label_name != NULL)
        {
            if (ft_strcmp(tmp->label_name, label_to_check) == 0)
                return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

static void check_label_content(t_args *current, char *content)
{
    current->value = ft_atoi(content);
    if (*content == '-' && ft_strlen(content + 1) > 19)
        current->value = 0;
    else if (ft_strlen(content) > 20)
        current->value = -1;
}

int arg_dir_ind_parse(t_args *current, char num_arg, int num_line, \
t_instructions *check_label)
{
    char *content;

    content = (current->type < 3) ? current->content + 1 : current->content;
    if (current->type == DIR || current->type == IND)
    {
        if (*content == LABEL_CHAR)
        {
            if (ft_label_exist(check_label, content + 1) == 0)
            {
                ft_printf("Undefined label [arg %d] - Line %d\n", \
                num_arg, num_line);
                return (-1);
            }
            current->label = content + 1;
        }
        else if (ft_isnumber_syntax(content, 1) == 1)
            check_label_content(current, content);
        else
        {
            ft_printf("Undefined syntax [arg %d] - Line %d\n", \
            num_arg, num_line);
            return (-1);
        }
    }
    return (0);
}

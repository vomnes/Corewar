/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opcode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:23:26 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/08 10:54:32 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int pick_up_area(char **content, char *line, char to_analyse, int (*type)())
{
    if ((*type)(to_analyse) == 1)
    {
        if (!(*content = ft_strndup(line, ft_charindex(line, to_analyse))))
            return (-1);
        return (1);
    }
    return (0);
}

static int ft_is_sperator_char(int c)
{
    if (c == DIRECT_CHAR || c == '-')
        return (1);
    else if (ft_isdigit(c))
        return (1);
    else if (ft_isspace(c))
        return (1);
    return (0);
}

static int pick_up_area_all(char *to_analyse, char **content, int *i)
{
    int ret;

    ret = 0;
    if ((ret = pick_up_area(&(*content), to_analyse, to_analyse[*i], \
                            ft_is_sperator_char)) == -1)
        return (-1);
    if (ret == 1)
        return (1);
    return (0);
}

static int get_code(char *elem)
{
    int index;

    index = 1;
    ft_putendl(elem);
    if (!elem)
        return (-10);
    while (ft_strcmp(g_op_tab[index].name, elem) != 0)
    {
        index++;
        if (index > 16)
            return (-10);
    }
    return (index);
}

static int get_opcode(char *to_analyse, char **opcode_name)
{
    int i;
    char *content;
    int ret;

    i = 0;
    content = NULL;
    ret = 0;
    while (to_analyse[i] != '\0')
    {
        if ((ret = pick_up_area_all(to_analyse, &(*opcode_name), &i)) == -1)
            return (-1);
        if (ret == 1)
            break ;
        i++;
    }
    return (get_code(*opcode_name));
}

static int undefined_opcode(t_instructions *current, char **opcode_name)
{
    if (current->opcode == -10)
    {
        if (*opcode_name != NULL && *opcode_name[0] != '\0')
            ft_printf("Unknown instruction : '%s' - Line %d\n", \
            *opcode_name, current->num_line);
        else
            ft_printf("Undefined instruction - Line %d\n", current->num_line);
        ft_strdel(&(*opcode_name));
        return (-1);
    }
    return (0);
}

int parse_opcode(t_instructions **lst)
{
	t_instructions *current;
    char *opcode_name;

	current = *lst;
    opcode_name = NULL;
	while(current != NULL)
	{
        if (current->line_opcode != NULL)
        {
            if ((current->opcode = get_opcode(current->line_opcode, &opcode_name)) == -1)
            {
                ft_strdel(&opcode_name);
                return (-1);
            }
            if (undefined_opcode(current, &opcode_name) == -1)
                return (-1);
            if (!(current->line_args = ft_strtrim(current->line_opcode + ft_strlen(opcode_name))))
                return (-1);
            ft_strdel(&opcode_name);
        }
		current = current->next;
	}
    return (0);
}

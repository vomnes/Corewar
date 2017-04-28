/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:58:00 by vomnes            #+#    #+#             */
/*   Updated: 2017/04/27 19:46:11 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_isprint_nospace(int c)
{
	if (c > 32 && c < 127)
		return (1);
	else
		return (0);
}

void check_header_content(char *clean_line, const char *cmd_string,\
unsigned int content_len)
{
    char *name;
    int index_open;
    int index_close;

    if (ft_strncmp(clean_line, cmd_string, ft_strlen(cmd_string)) == 0)
    {
        name = clean_line + ft_strlen(cmd_string);
        index_open = ft_charindex(name, '\"');
        if (ft_isstrn_ctype(name, ft_isprint_nospace, index_open))
        {
            ft_printf("Syntax error before content %s - Line %d\n", cmd_string, 0);
            exit (-1);
        }
        if (ft_nb_occ(name, '\"') != 2)
        {
            ft_printf("Syntax error - %s - Line %d\n", cmd_string, 0);
            exit (-1);
        }
        index_close = ft_charindex(name + index_open + 1, '\"');
        if (index_close > (int)content_len)
        {
            ft_printf("Champion %s too long, %d character(s) over the limit (Max length %d)\n",\
            cmd_string, index_close - content_len, content_len);
            exit (-1);
        }
        if (ft_isstr_ctype(name + (index_open + index_close + 2), ft_isprint))
        {
            ft_printf("Syntax error after content %s - Line %d\n", cmd_string, 0);
            exit (-1);
        }
    }
}
int parsing_input(t_data *data)
{
    char *line;
    char *clean_line;

	line = NULL;
    clean_line = NULL;
	while (get_next_line(data->input.fd, &line) > 0)
	{
        if (!(clean_line = ft_strtrim(line)))
        {
            ft_strdel(&line);
            return (-1);
        }
        check_header_content(clean_line, NAME_CMD_STRING, PROG_NAME_LENGTH);
        check_header_content(clean_line, COMMENT_CMD_STRING, COMMENT_LENGTH);
        ft_strdel(&line);
    }
    ft_strdel(&line);
    return (0);
}

// check nb \"
// if (nb != 2)
//     error syntax NAME_CMD_STRING
// if ((name + (index_1 + index_2)) is strprint)
//     error syntax NAME_CMD_STRING
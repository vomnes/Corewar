/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:59:02 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/03 16:22:42 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_isprint_nospace(int c)
{
	if (c > 32 && c < 127)
		return (1);
	else
		return (0);
}

static void name_comment_checked(t_parsing *parsing, char flag_type)
{
	if (ft_strncmp(parsing->clean_line, NAME_CMD_STRING, \
		ft_strlen(NAME_CMD_STRING)) == 0 && flag_type == 1)
	{
		if (parsing->name_stocked == 0)
			parsing->name_stocked = 1;
		else
		{
			ft_printf("Champion name already defined - Line %d\n", parsing->line_nb);
			exit (-1);
		}
	}
	else if (ft_strncmp(parsing->clean_line, COMMENT_CMD_STRING, \
			ft_strlen(COMMENT_CMD_STRING)) == 0 && flag_type == 0)
	{
		if (parsing->comment_stocked == 0)
			parsing->comment_stocked = 1;
		else
		{
			ft_printf("Champion comment already defined - Line %d\n", parsing->line_nb);
			exit (-1);
		}
	}
}

static void check_header_content(const char *cmd_string, unsigned int content_len,
t_parsing *parsing, char flag_type)
{
    char *name;
    int index_open;
    int index_close;

    if (ft_strncmp(parsing->clean_line, cmd_string, ft_strlen(cmd_string)) == 0)
    {
        name = parsing->clean_line + ft_strlen(cmd_string);
        index_open = ft_charindex(name, '\"');
        if (ft_isstrn_ctype(name, ft_isprint_nospace, index_open))
        {
            ft_printf("Syntax error before content of %s - Line %d\n", cmd_string, parsing->line_nb);
            exit (-1);
        }
        if (ft_nb_occ(name, '\"') != 2)
        {
            ft_printf("Syntax error - %s - Line %d\n", cmd_string, parsing->line_nb);
            exit (-1);
        }
        index_close = ft_charindex(name + index_open + 1, '\"');
        if (index_close > (int)content_len)
        {
            ft_printf("Champion %s too long, %d character(s) over the limit (Max length %d)\n",\
            cmd_string, index_close - content_len, content_len);
            exit (-1);
        }
        if (ft_isstr_ctype(name + (index_open + index_close + 2), ft_isprint_nospace))
        {
            ft_printf("Syntax error after content %s - Line %d\n", cmd_string, parsing->line_nb);
            exit (-1);
        }
    }
	name_comment_checked(parsing, flag_type);
}

int parse_name_comment(t_parsing *parsing)
{
	check_header_content(NAME_CMD_STRING, PROG_NAME_LENGTH, parsing, 1);
	check_header_content(COMMENT_CMD_STRING, COMMENT_LENGTH, parsing, 0);
	if (ft_strncmp(parsing->clean_line, NAME_CMD_STRING, \
		ft_strlen(NAME_CMD_STRING)) != 0 &&
		ft_strncmp(parsing->clean_line, COMMENT_CMD_STRING, \
		ft_strlen(COMMENT_CMD_STRING)) != 0)
	{
		if (parsing->name_stocked == 0 && parsing->comment_stocked == 0)
		{
			ft_putendl_fd("Name and Comment undefined", 2);
			exit (-1);
		}
		else if (parsing->comment_stocked == 0)
		{
			ft_putendl_fd("Champion comment undefined", 2);
			exit (-1);
		}
		else if (parsing->name_stocked == 0)
		{
			ft_putendl_fd("Champion name undefined", 2);
			exit (-1);
		}
	}
	return (0);
}

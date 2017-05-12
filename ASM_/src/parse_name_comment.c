/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:59:02 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/12 15:06:38 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	name_comment_checked(t_parsing *parsing, char flag_type)
{
	if (ft_strncmp(parsing->clean_line, NAME_CMD_STRING, \
		ft_strlen(NAME_CMD_STRING)) == 0 && flag_type == 1)
	{
		if (parsing->name_stocked == 0)
			parsing->name_stocked = 1;
		else
		{
			ft_dprintf(2, "Champion name already defined - Line %d\n", \
			parsing->line_nb);
			exit(-1);
		}
	}
	else if (ft_strncmp(parsing->clean_line, COMMENT_CMD_STRING, \
			ft_strlen(COMMENT_CMD_STRING)) == 0 && flag_type == 0)
	{
		if (parsing->comment_stocked == 0)
			parsing->comment_stocked = 1;
		else
		{
			ft_dprintf(2, "Champion comment already defined - Line %d\n", \
			parsing->line_nb);
			exit(-1);
		}
	}
}

void		parse_undefined_name_comment(t_parsing *parsing)
{
	if (parsing->name_stocked == 0 && parsing->comment_stocked == 0)
	{
		ft_putendl_fd("Name and Comment undefined", 2);
		exit(-1);
	}
	else if (parsing->comment_stocked == 0)
	{
		ft_putendl_fd("Champion comment undefined", 2);
		exit(-1);
	}
	else if (parsing->name_stocked == 0)
	{
		ft_putendl_fd("Champion name undefined", 2);
		exit(-1);
	}
}

/*
** parse_name_comment : Check if the header is well formated.
** .name "my_name"
** .comment "my_comment"
*/

int			parse_name_comment(t_parsing *parsing, header_t *header)
{
	check_header_content(NAME_CMD_STRING, PROG_NAME_LENGTH, parsing, header);
	name_comment_checked(parsing, 1);
	check_header_content(COMMENT_CMD_STRING, COMMENT_LENGTH, parsing, header);
	name_comment_checked(parsing, 0);
	if (ft_strncmp(parsing->clean_line, NAME_CMD_STRING, \
		ft_strlen(NAME_CMD_STRING)) != 0 &&
		ft_strncmp(parsing->clean_line, COMMENT_CMD_STRING, \
		ft_strlen(COMMENT_CMD_STRING)) != 0)
		parse_undefined_name_comment(parsing);
	return (0);
}

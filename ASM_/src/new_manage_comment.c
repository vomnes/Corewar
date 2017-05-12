/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_manage_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:58:09 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/11 18:52:48 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int get_name(char **clean_line, char **name_line, int *inside_name)
{
    int nb_occ;

    nb_occ = 0;
    if (ft_strncmp(*clean_line, NAME_CMD_STRING, \
    ft_strlen(NAME_CMD_STRING)) == 0
    || *inside_name == 1)
    {
        nb_occ = ft_nb_occ(*clean_line, '\"');
        if (nb_occ > 2)
        {
            ft_putendl("Error");
            exit (-1);
        }
        else
        {
            if (nb_occ == 1)
                *inside_name ^= 1;
            if (!(*name_line = ft_strjoin_free(*name_line, *clean_line)))
                return (-1);
            if (*inside_name == 1)
            {
                if (!(*name_line = ft_strjoin_free(*name_line, "\n")))
                    return (-1);
            }
        }
    }
    return (0);
}

static int get_comment(char **clean_line, char **comment_line, int *inside_comment)
{
    int nb_occ;

    nb_occ = 0;
    if (ft_strncmp(*clean_line, COMMENT_CMD_STRING, \
    ft_strlen(COMMENT_CMD_STRING)) == 0
    || *inside_comment == 1)
    {
        nb_occ = ft_nb_occ(*clean_line, '\"');
        if (nb_occ > 2)
        {
            ft_putendl("Error");
            exit (-1);
        }
        else
        {
            if (nb_occ == 1)
                *inside_comment ^= 1;
            if (!(*comment_line = ft_strjoin_free(*comment_line, *clean_line)))
                return (-1);
            if (*inside_comment == 1)
            {
                if (!(*comment_line = ft_strjoin_free(*comment_line, "\n")))
                    return (-1);
            }
        }
    }
    return (0);
}

int			parsing(int fd)
{
	char *line;
    char *clean_line;
    int num;
    int inside_comment;
    int inside_name;
    char *name_line;
    char *comment_line;

	line = NULL;
    num = 0;
    clean_line = NULL;
    inside_comment = 0;
    inside_name = 0;
    if (!(name_line = ft_strnew(1)))
        return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		num++;
        if (inside_name == 0 && inside_comment == 0)
        {
            if (!(clean_line = ft_strtrim_comment(line, COMMENT_CHAR)))
                     return (-1);
        }
        else
        {
            if (!(clean_line = ft_strdup(line)))
                     return (-1);
        }
        ft_printf("[%2d] -|%s\n", num, clean_line);
        get_name(&clean_line, &name_line, &inside_name);
        get_comment(&clean_line, &comment_line, &inside_comment);
		parse_name_comment(&(data->parsing), &(data->header));
        if (ft_strncmp(parsing->clean_line, NAME_CMD_STRING,\
            ft_strlen(NAME_CMD_STRING)) == 0 && \
            ft_strncmp(parsing->clean_line, NAME_CMD_STRING,\
            ft_strlen(NAME_CMD_STRING)) == 0 &&
            (*program_name != '\0' && *comment != '\0'))
        {
            Error collect name/comment
        }
        {
        if (*program_name != '\0' && *comment != '\0')
        {

        }
        ft_strdel(&clean_line);
		ft_strdel(&line);
	}
    ft_putendl(name_line);
    ft_putendl(comment_line);
    ft_strdel(&clean_line);
	ft_strdel(&line);
    return (0);
}

int main(int argc, char **argv)
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    parsing(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:51:51 by vomnes            #+#    #+#             */
/*   Updated: 2017/04/26 17:06:12 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define FILE argc - 1
#define OPTION argc - 2
#define USAGE "Usage: ./asm [-a] <sourcefile.s>\n"
#define OPT "       -a : Instead of creating a .cor file, outputs a stripped"
#define OPT_2 " and annotated version of the code to the standard output\n"

static int open_input_error(char *file_name, int *fd)
{
    char *term;

    if (open(file_name, O_DIRECTORY) > 0)
    {
        ft_printf("Input can't be a directory\n");
        return (-1);
    }
    if ((*fd = open(file_name, O_RDONLY)) < 0)
    {
        ft_printf("Can't read source file %s\n", file_name);
        return (-1);
    }
    if (ft_strlen(file_name) > 128)
    {
        ft_printf("File name too long (> 128 char) %s\n", file_name);
        return (-1);
    }
    if ((term = ft_strstr(file_name, ".s")) == NULL || ft_strlen(term) > 2)
    {
        ft_putstr("Wrong file name - [.s]\n");
        return (-1);
    }
    return (0);
}

/*
** open_input : Check the input file, it's format and option parameter,
** if the file is good (Not too long, not a directory, .s) and can be open
** stock file name and input fd in t_input.
*/

int open_input(int argc, char **argv, t_input *input_data)
{
    input_data->fd = 0;
    ft_bzero(input_data->file_name, 129);
    if (argc <= 1 || ft_strcmp(argv[FILE], "-a") == 0)
    {
        ft_putstr(USAGE);
        ft_putstr(OPT);
        ft_putstr(OPT_2);
        return (-1);
    }
    if (open_input_error(argv[FILE], &input_data->fd) == -1)
        return (-1);
    ft_strcat(input_data->file_name, argv[FILE]);
    if (ft_strcmp(argv[OPTION], "-a") == 0)
    {
        ft_putstr("Option [on]\n");
    }
    return (0);
}

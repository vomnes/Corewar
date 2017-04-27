/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_binary_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:14:15 by vomnes            #+#    #+#             */
/*   Updated: 2017/04/27 17:09:14 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Create the .cor binary file with the name of the input without .s
** Return the binary file's fd.
*/

int create_binary_file(t_input input)
{
    char    *name_dot_cor;
    int     binary_fd;

    if (!(name_dot_cor = ft_strndup(input.file_name, \
    ft_strindex(input.file_name, ".s"))))
        return (-1);
    if (!(name_dot_cor = ft_strjoin_free(name_dot_cor, ".cor")))
        return (-1);
    binary_fd = open(name_dot_cor, O_RDWR | O_CREAT | O_TRUNC, \
                            S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, 0777);
    if (binary_fd == -1)
        return (-1);
    // ft_printf("Writing output program to %s\n", name_dot_cor);
    ft_strdel(&name_dot_cor);
    return (binary_fd);
}

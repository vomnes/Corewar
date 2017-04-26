/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_binary_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:14:15 by vomnes            #+#    #+#             */
/*   Updated: 2017/04/26 15:42:43 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int create_binary_file(t_input input)
{
    char *name_dot_cor;
    int binary_fd;

    if (!(name_dot_cor = ft_strndup(input.file_name, \
    ft_strindex(input.file_name, ".s"))))
        return (-1);
    if (!(name_dot_cor = ft_strjoin(name_dot_cor, ".cor")))
        return (-1);
    binary_fd = open(name_dot_cor, O_RDWR | O_CREAT | O_TRUNC, \
                            S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, 0777);
    return (binary_fd);
}

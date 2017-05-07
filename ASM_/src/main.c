/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:34:38 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/07 11:58:35 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int argc, char **argv)
{
	t_data data;

	if (open_input(argc, argv, &data.input) == -1)
		return (-1);
	if ((data.binary_file.fd = create_binary_file(data.input)) == -1)
		return (-1);
	if (parsing_input(&data) == -1)
		return (-1);
	// print_instructions_list(data.parsing.lst);
	// delete_lst_instructions(data.parsing.lst);
// if (generate_binary_code(&data) == -1)
	// 	return (-1);
	return (0);
}


// ft_write_nb(fd, 0x0b680100);
// ft_write_nb(fd, 0x0f000106);
// ft_write_nb(fd, 0x64010000);
// ft_write_nb(fd, 0x00000101);
// ft_write_nb(fd, 0x01);
// 42
// Just a basic Winner Program

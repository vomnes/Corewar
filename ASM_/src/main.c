/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:34:38 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/09 13:15:09 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int argc, char **argv)
{
	t_data data;

	if (open_input(argc, argv, &data.input) == -1)
		return (-1);
	if (parsing_input(&data) == -1)
		return (-1);
	if ((data.binary_file.fd = create_binary_file(data.input)) == -1)
		return (-1);
	if (generate_binary_code(&data) == -1)
			return (-1);
	print_instructions_list(data.parsing.lst);
	ft_printf("prog_size = %d | %x\n", data.header.prog_size, data.header.prog_size);
	// delete_lst_instructions(data.parsing.lst);
	return (0);
}

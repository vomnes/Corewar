/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:34:38 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/23 15:36:08 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define SUCCESS 0
#define FAILURE -1

static void	print_usage(int argc, char **argv)
{
	if (argc <= 1 || ft_strcmp(argv[FILE], "-d") == 0 ||
	ft_strcmp(argv[FILE], "-details") == 0 ||
	ft_strcmp(argv[FILE], "-r") == 0 ||
	ft_strcmp(argv[FILE], "-rev") == 0)
	{
		ft_putstr("Usage: ./asm [-details/-d | -rev/-r] <sourcefile.s>\n");
		ft_putstr("       -details : Instead of creating a .cor file, \
outputs a stripped and\n");
		ft_putstr("                  annotated version of the code to the \
standard output.\n");
		ft_putstr("       -rev     : Disassemble a .cor file by writing on");
		ft_putstr(" the standard\n                  \
the pseudo-asm code of this .cor file.\n");
		exit(-1);
	}
}

static int	manage_binary(t_data *data)
{
	if (data->header.prog_size == 0)
	{
		ft_dprintf(2, "No enough data to generate a binary file player \
- Program size : 0 bytes\n");
		return (-1);
	}
	else
	{
		if ((data->binary_file.fd = create_binary_file(data->input)) == -1)
			return (-1);
		if (generate_binary_code(data) == -1)
			return (-1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_data data;

	print_usage(argc, argv);
	if (ft_strcmp(argv[OPTION], "-r") == 0 || ft_strcmp(argv[OPTION], \
		"-rev") == 0)
		rev_process_reverse_binary(argc, argv);
	else
	{
		if (open_input(argc, argv, &data.input) == -1)
			return (ft_exit_clean(&data.parsing.lst, FAILURE, &data));
		if (parsing_input(&data) == -1)
			return (ft_exit_clean(&data.parsing.lst, FAILURE, &data));
		if (program_data(&data) == -1)
			return (ft_exit_clean(&data.parsing.lst, FAILURE, &data));
		if (ft_strcmp(argv[OPTION], "-d") == 0 || ft_strcmp(argv[OPTION], \
			"-details") == 0)
			details_compilation(data.parsing.lst, data.header);
		else
		{
			if (manage_binary(&data) == -1)
				return (ft_exit_clean(&data.parsing.lst, FAILURE, &data));
		}
		ft_exit_clean(&data.parsing.lst, SUCCESS, &data);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_parse_line_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:34:44 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:37:46 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static char	**handle_dumps(char **av, t_vm *vm)
{
	int tmp;

	if (*av && ft_strcmp(*av, "-dump") == 0)
	{
		if (av[1] && ft_atoi_error(av[1], &tmp) && tmp >= 0)
			vm->dumps = tmp;
		else
			vm_error_exit(vm, "Bad entry for option -dump");
		return (av + 2);
	}
	return (NULL);
}

static char	**handle_verbose(char **av, t_vm *vm)
{
	int	tmp;

	if (*av && ft_strcmp(*av, "-v") == 0)
	{
		if (av[1] && ft_atoi_error(av[1], &tmp) && tmp >= 0 && tmp <= 31)
			vm->verbose = tmp;
		else
			vm_error_exit(vm, "Bad entry for option -v");
		return (av + 2);
	}
	return (NULL);
}

char		**vm_parse_line_command(char **av, t_vm *vm)
{
	static int	count_champs = 1;
	char		**ret;

	if ((ret = handle_dumps(av, vm)))
		av = ret;
	else if ((ret = handle_verbose(av, vm)))
		av = ret;
	else if (*av && ft_strcmp(*av, "-vis") == 0 && av++)
		vm->vis = 1;
	else if (*av && ft_strcmp(*av, "-a") == 0 && av++)
		vm->aff = 1;
	else if (*av)
	{
		av = vm_read_file_champ(av, vm, count_champs);
		count_champs++;
		++av;
	}
	else
		return (av);
	return (vm_parse_line_command(av, vm));
}

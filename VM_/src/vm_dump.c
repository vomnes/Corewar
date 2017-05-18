/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:59:54 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:13:55 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			check_pos_pc(t_vm vm, int i)
{
	t_process	*process;
	int			value;

	process = vm.processes;
	while (process)
	{
		value = process->pc;
		if (value == i && value != 0)
			return (1);
		process = process->next;
	}
	return (0);
}

void		print_memory_dump(t_vm vm)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < MEM_SIZE)
	{
		j = -1;
		ft_printf("0x%04x : ", i);
		while (++j < 64)
		{
			if (check_pos_pc(vm, i))
				ft_printf("%s%02x %s", RED, vm.memory[i++], DEF);
			else
				ft_printf("%02x ", vm.memory[i++]);
		}
		ft_putchar('\n');
	}
}

void		vm_dump_if_necessary(t_vm *vm)
{
	if (vm->dumps > -1 && vm->dumps == vm->cycle_nbr)
	{
		print_memory_dump(*vm);
		vm_delete_data(vm);
		exit(0);
	}
}

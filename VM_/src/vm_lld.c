/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:23:35 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:23:36 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_lld(t_process *process, t_vm *vm)
{
	int load;
	int pc;

	pc = process->pc;
	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		if (process->instruction.first_type == T_DIR)
			load = process->instruction.params[0].in;
		else
			load = vm_read_memory_int(vm, pc +
				process->instruction.params[0].sh);
		vm_store_in_register(
			&process->registers[process->instruction.params[1].uch], load);
		if (vm_verbose_operations(vm))
			ft_printf("P%5d | lld %d r%hhd\n", process->no, load,
			process->instruction.params[1].uch);
		process->carry = 0;
		if (load == 0)
			process->carry = 1;
	}
	vm_advance_pc(process, vm);
}

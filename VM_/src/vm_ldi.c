/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:20:48 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/22 12:36:49 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_ldi(t_process *process, t_vm *vm)
{
	int		pc;
	int		param1;
	int		param2;
	int		sum;
	int		load;

	pc = process->pc;
	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		param1 = vm_param_to_int_idx(process, vm, 0);
		param2 = vm_param_to_int_idx(process, vm, 1);
		sum = param1 + param2;
		load = vm_read_memory_int(vm, mod(pc + sum % IDX_MOD));
		vm_store_in_register(
			&process->registers[process->instruction.params[2].uch], load);
		if (vm_verbose_operations(vm))
			ft_printf("P% 5d | ldi %d %d r%d\n       | -> load from %d + %d \
= %d (with pc and mod %d)\n", process->no, param1, param2, process->instruction.
params[2].uch, param1, param2, sum, pc + sum % IDX_MOD);
	}
	vm_advance_pc(process, vm);
}

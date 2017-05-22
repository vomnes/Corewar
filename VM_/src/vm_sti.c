/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:41:35 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/22 12:41:24 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_sti(t_process *process, t_vm *vm)
{
	int	pc;
	int	param2;
	int	param3;
	int	sum;
	int	storage;

	pc = process->pc;
	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		param2 = vm_param_to_int_idx(process, vm, 1);
		param3 = vm_param_to_int_idx(process, vm, 2);
		sum = param2 + param3;
		storage = vm_read_register(
			process->registers[process->instruction.params[0].uch]);
		vm_store_in_memory_int(vm, mod(pc + sum % IDX_MOD), storage);
		vm_fill_cells(vm, mod(pc + sum % IDX_MOD), process->player_no);
		if (vm_verbose_operations(vm))
			ft_printf("P% 5d | sti r%hhd %d %d\n       | -> store to %d + %d = \
%d (with pc and mod %d)\n", process->no, process->instruction.params[0].uch,
param2, param3, param2, param3, sum, pc + sum % IDX_MOD);
	}
	vm_advance_pc(process, vm);
}

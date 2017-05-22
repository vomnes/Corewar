/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:41:07 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/22 12:41:11 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_st(t_process *process, t_vm *vm)
{
	int	pc;
	int	storage;

	pc = process->pc;
	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		storage = vm_read_register(
			process->registers[process->instruction.params[0].uch]);
		if (process->instruction.second_type == T_REG)
			vm_store_in_register(
			&process->registers[process->instruction.params[1].uch], storage);
		else
		{
			vm_store_in_memory_int(vm,
			mod(pc + process->instruction.params[1].sh % IDX_MOD), storage);
			vm_fill_cells(vm, mod(pc + process->instruction.params[1].sh %
			IDX_MOD), process->player_no);
		}
		if (vm_verbose_operations(vm))
			ft_printf("P% 5d | st r%hhd %d\n", process->no, process->
			instruction.params[0].uch, process->instruction.params[1].sh);
	}
	vm_advance_pc(process, vm);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:43:07 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:43:34 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_zjmp(t_process *process, t_vm *vm)
{
	short	indirection;
	int		pc;

	pc = process->pc;
	process->instruction.args[0] = T_DIR;
	vm_get_parameters(process, vm);
	indirection = vm_read_memory_short(vm, pc + 1);
	if (process->carry == 1)
	{
		process->pc = MOD(pc + indirection % IDX_MOD);
		vm->cells[pc].present = 0;
		vm->cells[MOD(pc + indirection % IDX_MOD)].present = process->player_no;
		if (vm_verbose_operations(vm))
			ft_printf("P%5d | zjmp %hd OK\n", process->no, indirection);
	}
	else
	{
		if (vm_verbose_operations(vm))
			ft_printf("P%5d | zjmp %hd FAILED\n", process->no, indirection);
		vm_advance_pc(process, vm);
	}
}

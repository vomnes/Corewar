/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:42:03 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 11:42:24 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_sub(t_process *process, t_vm *vm)
{
	int	pc;
	int	sub1;
	int	sub2;
	int	diff;

	pc = process->pc;
	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		sub1 = vm_read_register(
			process->registers[process->instruction.params[0].uch]);
		sub2 = vm_read_register(
			process->registers[process->instruction.params[1].uch]);
		process->carry = 0;
		if ((diff = sub1 - sub2) == 0)
			process->carry = 1;
		vm_store_in_register(
			&process->registers[process->instruction.params[2].uch], diff);
		if (vm_verbose_operations(vm))
			ft_printf("P%5d | sub r%hhd r%hhd r%hhd\n", process->no,
			process->instruction.params[0].uch, process->
			instruction.params[1].uch, process->instruction.params[2].uch);
	}
	vm_advance_pc(process, vm);
}

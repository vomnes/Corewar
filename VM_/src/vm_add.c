/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:55:48 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/19 11:19:58 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_add(t_process *process, t_vm *vm)
{
	int	pc;
	int	add1;
	int	add2;
	int	sum;

	pc = process->pc;
	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		add1 = vm_read_register(
			process->registers[process->instruction.params[0].uch]);
		add2 = vm_read_register(
			process->registers[process->instruction.params[1].uch]);
		process->carry = 0;
		if ((sum = add1 + add2) == 0)
			process->carry = 1;
		vm_store_in_register(
			&process->registers[process->instruction.params[2].uch], sum);
		if (vm_verbose_operations(vm))
			ft_printf("P% 5d | add r%hhd r%hhd r%hhd\n", process->no,
			process->instruction.params[0].uch, process->
			instruction.params[1].uch, process->instruction.params[2].uch);
	}
	vm_advance_pc(process, vm);
}

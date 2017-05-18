/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:58:33 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 10:58:34 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_and(t_process *process, t_vm *vm)
{
	int	pc;
	int	param1;
	int	param2;
	int	result;

	pc = process->pc;
	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		param1 = vm_param_to_int_idx(process, vm, 0);
		param2 = vm_param_to_int_idx(process, vm, 1);
		process->carry = 0;
		if ((result = param1 & param2) == 0)
			process->carry = 1;
		vm_store_in_register(
			&process->registers[process->instruction.params[2].uch], result);
		if (vm_verbose_operations(vm))
			ft_printf("P%5d | and %d %d r%hhd\n", process->no, param1,
			param2, process->instruction.params[2].uch);
	}
	vm_advance_pc(process, vm);
}

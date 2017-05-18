/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:57:42 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/18 10:57:43 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		vm_aff(t_process *process, t_vm *vm)
{
	int				character;

	if (vm_check_parameter_types(process->instruction) &&
		vm_get_parameters(process, vm) &&
		vm_valid_registers(process->instruction))
	{
		character = vm_read_register(
			process->registers[process->instruction.params[0].uch]);
		character = character % 256;
		if (vm->aff)
			ft_printf("Aff: %c\n", (char)character);
	}
	vm_advance_pc(process, vm);
}

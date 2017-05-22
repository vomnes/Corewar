/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_parameters2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:31:17 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/22 12:40:21 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		vm_param_to_int_idx(t_process *process, t_vm *vm, int i)
{
	int	pc;

	if (process->instruction.args[i] == T_REG)
		return (vm_read_register(
			process->registers[process->instruction.params[i].uch]));
	else if (process->instruction.args[i] == T_DIR)
	{
		if (g_op_tab[process->instruction.opcode].has_index)
			return (process->instruction.params[i].sh);
		else
			return (process->instruction.params[i].in);
	}
	else if (process->instruction.args[i] == T_IND)
	{
		pc = process->pc;
		return (vm_read_memory_int(vm, mod(pc +
			process->instruction.params[i].sh % IDX_MOD)));
	}
	else
		ft_dprintf(2, "Error: Process %i is trying to read parameter %i with\
		no valid arg type (opcode = %s)\n", process->no, i + 1,
		process->instruction.opcode);
	return (0);
}

int		vm_param_to_int_no_idx(t_process *process, t_vm *vm, int i)
{
	int	pc;

	if (process->instruction.args[i] == T_REG)
		return (vm_read_register(
			process->registers[process->instruction.params[i].uch]));
	else if (process->instruction.args[i] == T_DIR)
	{
		if (g_op_tab[process->instruction.opcode].has_index)
			return (process->instruction.params[i].sh);
		else
			return (process->instruction.params[i].in);
	}
	else if (process->instruction.args[i] == T_IND)
	{
		pc = process->pc;
		return (vm_read_memory_int(vm, mod(pc +
			process->instruction.params[i].sh)));
	}
	else
		ft_dprintf(2, "Error: Process %i is trying to read parameter %i with\
		no valid arg type (opcode = %s)\n", process->no, i + 1,
		process->instruction.opcode);
	return (0);
}

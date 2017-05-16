#include "vm.h"

int		vm_param_to_int_idx(t_process *process, t_vm *vm, int i)
{
	int	pc;

	if (process->instruction.args[i] == T_REG)
		return (vm_read_register(
			process->registers[process->instruction.params[i].uch]));
	else if (process->instruction.args[i] == T_DIR)
		return (process->instruction.params[i].in);
	else if (process->instruction.args[i] == T_IND)
	{
		pc = process->pc;
		//pc = vm_read_register(process->pc);
		return (vm_read_memory_int(vm, MOD(pc +
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
//		pc = vm_read_register(process->pc);
		pc = process->pc;
		return (vm_read_memory_int(vm, MOD(pc +
			process->instruction.params[i].sh)));
	}
	else
		ft_dprintf(2, "Error: Process %i is trying to read parameter %i with\
		no valid arg type (opcode = %s)\n", process->no, i + 1,
		process->instruction.opcode);
	return (0);
}

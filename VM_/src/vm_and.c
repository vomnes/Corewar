#include "vm.h"

int			check_good_parameters(t_process *process, char *name)
{
	if ((process->instruction.first_type == T_REG ||
		process->instruction.first_type == T_IND ||
		process->instruction.first_type == T_DIR) &&
		(process->instruction.second_type == T_REG ||
		process->instruction.second_type == T_DIR ||
		process->instruction.second_type == T_IND) &&
		(process->instruction.third_type == T_REG))
		return (1);
	return (0);
}

void		get_good_parameters(t_process *process, pc)
{
	int		first_param;

	if (process->instruction.first_type == T_REG)
		first_param = vm->memory[MOD(pc + 2)];
	else if (process->instruction.first_type == T_IND)
		first_param = vm_read_memory_short(vm, pc + 3);
	else if (process->instruction.first_type == T_DIR)
		first_param = vm_read_memory_int(vm, pc + 3);
}

void		vm_and(t_process *process, t_vm *vm)
{
	int		pc;

	pc = vm_read_register(process->pc);
	vm_decode_parameter_byte(process, vm);
	if (check_good_parameters(process))
		get_good_parameters(process, pc);
	else
		process->carry = 0;
}

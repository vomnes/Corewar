#include "vm.h"

int					move_pc(t_process *process, int pc)
{
	int count;

	count = 2;
	if (process->instruction.first_type == T_DIR)
		count += 4;
	else if (process->instruction.first_type == T_IND)
		count += 2;
	else if (process->instruction.first_type == T_REG)
		count += 1;
	if (process->instruction.second_type == T_DIR)
		count += 4;
	else if (process->instruction.second_type == T_IND)
		count += 2;
	else if (process->instruction.second_type == T_REG)
		count += 1;
	pc += count;
	return (pc);
}

void				vm_ld(t_process *process, t_vm *vm)
{
	unsigned int	pc;
	int				first_param;
	int				second_param;

	first_param = 0;
	second_param = 0;
	pc = vm_read_register(process->pc);
	vm_decode_parameter_byte(process, vm);
	if (process->instruction.first_type == T_DIR)
	{
		first_param = vm_read_memory_int(vm, pc + 2);
		second_param = MOD(pc + 6);
		if (second_param > 0 && second_param < REG_NUMBER)
			vm_store_in_register(&process->registers[second_param],
								(pc + (first_param % IDX_MOD)));
	}
	else if (process->instruction.first_type == T_IND)
	{
		first_param = vm_read_memory_short(vm, pc + 2);
		second_param = MOD(pc + 4);
		if (second_param > 0 && second_param < REG_NUMBER)
			vm_store_in_register(&process->registers[second_param],
								(pc + (first_param % IDX_MOD)));
	}
	vm_store_in_register(&process->pc, move_pc(process, pc));
}

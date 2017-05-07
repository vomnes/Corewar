#include "vm.h"

static void		get_second_parameter(t_process *process, t_vm *vm, int pc)
{
	int			first_param;
	int			second_param;
	int			value;

	first_param = vm->memory[MOD(pc + 2)];
	second_param = 0;
	if (first_param <= 0 || first_param > REG_NUMBER)
		return ;
	if (process->instruction.second_type == T_IND)
	{
		second_param = vm_read_memory_short(vm, pc + 3);
		value = vm_read_register(process->registers[first_param]);
		vm_store_in_memory_int(vm, (pc + (second_param % IDX_MOD)), value);		// Check if second_param <= 0 ?
	}
	else if (process->instruction.second_type == T_REG)
	{
		second_param = vm->memory[MOD(pc + 3)];
		if (second_param > 0 && second_param <= REG_NUMBER)
		{
			value = vm_read_register(process->registers[first_param]);
			vm_store_in_register(&process->registers[second_param], value);
		}
	}
}

void			vm_st(t_process *process, t_vm *vm)
{
	int			pc;

	pc = vm_read_register(process->pc);
	vm_decode_parameter_byte(process, vm);
	if (process->instruction.first_type == T_REG)
		get_second_parameter(process, vm, pc);
	vm_advance_pc(process);
}
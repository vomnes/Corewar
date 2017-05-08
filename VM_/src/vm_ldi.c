#include "vm.h"

static short	get_param(t_process *process, t_vm *vm, int *index,
						t_arg_type type)
{
	short			indirection;
	unsigned char	reg_number;

	if (type == T_DIR)
	{
		*index = MOD(*index + 2);
		return (vm_read_memory_short(vm, *index - 2));
	}
	else if (type == T_IND)
	{
		indirection = vm_read_memory_short(vm, *index) % IDX_MOD;
		*index = MOD(*index + 2);
		return (vm_read_memory_short(vm,
				MOD(vm_read_register(process->pc) + indirection)));
	}
	else
	{
		reg_number = vm->memory[MOD(*index)];
		*index = MOD(*index + 1);
		if (reg_number > 0 && reg_number <= REG_NUMBER)
		// !!! This will cast an int to a short!! Should we do that??
			return (vm_read_register(process->registers[reg_number]));
		else
			process->carry = 0;
		return (0);
	}
}

void			vm_ldi(t_process *process, t_vm *vm)
{
	int				index;
	short			param1;
	short			param2;
	unsigned char	reg_number;

	index = vm_read_register(process->pc) + 2;
	process->carry = 1;
	if (vm_check_parameter_types(process->instruction))
	{
		param1 = get_param(process, vm, &index, process->instruction.args[0]);
		param2 = get_param(process, vm, &index, process->instruction.args[1]);
		if (process->carry)
		{
			reg_number = vm->memory[MOD(index)];
			if (reg_number > 0 && reg_number <= REG_NUMBER)
				vm_store_in_register(&process->registers[reg_number],
						vm_read_memory_int(vm,
							MOD((param1 + param2) % IDX_MOD)));
			else
				process->carry = 0;
		}
	}
	else
		process->carry = 0;
	vm_advance_pc(process);
}


/*
static short	get_param(t_process *process, t_vm *vm, int *index,
						t_arg_type type)
{
	short			indirection;
	unsigned char	reg_number;
	short			result;

	if (type == T_DIR)
	{
		result = vm_read_memory_short(vm, *index);
		*index = MOD(*index + 2);
	}
	else if (type == T_IND)
	{
		indirection = vm_read_memory_short(vm, *index) % IDX_MOD;
		result = vm_read_memory_short(vm, MOD(process->pc + indirection));
		*index = MOD(*index + 2);
	}
	else
	{
		reg_number = vm->memory[MOD(*index)];
		if (reg_number > 0 && reg_number <= REG_NUMBER)
			result = vm_read_register(process->registers[reg_number]);
		else
			process->carry = 0;
		*index = MOD(*index + 1);
	}
	return (result);
}
*/

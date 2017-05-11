#include "vm.h"

static long long			get_param(t_process *process, t_vm *vm, long long *index,
						t_arg_type type)
{
	int				indirection;
	unsigned char	reg_number;

	if (type == T_DIR)
	{
		*index = MOD(*index + 2);
		return (vm_read_memory_int(vm, *index - 2, 2));
	}
	else if (type == T_IND)
	{
		indirection = vm_read_memory_int(vm, *index, 2) % IDX_MOD;
		*index = MOD(*index + 2);
		return (vm_read_memory_int(vm,
				MOD(vm_read_register(process->pc) + indirection), 2));
	}
	else
	{
		reg_number = vm->memory[MOD(*index)];
		*index = MOD(*index + 1);
		if (reg_number > 0 && reg_number <= REG_NUMBER)
			return (vm_read_register(process->registers[reg_number]));
		process->carry = 0;
		return (0);
	}
}

void			vm_lldi(t_process *process, t_vm *vm)
{
	long long		index;
	long long		param1;
	long long		param2;
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
						vm_read_memory_int(vm, MOD(param1 + param2), 4));
			else
				process->carry = 0;
		}
	}
	else
		process->carry = 0;
	vm_advance_pc(process);
}
